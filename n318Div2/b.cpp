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
int matrix[4001][4001];
int loc[4001][4001];
int sz[4001];
int sums[4001];
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	for ( int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		matrix[a][b]=matrix[b][a]=1;
		loc[a][sz[a]++]=b;
		loc[b][sz[b]++]=a;
	}
	FOR(i,n)
		FOR(j,n)
		 sums[i]+=matrix[i][j];
	int m=40000;
	FOR(i,n)
		FOR(j,n){
			if (matrix[i][j]==0)
				continue;
			FOR(k,sz[i])
			{
				if (matrix[j][loc[i][k]]==1 ){
					int tmpres=sums[i]+sums[j]+sums[loc[i][k]];
					if ( tmpres < m) 
						m=tmpres;
				}
			}		
		}
	if ( m==40000 )
		printf("-1\n");
	else
		printf("%d\n",m-6);
	return 0;
}
