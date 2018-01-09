#include <iostream>
#include <vector>
using namespace std;
class Solution81 {
public:
	vector<int> plusOne(vector<int>& digits) {
		int flag = 1;
		int temp;		
		for (int i = digits.size()-1; i >= 0;i--)
		{
			if (flag==1)
			{
				temp = digits[i] + 1;
			}	
			if (temp==10)
			{
				digits[i] = 0;
				flag = 1;
			}
			else
			{
				digits[i] = temp;
				flag = 0;
				break;
			}
		}
		if (flag==1)
		{
			vector<int>::iterator a = digits.begin();
			digits.insert(a,1, 1);
		}
		return digits;
	}
};
class Solution81_1 {
public:
	vector<int> plusOne(vector<int>& digits) {
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			if (digits[i] == 9)
			{
				digits[i] = 0;
			}
			else
			{
				digits[i]++;
				return digits;
			}
		}
		digits[0] = 1;
		digits.push_back(0);
		return digits;
	}
};
#if 0
void main()
{
	Solution81_1 s;
	vector<int>a= {9, 9, 9, 9};
	vector<int>b = s.plusOne(a);
	for (int i = 0; i < b.size();i++)
	{
		cout << b[i];
	}
	cout << endl;
	system("pause");
}
#else
#endif