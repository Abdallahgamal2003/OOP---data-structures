#include<iostream>

using namespace std;

template<class t>

class node {
public:
    t values;
    node<t> *next;
};

template<class t>

class list {
private:
    node<t> *head;
    node<t> *tail;

public:
    list() {
        head = nullptr;
        tail = nullptr;
    }

    list(t value, int initial_size) {
        node<t> *temp;
        temp = new node<t>;
        temp->values = value;
        temp->next = nullptr;
        head = temp;
        tail = temp;
        temp = nullptr;
        for (int i = 0; i < initial_size - 1; i++) {
            node<t> *test;
            test = new node<t>;
            test->values = value;
            test->next = nullptr;
            tail->next = test;
            tail = test;
        }
    }

    ~list() {
        while (head != tail) {
            delete_last();
        }
        delete head;
        delete tail;
    }

    list<t> &operator=(list<t> another_list) {
        if (&another_list == this)
            return *this;
        iterator test = another_list.begin();
        this->push_back(*test);
        while (test != another_list.end()) {
            ++test;
            this->push_back(*test);
        }
        return *this;
    }

    int size() {
        int l = 0;
        node<t> *temp = head;
        while (temp != nullptr) {
            l++;
            temp = temp->next;
        }
        return l;
    }


    class iterator {
    public:
        node<t> *tempIterator;
        node<t> *headIterator;

        iterator() {
            tempIterator = nullptr;
            headIterator = nullptr;
        }

        iterator(node<t> *tempI, node<t> *headI) {
            tempIterator = tempI;
            headIterator = headI;
        }

        void operator--() {
            list<t>::iterator obj;
            obj.tempIterator = this->headIterator;
            obj.headIterator = this->headIterator;
            if (this->tempIterator == this->headIterator)
                cout << "NOT IN RANGE" << endl;
            else {
                while (obj.tempIterator->next != nullptr) {
                    if (obj.tempIterator->next == this->tempIterator) {
                        this->tempIterator = obj.tempIterator;
                    }
                    ++obj;
                }
            }
        }

        void operator++() {
            if (tempIterator->next == nullptr)
                cout << "NOT IN RANGE" << endl;
            else {
                tempIterator = tempIterator->next;
            }
        }

        bool operator==(const iterator &ptrx) const {
            return (tempIterator == ptrx.tempIterator);
        }

        bool operator!=(const iterator &ptrx) const {
            return (tempIterator != ptrx.tempIterator);
        }

        t &operator*() const {
            return tempIterator->values;
        }
    };

//returning iterators
    iterator begin() {
        return iterator(head, head);
    }

    iterator end() {
        return iterator(tail, head);
    }

    void insert_first(t value) {
        node<t> *n;
        n = new node<t>;
        n->values = value;
        n->next = head;
        head = n;
    }

    void insert_last(t value) {
        node<t> *n;
        n = new node<t>;
        if (head == nullptr) {
            insert_first(value);
        } else {
            n->next = nullptr;
            tail->next = n;
            tail = n;
            n->values = value;
        }
    }

    void insert_pos(t value, int pos) {
        if (pos == 0) {
            insert_first(value);
        } else if (pos >= size()) {
            insert_last(value);
        } else {
            node<t> *temp;
            temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }
            node<t> *x;
            x = new node<t>;
            x->next = temp->next;
            temp->next = x;
            x->values = value;
        }
    }

    void push_back(t value) {
        node<t> *temp;
        temp = new node<t>;
        temp->values = value;
        temp->next = nullptr;
        if (head == nullptr) {
            head = temp;
            tail = temp;
            temp = nullptr;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    iterator erase(iterator pos) {
        node<t> *deleting = pos.tempIterator->next;
        pos.tempIterator->next = pos.tempIterator->next->next;
        if (deleting == tail)
            tail = pos.tempIterator;
        delete deleting;
        return pos;
    }

    void delete_first() {
        if (head != nullptr) {
            node<t> *temp;
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void delete_last() {
        node<t> *temp;
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nullptr;
        tail = temp;
    }

    void delete_pos(int pos) {
        node<t> *temp;
        temp = head;
        node<t> *x;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        x = temp->next;
        temp->next = x->next;
        delete x;
    }

    void print() {
        node<t> *temp;
        temp = head;
        while (temp != nullptr) {
            cout << temp->values << "   ";
            temp = temp->next;
        }
    }
};

int main() {
    list<int> l(99, 2);
    l.insert_first(4);
    l.insert_first(3);
    l.insert_first(2);
    l.insert_first(1);
    l.insert_last(12);
    l.insert_last(7);
    l.insert_pos(88, 5);
    l.delete_first();
    l.delete_last();
    l.delete_pos(3);
    l.print();
    cout << "\nsize is = " << l.size()
         << endl;
    list<int>::iterator iterator1 = l.begin();
    list<int>::iterator iterator2 = l.begin();
    cout << *iterator1 << endl;
    ++iterator1;
    cout << *iterator1 << endl;
    ++iterator1;
    cout << *iterator1 << endl;
    ++iterator1;
    cout << *iterator1 << endl;
    ++iterator1; //end of linkedlist
    cout << *iterator1 << endl;
    ++iterator1; //out
    cout << *iterator1 << endl;
    --iterator1; //back to last element
    cout << *iterator1 << endl;
    cout << "\n\n";
    l.erase(iterator2);
    cout << "Erased succesfully\n";
    list<int> l1;
    l1 = l;
    l1.print();

    return 0;
}