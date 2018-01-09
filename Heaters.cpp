#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution121 {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int maxidx = 0;
		int s = 0;	
		for (int i = 0; i < houses.size();i++)
		{
			int temp = abs(heaters[s]-houses[i]);
			for (int j = s+1; j < heaters.size();j++)
			{
				if (houses[i] == heaters[j])
				{
					temp = 0;
					break;
				}
				else if (houses[i] < heaters[j])
				{
					if (heaters[j] - houses[i]< temp)
						temp = heaters[j] - houses[i];
					break;
				}
				else
				{
					if (houses[i] - heaters[j]<temp)
						temp = houses[i] - heaters[j];
					s = j;
				}
			}
			if (temp > maxidx)
				maxidx = temp;
		}
		return maxidx;
	}
};
class Solution121_1 {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int maxidx = 0;
		int index = 0;
		for (int i = 0; i < houses.size();i++)
		{
			while (index + 1 < heaters.size() && (abs(heaters[index + 1] - houses[i]) <= abs(heaters[index] - houses[i])))
				index++;
			int temp = abs(heaters[index] - houses[i]);
			maxidx = maxidx < temp ? temp : maxidx;
		}
		return maxidx;
	}
};
#if 0
void main()
{
	Solution121_1 s;
	vector<int>houses = {1,2,3,4};
	vector<int>heaters = {1,4};
	cout << s.findRadius(houses, heaters) << endl;
	system("pause");
}
#else
#endif