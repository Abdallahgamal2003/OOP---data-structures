#include <iostream>
#include <set>
#include <string>

using namespace std;

void RecPermute(const string &soFar, string rest) {
    set<string> ptr;
    if (rest.empty())             // No more characters
        cout << soFar << endl; // Print the word
    else                       // Still more chars
        // For each remaining char
        // longlong unsigned int because of warning when comparing
        for (long long unsigned int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i) + rest.substr(i + 1);
            // Added part
            long long unsigned int ptrSize = ptr.size();
            ptr.insert(next);
            if (ptrSize != ptr.size())
                RecPermute(next, remaining);
        }
}

// "wrapper" function
void ListPermutations(string s) {
    RecPermute("", s);
}

int main() {
    ListPermutations("qqqq");
    return 0;
}
