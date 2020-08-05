int Solution::solve(string start, string target, vector<string> &C) {
  set<string> S;
  for (int i = 0; i < C.size(); i++) {
    S.insert(C[i]);
  }
  queue<pair<string, int>> q;
  q.push({start, 1});
  while (!q.empty()) {
    pair<string, int> curr_pair = q.front(); q.pop();
    string curr = curr_pair.first;
    for (int pos = 0; pos < start.size(); pos++) {
      char orig_char = curr[pos];
      for (char c = 'a'; c <= 'z'; c++) {
        curr[pos] = c;
        if (curr == target)
          return curr_pair.second + 1;
        if (D.find(curr) != D.end()) {
          q.push({curr, curr_pair.second + 1});
          D.erase(curr);
        }
      }
      curr[pos] = orig_char;
    }
  }
  return 0;
}



//TLE - inefficient
bool isValidTransformation(string a, string b) {
  int count = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) {
      count++;
      if (count > 1) {
        return false;
      }
    }
  }
  return true;
}
int bfs(string src, string dest, map<string, vector<string>> graph) {
  map<string, int> distance;
  for (auto i : graph) {
    distance[i.first] = INT_MAX;
  }
  queue<string> q;
  q.push(src);
  distance[src] = 0;
  while (!q.empty()) {
    string curr = q.front(); q.pop();
    for (auto i : graph[curr]) {
      if (distance[i] == INT_MAX) {
        distance[i] = distance[curr] + 1;
        if (i == dest) {
          return distance[dest] + 1;
        }
        q.push(i);
      }
    }
  }
  return 0;

}
int Solution::solve(string A, string B, vector<string> &C) {
  map<string, vector<string>> graph;
  for (int i = 0; i < C.size(); i++) {
    if (isValidTransformation(A, C[i])) {
      graph[A].push_back(C[i]);
      graph[C[i]].push_back(A);
    }
    if (isValidTransformation(B, C[i])) {
      graph[B].push_back(C[i]);
      graph[C[i]].push_back(B);
    }
    for (int j = i + 1; j < C.size(); j++) {
      if (isValidTransformation(C[i], C[j])) {
        graph[C[j]].push_back(C[i]);
        graph[C[i]].push_back(C[j]);
      }
    }
  }
  return bfs(A, B, graph);
}