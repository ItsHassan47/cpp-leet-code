#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

void gameOfLife(vector<vector<int>> &board)
{
	if (board.size() == 0)	return;
	vector<vector<int>>neighbours;
	int row = board.size();
	int col = board[0].size();
	int liveNeighbours = 0;
	neighbours.assign(board.begin(), board.end());

	for (int i = 0, k = 0; i < row; ++i, ++k) {
		for (int j = 0; j < col; ++j) {
			if (i - 1 != -1 && j - 1 != -1)
				liveNeighbours += board[i - 1][j - 1] == 1;
			if (i - 1 != -1)
				liveNeighbours += board[i - 1][j] == 1;
			if (i + 1 < row)
				liveNeighbours += board[i + 1][j] == 1;
			if (j - 1 != -1)
				liveNeighbours += board[i][j - 1] == 1;
			if (j + 1 < col)
				liveNeighbours += board[i][j + 1] == 1;
			if (i + 1 < row && j + 1 < col)
				liveNeighbours += board[i + 1][j + 1] == 1;
			if (i - 1 != -1 && j + 1 < col)
				liveNeighbours += board[i - 1][j + 1] == 1;
			if (i + 1 < row && j - 1 != -1)
				liveNeighbours += board[i + 1][j - 1] == 1;
			if (liveNeighbours == 3 && board[i][j] == 0)
				neighbours[i][j] = 1;
			if (liveNeighbours < 2 || liveNeighbours > 3)
				neighbours[i][j] = 0;

			liveNeighbours = 0;
		}
	}
	board.assign(neighbours.begin(), neighbours.end());
}

int main()
{
	vector<vector<int>> board
	{
		{1,0,0,0,0,0,0,0,0},
		{0,1,1,0,0,0,0,0,0},
		{1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
	};
	for (int i = 0; i < 50; ++i) {
		gameOfLife(board);
		Sleep(1000);
		system("CLS");
		for (const auto &row : board) {
			for (const auto &v : row) {
				cout << v << " ";
			}
			cout << endl;
		}
	}

	return 0;
}