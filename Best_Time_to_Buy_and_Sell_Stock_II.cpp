#include <iostream>
#include <vector>
using namespace std;
class Solution31 {
public:
	int maxProfit(vector<int>& prices) {
		int buy = 0;
		int sell = 0;
		int profit = 0;
		for (int i = 1; i < prices.size();i++)
		{
			if (prices[i]>prices[i - 1] && i==prices.size()-1)
			{
				profit = profit + prices[i] - prices[buy];
			}
			if (prices[i]>prices[i-1])
			{
				sell = i;
			}
			else
			{
				profit = profit + prices[i - 1] - prices[buy];
				buy = i;
			}
		}
		return profit;
	}
};
#if 0
void main()
{
	Solution31 s;
	vector<int>a = { 12, 4, 5, 6, 1, 3, 7 };
	cout << s.maxProfit(a) << endl;
	system("pause");
}
#else 
#endif