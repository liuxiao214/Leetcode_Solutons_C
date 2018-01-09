#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;
class Solution50 {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string>time;
		for (int i = 0; i < 12;i++)
		{
			for (int j = 0; j < 60;j++)
			{
				if (bitset<10>(i << 6 | j).count() == num)
				{
					string s = "";
					stringstream stream;
					stream << i;
					string temp = stream.str();
					s = temp + ":";
					if (j>=10)
					{
						stringstream stream;
						stream << j;
						string temp = stream.str();
						s = s + temp;
					}
					else
					{
						stringstream stream;
						stream << j;
						string temp = stream.str();
						s = s + "0" + temp;
					}
					time.push_back(s);
				}	
			}
		}
		return time;
	}
};
class Solution50_1 {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string>time;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 60; j++)
			{
				if (bitset<10>(i << 6 | j).count() == num)
				{
					time.push_back(to_string(i) + (j>=10 ? ":" : ":0") +to_string(j));
				}
			}
		}
		return time;
	}
};
#if 0
void main()
{
	Solution50_1 s;
	vector<string>t = s.readBinaryWatch(1);
	for (int i = 0; i < t.size();i++)
	{
		cout << t[i] << endl;
	}
	system("pause");
}
#else
#endif