int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};
//one way of writing dfs
void dfs1(vector<string> &A, vector<vector<bool>> &visited, int n, int m, int i, int j) {
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int newi = i + X[k];
        int newj = j + Y[k];
        if (newi >= 0 && newj >= 0 && newi < n && newj < m
                && A[newi][newj] == 'X' && !visited[newi][newj]) {
            dfs1(A, visited, n, m, newi, newj);
        }
    }
}
//another way of writing dfs
void dfs2(vector<string> &A, vector<vector<bool>> &visited, int n, int m, int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m ) return;
    if (visited[i][j]) return;
    if (A[i][j] != 'X') return;
    visited[i][j] = true;
    for (int k = 0; k < 4; k++)
        dfs2(A, visited, n, m, i + X[k], j + Y[k]);
}
int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<bool>> visited (n, vector<bool>(m, 0));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'X' && !visited[i][j]) {
                count++;
                dfs2(A, visited, n, m, i, j);
            }
        }
    }
    return count;
}