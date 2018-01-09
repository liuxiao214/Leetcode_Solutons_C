#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution22 {
public:
	vector<int> constructRectangle(int area) {
		vector<int>a;
		int W, L;
		W = sqrt(area);
		for (int i = W; i >= 1;i--)
		{
			L = area / i;
			if (i*L == area)
			{
				a.push_back(L);
				a.push_back(i);
				return a;
			}
		}
	}
};
#if 0
void main()
{
	Solution22 s;
	vector<int>a = s.constructRectangle(6);
	for (int i = 0; i < a.size();i++)
	{
		cout << a[i] << endl;
	}
	system("pause");
}
#else
#endif