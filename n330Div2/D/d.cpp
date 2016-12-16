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
double r,v;
double a,b;
double d;
double fmax(double a, double b){
	if ( a> b) return a;
	else return b;
}
double bin_s(){
	double low=0.0;
	double high=2999999999.0;
	double mid;
	double start1;
	double start2;
	while ( high-low>1e-7*fmax(high,1)){
		mid=(low+high)/2;
		start1=M_PI/2+v*mid/(2*r);
		start2=start1-M_PI;
		double dist1=cos(start1-v/r*mid)*r+v*mid-cos(start1)*r;
		double dist2=cos(start2-v/r*mid)*r+v*mid-cos(start2)*r;
		if ( dist1< dist2)
			dist1=dist2;
		if (dist1> d)
			high=mid;
		else
			low=mid;
	}
//	printf("Start: %lf\n",start1);
	return low;
}

int main(){
	scanf("%d %lf %lf",&n,&r,&v);
	FOR(i,n){
		scanf("%lf %lf",&a,&b);
		d=b-a;
		printf("%lf\n",bin_s());
	}
	return 0;
}
