//#include<fraction.h>
#include <iostream>
#include<string>

using namespace std;
string add(string str1, string str2) //this function convert from string  to integer and sum the integers
{
	string str3 = "", str4 = "", str5 = "", str6 = "", str7 = "";
	int a, b, c, d, s, h;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] == '/')
		{
			break;
		}
		str3 = str3 + str1[i];
	}
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		if (str1[i] == '/')
		{
			break;
		}
		str4 = str1[i] + str4;
	}
	for (int i = 0; i < str2.length(); i++)
	{
		if (str2[i] == '/')
		{
			break;
		}
		str5 = str5 + str2[i];
	}
	for (int i = str2.length() - 1; i >= 0; i--)
	{
		if (str2[i] == '/')
		{
			break;
		}
		str6 = str2[i] + str6;
	}
	a = stoi(str3);
	b = stoi(str4);
	c = stoi(str5);
	d = stoi(str6);
	s = (a * d) + (b * c);
	h = b * d;
	str7 = to_string(s) + '/' + to_string(h);
	return str7;
}
string reduce(string str1) //this function reduce the result string after convert it to integer 
{
	string str3 = "", str4 = "", str5 = "", str6 = "";
	int a, b, j;
	bool check = false, flag = false;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] == '/')
		{
			break;
		}
		str3 = str3 + str1[i];
	}
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		if (str1[i] == '/')
		{
			break;
		}
		str4 = str1[i] + str4;
	}
	a = stoi(str3);
	b = stoi(str4);
	if (a < 0)
	{
		flag = true;
		a *= -1;
	}
	if (b < 0)
	{
		check = true;
		b *= -1;
	}
	if (a > b)
	{
		for (int i = b; i >= 0; i--)
		{
			if (a % i == 0 && b % i == 0)
			{
				j = i;
				break;
			}
		}
	}
	if (a < b)
	{
		for (int i = a; i >= 0; i--)
		{
			if (a % i == 0 && b % i == 0)
			{
				j = i;
				break;
			}
		}
	}
	if (flag == true || check == true)
	{
		str5 = '-' + to_string(a / j) + '/' + to_string(b / j);
	}
	else
	{
		str5 = to_string(a / j) + '/' + to_string(b / j);
	}
	return str5;
}
string subtraction(string str1, string str2) //this function to subtract two strings after converting to integer 
{
	string str3 = "", str4 = "", str5 = "", str6 = "", str7 = "";
	int a, b, c, d, s, h;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] == '/')
		{
			break;
		}
		str3 = str3 + str1[i];
	}
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		if (str1[i] == '/')
		{
			break;
		}
		str4 = str1[i] + str4;
	}
	for (int i = 0; i < str2.length(); i++)
	{
		if (str2[i] == '/')
		{
			break;
		}
		str5 = str5 + str2[i];
	}
	for (int i = str2.length() - 1; i >= 0; i--)
	{
		if (str2[i] == '/')
		{
			break;
		}
		str6 = str2[i] + str6;
	}
	a = stoi(str3);
	b = stoi(str4);
	c = stoi(str5);
	d = stoi(str6);
	s = (a * d) - (b * c);
	h = b * d;
	str7 = to_string(s) + '/' + to_string(h);
	return str7;
}
string  multiplication(string str1, string str2)//this function multiple  two strings after converting to integer 
{
	string str3 = "", str4 = "", str5 = "", str6 = "", str7 = "";
	int a, b, c, d, s, h;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] == '/')
		{
			break;
		}
		str3 = str3 + str1[i];
	}
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		if (str1[i] == '/')
		{
			break;
		}
		str4 = str1[i] + str4;
	}
	for (int i = 0; i < str2.length(); i++)
	{
		if (str2[i] == '/')
		{
			break;
		}
		str5 = str5 + str2[i];
	}
	for (int i = str2.length() - 1; i >= 0; i--)
	{
		if (str2[i] == '/')
		{
			break;
		}
		str6 = str2[i] + str6;
	}
	a = stoi(str3);
	b = stoi(str4);
	c = stoi(str5);
	d = stoi(str6);
	s = a * c;
	h = b * d;
	str7 = to_string(s) + '/' + to_string(h);
	return str7;
}
string division(string str1, string str2) //this function to division two strings after converting to integer 
{
	string str3 = "", str4 = "", str5 = "", str6 = "", str7 = "";
	int a, b, c, d, s, h;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] == '/')
		{
			break;
		}
		str3 = str3 + str1[i];
	}
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		if (str1[i] == '/')
		{
			break;
		}
		str4 = str1[i] + str4;
	}
	for (int i = 0; i < str2.length(); i++)
	{
		if (str2[i] == '/')
		{
			break;
		}
		str5 = str5 + str2[i];
	}
	for (int i = str2.length() - 1; i >= 0; i--)
	{
		if (str2[i] == '/')
		{
			break;
		}
		str6 = str2[i] + str6;
	}
	a = stoi(str3);
	b = stoi(str4);
	c = stoi(str5);
	d = stoi(str6);
	s = a * d;
	h = b * c;
	str7 = to_string(s) + '/' + to_string(h);
	return str7;
}
bool greater_than(string str1, string str2) //this function : detect the biggest and the smallest
{
	string str3 = "", str4 = "", str5 = "", str6 = "", str7 = "";
	int a, b, c, d, s, h, l, m, n;
	bool y = false;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] == '/')
		{
			break;
		}
		str3 = str3 + str1[i];
	}
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		if (str1[i] == '/')
		{
			break;
		}
		str4 = str1[i] + str4;
	}
	for (int i = 0; i < str2.length(); i++)
	{
		if (str2[i] == '/')
		{
			break;
		}
		str5 = str5 + str2[i];
	}
	for (int i = str2.length() - 1; i >= 0; i--)
	{
		if (str2[i] == '/')
		{
			break;
		}
		str6 = str2[i] + str6;
	}
	a = stoi(str3);
	b = stoi(str4);
	c = stoi(str5);
	d = stoi(str6);
	h = b * d;
	s = (a * d) / h;
	l = (b * c) / h;
	if (s > l)
	{
		y = true;
	}
	return y;
}
bool less_than(string str1, string str2) //this function : detect the biggest and the smallest
{
	string str3 = "", str4 = "", str5 = "", str6 = "", str7 = "";
	int a, b, c, d, s, h, l, m, n;
	bool z = false;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] == '/')
		{
			break;
		}
		str3 = str3 + str1[i];
	}
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		if (str1[i] == '/')
		{
			break;
		}
		str4 = str1[i] + str4;
	}
	for (int i = 0; i < str2.length(); i++)
	{
		if (str2[i] == '/')
		{
			break;
		}
		str5 = str5 + str2[i];
	}
	for (int i = str2.length() - 1; i >= 0; i--)
	{
		if (str2[i] == '/')
		{
			break;
		}
		str6 = str2[i] + str6;
	}
	a = stoi(str3);
	b = stoi(str4);
	c = stoi(str5);
	d = stoi(str6);
	h = b * d;
	s = (a * d) / h;
	l = (b * c) / h;
	if (s < l)
	{
		z = true;
	}
	return z;
}
class fraction //class takes 2 strings to do the functions above in operators
{
public:
	bool x;
	string str1, str2;
	fraction() {} //default constructor
	fraction(string s1, string s2) //paramitarized constructor
	{
		str1 = s1;
		str2 = s2;
	}
	fraction operator+(fraction& s)//add operator by taking objects from the class
	{
		fraction s2;
		s2.str1 = reduce(add(str1, s.str1));
		return s2;
	}
	fraction operator-(fraction& s)//subtract operator by taking objects from the class
	{
		fraction s2;
		s2.str1 = reduce(subtraction(str1, s.str1));
		return s2;
	}
	fraction operator*(fraction& s)//multiplication operator by taking objects from the class
	{
		fraction s2;
		s2.str1 = reduce(multiplication(str1, s.str1));
		return s2;
	}
	fraction operator/(fraction& s)//division operator by taking objects from the class
	{
		fraction s2;
		s2.str1 = reduce(division(str1, s.str1));
		return s2;
	}
	bool operator>(fraction& s)//greater than operator by taking objects from the class
	{
		bool flag = false;
		if (greater_than(str1, s.str1))
			flag = true;
		return flag;
	}
	bool operator<(fraction& s)//smaller than operator by taking objects from the class
	{
		bool check = false;
		if (less_than(str1, s.str1));
		check = true;
		return check;
	}
	bool operator==(fraction& s)//equality operator by taking objects from the class
	{
		bool check = false;
		if (str1 == s.str1)
		{
			check = true;
		}
		return check;
	}

