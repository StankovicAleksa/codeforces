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


const int max_size=100000;
char buf[max_size];
int buf_size=0,pos=0;
#define getbuf() buf_size=fread(buf,1,max_size,stdin)
#define get(tok) {if (pos>=buf_size){if (feof(stdin)) tok=0;  else {getbuf();pos=0;tok=buf[pos++];}}else tok=buf[pos++];}
#define in(v) { int tok;get(tok); while(tok==' ' || tok == '\n') get(tok); v= tok-'0'; get(tok);		while(tok>='0'&&tok<='9'){v*=10;v+=(tok-'0');get(tok);}}
 
int n;
long long sum;
long long m;
long long tmp;
int main(){
	scanf("%d %I64d",&n,&m);
	FOR(i,n){
		in(tmp);
		sum+=tmp;
		sum%=m;
	}
	printf("%I64d\n",sum);
	return 0;
}
