#include <iostream>
#include <string>

using namespace std;

class StudentName {
private:
    string name;
public:
    StudentName(string input) {
        int spaceCount = 0, lastPosition = 0;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == ' ') {
                spaceCount++;
                lastPosition = i;
            }
        }
        if (spaceCount == 0)
            name = input + " " + input + " " + input;
        else if (spaceCount == 1)
            name = input + input.substr(lastPosition);
        else
            name = input;
    }

    string getName() { return name; }

    bool replace_s(int pos1, int pos2) {
        string *arr;
        arr = new string[name.length()];
        for (int i = 0; i < name.length(); i++) {
            if (name[i] == ' ')
                continue;
            arr[i] = name[i];
        }
        for (int i = 0; i < name.length(); ++i) {
            cout << arr[i];
        }
        bool check = true;
        if (pos1 >= name.length() || pos1 < 0 || pos2 >= name.length() || pos2 < 0) {
            check = false;
            cout << "Out of range\n";
        } else {

        }
        return check;
    }

    void Print() {
        cout << "1) ";
        int counter = 2;
        for (int i = 0; i < name.length(); i++) {
            cout << name[i];
            if (name[i] == ' ') {
                cout << '\n' << counter << ")";
                cout << name[i];
                counter++;
            }
        }
        cout << endl << endl;
    }
};

int main()
{
    StudentName obj1("Ahmed");
    obj1.Print();

    StudentName obj2("Ahmed amr");
    obj2.Print();

    StudentName obj3("Ahmed amr ali");
    obj3.Print();

    StudentName obj4("Ahmed amr ali mohamed");
    obj4.Print();

    StudentName obj5("Ahmed amr ali mohamed Mostafa");
    obj5.Print();
    return 0;
}