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


int niz[100];
int n;
int b;
multiset<int> s;
int main(){
	int res=0;
	scanf("%d",&n);
	FOR(i,n)
		scanf("%d",niz+i);
	for ( int i=1;i<n;i++)
		s.insert(-niz[i]);
	while (true){
		int b=*s.begin();
		b=-b;
		s.erase(s.begin());
		if ( b>=niz[0] ){
		 niz[0]++	;
		 res++;
		}
		else 
			break;
		b--;
		s.insert(-b);
	}
	printf("%d\n",res);
	return 0;
}
