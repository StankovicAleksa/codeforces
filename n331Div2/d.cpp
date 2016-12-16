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

#define MAX_N 2005
int h;
int niz[MAX_N];
int lft[MAX_N];
int rght[MAX_N];
double dp[MAX_N][MAX_N][2][2]; // [0][0] - chopped lft before ,chopped rght before
double prob[MAX_N][MAX_N][2][2];
int n;
double p;
double res;
double minM(double a, double b){
	if ( a < 0 || b< 0 )
		return 0;
	if ( a< b) return a; return b;
}
int main(){
	scanf("%d %d %lf",&n,&h,&p);			
	FORI(i,n)
		scanf("%d",niz+i);
	std::sort(niz+1,niz+n+1);

	// reaching variables
	FORI(i,n){
		int rReach=niz[i]+h;
		rght[i]=i;
		for ( int j=i+1;j<=n;j++){
			if ( niz[j] < rReach ) {
				rght[i]=j;
				rReach=niz[j]+h;
			}	
		}
		int lReach=niz[i]-h;
		lft[i]=i;
		for ( int j=i-1;j>=1;j--){
			if ( niz[j] > lReach ) {
				lft[i]=j;
				lReach=niz[j]-h;
			}	
		} 
	}
	niz[0]=-2000000000;	
	niz[n+1]= 2000000000;	
	prob[1][n][0][0]=0.25;
	prob[1][n][0][1]=0.25;
	prob[1][n][1][0]=0.25;
	prob[1][n][1][1]=0.25;
	// calculate solution
	for ( int i=1;i<=n;i++){
		for ( int j=n;j>=i; j-- ){
			// chopping lft tree to the lft
			dp[i+1][j][0][0]+=p/2*(dp[i][j][0][0]+prob[i][j][0][0]*minM(niz[i]-niz[i-1],	h));
			dp[i+1][j][0][1]+=p/2*(dp[i][j][0][1]+prob[i][j][0][1]*minM(niz[i]-niz[i-1],	h));
			dp[i+1][j][0][0]+=p/2*(dp[i][j][1][0]+prob[i][j][1][0]*minM(niz[i]-niz[i-1]-h,	h));
			dp[i+1][j][0][1]+=p/2*(dp[i][j][1][1]+prob[i][j][1][1]*minM(niz[i]-niz[i-1]-h,	h));
			prob[i+1][j][0][0]+=prob[i][j][0][0]*p/2;
			prob[i+1][j][0][1]+=prob[i][j][0][1]*p/2;
			prob[i+1][j][0][0]+=prob[i][j][1][0]*p/2;
			prob[i+1][j][0][1]+=prob[i][j][1][1]*p/2; 
			// chopping lft tree to the rght 
			dp[rght[i]+1][j][1][0]+=(1-p)/2*(dp[i][j][0][0]+prob[i][j][0][0]*minM(niz[rght[i]]+h-niz[i] ,	niz[j+1]-h-niz[i]));
			dp[rght[i]+1][j][1][0]+=(1-p)/2*(dp[i][j][1][0]+prob[i][j][1][0]*minM(niz[rght[i]]+h-niz[i] ,	niz[j+1]-h-niz[i]));
			dp[rght[i]+1][j][1][1]+=(1-p)/2*(dp[i][j][0][1]+prob[i][j][0][1]*minM(niz[rght[i]]+h-niz[i] ,	niz[j+1]-niz[i]));
			dp[rght[i]+1][j][1][1]+=(1-p)/2*(dp[i][j][1][1]+prob[i][j][1][1]*minM(niz[rght[i]]+h-niz[i] ,	niz[j+1]-niz[i]));
			
			prob[rght[i]+1][j][1][0]+=prob[i][j][0][0]*(1-p)/2;
			prob[rght[i]+1][j][1][1]+=prob[i][j][0][1]*(1-p)/2;
			prob[rght[i]+1][j][1][0]+=prob[i][j][1][0]*(1-p)/2;
			prob[rght[i]+1][j][1][1]+=prob[i][j][1][1]*(1-p)/2;
			// chopping rght tree to the rght
			dp[i][j-1][0][1]+=(1-p)/2*(dp[i][j][0][1]+prob[i][j][0][1]*minM(niz[j+1]-niz[j]		 ,	h));
			dp[i][j-1][1][1]+=(1-p)/2*(dp[i][j][1][1]+prob[i][j][1][1]*minM(niz[j+1]-niz[j]		 ,	h));
			dp[i][j-1][0][1]+=(1-p)/2*(dp[i][j][0][0]+prob[i][j][0][0]*minM(niz[j+1]-niz[j]-h 	 ,	h));
			dp[i][j-1][1][1]+=(1-p)/2*(dp[i][j][1][0]+prob[i][j][1][0]*minM(niz[j+1]-niz[j]-h   ,	h));
		
			prob[i][j-1][0][1]+=prob[i][j][0][0]*(1-p)/2;
			prob[i][j-1][0][1]+=prob[i][j][0][1]*(1-p)/2;
			prob[i][j-1][1][1]+=prob[i][j][1][0]*(1-p)/2;
			prob[i][j-1][1][1]+=prob[i][j][1][1]*(1-p)/2;
			// chopping rght tree to the lft 
			dp[i][lft[j]-1][0][0]+=(p/2)*(dp[i][j][0][1]+prob[i][j][0][1]*minM(niz[j]-niz[lft[j]]+h     ,niz[j]-niz[i-1]));
			dp[i][lft[j]-1][1][0]+=(p/2)*(dp[i][j][1][1]+prob[i][j][1][1]*minM(niz[j]-niz[lft[j]]+h     ,niz[j]-niz[i-1]-h));
			dp[i][lft[j]-1][0][0]+=(p/2)*(dp[i][j][0][0]+prob[i][j][0][0]*minM(niz[j]-niz[lft[j]]+h     ,niz[j]-niz[i-1]));
			dp[i][lft[j]-1][1][0]+=(p/2)*(dp[i][j][1][0]+prob[i][j][1][0]*minM(niz[j]-niz[lft[j]]+h     ,niz[j]-niz[i-1]-h));
		
			prob[i][lft[j]-1][0][0]+=prob[i][j][0][0]*(p/2);
			prob[i][lft[j]-1][0][0]+=prob[i][j][0][1]*(p/2);
			prob[i][lft[j]-1][1][0]+=prob[i][j][1][0]*(p/2);
			prob[i][lft[j]-1][1][0]+=prob[i][j][1][1]*(p/2);
			}
	}
	//printf("%lf %lf\n",p,dp[1][2][0][0]);
	/*for ( int i=0;i<=n+1;i++){
		for ( int j=0;j<=n+1;j++)
			printf("%.3lf ",dp[i][j][1][0]);
		printf("\n");
	}
	*/
	for ( int i=0;i<=n+1;i++)
		for ( int j=0;j<=n+1;j++){
			if ( i>j ){
				res+=dp[i][j][0][0]+dp[i][j][0][1]+dp[i][j][1][0]+dp[i][j][1][1];
			}
		}
	printf("%.17lf\n",res);
	return 0;
}
