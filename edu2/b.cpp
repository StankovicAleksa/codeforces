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

#define SIZE 200001
int a[SIZE],b[SIZE];
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	FOR(i,n)
		scanf("%d",a+i);
	FOR(i,m)
		scanf("%d",b+i);
	sort(a,a+n);
	FOR(i,m){
		int index=upper_bound(a,a+n,b[i])-a;
		printf("%d ",index);
	}
	return 0;
}
