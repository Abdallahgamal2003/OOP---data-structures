#include<iostream>
using namespace std;
class node {
public:
	string first_name, last_name, phoneNumber;
	node* next;
	node() {
		first_name = "";
		last_name = "";
		phoneNumber = "";

	}
	node(string f, string l, string p) {
		first_name = f;
		last_name = l;
		phoneNumber = p;

	}
};
class phoneDirectory :public node {
	node* head;
	node* tail;
public:
	phoneDirectory() {
		head = NULL;
		tail = NULL;
	}
	void insert_first(string f_n, string l_n, string p_d) {
		node* n = new node(f_n, l_n, p_d);
		n->next = head;
		if (head == NULL) {
			tail = n;
		}
		head = n;
	}
	void insert_last(string f_n, string l_n, string p_d) {
		node* n = new node(f_n, l_n, p_d);
		if (head == NULL) {
			insert_first(f_n, l_n, p_d);
		}
		else {
			n->next = NULL;
			tail->next = n;
			tail = n;
		}
	}
	string search_p(string p_d) {
		string search;
		node* temp = head;
		while (temp != NULL) {
			if (temp->phoneNumber == p_d) {
				search = temp->first_name + " " + temp->last_name;
				break;
			}
			temp = temp->next;

		}
		return search;
	}
	string search_f(string f_n) {
		string search;
		node* temp = head;
		while (temp != NULL) {
			if (temp->first_name == f_n) {
				search = temp->phoneNumber;
				break;
			}
			temp = temp->next;

		}
		return search;
	}
	int length() {
		int l = 0;
		node* temp = head;
		while (temp != NULL) {
			l++;
			temp = temp->next;
		}
		return l;
	}
	void delete_byname(string f_n) {
		node* temp = head;
		node* x;
		int index = 0;
		for (int i = 0; i < length(); i++) {
			if (temp->first_name == f_n) {
				index = i;
				break;

			}
		}
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		x = temp->next;
		temp->next = x->next;
		delete x;



	}
	void bubble_sorting() {
		node* temp1 = head;
		node* temp2 = head;
		string x;
		while (temp1 != NULL) {
			temp2 = head;
			while (temp2->next != NULL) {
				if (temp2->first_name[0] > temp2->next->first_name[0]) {
					x = temp2->first_name;
					temp2->first_name = temp2->next->first_name;
					temp2->next->first_name = x;
				}
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}
	}

	void print() {
		node* temp = head;
		while (temp != NULL) {
			cout << temp->first_name << "  " << temp->last_name << "        " << temp->phoneNumber << endl;
			temp = temp->next;
		}
		cout << endl;
	}

};
int main() {
	phoneDirectory direct;
	cout << "WELCOME TO OUR PHONE DIRECTORY" << endl;
	cout << endl;
	cout << "choose one process y entering it’s number" << endl;
	cout << endl;
	char choice = '0';
	while (choice != 6) {
		cout << endl;
		cout << "  1. Add an entry to the directory" << endl;
		cout << "  2. Look up a phone number" << endl;
		cout << "  3. Look up a first name" << endl;
		cout << "  4. Delete an entry from the directory" << endl;
		cout << "  5. List All enteries in phone directory" << endl;
		cout << "  6. Exit from this program" << endl;
		cout << endl;
		cout << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;
		cout << endl;
		if (choice == '1') {
			string f, l, p;
			cout << "Enter the first name: ";
			cin >> f;
			cout << "Enter the last name: ";
			cin >> l;
			cout << "Enter the phone number: ";
			cin >> p;
			direct.insert_last(f, l, p);
		}
		if (choice == '2') {
			string ph;
			cout << "Enter phone number: ";
			cin >> ph;
			cout << endl;
			cout << direct.search_p(ph);
			cout << endl;

		}
		if (choice == '3') {
			string fn;
			cout << "Enter the first name: ";
			cin >> fn;
			cout << endl;
			cout << direct.search_f(fn);
			cout << endl;
		}
		if (choice == '4') {
			string fn;
			cout << "Enter the first name : ";
			cin >> fn;
			direct.delete_byname(fn);
			direct.print();

		}
		if (choice == '5') {
			direct.bubble_sorting();
			direct.print();

		}
		if (choice == '6') {
			cout << "-----------------END--------------------" << endl;
			break;
		}

	}

}