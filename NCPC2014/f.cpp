#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long

#define MAX_N 705
#define MAX_N2 MAX_N * MAX_N
#define MAX_M 4005
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define REPD(i,a,b) for ( int i=(a);i>=(b);--i)
int n,m;
int l;
struct edge{
	int p,k;
};

bool operator < ( edge e1, edge e2){
	return e1.p<e2.p;
}

edge edges[MAX_M*2+MAX_N];
double loc[MAX_N][2];
int poc[MAX_N+1];
struct pair_node{
	int a,b;
	double dist;
};
bool operator<(pair_node p1, pair_node p2){
	return p1.dist>p2.dist;
}
pair_node pairs[MAX_N2];
int psz;
double dists[MAX_N2];
int parent[MAX_N2];
int root[MAX_N2];
bool processed[MAX_N2];
int find_root(int t){
	if ( root[t]==t) return t;
	return root[t]=find_root(root[t]);
}
void set_root(int t, int g_root){
	int tmp=find_root(t);
	if ( tmp == g_root) return;
	root[tmp]=g_root;
	parent[tmp]=g_root;
}

#define N 500007
#define LOGN 20
int pos[N], anc[LOGN+1][N]; // temp
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
int main() {
	scanf("%d",&n);
	for ( int i=0;i<n;i++)
		scanf("%lf %lf",loc[i],loc[i]+1);
	scanf("%d",&m);
	int a,b;
	for ( int i=0;i<m;i++){
		scanf("%d %d",&a,&b); a--;b--;
		edges[2*i].p=a;edges[2*i].k=b;
		edges[2*i+1].p=b;edges[2*i+1].k=a;
	}
	//for ( int i=0;i<n;i++){
	//	edges[2*m+i].p=i;
	//	edges[2*m+i].k=i;
	//}
	//sort(edges,edges+2*m+n);
	sort(edges,edges+2*m);
	int p=0;
	for ( int i=0;i<n;i++){
		poc[i]=p;
		while ( p<2*m && edges[p].p == i ) p++;
	}
	poc[n]=p;
	for ( int i=0;i<n;i++){
		for ( int j=0;j<n;j++){
			if ( i==j ) continue;
			pairs[psz].a=i;
			pairs[psz].b=j;
			pairs[psz].dist=sqrt((loc[i][0]-loc[j][0])*(loc[i][0]-loc[j][0])+(loc[i][1]-loc[j][1])*(loc[i][1]-loc[j][1]));
			dists[i*n+j+1]=pairs[psz].dist;
			psz++;
		}
	}
	sort(pairs,pairs+psz);

	for ( int i=0;i<MAX_N2;i++){
		parent[i]=-1;
		root[i]=i;
	}

	for (int cnt=0;cnt<psz;cnt++){
		int cur=pairs[cnt].a*n+pairs[cnt].b+1;
		a=pairs[cnt].a;
		b=pairs[cnt].b;
		for ( int i=poc[a];i<poc[a+1];i++){
				int t=edges[i].k*n+b+1;
				if (!processed[t] || (edges[i].k==a )) continue;
				set_root(t,cur);
			}
		for ( int i=poc[b];i<poc[b+1];i++){
				int t=a*n+edges[i].k+1;
				if (!processed[t] || (edges[i].k==b )) continue;
				set_root(t,cur);
			}
		processed[cur]=true;
	}	

	int on=n;
	n*=n;
	init(pairs[psz-1].a*on+pairs[psz-1].b+1);
	scanf("%d",&l);
	for ( int cnt=0;cnt<l;cnt++){
		scanf("%d %d",&a,&b);
		a--;
		b--;
		int t1=a*on+b+1;
		int t2=b*on+a+1;
		int res=lca(t1,t2);
		printf("%lf\n",dists[res]);
	}
	return 0;
}
