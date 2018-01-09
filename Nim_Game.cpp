#include <iostream>
using namespace std;
class Solution8 {
public:
	bool canWinNim(int n) {
		if (n % 4 == 0)
		{
			cout << "You never can win" << endl;
			return false;
		}
		else
		{
			cout << "You can win" << endl;
			return true;
		}
	}
};
#if 0
void main()
{
	Solution8 a;
	a.canWinNim(8);
	system("pause");
}
#else
#endif