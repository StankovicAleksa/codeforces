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

int a,p;
int pmin;
int n;
int res;
int main(){
	scanf("%d",&n);
	pmin=9999999;
	FOR (i,n){
		scanf("%d %d",&a,&p);
		if ( p<pmin) pmin=p;
		res+=a*pmin;
	}
	printf("%d\n",res);
	return 0;
}
