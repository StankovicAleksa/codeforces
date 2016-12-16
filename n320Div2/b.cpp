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
bool used[1000];
struct par{
	int a,b;
	int val;
};
bool operator < (par p1, par p2){
	if (p1.val==p2.val){
		if (p1.a==p2.a)
			return p1.b<p2.b;
		return p1.a<p2.a;
	}
	return p1.val>p2.val;
}
int res[1000];
set <par> s;
int main(){
	scanf("%d",&n);
	FORI(i,2*n-1)
		FORI(j,i){
			par p;
			scanf("%d",&p.val);
			p.a=i+1;
			p.b=j;
			s.insert(p);
		}
	while(!s.empty()){
		par p=*s.begin();
		s.erase(s.begin());
		if ( !used[p.a] && !used[p.b] ){
			res[p.a]=p.b;
			res[p.b]=p.a;
			used[p.a]=used[p.b]=true;
		}
	}
	FORI(i,2*n)
		printf("%d ",res[i]);
	printf("\n");
	return 0;
}
