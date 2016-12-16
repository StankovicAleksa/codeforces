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


int n,k;
int nk;
long long mod=1000000007;
int a[100000];
int b[100000];
long long res;
void init();
void solve();
void output();
long long pw;
int main(){
	init();
	solve();	
	output();
	return 0;
}

void init(){
	scanf("%d %d",&n,&k);
	nk=n/k;
	FOR(i,nk)
		scanf("%d",a+i);
	FOR(i,nk)
		scanf("%d",b+i);
	pw=1;
	for ( int i=0;i<k-1;i++)
		pw*=10;
}
void solve(){
	int at,bt;
	long long tres;
	FOR(i,nk){
		tres=0;
		at=a[i];
		bt=b[i];
		if ( bt==0 ) {
			tres=0;
		}else{
			tres=(pw*bt-1)/at+1;
		}
		tres+=(pw*10-1)/at-(pw*(bt+1)-1)/at;
		tres%mod;
		if ( i==0)
			res=tres;
		else
		{res*=tres;res%=mod;}
	}	
}
void output(){
	printf("%I64d\n",res);
}
