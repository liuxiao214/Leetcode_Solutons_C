#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution61 {
public:
	string int2char(int num)
	{
		if (num == 0)
			return "0";
		if (num == 1)
			return "1";
		if (num == 2)
			return "2";
		if (num == 3)
			return "3";
		if (num == 4)
			return "4";
		if (num == 5)
			return "5";
		if (num == 6)
			return "6";
		if (num == 7)
			return "7";
		if (num == 8)
			return "8";
		if (num == 9)
			return "9";
		if (num == 10)
			return "a";
		if (num == 11)
			return "b";
		if (num == 12)
			return "c";
		if (num == 13)
			return "d";
		if (num == 14)
			return "e";
		if (num == 15)
			return "f";
	}
	string toHex(int num) {
		if (num == 0)
			return "0";
		string hnum="";
		if (num>0)
		{
			while (num>0)
			{
				int yu = num % 16;
				num = num / 16;
				hnum = int2char(yu) + hnum;
			}
			return hnum;
		}
		else
		{
			int temp = 0 - num;
			vector<int>bnum(32, 0);
			bnum[0]++;
			for (int i = bnum.size() - 1; i > 0;i--)
			{
				bnum[i] = 1 - temp % 2;
				temp = temp / 2;
			}		
			if (bnum[bnum.size() - 1] == 0)
				bnum[bnum.size() - 1] = 1;
			else
			{
				int flag = 1;
				for (int i = bnum.size() - 1; i > 0; i--)
				{
					if (bnum[i] == 1 && flag == 1)
					{
						bnum[i] = 0;
						flag = 1;
					}
					else
					{
						bnum[i] = 1;
						flag = 0;
						break;
					}
				}
			}
			for (int i = bnum.size() - 1; i>=0; i = i - 4)
			{
				int subnum = 0;
				for (int j = 0; j < 4;j++)
				{
					subnum += bnum[i - j]*pow(2,j);
				}
				hnum = int2char(subnum) + hnum;
			}
			return hnum;
		}
	}
};
const string hexx = "0123456789abcdef";
class Solution61_1 {
public:
	string toHex(int num) {
		if (num == 0)
			return "0";
		string hnum="";
		int count = 0; 
		while (num && count<8)
		{
			hnum = hexx[num & 0xf] + hnum;
			count++;
			num = num >> 4;
		}
		return hnum;
	}
};
#if 0
void main()
{
	Solution61_1 s;
	string h = s.toHex(-2);
	cout<<h<<endl;
	system("pause");
}
#else
#endif
