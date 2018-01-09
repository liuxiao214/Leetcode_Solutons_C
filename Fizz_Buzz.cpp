#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution4 {
public:
	vector<string> fizzBuzz(int n) {
		vector<string>num;
		for (int i = 1; i <= n; i++)
		{
			if ((i % 3 != 0) && (i % 5 != 0))
			{
				string temp;
				int j = i;
				while (j > 0)
				{
					temp.insert(0,1,(j % 10) + '0');
					j = j / 10;
				}
				num.push_back(temp);
			}
			else if((i % 3 == 0) && (i % 5 != 0))
			{
				string temp = "Fizz";
				num.push_back(temp);
			}
			else if((i % 3 != 0) && (i % 5 == 0))
			{
				string temp = "Buzz";
				num.push_back(temp);
			}
			else
			{
				string temp = "FizzBuzz";
				num.push_back(temp);
			}
		}
		return num;
	}
};
#if 0
void main()
{
	Solution4 s;
	vector<string>a = s.fizzBuzz(15);
	for (int i = 0; i < a.size();i++)
	{
		cout << a[i] << endl;
	}
	system("pause");
}
#else
#endif