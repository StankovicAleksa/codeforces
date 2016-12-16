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
int nums[1005];
int sz;
int vis[1005];
bool used[1005];
int a;

int main(){
	scanf("%d %d",&n,&m);
	nums[sz++]=0;
	
	for ( int i=0;i<n;i++){
		scanf("%d",&a);
		a%=m;
		int szb=sz;
		for ( ;vis[a]<szb;vis[a]++){
			int tmp=a+nums[vis[a]];
			tmp%=m;
			if ( tmp==0)
			{printf("YES\n");return 0;}
			if (used[tmp])
				continue;
			used[tmp]=true;
			nums[sz++]=tmp;
		}
	}
	printf("NO\n");
	return 0;
}
