#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (short i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (short i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,short(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<short,short>
#define vi vector<short>
#define ll long long
#define SZ(x) short((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl; 
#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

#define MAX_V 3000
#define MAX_INT 9999



struct edge{ short poc, kraj; };
bool operator < ( edge e1, edge e2){ return e1.poc< e2.poc;}

short min(short a, short b) { if ( a<b) return a; else return b;}

short n;
short poc[MAX_V+1];
edge edges[2*MAX_V-2];
short res[MAX_V+1]; // -1 than real 
void process_input();

void dfs(short node,short parent);
void queries();
int main(){
	process_input();
	dfs(0,-1);
	queries();
	return 0;
}

short dp[MAX_V+1][MAX_V+1];
short below[MAX_V+1];
short vals[MAX_V+1];

void process_input(){
	scanf("%hd",&n);
	FOR(i,n-1){
		short a, b;
		scanf("%hd %hd",&a,&b);
		a--; b--;
		edges[2*i].poc=a; edges[2*i].kraj=b;
		edges[2*i+1].poc=b; edges[2*i+1].kraj=a;
	}
	sort(edges,edges+2*n-2);
	short p=0;
	for ( short i=0;i<n;i++){
		poc[i]=p;
		while ( p< 2*n && edges[p].poc==i ) p++;
	}
	poc[n]=p;
	for ( short i=0;i<=n;i++)
		res[i]=MAX_INT;
	for ( short i=0;i<=n;i++)
	for ( short j=1;j<=n;j++){
		dp[i][j]=MAX_INT;
	}
		
}


void dfs(short node,short parent){
	for ( short i=poc[node];i<poc[node+1];i++){
		register short nxt=edges[i].kraj;
		if ( nxt==parent ) continue;
		else{
			dfs(nxt,node);
			dp[nxt][below[nxt]]=1;

			// trying all combinations, optimizations possible
			for ( short j=below[node];j>=0;j--)
			for ( short k=0;k<=below[nxt];k++){
				dp[node][j+k]=min(dp[nxt][k]+dp[node][j],dp[node][j+k]);
			}
			below[node]+=below[nxt];
		}
	}
	below[node]++;
	for ( short i=0;i<below[node];i++)
		res[below[node]-i]=min(res[below[node]-i],dp[node][i]+(parent!=-1));
}


void queries(){
	short q;
	scanf("%hd",&q);
	short a;
	FOR(i,q){
		scanf("%hd",&a);
		printf("%hd\n",res[a]);
	}
}
