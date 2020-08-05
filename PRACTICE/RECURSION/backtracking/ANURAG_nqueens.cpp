bool is_safe(vector <string> board, int n, int row, int col)
{
  for (int j = 0; j < col; j++)
    if (board[row][j] == 'Q')
      return false;

  for (int i = row, j = col; i >= 0 && j >= 0 ; i--, j--)
    if (board[i][j] == 'Q') return false;

  for (int i = row, j = col; i < n && j >= 0 ; i++, j--)
    if (board[i][j] == 'Q') return false;

  return true;
}

void Nqueens(vector<vector<string> >& ans, vector<string> board, int n, int col = 0)
{
  if (col == n)  
    ans.push_back(board);
  for (int row = 0; row < n; row++)
  {
    if (is_safe(board, n, row, col))
    {
      board[row][col] = 'Q';
      Nqueens(ans, board, n, col + 1);
      board[row][col] = '.';
    }
  }

}
vector<vector<string> > Solution::solveNQueens(int n) {
  vector<vector<string> > ans;
  vector<string> board;

  string s = "";
  for (int i = 0; i < n; i++) 
    s += '.';

  for (int i = 0; i < n; i++)
    board.push_back(s);

  Nqueens(ans, board, n);

  return ans;
}
