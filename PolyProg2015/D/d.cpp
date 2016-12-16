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
int matrix[52][52];
bool fr[52][52];
int neigh[52][52];
int vec[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

struct point{
	int y,x;
	point(){}
	point(int _y,int _x){
		y=_y;
		x=_x;
	}
};
bool operator<(point p1, point p2){
	if (matrix[p1.y][p1.x]==matrix[p2.y][p2.x]){
		if ( p1.y==p2.y)
			return p1.x<p2.x;
		return p1.y<p2.y;
	}
	return matrix[p1.y][p1.x]-matrix[p2.y][p2.x];
}
void delNode(int y, int x);
int res=0;
set <point> ps;
int main(){
	scanf("%d %d",&n,&m);
	FORI(i,n)
		FORI(j,m){
		scanf("%d",&matrix[i][j]);
		res+=matrix[i][j];
		}

	// make free matrix
	FORI(i,n)
		FORI(j,m)	{
			if (matrix[i][j]==1)
				continue;
			fr[i][j]=true;
			FOR(k,4){
				if ( matrix[i+vec[k][0]][j+vec[k][1]]==1 )
					fr[i][j]=false;
			}
		}


	//calculate solution
	FORI(i,n)
		FORI(j,m)	{
			if (!fr[i][j]) 
				continue;
			FOR(k,4){
				if ( fr[i+vec[k][0]][j+vec[k][1]]==true )
					neigh[i][j]++;
			}

			ps.insert(point(i,j));	
		}
	while (!ps.empty()){
		point p=*ps.begin();	
		ps.erase(ps.begin());
		int i=p.y;
		int j=p.x;
		if (!fr[i][j])  // unnecessary
			continue;
		fr[i][j]=false;
		FOR(k,4){
			delNode(i+vec[k][0],j+vec[k][1]);
		}
		res++;
	}
	printf("%d\n",res);
	return 0;
}

void delNode(int y, int x){
	fr[y][x]=false;
	set <point>::iterator it=ps.find(point(y,x));
	if ( it == ps.end())
		return;
	point pLoc=*it;
	ps.erase(it);
	FOR(k,4) {
		it=ps.find(point(pLoc.y+vec[k][0],pLoc.x+vec[k][1]));
		if (it==ps.end())
			continue;	
		ps.erase(it);
		neigh[pLoc.y+vec[k][0]][pLoc.x+vec[k][1]]--;
		ps.insert(point(pLoc.y+vec[k][0],pLoc.x+vec[k][1]));
	}
}
