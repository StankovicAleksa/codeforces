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
int n, w;
int niz[200000];
int main(){
	scanf("%d %d",&n,&w);
	FOR(i,2*n){
		scanf("%d",niz+i);
	}
	sort(niz,niz+2*n);
	int s1=niz[0];
	int s2=niz[n];

	double res=w/(3.0*n);
	if ( res>s1 )
		res=s1;
	if ( res*2>s2 )
		res=s2/2.0;
	printf("%lf\n",res*3*n);
	return 0;
}
