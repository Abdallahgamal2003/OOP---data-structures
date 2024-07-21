#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

void basedSort(vector<string>& vec2) {
	int count = 0;
	
	
	
	swap(vec2[0], vec2[1]);
	for (int i = 0; i < vec2.size(); i++) {
		if (vec2[i] == "untitled") {	
			swap(vec2[count], vec2[i]);
			count++;	
		}
	}
	cout << "The songs after sorting :" << endl;
	sort(vec2.begin()+count, vec2.end());
	for (int i = 0; i < vec2.size(); i++) {
		cout << vec2[i] << endl;
	}
}

int main() {
	int n;
	cout << "Enter the number of songs :"<<" ";
	cin >> n;
	vector<string>vec(n);
	cout << "Enter the songs :" << endl;
	for (int i=0; i < n; i++) {
		cin >> vec[i];
	}
	basedSort(vec);
	return 0;
}
