void recur(int row, vector<int> pos, int n, vector<vector<string>> &ans)
{
    int i, j;
    if (row == n)
    {
        vector<string> valid;
        for (i = 0; i < n; i++){
            string r = "";
            for (j = 0; j < n; j++){
                if (j == pos[i])
                    r += 'Q';
                else
                    r += '.';
            }
            valid.push_back(r);
        }
        ans.push_back(valid);

        return;
    }
    for (int c = 0; c < n; c++)
    {
        bool flag = true;
        //can place
        for (j = 0; j < pos.size(); j++)
            if (abs(row - j) == abs(pos[j] - c) || c == pos[j])
                flag = false; //can not be placed

        if (!flag)
            continue;
        pos.push_back(c);
        recur(row + 1, pos, n, ans);
        pos.pop_back();
        //pos[row] = -1;
    }
}
vector<vector<string> > Solution::solveNQueens(int A)
{
    vector<int> pos;
    vector<vector<string> >ans;
    recur(0, pos, A, ans);
    return ans;
}