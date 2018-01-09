#include <iostream>
#include <vector>
using namespace std;

class Solution62 {
public:
	int maxProfit(vector<int>& prices) {
		int max = 0;
		for (int i = 0; i < prices.size();i++)
		{
			for (int j = i + 1; j<prices.size();j++)
			{
				if ((prices[j] - prices[i]) > max)
				{
					max = prices[j] - prices[i];
				}
			}		
		}
		return max;
	}
};
class Solution62_1 {
public:
	int maxProfit(vector<int>& prices) {
		int max = 0;
		int buy = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i]<prices[buy])
			{
				buy=i;
			}
			else
			{
				if (prices[i]-prices[buy]>max)
				{
					max = prices[i] - prices[buy];
				}
			}
		}
		return max;
	}
};
#if 0
void main()
{
	Solution62_1 s;
	vector<int>a = { 7, 1, 6, 4 ,3};
	cout << s.maxProfit(a) << endl;
	system("pause");
}
#else
#endif