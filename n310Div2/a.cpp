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
int n0;
int n1;
int n;
int abs(int a){ if ( a< 0 ) return -a; return a;}
char rec[200005];
int main(){
	scanf("%d",&n);
	scanf("%s",rec);
	for (char *c=rec;*c!=0;c++){
		if (*c=='0')
			n0++;
		else
			n1++;
	}
	printf("%d\n",abs(n0-n1));
	return 0;
}
