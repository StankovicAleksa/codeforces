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


char s[101];
int sum[101][26];
int len;
int n,m;
void initSums();
long long process_interval(long long left, long long right, int cn);
int main(){
	scanf("%s",s);
	len=strlen(s);
	initSums();
	scanf("%d %d",&n,&m);
	FOR(cnt,m){
		long long l,r;
		char c;
		scanf("%lld %lld %c",&l,&r,&c);
		int cn=c-'a';	
		long long res=process_interval(l,r,cn);
	}
	return 0;
}

void initSums(){
	FOR(i,26) 
		FORI(j,len) sum[j][i]=sum[j-1][i]+(s[j]=='a'+i); 
}

long long process_interval(long long left, long long right, int cn){
		
}
