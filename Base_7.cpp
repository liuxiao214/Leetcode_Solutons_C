#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;
class Solution46 {
public:
	string convertToBase7(int num) {
		if (num==0)
		{
			return "0";
		}
		string s = "";
		int t = num;
		if (num<0)
		{
			num = 0 - num;
		}
		while (num>0)
		{				
			int temp = num % 7;
			num = num / 7;
			stringstream stream;
			stream << temp;
			string ss = stream.str();
			s = ss + s;
		}
		if (t>0)
		{
			return s;
		}
		else
		{
			s = "-" + s;
			return s;
		}
	}
};
#if 0
void main()
{
	Solution46 s;
	cout<<s.convertToBase7(-7).c_str()<<endl;
	system("pause");
}
#else
#endif