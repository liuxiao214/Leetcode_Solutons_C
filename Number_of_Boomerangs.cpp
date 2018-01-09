#include <iostream>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
class Solution52 {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		if (points.size() == 0 || points.size() == 1 || points.size() == 2)
		{
			return 0;
		}
		int sum = 0;		
		for (int i = 0; i < points.size();i++)
		{
			map<int, int>dist;
			for (int j = 0; j < points.size();j++)
			{
				int x = points[i].first - points[j].first;
				int y = points[i].second - points[j].second;
				dist[x*x + y*y]++;
			}
			for (map<int, int>::iterator k = dist.begin(); k != dist.end(); k++)
			{
				sum = sum + (k->second)*(k->second - 1);
			}
		}
		return sum;
	}
};
#if 0
void main()
{
	Solution52 s;
	vector<pair<int, int>>a = { { 0, 0 }, { 1, 0 }, { 2, 0 } };
	cout << s.numberOfBoomerangs(a)<<endl;
	system("pause");
}
#else
#endif