//interviewbit.com/problems/knight-on-chess-board/

//Approach 1 - prefer 2nd one
int Solution::knight(int n, int m, int a, int b, int x, int y) {
  if (a == x && b == y) return 0;
  int X[8] = {2, 2, 1, 1, -1, -1, -2, -2};
  int Y[8] = {1, -1, 2, -2, 2, -2, 1, -1};

  int count = 0;

  map<pair<int, int>, pair<int, int>> parent;
  parent[ {a, b}] = {a, b};

  bool visited [n + 1][m + 1];
  memset(visited, false, sizeof visited);
  visited [a][b] = true;

  queue<pair<int, int>> q;
  q.push({a, b});

  bool stop = false;
  while (!q.empty() && !stop) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    for (int k = 0; k < 8; k++) {
      int newi = i + X[k];
      int newj = j + Y[k];
      if (newi >= 1 && newj >= 1 && newi <= n && newj <= m && !visited[newi][newj]) {
        parent[ {newi, newj}] = {i, j};
        if (newi == x && newj == y) {
          stop = true;
        }
        visited[newi][newj] = true;
        q.push({newi, newj});
      }
    }
  }
  if (!stop) return -1;
  while (parent[ {x, y}] != make_pair(x, y)) {
    count++;
    int tempx = parent[ {x, y}].first;
    int tempy = parent[ {x, y}].second;
    x = tempx;
    y = tempy;
  }
  return count;
}

//Approach 2
struct cell {
  int x, y;
  int dis;
  cell() {}
  cell(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};
int Solution::knight(int n, int m, int a, int b, int p, int r) {
  if (a == p && b == r) return 0;

  int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
  int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

  queue<cell> q;
  q.push(cell(a, b, 0));

  cell t;
  int x, y;

  bool visit[n + 1][m + 1];
  memset(visit, false, sizeof visit);
  visit[a][b] = true;

  while (!q.empty()) {
    t = q.front(); q.pop();
    for (int i = 0; i < 8; i++) {
      x = t.x + dx[i];
      y = t.y + dy[i];
      if (x >= 1 && x <= n && y >= 1 && y <= m && !visit[x][y]) {
        if (x == p && y == r)
          return t.dis + 1;
        visit[x][y] = true;
        q.push(cell(x, y, t.dis + 1));
      }
    }
  }
  return -1;
}