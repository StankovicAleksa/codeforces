#include <bits/stdc++.h>
#include <regex.h>
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

#define SIZE 100005
char ulaz[SIZE];
vector<pii> v1;
vector<pii> v2;
void ps(int poc, int kraj){
	for ( int i=poc;i<kraj;i++)
		printf("%c",ulaz[i]);
}
int main(){
	int n;
	scanf("%s",ulaz);
	n=strlen(ulaz);	
	const char *reg1 = "[^,;]*(,|;)";
	const char *reg2="([1-9][0-9]*|0)$";
	re_pattern_buffer buffer;
	re_pattern_buffer bf2;
  char map[SIZE];

	buffer.translate = 0;
	buffer.fastmap = map;
	buffer.buffer = 0;
	buffer.allocated = 0;

	re_set_syntax(RE_SYNTAX_POSIX_EXTENDED);
	re_compile_pattern(reg1,strlen(reg1),&buffer);
	re_compile_pattern(reg2,strlen(reg2),&bf2);
	re_compile_fastmap(&buffer);
	//re_compile_fastmap(&bf2);
	re_registers regs;
	re_registers regs1;
	int ofs = 0;
	int p=0;
	while (true ){
		if (re_search(&buffer,ulaz+p,n-p,0,n-p,&regs)!=-1) {
			//ps(p,p+regs.end[0]); printf("\n");
			if ( re_search(&bf2,ulaz+p,regs.end[0]-1,0,regs.end[0]-1,&regs1) != -1 )
				v1.pb(pii(p,p+regs.end[0]-1));
			else
				v2.pb(pii(p,p+regs.end[0]-1));
		} else
			break;
		p+=regs.end[0];
	}
	if ( re_search(&bf2,ulaz+p,n-p,0,n-p,&regs1) != -1 )
		v1.pb(pii(p,n));
	else
		v2.pb(pii(p,n));
	if ( v1.size() == 0 ) {
		cout << "-" << endl;
	}	else {
		cout<<"\"";
		FOR(i,v1.size()){
			if ( i > 0 ) cout<<",";
			ps(v1[i].first,v1[i].second);
		}
		cout<<"\"";
	}
	cout<<endl;
	if ( v2.size() == 0 ) {
		cout << "-" << endl;
	}	else {
		cout<<"\"";
		FOR(i,v2.size()){
			if ( i > 0 ) cout<<",";
			ps(v2[i].first,v2[i].second);
		}
		cout<<"\"";
	}
	cout<<endl;
	return 0;
}
