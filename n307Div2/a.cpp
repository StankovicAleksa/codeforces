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
int niz[2005];
struct student{
	int pos;
	int v;
};
student sts[2005];
bool operator <(student s1, student s2){
	return s1.v>s2.v;
}
int main(){
	scanf("%d",&n);
	FOR(i,n){
		scanf("%d",niz+i);
		sts[i].pos=i;
		sts[i].v=niz[i];
	}
	sort(sts,sts+n);
	int p,k;
	p=0;
	k=0;
	while (p<n){
		for ( k=p;k<n;k++){
			if ( sts[p].v==sts[k].v)
				niz[sts[k].pos]=p+1;
			else 
				break;
		}
		p=k;
	}
	FOR(i,n)
		printf("%d ",niz[i]);
	printf("\n");
	return 0;
}
