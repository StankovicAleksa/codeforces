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
struct rec{
	char val[102];
	int sz;
};

bool mystrcmp(char *r1, char *r2,int sz){
	for ( int i=0;i<sz;i++)
		if ( tolower(r1[i])<tolower(r2[i]))
			return true;
		else if (tolower(r1[i])>tolower(r2[i]))
			return false;
	return false;
}
bool equal(char *r1, char *r2,int sz){
	for ( int i=0;i<sz;i++)
		if ( tolower(r1[i])!=tolower(r2[i]))
			return false;
	return true;
	}
int max(int a, int b){
	if ( a>b ) return a;
	else return b;
}
int min(int a, int b){
	if ( a<b ) return a;
	else return b;
}
bool operator <(rec r1,rec r2){
	if ( r1.sz < 10 && r2.sz >= 10 )
		return true;
	if ( r1.sz>=10 && r2.sz<10 )
		return false;
	if ( r1.sz < 10 || r2.sz < 10 ){
		if ( r1.sz!=r2.sz)
			return r1.sz<r2.sz;
		return mystrcmp(r1.val,r2.val,r1.sz);
	}

	if ( equal(r1.val+r1.sz-10,"@bmail.com",10) && !equal(r2.val+r2.sz-10,"@bmail.com",10))
		return true;
	if ( !equal(r1.val+r1.sz-10,"@bmail.com",10) && equal(r2.val+r2.sz-10,"@bmail.com",10))
		return false;
	if ( equal(r1.val+r1.sz-10,"@bmail.com",10) && equal(r2.val+r2.sz-10,"@bmail.com",10)){
		int i1=0; int i2=0;
		while (true ){
			while ( r1.val[i1] == '.' ) i1++;
			while ( r2.val[i2] == '.' ) i2++;
			bool end1=(r1.val[i1]=='@' || r1.val[i1]=='+');
			bool end2=(r2.val[i2]=='@' || r2.val[i2]=='+');
			if ( end1 && end2 )
				return false;
			if ( end1 )
				return true;
			if ( end2 )
				return false;
			if ( tolower(r1.val[i1])<tolower(r2.val[i2]))
				return true;
			if ( tolower(r1.val[i1])>tolower(r2.val[i2]))
				return false;

			i1++; i2++;
		}
		return false;
	}
	else  {
		if ( r1.sz!=r2.sz)
			return r1.sz<r2.sz;
		return mystrcmp(r1.val,r2.val,r1.sz);
	}
}

rec niz[20000];
int flags[20000];
int main(){
	scanf("%d",&n);
	for ( int i=0;i<n;i++){
		scanf("%s",niz[i].val);
		niz[i].sz=strlen(niz[i].val);
		}
	sort(niz,niz+n);
	int res=0;
	int p,k;
	p=0;
	while ( p<n ){
		flags[p]=1;
		res++;
		while(p<n-1){
			if ( !(niz[p]<niz[p+1]) && 	!(niz[p+1]<niz[p]) ){
				p++;
			}
			else break;
		}
		p++;
	}
	printf("%d\n",res);
	p,k;
	p=0;
	while (p<n){
		k=p;
		while (flags[++k] == 0 && k<n );
		printf("%d ",k-p);
		for ( int i=p;i<k;i++)
			printf("%s ",niz[i].val);
		printf("\n");
		p=k;
	}

	//printf("\n\n");
	//for ( int i=0;i<n;i++)
		//printf("%s \n",niz[i].val);
	return 0;
}
