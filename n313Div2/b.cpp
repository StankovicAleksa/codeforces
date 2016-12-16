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
int a[2];
int dim[2][2];
int max(int a, int b){if ( a>b) return a; return b;}
int m;
int main(){
	scanf("%d %d",a,a+1);
	FOR(i,2)
		scanf("%d %d",dim[i],dim[i]+1);
	FOR(i,2)
		FOR(j,2)
			FOR(k,2){
				int	m=max(dim[0][i],dim[1][j]);
				int s=dim[0][(i+1)%2]+dim[1][(j+1)%2];
				if ( m<=a[k] && s <=a[(k+1)%2] )
				{
					printf("YES\n");
					return 0;
				}
		}
	printf("NO\n");
	return 0;
}
