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
#define INF 999999999.0
#define real double




// usage: init(n, s, t), addEdge(u, v, capa u->v, capa v->u), dinicFlow()
const int N = 100000 + 7, M = 2000000 + 7;
typedef double T; // if changing this to long long, also change INF to 10^18
real fabs(real a){ if ( a< 0 ) return -a; return a;}

real eps=1e-14;
int nodes, src, dest, nedge;
int point[M], nxt[M];
real capa[M],flow[M];
int head[N], dist[N], Q[N], work[N];
void init (int _nodes, int _src, int _dest) {
	nodes = _nodes + 2; // just to be safe
	src = _src;
	dest = _dest;
	FOR(i,nodes) head[i] = -1;
	nedge = 0;
}
void addEdge(int u, int v, real c1, real c2 = 0.0) {
	point[nedge]=v, capa[nedge]=c1, flow[nedge]=0.0, nxt[nedge]=head[u],
		head[u]=(nedge++);
	point[nedge]=u, capa[nedge]=c2, flow[nedge]=0.0, nxt[nedge]=head[v],
		head[v]=(nedge++);
}
bool dinicBfs() {
	FOR(i,nodes) dist[i] = -1;
	dist[src] = 0;
	int szQ = 1;
	Q[0] = src;
	FOR(cl,szQ) {
		for (int k = Q[cl], i = head[k]; i >= 0; i = nxt[i]) {
			if (flow[i] < capa[i] && dist[point[i]] < 0) {
				dist[point[i]] = dist[k] + 1;
				Q[szQ++] = point[i];
			}
		}
	}
	return dist[dest] >= 0;
}
T dinicDfs (int x, T exp) {
	if (x == dest) return exp;
	T res = 0;
	for (int& i = work[x]; i >= 0; i = nxt[i]) {
		int v = point[i]; T tmp;
		if (flow[i] < capa[i] && dist[x]+1 == dist[v]
				&& (tmp = dinicDfs(v, min(exp, (T)capa[i] - flow[i]))) > 0) {
			flow[i] += tmp;
			flow[i^1] -= tmp;
			res += tmp;
			exp -= tmp;
			if (0 == exp) break;
		}
	}
	return res;
}
T dinicFlow () {
	T res = 0;
	while (dinicBfs()) {
		FOR(i,nodes) work[i] = head[i];
		res += dinicDfs(src,INF);
	}
	return res;
}


// geometry



