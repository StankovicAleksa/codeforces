#include <bits/stdc++.h>
#include <cmath>
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
double x1,x2,ya1,ya2,r1,r2;
int main(){
	scanf("%lf %lf %lf",&x1,&ya1,&r1);
	scanf("%lf %lf %lf",&x2,&ya2,&r2);
	double d=(x1-x2)*(x1-x2)+(ya1-ya2)*(ya1-ya2);
	d=sqrt(d);
	if ( r1+r2<= d) {
		printf("0\n");
		return 0;
	}
	if ( r1>= r2+d ){
		printf("%.13lf\n",r2*r2*M_PI);
		return 0;
	}
	if ( r2>= r1+d ){
		printf("%.13lf\n",r1*r1*M_PI);
		return 0;
	}
	double alpha1=acos((r1*r1+d*d-r2*r2)/(2*r1*d));
	double alpha2=acos((r2*r2+d*d-r1*r1)/(2*r2*d));
	double p1=alpha1*r1*r1-sin(alpha1)*r1*cos(alpha1)*r1;
	double p2=alpha2*r2*r2-sin(alpha2)*r2*cos(alpha2)*r2;
	printf("%.13lf\n",(p1+p2),alpha1,alpha2);
	return 0;
}
