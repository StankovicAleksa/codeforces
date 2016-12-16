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
int a[500005];
int a1[500005];
int pos[500005];
int sz;
int type[500005];
int middle(int pos){
	int sum=a1[pos-1]+a1[pos]+a1[pos+1];
	if ( sum<= 1)
		return 0;
	else 
		return 1;
}
int min(int a, int b){ if ( a< b) return a; return b;}
int main(){
	scanf("%d",&n);
	FOR(i,n)
		scanf("%d",a1+i);
	bool change=false;
	a[0]=a1[0];
	a[n-1]=a1[n-1];
	FORI(i,n-2){
		int m=middle(i);
		if ( m!=a1[i]){
			change=true;
		}
		a[i]=m;
	}
	if ( !change ){
		printf("0\n");
		FOR(i,n)
			printf("%d ",a[i]);
		printf("\n");
	} else{
		int tMoves=0;
		FORI(i,n-1){
			if ( a[i-1]==a[i] ){
				pos[sz]=i;
				type[sz]=a[i];
				sz++;
			}
		}	
		int index=0;
		
		for ( int i=2;i<n-2;i++){
			while( pos[index+1]<= i )
				index++;
			int pc=pos[index];
			int kr=pos[index+1]-1;
			int moves=min(i-pc,kr-i);
			if ( i-pc < kr-i) 
				a[i]=type[index];
			else
				a[i]=type[index+1];
			if ( moves>tMoves)
				tMoves=moves;
		}
		printf("%d\n",tMoves+1);	
		FOR(i,n)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
