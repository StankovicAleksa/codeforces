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

int p,c;
int n;
int res;
int max(int a, int b){
	if ( a> b) return a;
	return b;
}
int main(){
	scanf("%d",&n);
	int tmpres=0;
	p=-3;
	FOR(i,n){
		scanf("%d",&c);
		if ( c>=p  ){
			tmpres++;
		}
		else{
			res=max(res,tmpres);
			tmpres=1;
		}
		p=c;
	}
	res=max(res,tmpres);
	printf("%d\n",res);
	return 0;
}
