#include <iostream>
using namespace std;
class Solution0
{
public:
	int hammingDistance(int x, int y)
	{
		int a[100], b[100];
		int i = 0, j = 0, len1, len2, k, flag;
		int sum = 0;
		while (x > 0)
		{
			a[i] = x % 2;
			x = x / 2;
			i++;
		}
		while (y > 0)
		{
			b[j] = y % 2;
			y = y / 2;
			j++;
		}
		if (i > j)
		{
			len1 = j;
			len2 = i;
			flag = 1;
		}
		else
		{
			len1 = i;
			len2 = j;
			flag = 2;
		}
		for (k = 0; k < len1; k++)
		{
			if (a[k] != b[k])
				sum++;
		}
		for (k; k < len2; k++)
		{
			if (flag == 1)
			{
				if (a[k] == 1)
					sum++;
			}
			else
			{
				if (b[k] == 1)
					sum++;
			}

		}
		return sum;
	}
};
#if 0
void main()
{
	Solution0 mys;
	cout << mys.hammingDistance(1, 4);
	system("pause");
/*	int x, y;
	while (cin >> x >> y)
	{
		int a[100], b[100];
		int i = 0, j = 0, len1, len2, k, flag;
		int sum = 0;
		while (x > 0)
		{
			a[i] = x % 2;
			x = x / 2;
			i++;
		}
		while (y > 0)
		{
			b[j] = y % 2;
			y = y / 2;
			j++;
		}
		if (i > j)
		{
			len1 = j;
			len2 = i;
			flag = 1;
		}
		else
		{
			len1 = i;
			len2 = j;
			flag = 2;
		}
		for (k = 0; k < len1; k++)
		{
			if (a[k] != b[k])
				sum++;
		}
		for (k; k < len2; k++)
		{
			if (flag == 1)
			{
				if (a[k] == 1)
					sum++;
			}
			else
			{
				if (b[k] == 1)
					sum++;
			}

		}
		cout << sum << endl;
	//	system("pause");
	}
	*/
}
#else
#endif