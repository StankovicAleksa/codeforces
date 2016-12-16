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
#define real double
int n,k;
struct pt{
	real x,y;
	pt(real _x=0, real _y=0){
		x=_x;
		y=_y;
	}
};
real eps=1e-6;
bool operator < ( pt p1, pt p2 ){ // implementing also same points, for set
	if ( fabs(p1.x-p2.x) < eps ) return false;
	return p1.x<p2.x;
}
real area(pt p1, pt p2){
	return (p2.x-p1.x)*(p1.y+p2.y)/2;
}
pt operator + ( pt p1, pt p2){ return pt(p1.x+p2.x,p1.y+p2.y);}
pt operator - ( pt p1, pt p2){ return pt(p1.x-p2.x,p1.y-p2.y);}
pt operator * ( pt p1, real r){ return pt(p1.x*r,p1.y*r);}
pt operator * ( real r, pt p1){ return pt(p1.x*r,p1.y*r);}
bool debug=false;
void print(pt p){
	if (debug)
	printf("x: %.2lf, y: %.2lf ;  ",p.x,p.y);
}
real fabs(real t) { return t<0?-t:t;}
std::set<pt> tck;
std::set<pt> tck_temp;

int main(){
	scanf("%d %d",&n,&k);
	FOR(i,k+1)
	tck.insert(pt(i,0));
	for ( int c=0;c<n;c++){
		real tres=0;
		set<pt>::iterator it=tck.begin(),it2;
		it2=it;it2++;
		pt lo=*it,ro=*it2;
		pt lb,rb;
		scanf("%lf",&lb.y);
		lb.x=0;
		FORI(j,k){
			scanf("%lf",&rb.y);
			rb.x=j;
			while ( lo.x+eps<rb.x){
				// find current points
				pt lbtemp,rbtemp;
				lbtemp=lb+(lo.x-lb.x)*(rb-lb);
				rbtemp=lb+(ro.x-lb.x)*(rb-lb);
				// process all the cases
				if ( lbtemp.y <= lo.y && rbtemp.y<= ro.y ){  // polygon part is wholy below
					tck_temp.insert(lo);
					tck_temp.insert(ro);
				} else if ( lbtemp.y>= lo.y && rbtemp.y <= ro.y ) {  // left part is visible, right not
					double t= (lbtemp.y-lo.y) / (ro.y-lo.y-(rbtemp.y-lbtemp.y));
					pt inter=t*(ro-lo)+lo;
					
					tres+=area(lbtemp,inter)-area(lo,inter);

					tck_temp.insert(lbtemp);
					tck_temp.insert(inter);
					tck_temp.insert(ro);
				} else if ( lbtemp.y< lo.y && rbtemp.y > ro.y ) { // right part is visible
					double t= (lbtemp.y-lo.y) / (ro.y-lo.y-(rbtemp.y-lbtemp.y));
					pt inter=t*(ro-lo)+lo;
					tres+=area(inter,rbtemp)-area(inter,ro);
					tck_temp.insert(lo);
					tck_temp.insert(inter);
					tck_temp.insert(rbtemp);
			} else {
					tres+=area(lbtemp,rbtemp)-area(lo,ro);
					tck_temp.insert(lbtemp);
					tck_temp.insert(rbtemp);
				}

				it2++;
				it++;
				if (it2==tck.end() )
					break;	
				lo=*it;
				ro=*it2;
			}
			lb=rb;
		}
		printf("%lf\n",tres);
		tck=tck_temp;
		tck_temp.clear();
	}
	return 0;
}
