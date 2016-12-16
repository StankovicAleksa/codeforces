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
struct tr{
	int a;
	int x;
} trs[102];
bool operator < (tr t1, tr t2){
	return t1.x<t2.x;
}
int main(){
	scanf("%d",&n);
	int a,x;
	FOR(i,n)
		scanf("%d %d",&trs[i].x,&trs[i].a);
	sort(trs,trs+n);
	int poc=n;
	FOR(i,n){
		if (trs[i].x>0 ){
			poc=i;
			break;
		}
	}
	int res=0;
	int l=poc-1;
	int r=poc;
	while (true){
		if ( l==-1 ){
			if ( r!=n )
				res+=trs[r].a;
			break;
		}	else if( r==n){
			if ( l!=-1 )
				res+=trs[l].a;
			break;
		}
		else{
			res+=trs[l--].a;
			res+=trs[r++].a;
		}
	}
	printf("%d\n",res);
	return 0;
}
