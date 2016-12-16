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
int n,m;
int matrix[100][100];
int pob[100];
bool van[100];
int main(){
	scanf("%d %d",&n,&m);
	FOR(i,m)
		FOR(j,n)
		scanf("%d",matrix[i]+j);

	// first circle
	FOR(i,m){
		int p=0;
		int mx=-10;
		FOR(j,n){
			if (matrix[i][j]>mx)
				mx=matrix[i][j],p=j;
		}
		pob[p]++;
	}
	int mx=-1;
	int res;
	FOR(i,n)
		if (pob[i]>mx){
			mx=pob[i]; res=i+1;}

	printf("%d\n",res);
	return 0;
}
