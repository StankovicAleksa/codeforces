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
int a,b,a1,b1;
int abs(int a){ if ( a <0 ) return -a; return a;}
int main(){
	scanf("%d",&n);
	int res=0;
	FOR(i,n){
		scanf("%d %d %d %d",&a,&b,&a1,&b1);
		res+=(abs(a-a1)+1)*(abs(b-b1)+1);
	}
	printf("%d\n",res);
	return 0;
}
