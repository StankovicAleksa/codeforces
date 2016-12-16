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

char  s[100005];
char s1[100005];
char s2[100005];

int cs[26];
int cs1[26];
int cs2[26];

int tcs[26];

int mx;
int m1,m2;
int tmp1,tmp2;
int main(){
	scanf("%s",s);
	scanf("%s",s1);
	scanf("%s",s2);
	int n,n1,n2;
	n=strlen(s);
	n1=strlen(s1);
	n2=strlen(s2);

		
	FOR(i,n)
		cs[s[i]-'a']++;
	FOR(i,n1)
		cs1[s1[i]-'a']++;
	FOR(i,n2)
		cs2[s2[i]-'a']++;

	FOR(i1,n){
		FOR(j,26)
			tcs[j]=cs[j];
		bool poss=true;
		FOR(j,26){
			tcs[j]-=i1*cs1[j];
			if ( tcs[j]<0){
				poss=false;
				break;
			}
		}
		if ( !poss){
			break;
		}
		FOR(i2,n){
			bool ps=true;
			if ( i2>0){
				FOR(j,26){
					tcs[j]-=cs2[j];
					if ( tcs[j]< 0){
						ps=false;
						break;
					}
				}
			}
			if ( !ps) 
				break;
			if (i1+i2>mx){
				mx=i1+i2;
				m1=i1;
				m2=i2;
			}
		}
	}
	FOR(i,26){
		cs[i]-=m1*cs1[i]+m2*cs2[i];
	}	
	FOR(i,m1)	
		printf("%s",s1);
	FOR(i,m2)
		printf("%s",s2);
	FOR(i,26){
		FOR(j,cs[i])
			printf("%c",'a'+i);
	}
	printf("\n");
	return 0;
}
