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
int niz[100000];
int cntSort[1000001];
int first[1000001];
int last[1000001];

int n;
int main(){
	scanf("%d",&n);
	FOR(i,n){
		scanf("%d",niz+i);
		cntSort[niz[i]]++;
		if ( first[niz[i]]==0 ){
			first[niz[i]]=i+1;
		} 
		last[niz[i]]=i+1;
	}
	int mx=0;
	FORI(i,1000000){
		if (cntSort[i]>mx)
			mx=cntSort[i];
	}
	int minRazm=200000;
	int resNode=0;
	FOR(i,n){
		if ( cntSort[niz[i]]==mx && minRazm>last[niz[i]]-first[niz[i]] ){
			resNode=i;
			minRazm=last[niz[i]]-first[niz[i]];
		}
	}
	printf("%d %d\n",first[niz[resNode]],last[niz[resNode]]);
	return 0;
}
