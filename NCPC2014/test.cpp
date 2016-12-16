#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl; 
#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second
// before calling set: N, LOGN, n, parent (vertices numbered 1..n)
// parent - array: parent[i] is the parent of i (parent[root] is irrelevant)
// works for a tree. if you have a forest, make it into a tree by adding a superroot
#define N 4
#define LOGN 17
int n, parent[N], // input
		pos[N], anc[LOGN+1][N]; // temp
int getPos (int u) {
	if (pos[u] == -1) pos[u] = getPos(parent[u])+1;
	return pos[u];
}
void init (int root) {
	FORI(i,n) anc[0][i] = parent[i];
	FORI(i,n) pos[i] = -1;
	pos[root] = 0;
	FORI(i,n) if (pos[i] == -1) getPos(i);
	FORI(i,LOGN) FORI(j,n) anc[i][j] = anc[i-1][anc[i-1][j]];
}
int lca (int u, int v) {
	if (pos[u] < pos[v]) swap(u,v);
	int diff = pos[u] - pos[v];
	REPD(k,LOGN,0) if ((1<<k) <= diff) {
		diff -= 1<<k;
		u = anc[k][u];
	}
	// now they are equidistant from root
	if (u==v) return u;
	REPD(k,LOGN,0) if (anc[k][u] != anc[k][v]) {
		u = anc[k][u];
		v = anc[k][v];
	}
	return parent[u];
}
int main(){
	n=3;
	parent[2]=1;
	parent[3]=2;
	init(1);
	printf("%d",lca(2,3));	
	return 0;
}
