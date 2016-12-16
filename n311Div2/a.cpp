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
int l[3],h[3];
int min(int a,int b){ if ( a<b) return a;  return b;}
int max(int a,int b){ if ( a>b) return a;  return b;}
int main(){
	scanf("%d",&n);
	FOR(i,3)
		scanf("%d %d",l+i,h+i);
	int g1=n-l[1]-l[2];
	int v1=min(g1,h[0]);
	n-=v1;
	int v2=min(h[1],n-l[2]);
	int v3=n-v2;
	printf("%d %d %d\n",v1,v2,v3);
	return 0;
}
