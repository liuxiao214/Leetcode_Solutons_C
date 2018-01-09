#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Solution59 {
public:
	string addStrings(string num1, string num2) {
		if (num1.length() == 0 && num2.length() == 0)
			return "";
		if (num1.length() == 0)
			return num2;
		if (num2.length() == 0)
			return num1;
		if (num1.length()<num2.length())
		{
			string sstemp = num1;
			num1 = num2;
			num2 = sstemp;
		}
		int i = num1.length() - 1;
		int j = num2.length() - 1;
		int flag = 0;
		string sum = "";
		while (i>=0 && j>=0)
		{
			int temp = 0;
			if (flag==1)
			{
				temp = (num1[i] - '0') + (num2[j] - '0')+1;
			}
			else
				temp = (num1[i] - '0') + (num2[j] - '0');
			stringstream sstream;
			if (temp>9)
			{
				flag = 1;
				sstream << (temp - 10);
			}
			else
			{
				flag = 0;
				sstream << temp;	
			}
			string stemp = sstream.str();
			sum = stemp + sum;
			i--;
			j--;
		}  
		if (i >= 0)
		{
			for (int k = i; i >= 0; i--)
			{
				stringstream sstream;
				if (flag == 1 && num1[i] == '9')
				{
					sum = "0" + sum;
					flag = 1;
				}
				else if (flag == 1)
				{
					int itemp = 1 + num1[i] - '0';
					sstream << itemp;
					string stemp = sstream.str();
					sum = stemp + sum;
					flag = 0;
				}
				else
				{
					sum = num1[i] + sum;
					flag = 0;
				}
			}
		}
		if (flag==1)
		{
			sum = "1" + sum;
		}
		return sum;
	}
};
class Solution59_1 {
public:
	string addStrings(string num1, string num2) {
		if (num1.length() == 0 && num2.length() == 0)
			return "";
		if (num1.length() == 0)
			return num2;
		if (num2.length() == 0)
			return num1;
		int i = num1.length() - 1;
		int j = num2.length() - 1;
		int flag = 0;
		string ssum = "";
		while (i>=0 ||j>=0 ||flag)
		{
			long sum = 0;
			if (i>=0)
			{
				sum = sum + num1[i]-'0';
				i--;
			}
			if (j>=0)
			{
				sum = sum + num2[j] - '0';
				j--;
			}
			sum = sum + flag;
			flag = sum / 10;
			sum = sum % 10;
			ssum = to_string(sum) + ssum;
		}
		return ssum;
	}
};
#if 0
void main()
{
	Solution59_1 s;
	string s1 = "1";
	string s2 = "9";
	string s3 = s.addStrings(s1, s2);
	cout << s3 << endl;
	system("pause");
}
#else
#endif