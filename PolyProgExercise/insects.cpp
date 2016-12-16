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
#define FOREACH(i,t) for (vi::iterator i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second
const int inf=2000000000;


/*const int N=2000;

int nf,cap[N][N];
int flow[N][N];

int edmonds(int s, int t){
	int b,e,q[nf],p[nf],res=0;
	vi adj[nf];
	FOR(i,nf) FOR (j,nf) {flow[i][j]=0; if ( cap[i][j] ) adj[i].pb(j),adj[j].pb(i);}
	while(1){
		FOR(i,nf) p[i]=-1;
		for ( q[b=e=0]=s; b<=e;++b) FOREACH(v,adj[q[b]])
			if ( flow[q[b]][*v] < cap[q[b]][*v] && p[*v] < 0 ) p[q[++e] = *v ] = q[b];
		if ( p[t]<0 ) return res;
		int d=cap[p[t]][t]-flow[p[t]][t];
		for ( int i=t;i!=s;i=p[i]) d=min(d,cap[p[i]][i]-flow[p[i]][i]);
		for ( int i=t; i!=s;i=p[i]) flow[p[i]][i]+=d, flow[i][p[i]] -= d;
		res+=d;
	}
}
*/
const int N = 3000; // INPUT
int nf, cap[N][N];
// INPUT (vertices 0..n-1)
int flow[N][N];
// OUTPUT
int edmonds (int s, int t) {
	int b, e, q[nf], p[nf], res = 0;
	vi adj[nf];
	FOR(i,nf) FOR(j,nf) { flow[i][j] = 0; if (cap[i][j]) adj[i].pb(j), adj[j].pb(i); }
	while (1) {
		FOR(i,nf) p[i] = -1;
		for (q[b=e=0] = s; b <= e; ++b) FOREACH(v,adj[q[b]])
			if (flow[q[b]][*v] < cap[q[b]][*v] && p[*v] < 0) p[q[++e] = *v] = q[b];
		if (p[t] < 0) return res;
		int d = cap[p[t]][t] - flow[p[t]][t];
		for (int i = t; i != s; i = p[i]) d = min(d, cap[p[i]][i] - flow[p[i]][i]);
		for (int i = t; i != s; i = p[i]) flow[p[i]][i] += d, flow[i][p[i]] -= d;
		res += d;
	}
}


int n,p,c[3];
int csz=256;
int nsz=1000;
int main(){
	scanf("%d %d",&n,&p);
	FOR(i,3)
		scanf("%d",c+i);
	nf=N-1;
	int start=N-3,term=N-5;
	int a[3];
	for ( int i=0;i<n;i++){
		FOR(j,3) {
			scanf("%d",a+j);
			cap[i][nsz+j*csz+a[j]]=inf;
		}
	}		
	FOR(j,3)
	FOR(i,csz)
		cap[nsz+j*csz+i][term]=c[j];
	FOR(i,nsz)
		cap[start][i]=p;
	printf("%d\n",n*p-edmonds(start,term));
	return 0;
}
