#include <iostream>
#include<string>

using namespace std;
string remove(string str)
{
	string ns;
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) != '-')
			ns += str.at(i);
	}
	return ns;
}
string add(string str1, string str2)
{
	int num = 0;
	string result = "";
	if (str1[0] == '-')
	{
		str1 = remove(str1);
	}
	if (str2[0] == '-')
	{
		str2 = remove(str2);
	}
	while (str1.length() > str2.length()) str2 = '0' + str2;
	while (str1.length() < str2.length()) str1 = '0' + str1;
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		num = (str1[i] - '0') + (str2[i] - '0') + num;
		result = char((num % 10) + '0') + result;
		num /= 10;
	}
	if (num == 1)
	{
		result = '1' + result;
	}
	return result;
}
string subtraction(string str1, string str2)
{
	bool flag = false;
	bool check = false;
	bool ck = false;
	bool ck2 = false;
	string result;
	if (str1[0] == '-')
	{
		flag = true;
		str1 = remove(str1);
	}
	else if (str2[0] == '-')
	{
		check = true;
		str2 = remove(str2);
	}
	while (str1.length() > str2.length())
	{
		ck = true;
		str2 = '0' + str2;

	}
	while (str1.length() < str2.length())
	{
		ck2 = true;
		str1 = '0' + str1;
	}
	for (int i = 0; i < str1.length(); i++)
	{
		if ((str1[i] - '0') > (str2[i] - '0'))
		{
			ck = true;
			if (str1[0] == '-')
			{
				flag = true;
			}
			break;
		}
		else if ((str1[i] - '0') < (str2[i] - '0'))
		{
			ck2 = true;
			if (str2[0] == '-')
			{
				check = true;
			}
			break;
		}
	}
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		int num = 0;
		if (ck == true)
		{
			if ((str1[i] - '0') > (str2[i] - '0'))
			{
				num = (str1[i] - '0') - (str2[i] - '0');
			}
			if ((str1[i] - '0') < (str2[i] - '0'))
			{
				num = ((str1[i] - '0') + 10) - (str2[i] - '0');
				if (i == 0)
					break;
				str1[i - 1] = ((str1[i - 1] - '0') - 1) + '0';
			}
		}
		if (ck2 == true)
		{
			if ((str2[i] - '0') > (str1[i] - '0'))
			{
				num = (str2[i] - '0') - (str1[i] - '0');
			}
			if ((str2[i] - '0') < (str1[i] - '0'))
			{
				num = ((str2[i] - '0') + 10) - (str1[i] - '0');
				if (i == 0)
					break;
				str2[i - 1] = ((str2[i - 1] - '0') - 1) + '0';
			}
		}
		result = char(num + '0') + result;
	}
	if (ck == true && flag == true)
	{
		result = '-' + result;
	}
	if (ck2 == true && check == true)
	{
		result = '-' + result;
	}
	return result;
}
class BigInt
{
public:
	string str1, str2;
	BigInt()
	{}
	BigInt(long long decInt)
	{
		string str = to_string(decInt);
		str2 = str;
	}
	BigInt(string decstr)
	{
		str1 = decstr;
	}
	BigInt operator+(BigInt& str)
	{
		BigInt result;
		string a = str.str1;
		string  a2 = str1;
		if (a[0] != '-' && a2[0] != '-')
		{
			result.str1 = add(a, a2);
		}
		if (a[0] == '-' || a2[0] == '-')
		{
			result.str1 = subtraction(a, a2);
		}
		if (a[0] == '-' && a2[0] == '-')
		{
			result.str1 = '-' + add(a, a2);
		}
		string a3 = str2;
		string a4 = str.str2;
		if (a3[0] != '-' && a4[0] != '-')
		{
			result.str2 = add(a3, a4);
		}
		if (a3[0] == '-' || a4[0] == '-')
		{
			result.str2 = subtraction(a3, a4);
		}
		if (a3[0] == '-' && a4[0] == '-')
		{
			result.str2 = '-' + add(a3, a4);
		}
		return result;
	}
	friend ostream& operator<<(ostream& out, const BigInt& str)
	{
		out << str.str1;
		out << str.str2;
		return out;
	}
	BigInt operator=(BigInt str)
	{
		str1 = str.str1;
		str2 = str.str2;
	}
	int size()
	{
		int l = 0;
		for (int i = 0; i <= str1.length()-1; i++)
		{
			l++;
		}
		return l;
	}
};
int main()
{
	/*BigInt str1( "123456789012345678901234567890");
	BigInt str2 ("113456789011345678901134567890");
	BigInt s3 = str1 + str2;*/ // expected value=236913578023691357802369135780


	/*BigInt str1("1223445667889887665443221");
	BigInt str2("-154362876984390765432");
	BigInt s3 = str1 + str2;*/ //expected value=1223291305012903274677789


	/*BigInt str1("19288765799");
	BigInt str2=str1;
	BigInt s3 = str1 + str2;*/ //expected value = 38577531598


	/*BigInt str1 ("-17658906543213");
	BigInt str2 ("-123987650765432");
	BigInt s3 = str1 + str2; */   //expected value = -141646557308645


	BigInt str1("-17658906543213");
	BigInt str2("123987650765432");
	BigInt s3 = str1 + str2;   //expected value = 106328744222219

	cout << "num 1=" << str1 << endl << "num 2 =" << str2 << endl << "num1+num2 = " << s3 << endl << s3.size();
}