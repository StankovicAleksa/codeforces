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
double cor1[2],cor[2];
double vmax;
double wFir[2],wSec[2];
double T;
double eps=1e-7;
double dmax=1e+12;
double dabs(double d){ if ( d< 0 ) return -d; return d;}
double max(double a, double b){
	if ( a> b) return a;
	else 
		return b;
}
double norm(double *v){
	return sqrt(v[0]*v[0]+v[1]*v[1]);
}
int main(){
	scanf("%lf %lf",cor1,cor1+1);
	scanf("%lf %lf",cor,cor+1);
	cor[0]-=cor1[0];	
	cor[1]-=cor1[1];	
	scanf("%lf",&vmax);
	scanf("%lf",&T);
	scanf("%lf %lf",wFir,wFir+1);
	scanf("%lf %lf",wSec,wSec+1);
	
	//alignment
	cor[0]/=vmax;
	cor[1]/=vmax;

	wFir[0]/=vmax;
	wFir[1]/=vmax;

	wSec[0]/=vmax;
	wSec[1]/=vmax;

	/** try in one go **/

	double tlow=0;
	double thigh=dmax;
	double tmid;
	double v[2];
	do { tmid=(tlow+thigh)/2;
		v[0]=cor[0]/tmid-wFir[0];
		v[1]=cor[1]/tmid-wFir[1];
		if ( norm(v) < 1 )
			thigh=tmid;
		else 
			tlow=tmid;
	} while ( thigh-tlow > eps);

	if ( tmid <= T ){
		printf("%lf\n",tmid);
	}
	else{
		cor[0]+=T*(wSec[0]-wFir[0]);
		cor[1]+=T*(wSec[1]-wFir[1]);
		double tlow=0;
		double thigh=dmax;
		double tmid;
		double v[2];
		while ( thigh-tlow >eps ){
			tmid=(tlow+thigh)/2;
			v[0]=cor[0]/tmid-wSec[0];
			v[1]=cor[1]/tmid-wSec[1];
			if ( norm(v) < 1 )
				thigh=tmid;
			else 
				tlow=tmid;
		}
		printf("%lf\n",tmid);
	}
	return 0;
}
