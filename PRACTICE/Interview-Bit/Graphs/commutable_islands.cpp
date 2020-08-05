//Approach - 1
int myCompare(vector<int> v1, vector<int> v2) {
  return v1[2] < v2[2];
}
class disjSet { 
    public:
    int rank;
    int parent;
};  
disjSet* makeSet(int n){
    disjSet* DJ = new disjSet[n];
    for(int i=0;i<n;i++){
        DJ[i].rank = 0;
        DJ[i].parent = i;
    }
    return DJ;
}
int find(disjSet* DJ,int x){
    if(DJ[x].parent!=x){
        DJ[x].parent = find(DJ,DJ[x].parent);
    }
    return DJ[x].parent;
}
void Union(disjSet* DJ,int x,int y){
    int xParent = find(DJ,x);
    int yParent = find(DJ,y);
    if(DJ[xParent].rank > DJ[yParent].rank){
        DJ[yParent].parent = DJ[xParent].parent;
    }
    if(DJ[xParent].rank < DJ[yParent].rank){
        DJ[xParent].parent = DJ[yParent].parent;
    }else {
        DJ[yParent].parent = DJ[xParent].parent;
        DJ[xParent].rank ++;
    }
}
int Solution::solve(int n, vector<vector<int> > &edges) {
    sort(edges.begin(), edges.end(), myCompare);
    disjSet* DJ = makeSet(n + 1);
    int count = 0;
    int i = 0;
    int cost = 0;
    while(count!=n-1){
        int x = edges[i][0];
        int y = edges[i][1];
        int xParent = find(DJ,x);
        int yParent = find(DJ,y);
        if(xParent!=yParent){
            cost += edges[i][2];
            Union(DJ,x,y);
            count++;
        }
        i++;
    }
    return cost;
}

//Approach 2 - Diff implementation of union find
struct DisjointSet {
    DisjointSet* parent;
    DisjointSet() {
        parent = this;
    }
};
DisjointSet* getParent(DisjointSet* A) {
    while (A->parent != A) {
        A->parent = getParent(A->parent);
        A = A->parent;
    }
    return A;
}
void merge(DisjointSet* A, DisjointSet* B) {
    while (getParent(A) != A) {
        A = A->parent;
    }
    while (getParent(B) != B) {
        B = B->parent;
    }
    A->parent = B;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(), B.end(), myCompare);
    int cost = 0;
    map<int, DisjointSet*> m;
    for (int i = 1; i <= A; i++) m[i] = new DisjointSet();
    for (int i = 0; i < B.size(); i++) {
        if (getParent(m[B[i][0]]) != getParent(m[B[i][1]])) {
            merge(m[B[i][0]], m[B[i][1]]);
            cost += B[i][2];
        }
    }
    return cost;
}