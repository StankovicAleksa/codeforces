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

#define MAX_N 200000
#define MAX_INT 1999999999 
int n;
int pos[MAX_N];
int poc, kraj;
int main(){
	scanf("%d",&n);
	FOR(i,n)
		scanf("%d",pos+i);
	sort(pos,pos+n);
	int sol=MAX_INT;	
	int	v=(n-1)/2; // moves of Vova
	for ( int i=0;i<=v;i++){
		if ( pos[n-1-(v-i)]-pos[i]<sol){
			sol=pos[n-1-(v-i)]-pos[i];
		}
	}
	printf("%d\n",sol);
	return 0;
}
