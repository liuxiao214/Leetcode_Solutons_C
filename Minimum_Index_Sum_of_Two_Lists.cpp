#include <iostream>
#include <vector>
#include <vector>
using namespace std;
class Solution35 {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
	{
		vector<string>s;
		vector<int>a;
		int item = 2002;
		for (int i = 0; i < list1.size();i++)
		{
			for (int j = 0; j < list2.size();j++)
			{
				if (list1[i]==list2[j])
				{
					a.push_back(i);
					a.push_back(j);
					if ((i+j)<item)
					{
						item = i + j;
					}
					break;
				}
			}
		}
		for (int i = 0; i < a.size()-1;i=i+2)
		{
			if (item==(a[i]+a[i+1]))
			{
				s.push_back(list1[a[i]]);
			}
		}
		return s;
	}
};
#if 0
void main()
{
	Solution35 s;
	vector<string>s1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
	vector<string>s2 = { "KFC", "Burger King", "Tapioca Express", "Shogun" };
	vector<string>s3 = s.findRestaurant(s1, s2);
	for (int i = 0; i < s3.size();i++)
	{
		cout << s3[i].c_str() << endl;;
	}
	system("pause");
}
#else
#endif