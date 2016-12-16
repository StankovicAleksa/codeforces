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

#define LEN 500001 
#define MAXN 500000
int n,m;
long long u[LEN],v[LEN];
int q;

long long prime=2394067599LL;
long long mod=1000035697;
long long hash_u[LEN],hash_v[LEN];
long long pows[LEN];
int a,b,l;
int max(int a, int b){ if ( a> b) return a; return b;}
long long pw(long long nm,long long exp, long long mod);
long long inv(long long a, long long mod);
void init_hash();
void init_pows();
long long gethash(int start, int end, long long mod, long long *ar); 
																							// inclusive [start,end]
int posDif(int pu,int pv,int l);

vector<pair<int,long long> >vals[MAXN+1];
long long last[MAXN+1];
void init_vals();


long long getSum(int poc, int kraj,long long val); 

int main(){
	scanf("%d",&n);
	FORI(i,n)
		scanf("%I64d",u+i);
	scanf("%d",&m);
	FORI(i,m)
		scanf("%I64d",v+i);
	scanf("%d",&q);
	init_hash();
	init_pows();
	init_vals();
	FOR(cnt,q){
		scanf("%d %d %d",&a,&b,&l);

		int dif=posDif(a,b,l);
		if ( dif==-1){
			printf("TAK\n");
			continue;
		}
		long long vdif=v[b+dif]-u[a+dif];
		vdif%=mod;	
		if (vdif<0) vdif+=mod;
		long long sum1=gethash(a,a+l-1,mod,hash_u);	
		long long sum2=gethash(b,b+l-1,mod,hash_v);
		long long difsum=	sum2-sum1;
		difsum%=mod; if (difsum<0 ) difsum+=mod;
		long long sum=getSum(a,a+l-1,u[a+dif]);
		if ( vdif*sum%mod==difsum)
			printf("TAK\n");
		else 
			printf("NIE\n");
	}
	return 0;
}

long long pw(long long nm, long long exp, long long mod){
	if ( exp==0 ) return 1;
	long long t=pw(nm,exp/2,mod);
	if ( exp%2== 1 ) return t*t%mod*nm%mod;
	else return t*t%mod;	
}
long long inv(long long a, long long mod){
	return pw(a,mod-2,mod);
}
void init_hash(){
	for ( int i=1;i<=n;i++)
		hash_u[i]=(hash_u[i-1]*prime+u[i])%mod;
	for ( int i=1;i<=m;i++)
		hash_v[i]=(hash_v[i-1]*prime+v[i])%mod;
}
void init_pows(){
	pows[0]=1;
	int l=max(n,m);
	FORI(i,l)
		pows[i]=pows[i-1]*prime%mod;
}
long long gethash(int start, int end, long long mod, long long *ar){
 
	// inclusive [start,end]

	long long sm=(ar[end]-ar[start-1]*pows[end-start+1])%mod;
  if ( sm<0 ) sm+=mod;
	return sm%mod;

}
int posDif(int poc_u, int poc_v, int l){
	
	int bk_u=poc_u+l-1,bk_v=poc_v+l-1;
	int mid_u,mid_v;
	int bp_u=poc_u,bp_v=poc_v;
	long long hsh_u,hsh_v;
	while ( bp_u<bk_u){
		mid_u=bp_u+(bk_u-bp_u+1)/2;
		mid_v=bp_v+(bk_v-bp_v+1)/2;
		hsh_u=gethash(mid_u,bk_u,mod,hash_u);
		hsh_v=gethash(mid_v,bk_v,mod,hash_v);
		if ( hsh_u!=hsh_v){
			bp_u=mid_u;
			bp_v=mid_v;
		}		
		else{
			bk_u=mid_u-1;
			bk_v=mid_v-1;
		}
	}
	if (  v[bp_v] ==u[bp_u] )
		return -1;
	else return bp_u-poc_u; 
}

void init_vals(){

	FORI(i,n){
		if (vals[u[i]].empty()){
			vals[u[i]].push_back(make_pair(0,0));
			last[u[i]]=0;
		}
		long long tmp=(last[u[i]]+pows[n-i]);
		if ( tmp > mod ) tmp-=mod;
		vals[u[i]].push_back(make_pair(i,tmp));
		last[u[i]]=tmp;
	}

}

long long getSum(int poc, int kraj,long long val){

	int low=0;
	int high=vals[val].size()-1;
	int mid=low;
	int pocindex;
	int krajindex;
	while ( low<high){
		mid=low+(high-low+1)/2;
		if ( vals[val][mid].first < poc )
			low=mid;
		else
			high=mid-1;
	}
	pocindex=low;
	low=0; high=vals[val].size()-1;
	mid=low;
	while ( low<high){
		mid=low+(high-low+1)/2;
		if ( vals[val][mid].first <= kraj )
			low=mid;
		else
			high=mid-1;
	}
	krajindex=low;
	long long sum=vals[val][krajindex].second-vals[val][pocindex].second;
	sum*=inv(pows[n-kraj],mod);
	sum%=mod;
	if ( sum<0 ) sum+=mod;
	return sum;
}
