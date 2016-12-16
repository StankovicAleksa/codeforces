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


const int maxE=300000;
const int maxN=123476;

struct edge{
	int poc,kraj;
}
bool operator < (edge e1,edge e2){
	return e1.poc<e2.poc;
}


edge edges[maxE];
int poc[maxN+1];

bool visited[maxN];

bool important[maxN];
int importants;
int n,m;
int minPot=9999999;
int dp[maxN];
int dp2[maxN];
int ispod[maxN];
int optRes;
int optNode;
void dfs(int t){
	if ( visited[t]) return;

	visited[t]=true;
	for( i=poc[t];i<poc[t+1];i++){
		
	}	
}
int main(){
	scanf("%d %d",&n,&m);
	int a,b;
	FOR(i,n-1){
		scanf("%d %d",&a,&b);
		a--;b--;
		edges[2*i].poc=a,edges[2*i].kraj=b;
		edges[2*i+1].poc=b,edges[2*i+1].kraj=a;
	}
	sort(edges,2*n-2);
	int p=0;
	FOR(i,n){
		poc[i]=p;
		while ( p < 2*n-2  && edges[p].poc==i ) p++;
	}
	poc[n]=p;

	FOR(i,m){
		scanf("%d",&a);
		a--;
		important[a]=true;
		importants++;
	}
	dfs(0);
	printf("%d\n",minPot);	
	return 0;
}
