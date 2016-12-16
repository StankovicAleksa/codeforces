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
char name[200005];
int n,m;
char trans[26];
char c1,c2;

int main(){
	scanf("%d %d\n",&n,&m);
	scanf("%s\n",name);
	FOR(i,26)
		trans[i]=i;
	FOR(i,m){
		scanf("%c %c\n",&c1,&c2);
		int p1,p2;
		FOR(j,26){
			if ( trans[j]==c1-'a' )
				p1=j;
			if ( trans[j]==c2-'a' )
				p2=j;
		}	
		trans[p1]=c2-'a';
		trans[p2]=c1-'a';
	}
	FOR(i,n){
		printf("%c",'a'+trans[name[i]-'a']);
	}
	printf("\n");
	return 0;
}
