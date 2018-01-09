#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;
class Solution111 {
public:
	string addBinary(string a, string b) {
		string sum = "";
		int i = a.length() - 1;
		int j = b.length() - 1;
		int flag = 0;
		while (i>=0 && j>=0)
		{
			if (flag==1)
			{
				if (a[i] == '1' && b[j] == '1')
				{
					sum.insert(0, 1, '1');
					flag = 1;
				}
				else if (a[i] == '0' && b[j] == '0')
				{
					sum.insert(0, 1, '1');
					flag = 0;
				}
				else
				{
					sum.insert(0, 1, '0');
					flag = 1;
				}
			}
			else
			{
				if (a[i] == '1' && b[j] == '1')
				{
					sum.insert(0, 1, '0');
					flag = 1;
				}
				else if (a[i] == '0' && b[j] == '0')
				{
					sum.insert(0, 1, '0');
					flag = 0;
				}
				else
				{
					sum.insert(0, 1, '1');
					flag = 0;
				}
			}
			i--;
			j--;
		}
		if (j==-1)
		{
			while (i>=0)
			{
				if (flag == 1 && a[i] == '1')
				{
					sum.insert(0, 1, '0');
					flag = 1;
				}
				else if (flag == 0 && a[i] == '0')
				{
					sum.insert(0, 1, '0');
					flag = 0;
				}
				else 
				{
					sum.insert(0, 1, '1');
					flag = 0;
				}
				i--;
			}			
		}
		if (i == -1)
		{
			while (j >= 0)
			{
				if (flag == 1 && b[j] == '1')
				{
					sum.insert(0, 1, '0');
					flag = 1;
				}
				else if (flag == 0 && b[j] == '0')
				{
					sum.insert(0, 1, '0');
					flag = 0;
				}
				else
				{
					sum.insert(0, 1, '1');
					flag = 0;
				}
				j--;
			}
		}
		if (flag==1)
			sum.insert(0, 1, '1');
		return sum;
	}
};
class Solution111_0 {//此法不合适
public:
	string addBinary(string a, string b) {
		stringstream stream1(a);
		stringstream stream2(b);
		int a1;
		int a2;
		stream1 >> a1;
		stream2 >> a2;
		int n = 0;
		int flag = 0;
		int i = 1;
		while (a1>0 || a2>0)
		{
			int temp =flag;
			if (a1 > 0)
			{
				temp = temp + a1 % 10;
				a1 = a1 / 10;
			}
			if (a2 > 0)
			{
				temp = temp + a2 % 10;
				a2 = a2 / 10;
			}
			n = n + temp * pow(10, i);//为0的时候不成功，此法不合适
			flag = temp / 2;				
		}
		return to_string(n);
	}
};
class Solution111_1 {
public:
	string addBinary(string a, string b) {
		string sum = "";
		int flag = 0;
		int i = a.length() - 1;
		int j = b.length() - 1;
		while (flag==1 || i>=0 || j>=0)
		{
			if (i >= 0)
				flag = flag + a[i--] - '0';
			if (j >= 0)
				flag = flag + b[j--] - '0';
			sum = char(flag%2+'0') + sum;
			flag = flag / 2;
		}
		return sum;
	}
};
#if 0
void main()
{
	Solution111_1 s;
	string s1 = "1";
	string s2 = "111";
	string s3 = s.addBinary(s1, s2);
	cout << s3 << endl;
	system("pause");
}
#else
#endif
