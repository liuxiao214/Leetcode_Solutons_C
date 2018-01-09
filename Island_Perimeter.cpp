#include <iostream>
#include <vector>
using namespace std;
class Solution7 {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		//cout << grid.size() << endl;
		//cout << grid[0].size() << endl;
		int sum = 0;
		int lenl = grid.size();
		for (int i = 0; i < grid.size(); i++)
		{
			int lens = grid[i].size();
			if (lenl==1 && lens==1)
			{
				if (grid[0][0]==1)
				{
					sum = 4;
					break;
				}
			}
			else if (lenl==1 && lens>1)
			{
				for (int j = 0; j < grid[i].size(); j++)
				{
					if (grid[i][j]==1 && i==0 && j==0)
					{
						sum = sum + 3;
						if (grid[i][j+1] == 0)
						{
							sum = sum + 1;
						}
					}
					else if (grid[i][j] == 1 && i == (lenl-1) && j==(lens-1))
					{
						sum = sum + 3;
						if (grid[i][j - 1] == 0)
						{
							sum = sum + 1;
						}
					}
					else
					{
						if (grid[i][j] == 1)
						{
							sum = sum + 2;
							if (grid[i][j - 1] == 0)
							{
								sum = sum + 1;
							}
							if (grid[i][j + 1] == 0)
							{
								sum = sum + 1;
							}
						}
						
					}
				}
			}
			else if (lens == 1 && lenl>1)
			{
				for (int j = 0; j < grid[i].size(); j++)
				{
					if (grid[i][j] == 1 && i == 0 && j == 0)
					{
						sum = sum + 3;
						if (grid[i+1][j] == 0)
						{
							sum = sum + 1;
						}
					}
					else if (grid[i][j] == 1 && i == (lenl - 1) && j == (lens - 1))
					{
						sum = sum + 3;
						if (grid[i-1][j] == 0)
						{
							sum = sum + 1;
						}
					}
					else
					{
						if (grid[i][j] == 1)
						{
							sum = sum + 2;
							if (grid[i - 1][j] == 0)
							{
								sum = sum + 1;
							}
							if (grid[i + 1][j] == 0)
							{
								sum = sum + 1;
							}
						}
						
					}
				}
			}
			else
			{
				for (int j = 0; j < grid[i].size(); j++)
				{
					if (grid[i][j] == 1 && i == 0 && 0 < j  && j < (lens - 1))
					{
						sum = sum + 1;
						if (grid[i][j - 1] == 0)
						{
							sum = sum + 1;
						}
						if (grid[i][j + 1] == 0)
						{
							sum = sum + 1;
						}
						if (grid[i + 1][j] == 0)
						{
							sum = sum + 1;
						}
					}
					else if (grid[i][j] == 1 && 0 < i && i < (lenl - 1) && j == 0)
					{
						sum = sum + 1;
						if (grid[i - 1][j] == 0)
						{
							sum = sum + 1;
						}
						if (grid[i + 1][j] == 0)
						{
							sum = sum + 1;
						}
						if (grid[i][j + 1] == 0)
						{
							sum = sum + 1;
						}
					}
					else if (grid[i][j] == 1 && (i == (lenl - 1)) && 0 < j && j < (lens - 1))
					{
						sum = sum + 1;
						if (grid[i][j - 1] == 0)
						{
							sum = sum + 1;
						}
						if (grid[i][j + 1] == 0)
						{
							sum = sum + 1;
						}
						if (grid[i - 1][j] == 0)
						{
							sum = sum + 1;
						}
					}
					else if (grid[i][j] == 1 && 0 < i && i < (lenl - 1) && (j == (lens - 1)))
					{
						sum = sum + 1;
						if (grid[i - 1][j] == 0)
						{
							sum = sum + 1;
						}
						if (grid[i + 1][j] == 0)
						{
							sum = sum + 1;
						}
						if (grid[i][j - 1] == 0)
						{
							sum = sum + 1;
						}
					}
					else if (grid[i][j] == 1 && i == 0 && j == 0)
					{
						sum = sum + 2;
						if (grid[i + 1][j] == 0)
						{
							sum = sum + 1;
						}
						if (grid[i][j + 1] == 0)
						{
							sum = sum + 1;
						}
					}
					else if (grid[i][j] == 1 && i == (lenl - 1) && j == (lens - 1))
					{
						sum = sum + 2;
						if (grid[i - 1][j] == 0)
						{
							sum = sum + 1;
						}
						if (grid[i][j - 1] == 0)
						{
							sum = sum + 1;
						}
					}
					else if (grid[i][j] == 1 && i == 0 && j == (lens - 1))
					{
						sum = sum + 2;
						if (grid[i + 1][j] == 0)
						{
							sum = sum + 1;
						}
						if (grid[i][j - 1] == 0)
						{
							sum = sum + 1;
						}
					}
					else if (grid[i][j] == 1 && i == (lenl - 1) && j == 0)
					{
						sum = sum + 2;
						if (grid[i - 1][j] == 0)
						{
							sum = sum + 1;
						}
						if (grid[i][j + 1] == 0)
						{
							sum = sum + 1;
						}
					}
					else
					{
						if (grid[i][j] == 1)
						{
							if (grid[i][j - 1] == 0)
							{
								sum = sum + 1;
							}
							if (grid[i][j + 1] == 0)
							{
								sum = sum + 1;
							}
							if (grid[i - 1][j] == 0)
							{
								sum = sum + 1;
							}
							if (grid[i + 1][j] == 0)
							{
								sum = sum + 1;
							}
						}
					}
				}
			}
			
		}
		return sum;
	}
};
class Solution7_7_7{
public:
	int islandPerimeter(vector<vector<int>>& grid)
	{
		int m = grid.size() * 2 + 1;
		int n = grid[0].size() * 2 + 1;
		vector<vector<int>>board(m, vector<int>(n, 0));
		for (int i = 0; i < grid.size();i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				int ii = 2 * i + 1;
				int jj = 2 * j + 1;
				if (grid[i][j]==1)
				{
					board[ii - 1][j] ^= 1;
					board[ii + 1][j] ^= 1;
					board[ii][jj - 1] ^= 1;
					board[ii][jj + 1] ^= 1;
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				sum = sum + board[i][j];
			}
		}
		return sum;
	}
};
class Solution7_7 {
public:
	int islandPerimeter(vector<vector<int>>& grid)
	{
		int m = grid.size() * 2 + 1;
		int n = grid[0].size() * 2 + 1;
		int sum = 0;
		std::vector<std::vector<int>> line(m, std::vector<int>(n, 0));
		for (auto i = 0; i < grid.size(); ++i)
		{
			for (auto j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j])
				{
					int iL = 2 * i + 1;
					int jL = 2 * j + 1;
					line[iL][jL - 1] ^= 1;
					line[iL][jL + 1] ^= 1;
					line[iL - 1][jL] ^= 1;
					line[iL + 1][jL] ^= 1;
				}
			}
		}
		for (auto i : line)
		{
			for (auto j : i)
			{
				sum += j;
			}
		}
		return sum;
	}
};
#if 0
void main()
{
	Solution7 mygrid;
	Solution7_7 mygrid1;
	Solution7_7_7 mygrid2;
	vector<vector<int>>a = { { 0, 1, 0, 0 }, {1,1,1,0}, {0,1,0,0}, {1,1,0,0} };
	vector<vector<int>>b = { {1} };
	vector<vector<int>>c = { { 1,1,1,1} };
	vector<vector<int>>d = { { 1 }, {0}, {0}, {0} };
	cout<<mygrid.islandPerimeter(a)<<endl;
	cout << mygrid.islandPerimeter(b) << endl;
	cout << mygrid.islandPerimeter(c) << endl;
	cout << mygrid.islandPerimeter(d) << endl;

	cout << mygrid1.islandPerimeter(a) << endl;
	cout << mygrid1.islandPerimeter(b) << endl;
	cout << mygrid1.islandPerimeter(c) << endl;
	cout << mygrid1.islandPerimeter(d) << endl;

	cout << mygrid2.islandPerimeter(a) << endl;
	cout << mygrid2.islandPerimeter(b) << endl;
	cout << mygrid2.islandPerimeter(c) << endl;
	cout << mygrid2.islandPerimeter(d) << endl;
	system("pause");
}
#else
#endif
