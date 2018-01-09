#include <iostream>
#include <math.h>
using namespace std;

class Solution67 {//³¬Ê±
public:
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		return climbStairs(n - 1)+climbStairs( n - 2);
	}
};
class Solution67_1 {
public:
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		int f1 = 1;
		int f2 = 2;
		int fn = 0;
		for (int i = 3; i <= n;i++)
		{
			fn = f1 + f2;
			f1 = f2;
			f2 = fn;
		}
		return fn;
	}
};
#if 0
void main()
{
	Solution67_1 s;
	cout << s.climbStairs(5) << endl;
	system("pause");
}
#else
#endif