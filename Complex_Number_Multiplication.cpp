#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution138 {
public:
	void getnumber(string s, int &real, int &ivirtual)
	{
		string sreal = "0";
		string svirtual = "0";
		for (int i = 0; i < s.length();i++)
		{
			if (s[i]=='+')
			{
				sreal = s.substr(0, i);
				svirtual = s.substr(i + 1, s.length() - i - 2);
			}
		}
		real = atoi(sreal.c_str());
		ivirtual = atoi(svirtual.c_str());
	}
	string complexNumberMultiply(string a, string b) {
		int a_real, a_ivirtual, b_real, b_ivirtual;
		getnumber(a, a_real, a_ivirtual);
		getnumber(b, b_real, b_ivirtual);
		int real = a_real*b_real - a_ivirtual*b_ivirtual;
		int ivirtual = a_ivirtual * b_real + b_ivirtual * a_real;
		string result = to_string(real) + "+" + to_string(ivirtual) + "i";
		return result;
	}
};
class Solution138_1 {
public:
	string complexNumberMultiply(string a, string b) {
		int ra, ia, rb, ib;
		char buff;
		stringstream aa(a), bb(b), ans;
		aa >> ra >> buff >> ia >> buff;
		bb >> rb >> buff >> ib >> buff;
		ans << ra*rb - ia*ib << "+" << ia*rb + ib*ra << "i";
		return ans.str();
	}
};

#if 0
void main()
{
	Solution138_1 s;
	string a = "1+-1i";
	string b = "1+-1i";
	string result = s.complexNumberMultiply(a, b);
	cout << result << endl;
	/*
	string ss = "-1+-2i";
	int a, b;
	s.getnumber(ss, a, b);
	cout << a << " " << b << endl;
	string sss = to_string(a);
	cout << sss << endl;
	*/
	system("pause");
}
#else
#endif