#include <iostream>
#include <vector>
using namespace std;
class Solution83 {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>a;
		if (numRows <= 0)
			return a;
		vector<int>b1 = { 1 };
		if (numRows == 1)
		{
			vector<int>b1 = { 1 };
			a.push_back(b1);
			return a;
		}
		vector<int>b2 = { 1,1 };
		a.push_back(b1);
		a.push_back(b2);
		for (int i = 2; i < numRows;i++)
		{		
			vector<int>temp(i+1,1);
			int j = 1;
			vector<int>b3 = a[i - 1];
			while (j < i)
			{
				temp[j] = b3[j - 1] + b3[j];
				j++;
			}
			a.push_back(temp);
		}
		return a;
	}
};
class Solution83_1 {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>a(numRows);
		for (int i = 0; i < numRows;i++)
		{
			a[i].resize(i + 1);
			a[i][0] = 1;
			a[i][i] = 1;
			for (int j = 1; j < i; j++)
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
		return a;
	}
};
#if 0
void main()
{
	Solution83_1 s;
	vector<vector<int>>a = s.generate(6);
	for (int i = 0; i < a.size();i++)
	{
		for (int j = 0; j < a[i].size();j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
}
#else
#endif