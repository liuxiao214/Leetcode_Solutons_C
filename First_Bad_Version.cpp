#include <iostream>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
	return true;
}

class Solution132 {//³¬Ê±
public:
	int firstBadVersion(int n) {
		for (int i = 1; i <= n; i++)
		{
			if (isBadVersion(i))
				return i;
		}
	}
};

class Solution132_1 {
public:
	int firstBadVersion(int n) {
		int low = 1;
		int high = n+1;
		int mid;
		while (low<high)
		{
			mid = (low + high) / 2;
			if (isBadVersion(mid))
			{
				high = mid;
			}				
			else
			{
				low = mid;
			}
		}
		return high;
	}
};
class Solution132_2 {
public:
	int firstBadVersion(int n) {
		int low = 0;
		int high = n;
		int mid;
		while (high-low>1)
		{
			mid = low + (high - low) / 2;
			if (isBadVersion(mid))
			{
				high = mid;
			}
			else
			{
				low = mid;
			}
		}
		return high;
	}
};
class Solution132_3 {
public:
	int firstBadVersion(int n) {
		int low = 1;
		int high = n;
		int mid;
		while (high>low)
		{
			mid = low + (high - low) / 2;
			if (isBadVersion(mid))
			{
				high = mid;
			}
			else
			{
				low = mid + 1;
			}
		}
		return high;
	}
};
#if 0
void main()
{
	Solution132_1 s;
	cout << s.firstBadVersion(19);
	system("pause");
}
#else
#endif