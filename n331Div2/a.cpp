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
int px[4];
int py[4];
int main(){
	int area=-1;
	scanf("%d",&n);
	for ( int i=0;i<n;i++){
		scanf("%d %d",px+i,py+i);
	}	
	for ( int i=0;i<n;i++)
		for ( int j=0;j<i;j++){
			if ( px[i]!=px[j] && py[i]!=py[j] ){
				area=abs((px[i]-px[j])*(py[i]-py[j]));
			}
		}
	printf("%d\n",area);
	return 0;
}
