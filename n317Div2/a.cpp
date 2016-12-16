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
int na,nb;
int k,m;
int g1,g2;
int tmp;
int main(){
	scanf("%d %d",&na,&nb);
	scanf("%d %d",&k,&m);
	
	FORI(i,na){
		scanf("%d",&tmp);
		if ( i==k )
			g1=tmp;
	}
	FORI(i,nb){
		scanf("%d",&tmp);
		if ( i== nb-m+1)
			g2=tmp;
	}
	if ( g1<g2)
		printf("YES\n");
	else 
		printf("NO\n");
	
	return 0;
}
