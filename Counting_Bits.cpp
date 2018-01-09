#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution140 {
public:
	int getbit(int num)
	{
		int count = 0;
		while (num>0)
		{		
			if (num % 2 == 1)
				count++;
			num = num / 2;
		}
		return count;
	}
	vector<int> countBits(int num) {
		vector<int>bits(num + 1,0);
		for (int i = 1; i < bits.size();i++)
		{
			bits[i] = getbit(i);
		}
		return bits;
	}
};
class Solution140_1 {
public:
	vector<int> countBits(int num) {
		vector<int>bits(num + 1, 0);
		for (int i = 1; i < bits.size(); i++)
		{
			bits[i] = bits[(i - 1)&i] + 1;
		}
		return bits;
	}
};
class Solution140_2 {
public:
	vector<int> countBits(int num) {
		vector<int>bits(1, 0);
		int j = 1;
		while (j<=num)
		{
			int n = bits.size();
			for (int i = 0; i < n && j<=num; i++,j++)
			{
				bits.push_back(bits[i] + 1);
			}
		}		
		return bits;
	}
};
class Solution140_3 {
public:
	vector<int> countBits(int num) {
		vector<int>bits(num + 1, 0);
		for (int i = 1; i < bits.size(); i++)
		{
			bits[i] = bits[i / 2] + i % 2;
		}
		return bits;
	}
};
class Solution140_4 {
public:
	vector<int> countBits(int num) {
		vector<int>bits(num + 1, 0);
		for (int i = 1; i < bits.size(); i++)
		{
			bits[i] = bits[i>>1] + i % 2;
		}
		return bits;
	}
};

#if 0
void main()
{
	Solution140_4 s;
	vector<int>bits = s.countBits(16);
	for (int i = 0; i < bits.size(); i++)
	{
		cout << bits[i] << " ";
	}
	cout << endl;
	system("pause");
}
#else
#endif
