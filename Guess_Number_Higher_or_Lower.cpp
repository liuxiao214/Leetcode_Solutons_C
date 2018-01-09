#include <iostream>
using namespace std;
const int a = 2;
int guess(int num)
{
	if (num > a)
		return -1;
	else if (num < a)
		return 1;
	else
		return 0;
}

class Solution101 {
public:
	int guessNumber(int n) {
		int low = 1;
		int high = n;
		while (1)
		{
			int mid = (high - low ) / 2 + low;
			if (guess(mid) == 1)
				low = mid + 1;
			else if (guess(mid) == -1)
				high = mid - 1;
			else
				return mid;
		}
	}
};
class Solution101_1 {
public:
	int guessNumber(int n) {
		int low = 1;
		int high = n;
		while (1)
		{
			int mid = (high + low) / 2;
			if (guess(mid) == 1)
				low = mid + 1;
			else if (guess(mid) == -1)
				high = mid - 1;
			else
				return mid;
		}
	}
};
#if 0
void main()
{
	Solution101 s;
	cout << s.guessNumber(2) << endl;
	system("pause");
}
#else
#endif