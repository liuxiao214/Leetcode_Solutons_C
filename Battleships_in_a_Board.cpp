#include <iostream>
#include <vector>

using namespace std;

class Solution139 {
public:
	void ifvisited(vector<vector<char>>& board,vector<vector<int>>& visited, int i, int j)
	{
		int p = i;
		visited[i][j] = 1;
		while (p+1<board.size())
		{
			p++;
			if (board[p][j] == 'X')
				visited[p][j] = 1;
			else                
				break;
		}
		while (j + 1 < board[0].size())
		{
			j++;
			if (board[i][j] == 'X')
				visited[i][j] = 1;
			else
				break;
		}
	}
	int countBattleships(vector<vector<char>>& board) {
		vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
		int count = 0;
		for (int i = 0; i < board.size();i++)
		{
			for (int j = 0; j < board[i].size();j++)
			{
				if (board[i][j] == 'X' && visited[i][j] == 0)
				{
					count++;
					ifvisited(board, visited, i, j);
				}
			}
		}
		return count;
	}
};
class Solution139_1 {
public:
	int countBattleships(vector<vector<char>>& board) {
		int count = 0;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (board[i][j] == 'X')
				{
					if (i == 0 && j == 0)
						count++;
					else if (i == 0 && board[i][j - 1] == '.')
						count++;
					else if (j == 0 && board[i - 1][j] == '.')
						count++;
					else if (j!=0 && i!=0 && board[i-1][j]=='.' && board[i][j-1]=='.')
						count++;
					else continue;
				}
			}
		}
		return count;
	}
};
class Solution139_2 {
public:
	int countBattleships(vector<vector<char>>& board) {
		int count = 0;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (board[i][j] == 'X' &&  (i==0 || board[i-1][j]=='.') && (j==0 || board[i][j-1]=='.') )
					count++;
			}
		}
		return count;
	}
};
#if 0
void main()
{
	Solution139_2 s;
	//vector<vector<char>> board = { { 'X', '.', '.', 'X' }, { '.', '.', '.', 'X' }, { '.', '.', '.', 'X' } };
	vector<vector<char>> board = { { 'X',  'X', 'X' }};
	cout<<s.countBattleships(board)<<endl;
	system("pause");
}
#else
#endif
