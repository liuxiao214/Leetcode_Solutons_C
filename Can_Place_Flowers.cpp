#include <iostream>
#include <vector>
using namespace std;

class Solution120 {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		if (n <= 0)
			return false;
		if (flowerbed.size() == 1)
		{
			if (flowerbed[0] == 0 && n == 1)
				return true;
			else
				return false;
		}
		if (flowerbed.size() == 2)
		{
			if (flowerbed[0] == 0 && flowerbed[1] == 0 && n == 1)
				return true;
			else
				return false;
		}
		if (n > (flowerbed.size() / 2 + 1))
			return false;
		int flag1 = 0;
		int i = 0;
		if (flowerbed[i] == 0 && flowerbed[i+1] == 0)
		{
			n--;
			flag1 = 0;
			i++;
		}
		while(i < flowerbed.size()-1)
		{
			if (flowerbed[i]==1)
				flag1 = 0;
			else
				flag1++;		
			if (flag1 == 2 && flowerbed[i+1] == 0)
			{
				n--;
				flag1 = 0;
			}
			i++;
		}
		if (flag1 == 1 && flowerbed[i] == 0)
			n--;
		return n<=0;
	}
};
class Solution120_1 {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		for (int i = 0; i < flowerbed.size();i++)
		{
			if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
			{
				flowerbed[i] = 1;
				n--;
			}
		}
		return n <= 0;
	}
};
#if 0
void main()
{
	Solution120_1 s;
	vector<int>a = { 1,0,0, 0, 0,1};
	cout << s.canPlaceFlowers(a, 2) << endl;
	system("pause");
}
#else
#endif