inline bool iszero(real x){return x<=eps && x>=-eps;}
struct pt {
	real x,y;
	pt(real xx=0,real yy=0):x(xx),y(yy){}
	bool operator==(pt &a){return iszero(a.x-x) && iszero(a.y-y);}
};
bool operator<(const pt &a, const pt &b) {
	if (a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
ostream& operator<<(ostream &s,pt p) {return s<<"("<<p.x<<","<<p.y<<")";}
pt operator+(pt a,pt b){return pt(a.x+b.x,a.y+b.y);}
pt operator-(pt a,pt b){return pt(a.x-b.x,a.y-b.y);}
pt operator*(pt a,real r){return pt(a.x*r,a.y*r);}
pt operator/(pt a,real r){return pt(a.x/r,a.y/r);}
real vec(pt a,pt b){return a.x*b.y-a.y*b.x;}
real det(pt a,pt b,pt c){return vec(b-a,c-a);}
// det(a,b,c) >= 0 iff A,B,C are in counterclockwise order
pt operator*(pt a,pt b){return pt(a.x*b.x-a.y*b.y,b.x*a.y+b.y*a.x);}
real sqabs(pt a){return a.x*a.x+a.y*a.y;}
pt operator/(pt a,pt b) {return (a*pt(b.x,-b.y))/sqabs(b);}
real abs(pt a){return sqrt(a.x*a.x+a.y*a.y);}
real dalj(pt a,pt b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
real sqdist(pt a,pt b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
real arg(pt a){return atan2(a.y,a.x);} // from the range [-pi,pi]
real scal(pt a,pt b){return a.x*b.x+a.y*b.y;}

real lenproj(pt a,pt b){return scal(a,b)/abs(b);}
pt proj(pt a,pt b,pt c) { // projection of point A onto line BC
	pt d=c-b;
	return b+d*(scal(a-b,d)/sqabs(d));
}
vector<pt> circle_line_cross(pt c,real cr,pt a,pt b) {
	vector<pt> r;
	pt d=proj(c,a,b);
	real X=dalj(c,d);
	if (iszero(X-cr)){
		if ( dalj(d,a)+dalj(d,b)<=dalj(a,b)+eps)
			r.pb(d);
		return r;
	} // one point
	if (X>cr) return r; // line is too far
	real Y=sqrt(cr*cr-X*X);
	pt K=b-a;
	K=K*(Y/abs(K));
	pt test=d+K;
	if ( dalj(test,a)+dalj(test,b)<=dalj(a,b)+eps)
		r.pb(test);
	test=d-K;
	if ( dalj(test,a)+dalj(test,b)<=dalj(a,b)+eps)
		r.pb(test);

//	r.pb(d+K);r.pb(d-K);
	return r;
}


int n,m;
pt starpos[21];
real speed[21];
pt start[21];
pt end[21];
real energy[21];
real lasers[21];
pt smer[21];
set <real> timesteps;
int main(){
	scanf("%d",&n);
	FOR(i,n)
		scanf("%lf %lf",&starpos[i].x,&starpos[i].y);
	scanf("%d",&m);
	FOR(i,m){
		scanf("%lf %lf %lf %lf %lf %lf %lf",&start[i].x,&start[i].y,&end[i].x,&end[i].y,&speed[i],&lasers[i],&energy[i]);
		if ( dalj(end[i],start[i]) < eps )
			i--,m--;
		else
			smer[i]=(end[i]-start[i])/dalj(end[i],start[i]);
	}
	// creating time discretization
	FOR(i,m)
		FOR(j,n){
			vector<pt> inter=circle_line_cross(starpos[j],lasers[i],start[i],end[i]);
			if ( dalj(start[i],starpos[j])<=lasers[i]+eps){
				//if ( i== 0 ) printf("time:%lf %\n",0);
					timesteps.insert(0);
			}
			if ( dalj(end[i],starpos[j])<=lasers[i]+eps){
			//	if ( i== 0 ) printf("time: %d %lf\n",j,dalj(start[i],end[i])/speed[i]);
				timesteps.insert(dalj(start[i],end[i])/speed[i]);
			}
			for ( int k=0;k<inter.size();k++){
				pt point=inter[k];
				timesteps.insert(dalj(start[i],point)/speed[i]);
			//	if ( i== 0 ) printf("time: %d %lf\n",j,dalj(start[i],point)/speed[i]);
			}
		}

	// creating flow network	
	int szt=timesteps.size();
	int fin=szt*n+m+1;
	init(fin+1,0,fin);

	set<real>::iterator it,it2;	
	int cnt=0;
	int step=0;
	double eps2=sqrt(eps);
	for ( int i=1;i<=m;i++)
		addEdge(0,i,energy[i-1],0.0);
	for ( it = timesteps.begin();it!=timesteps.end();it++,step++){
		it2=it; it2++; if ( it2 == timesteps.end()) break;
		double t=*it;
		real dt=*it2-*it;		
		FOR(i,m){
			FOR(j,n){
				pt in=start[i]+(t*speed[i])*smer[i];
				pt dirCirc=(starpos[j]-in)/dalj(in,starpos[j]);
				if ( dalj(start[i],in)+dalj(in,end[i]) > dalj(start[i],end[i])+eps || dalj(in,starpos[j]) > lasers[i]+eps  ) 
					continue;
				// exiting point
				if ( dalj(in,end[i])<eps )
					continue;
				if ( dalj(in,starpos[j])+eps > lasers[i] &&  scal(smer[i],dirCirc) < -eps ) 
					continue;
				//printf("%lf %lf %lf",dalj(in,starpos[j]),lasers[i],scal(smer[i],dirCirc));
				//printf("; pos:  %lf %lf %lf %lf %lf %lf\n",in.x, in.y,smer[i].x,smer[i].y,starpos[j].x,starpos[j].y);
				addEdge(i+1,step*n+m+j+1,INF,0.0);	
			}
		}
		//printf("\n");
		FOR(i,n)
			addEdge(step*n+m+i+1,fin,dt,0.0);
	}

	// doing flow
	
	printf("%.15lf\n",dinicFlow());
	return 0;
}
