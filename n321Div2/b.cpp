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
int n,d;
struct fr{
	int m,s;

};
bool operator <(fr f1,fr f2){
	return f1.m<f2.m;
}
fr niz[100002];
int main(){
	scanf("%d %d",&n,&d);
	FOR(i,n)
		scanf("%d %d",&niz[i].m,&niz[i].s);
	sort(niz,niz+n);
	long long tmpsum=0;
	int p,k;
	p=0;
	k=0;
	long long res=0;
	while ( k<n ){
		while ( niz[p].m <= niz[k].m-d) 
			tmpsum-=niz[p++].s;
		tmpsum+=niz[k].s;
		if ( tmpsum> res)
			res=tmpsum;
		k++;
	}
	printf("%I64d\n",res);
	return 0;
}
