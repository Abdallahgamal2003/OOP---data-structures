#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;

class fraction
{
public:
    fraction();
    fraction(string str1, string string);
    fraction(const fraction& obj);


    int gcd(string str1, string str2);
    void reduce();



    bool operator <= (fraction obj);
    bool operator >= (fraction obj);
    bool operator == (fraction obj);
    bool operator != (fraction obj);


    friend istream& operator >> (istream& in, fraction& obj);
    friend ostream& operator << (ostream& out, fraction  obj);

    fraction operator + (fraction  obj);
    fraction operator - (fraction  obj);
    fraction operator * (fraction  obj);
    fraction operator / (fraction  obj);




protected:
    int num, dum;


};

#endif // FRACTION_H