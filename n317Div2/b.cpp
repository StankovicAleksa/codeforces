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
int n,s;
struct asset{
	int v;
	int p;
	char type;
	asset(){}
	asset(int _v,int _p,int _type){
		v=_v;
		p=_p;
		type=_type;
	}
} niz[1003];

bool operator < (asset a1,asset a2){
	if ( a1.type == a2.type){
		if ( a1.p==a2.p)
			return a1.v>a2.v;
		return (a1.p>a2.p);
	}
	else return a1.type < a2.type;
}
int max(int a, int b) { if ( a> b) return a; return b;}
int min(int a, int b) { if ( a< b) return a; return b;}
int main(){
	scanf("%d %d\n",&n,&s);
	FOR(i,n)
		scanf("%c %d %d\n",&niz[i].type,&niz[i].p,&niz[i].v);
	sort(niz,niz+n);
	//merging step
	int p,k;
	p=0;k=0;
	while ( true){
		niz[p]=niz[k];
		while ( ++k<n &&  niz[k].p==niz[p].p && niz[p].type==niz[k].type )
			niz[p].v+=niz[k].v;
		p++;
		if ( k >= n )
			break;
	}
	int sz=p;
	int first=true;
	int stmp=s;
	for (int i=max(sz-s,0);i<sz;i++){
		if (niz[i].type=='B') 
			continue;
		stmp--;
		if (!first)
			printf("\n");
		first=false;
		printf("%c %d %d",niz[i].type,niz[i].p,niz[i].v);
		if ( stmp==0 )
			break;
	}
	stmp=s;	
	FOR(i,sz){
		if ( niz[i].type=='S')
			break;
		if (!first)
			printf("\n");
		first=false;
		printf("%c %d %d",niz[i].type,niz[i].p,niz[i].v);
		stmp--;
		if ( stmp==0)
			break;
	}
	return 0;
}
