#include <iostream>
#include <math.h>
#include <set>
using namespace std;
class Solution63 {
public:
	bool isHappy(int n) {
		set<int>a;
		int flag = 1;
		while (n!=1)
		{
			int sum = 0;
			while (n > 0)
			{
				sum = sum + pow(n % 10, 2);
				n = n / 10;
			}
			if (a.count(sum))
			{
				flag = 0;
				break;
			}
			else
				a.insert(sum);
			n = sum;
		}
		if (flag == 1)
			return true;
		else
			return false;
	}
};
class Solution63_1 {
public:
	bool isHappy(int n) {
		/*������Ϊ����ǰ1��2��3��4��5��6���У�
		1�ǿ�������2,3,4,5,6����ص�2��״̬��Ҳ���Ƿǿ�������
		���Խ�ѭ��һֱ�����������sumΪС�ڵ���6������Ȼ���жϴ�ʱ�����Ƿ����1�Ϳ����ˡ�
		*/
		while (n>6)
		{
			int sum = 0;
			while (n>0)
			{
				sum = sum + pow(n % 10, 2);
				n = n / 10;
			}
			n = sum;
		}
		return n == 1;
	}
};
#if 0
void main()
{
	Solution63_1 s;
	cout << s.isHappy(8) << endl;
	system("pause");
}
#else
#endif