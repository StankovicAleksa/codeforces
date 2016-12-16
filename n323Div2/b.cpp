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
int niz[1001];
int n;
int main(){
	int res=0;
	scanf("%d",&n);
	FOR(i,n)
		scanf("%d",niz+i);
	
	int ind=0;int p=1;
	int col=0;
	while (true){
		if ( col>=niz[ind] ){
			col++;
			niz[ind]=9999999;
		}
		if ( col==n )
			break;
		if (ind==0 && p==-1 )
		{	p=1;res++;}
		if ( ind==n-1 && p==1)
		{p=-1;res++;}
		ind+=p;
	}
	printf("%d\n",res);
	return 0;
}
