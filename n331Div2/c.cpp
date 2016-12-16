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

#define MAX_N 100002
struct pt{
	int x,y;
	int nmbr;
	pt(){nmbr=-1;}
	pt( int _x, int _y){x=_x;y=_y;nmbr=-1;}
};
bool finalSort;
bool operator < ( pt p1, pt p2){
	if ( finalSort ) return p1.nmbr<p2.nmbr;
	if ( p1.x==p2.x) return p1.y<p2.y;
	return p1.x<p2.x;
}
pt pts[MAX_N];
int w[MAX_N];
int usW[2*MAX_N];
int n;
bool solvable=true;;
void input();
void solve();
void output();
int main(){
	input();
	solve();
	output();
	return 0;
}
void input(){
	scanf("%d",&n);
	FOR(i,n)
		scanf("%d %d",&pts[i].x,&pts[i].y);
	int a;
	FOR(i,n)
		scanf("%d",w+i);
	sort(pts,pts+n);
}
void solve(){
	FOR(i,n){
		int x=-w[i];
		int y=0;
		if ( x< 0 ) {
			y-=x;
			x=0;
		}
		x+=usW[w[i]+MAX_N];
		y+=usW[w[i]+MAX_N];	
		int index=lower_bound(pts,pts+n,pt(x,y))-pts;
		if ( index == n ) {
			solvable=false;
			break;
		} else{
			pts[index].nmbr=i;
			usW[w[i]+MAX_N]++;
		}
	}
	 // check correctness of numbering
	for ( int i=0;i<n;i++){
		int x=pts[i].x;
		int y=pts[i].y;
		if ( x> 0 ){
			pt p=*lower_bound(pts,pts+n,pt(x-1,y));
			if ( p.nmbr > pts[i].nmbr ){
				solvable=false;
				break;
			}
		}
		if ( y> 0 ){
			pt p=*lower_bound(pts,pts+n,pt(x,y-1));
			if ( p.nmbr > pts[i].nmbr ){
				solvable=false;
				break;
			}
		}
	}
}
void output(){
	if ( !solvable ){
		printf("NO\n");
		return;
	} else{
		printf("YES\n");
		finalSort=true;
		sort(pts,pts+n);
		FOR(i,n){
			printf("%d %d\n",pts[i].x,pts[i].y);
		}
	}
}
