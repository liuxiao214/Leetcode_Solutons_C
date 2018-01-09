#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution129 {//³¬Ê±
public:
	bool isprime(int n)
	{
		int j = sqrt(n);
		for (int i = 2; i <= j;i++)
		{
			if (n%i == 0)
				return false;
		}
		return true;
	}
	int countPrimes(int n) {
		if (n <= 2)
			return 0;
		int count = 1;
		for (int i = 3; i < n;i+=2)
		{
			if (isprime(i))
				count++;
		}
		return count;
	}
};
class Solution129_1 {
public:
	int countPrimes(int n) {
		if (n < 3)
			return 0;
		int count = 1;
		vector<bool>v(n, true);
		int j = sqrt(n);
		for (int i = 3; i < n;i+=2)
		{
			if (v[i])
			{
				count++;
				if (i>j)
					continue;
				for (int k = i*i; k < n; k += i)
					v[k] = false;
			}
		}
		return count;
	}
};
#if 0
void main()
{
	Solution129_1 s;
	cout << s.countPrimes(10) << endl;
	system("pause");
}
#else
#endif