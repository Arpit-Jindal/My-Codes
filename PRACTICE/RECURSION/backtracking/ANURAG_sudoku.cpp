bool unsassigned(vector <vector<char> > & a, int& row, int& col)
{
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (a[row][col] == '.') 
                return true;

    return false;
}

bool is_safe(vector<vector<char> > & a, int row, int col, char num)
{
    for (int i = 0; i < 9; i++)
        if (a[i][col] == num)
            return false;

    for (int i = 0; i < 9; i++)
        if (a[row][i] == num)
            return false;

    int rs = row - (row % 3);
    int cs = col - (col % 3);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (a[rs + i][cs + j] == num)
                return false;

    return true;
}

bool SUDOKU(vector<vector<char> > &a)
{
    int row = 0, col = 0;
    if (!unsassigned(a, row, col))
        return true;

    for (char num = '1'; num <= '9'; num++)
    {
        if (is_safe(a, row, col, num))
        {
            a[row][col] = num;
            if (SUDOKU(a))
                return true;
            a[row][col] = '.';
        }
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &a) {
    if (SUDOKU(a))
        cout << ""; //if not solvable
}