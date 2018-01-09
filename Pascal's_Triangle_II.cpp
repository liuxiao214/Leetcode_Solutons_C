#include <iostream>
#include <vector>
using namespace std;

class Solution95 {
public:
	vector<int> getRow(int rowIndex) {
		vector<int>b;
		if (rowIndex < 0)
			return b;
		vector<int>a(rowIndex+1,1);
		if (rowIndex == 0 || rowIndex == 1)
			return a;
		for (int i = 1; i < (rowIndex/2+1); i++)
		{
			int temp = 1;
			int x = rowIndex;
			int y = i;
			int count = i;
			while (count>0)
			{
				temp = temp*x;
				x--;
				count--;
			}
			while (y>0)
			{
				temp = temp / y;
				y--;
			}
			a[i] = temp;
			a[rowIndex - i] = temp;
		}
		return a;
	}//ÈÝÒ×Òç³ö
};
class Solution95_1 {
public:
	vector<int> getRow(int rowIndex) {
		vector<int>b;
		if (rowIndex < 0)
			return b;
		vector<int>a(rowIndex + 1, 1);
		if (rowIndex == 0 || rowIndex == 1)
			return a;
		vector<int>f1 = { 1, 1 };
		for (int i = 2; i <= rowIndex; i++)
		{
			vector<int>temp(i + 1, 1);
			int j = 1;
			while (j < (i/2+1))
			{
				temp[j] = f1[j - 1] + f1[j];
				temp[i - j] = temp[j];
				j++;
			}
			f1 = temp;
		}
		return f1;
	}
};
class Solution95_2 {
public:
	vector<int> getRow(int rowIndex) {
		vector<int>a(rowIndex + 1, 0);
		a[0] = 1;
		for (int i = 1; i <= rowIndex;i++)
		{
			for (int j = i; j >= 1;j--)
			{
				a[j] = a[j] + a[j - 1];
			}
		}
		return a;
	}
};
#if 0
void main()
{
	Solution95_2 s;
	vector<int>a = s.getRow(3);
	for (int i = 0; i < a.size();i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
}
#else
#endif