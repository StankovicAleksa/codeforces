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

#define SIZE 200005
char s[SIZE];
int cnt[26];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	FOR(i,n)
		cnt[s[i]-'a']++;
	for ( int i=0;i<26;i++){
		if ( cnt[i]%2==0 )
			continue;
		for ( int j=26;j>i;j--){
			if ( cnt[j]%2==1 ){
				cnt[i]++;
				cnt[j]--;
				break;
			}
		}
	}
	int p=0;
	for ( int i=0;i<26;i++){
		for ( int j=0;j<cnt[i]/2;j++){
			s[p+j]=s[n-p-j-1]='a'+i;
		}
		p+=cnt[i]/2;

	}
	for ( int i=0;i<26;i++)
		if ( cnt[i]%2==1 ){
			s[n/2]='a'+i;
		}
	printf("%s\n",s);
 	return 0;
}