	friend istream& operator>>(istream& in, fraction& str) //insertion input operator
	{
		in >> str.str1;
		return in;
	}
	friend ostream& operator<<(ostream& out, const fraction& str)//output operator
	{
		out << str.str1;
		out << str.str2;
		return out;
	}
};
class fraction_calculator//class takes objects from class fraction (aggregation) to print the outputs
{
public:
	fraction str1, str2;
	void calculator() {
		int c;
		cout << "Enter the first  \n";
		cin >> str1;
		cout << "Enter the second \n";
		cin >> str2;
		while (true) {

			cout << "1-Adding\n" <<
				"2-subtracting" << endl
				<< "3-multiplication" << endl
				<< "4-dividing" << endl
				<< "5-the biggest fraction" << endl
				<< "6-the smallest fraction" << endl
				<< "7-check equality" << endl
				<< "8-return" << endl
				<< "9-exit" << endl
				<< "choose: ";
			cin >> c;
			if (c == 1) {
				fraction str3(str1 + str2);

				cout << "str1+str2= " << str3 << endl;

			}
			else if (c == 2) {

				fraction str3(str1 - str2);
				cout << "str1-str2= " << str3 << endl;

			}
			else if (c == 3) {
				fraction str3(str1 * str2);

				cout << "str1*str2 " << str3 << endl;

			}
			else if (c == 4) {
				fraction str3(str1 / str2);
				cout << "str1/str2= " << str3 << endl;

			}
			else if (c == 5)
			{
				bool x(str1 > str2);
				cout << "the first fraction is the biggest :" << x << endl;
			}
			else if (c == 6)
			{
				bool y(str1 < str2);;
				cout << "the second fraction is the biggest :" << y << endl;
			}
			else if (c == 7)
			{
				bool z(str1 == str2);
				cout << "the equality :" << z << endl;

			}
			else if (c == 8) {

				calculator();
			}
			else if (c == 9)
			{
				cout << "thank you" << endl;
				break;
			}
		}
	}
};
int main()
{
	fraction_calculator k; //taking object from class fraction_calculator 
	k.calculator();//calling the function calculator
}