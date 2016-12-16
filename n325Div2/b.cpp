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
int sum1[52];
int sum2[52];
int tsum2[52];
int val1[52];
int val2[52];
int cr[52];
int a;
int main(){
	scanf("%d",&n);
	FORI(i,n-1) {
		scanf("%d",val1+i);
		sum1[i+1]=sum1[i]+val1[i];
	}
	FORI(i,n-1) {
		scanf("%d",val2+i);
		tsum2[i]=tsum2[i-1]+val2[i];
	}

	int su=tsum2[n-1];
	FORI(i,n){
		sum2[i]=su-tsum2[i-1];
	}
	FORI(i,n)
		scanf("%d",cr+i);
	int m1,m2;	
	m1=9999999;
	m2=9999999;	
	FORI(i,n){

			//if (i!=n  && sum1[i]+cr[i]+sum2[i]+2*val1[i] < m2 ) 
				//m2=sum1[i]+cr[i]+sum2[i]+2*val1[i]; 

			//if (i!=1   && sum1[i]+cr[i]+sum2[i]+2*val2[i-1] < m2 ) 
				//m2=sum1[i]+cr[i]+sum2[i]+2*val2[i-1]; 
		
		if ( sum1[i]+cr[i]+sum2[i] < m2 ){
			m2=sum1[i]+cr[i]+sum2[i] ; 
		}	
		if ( m1 > m2 )
		{
			int c=m1;
			m1=m2;
			m2=c;
		}
	}
	printf("%d\n",m1+m2);
	return 0;
}
