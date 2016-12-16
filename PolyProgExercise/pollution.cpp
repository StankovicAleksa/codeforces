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

#define MAX_N 105
#define real double

real eps=1e-9;

struct pt {
	real x,y;	
	bool on;
	bool dbl;
	pt(){}
	pt (real xx, real yy){
		x=xx; y=yy;
		on=false;
		dbl=false;
	}
	pt (real xx, real yy,bool on){
		x=xx; y=yy;
		this->on=on;
		dbl=false;
	}
};
pt operator+ (pt a, pt b){
	return pt(a.x+b.x,a.y+b.y);
}
pt operator- (pt a, pt b){
	return pt(a.x-b.x,a.y-b.y);
}
pt operator *(pt a, pt b){
	return pt(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}

pt operator *(pt a, real r){
	return pt(a.x*r,a.y*r);
}
real area(pt p1, pt p2){
	return (p1.x*p2.y-p1.y*p2.x)/2.0;
}
inline bool iszero(real x){
	return (x	<= eps && x>=-eps);
}
real abs(pt a){ return sqrt(a.x*a.x+a.y*a.y); }
real dist(pt p1, pt p2){ return abs(p1-p2); }
real sqabs(pt a){ return a.x*a.x+a.y*a.y; }
real scal(pt a, pt b){return a.x*b.x+a.y*b.y;}
real fabs(real a){ if ( a < 0 ) return -a; return a;}
bool inside(pt a, pt b, pt c){ // returns true if a is inside [b,c]
	return  fabs( dist(a,b)+dist(a,c)-dist(b,c))<eps;
}
pt proj( pt a, pt b, pt c){
	pt d=c-b;
	return b+d*(scal(a-b,d)/sqabs(d));

}

vector<pt> intersect(pt c, real cr, pt a, pt b){
	vector <pt> r;
	pt d=proj(c,a,b);
	real X=dist(c,d);
	if ( iszero(X-cr)){r.pb(d);return r;}
	if ( X>cr) return r;
	real Y=sqrt(cr*cr-X*X);
	pt K=b-a;
	K=K*(Y/abs(K));
	r.pb(d+K);r.pb(d-K);
	return r;
}


int n;
pt center(0,0);
real r;
pt points[MAX_N];
vector<pt> epts;
void input();
void construct_points();
void solve();
int main(){
	input();
	construct_points();
	solve();
	return 0;
}


void input(){
	// input data
	scanf("%d %lf",&n,&r);
	FOR(i,n)
		scanf("%lf %lf",&points[i].x,&points[i].y);
}

void construct_points(){
	points[n]=points[0];
	for ( int i=0;i<n;i++){	
		vector<pt> vec=intersect(center,r,points[i],points[i+1]);
		vector<pt> rvec;
		FOR(j,vec.size()){
			if ( inside(vec[j],points[i],points[i+1])){
				vec[j].on=true;
				rvec.pb(vec[j]);
			}
		}
		vec=rvec;
		if ( vec.empty()){
			if ( abs(points[i])<r+eps)
				epts.pb(points[i]);
		} else if ( vec.size() == 1){
			if ( abs(points[i])<r+eps ){
				epts.pb(points[i]);
				epts.pb(vec[0]);
			} else{
				epts.pb(vec[0]);
			}
		} else {
			if ( inside(vec[0],points[i],vec[1]) ){
				vec[0].dbl=true;
				epts.pb(vec[0]);
				epts.pb(vec[1]);
			} else{
				vec[1].dbl=true;
				epts.pb(vec[1]);
				epts.pb(vec[0]);
			}
		}
	}
	if(!epts.empty()){
		epts.pb(epts[0]);
	}
}

void solve(){
	real res=0.0;
	for ( int i=0;i+1<epts.size();i++){
		real plu;
		if ( epts[i].on && epts[i+1].on && !epts[i].dbl ){
			real d=dist(epts[i],epts[i+1]);
			d/=2;
			real phi=asin(d/r);
			phi*=2;
			plu=r*r*phi/2.0;
			if (epts[i].x<epts[i+1].x) plu=-plu;
		} else{
			plu=area(epts[i],epts[i+1]);
		}
		res+=plu;
	}
	printf("%lf\n",fabs(res));
}
