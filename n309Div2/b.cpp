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
struct st{
	char rec[105];
};
bool operator <(st s1, st s2){
	int i=strcmp(s1.rec,s2.rec);
	if( i<0)
		return true;
	else
		return false;
}
bool equal(st s1,st s2){
	return !(s1 < s2 || s2<s1);
}
st rows[100];
int main(){
	scanf("%d",&n);
	FOR(i,n)
		scanf("%s",rows[i].rec);
	sort(rows,rows+n);
	int p,k;
	p=0;
	k=0;
	int mx=0;
	while ( p<n ){
		k=p;
		int tmpres=0;
		while ( k<n && equal(rows[k],rows[p])){
			tmpres++;
			k++;
		}
		if ( k-p >mx )
			mx=k-p;
		p=k;
	}
	printf("%d\n",mx);
	return 0;
}
