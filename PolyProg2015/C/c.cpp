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

int n;
int sum [1000003];
int dp;
int last[1000003];
int br;
int mod= 1000000007;
int main(){
	scanf("%d",&n);
	sum[0]=1;
	for ( int i=1;i<=n;i++){
		scanf("%d",&br);
		dp=sum[i-1];
		if ( last[br]!=0 )
			dp-=sum[last[br]-1];
		
		// fast rescalling	
		while ( dp<0 ) dp+=mod;
		
		
		sum[i]=sum[i-1]+dp;

		while (sum[i]>mod) sum[i]-=mod;

		last[br]=i;
	}
	while ( dp < 0 ) dp+=mod;
	printf("%d\n",dp);		
	return 0;
}
