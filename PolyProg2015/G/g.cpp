#include <cstdio>
#include <algorithm>

using namespace std;

// mapping structures 
struct map{
	int val,loc;
	map(){}
	map(int _val,int _loc){
		val=_val;loc=_loc;
	}
} ;

int max(int a, int b){
	if ( a> b) return a; 
	return b;
}

bool phase1=true;
bool operator < (map p1, map p2){
	if ( phase1 && p1.val == p2.val ){
		return p1.loc < p2.loc;
	} else return p1.val< p2.val;
}

int n;
int niz1[100000];
map niz2[100000];

struct MaxTree{
	int *el;
	int s;

	MaxTree(int h){
		el=new int[2*(s=1<<h)];
		for ( int x=0;x<=2*s;x++){
			el[x]=0;	
		}
	}
	~MaxTree() {delete [] el ; }
	void set(int p, int v){
		for ( p+=s, el[p]=v, p/=2; p>0; p/=2) el[p]=max(el[2*p],el[2*p+1]);
	}
	int find(int p, int k){
		int m=0; p+=s; k+=s;
		while ( p< k ){
			if ( p&1 )    m= max(m,el[p++]);
			if (!(k&1))   m= max(m,el[k--]);
			p/=2; k/=2;
		}
		if ( p==k ) m = max ( m, el[p]);	
		return m;
	}
};



int main(){
	scanf("%d",&n);
	MaxTree tree(20);
	for ( int i=0;i<n;i++)
		scanf("%d",niz1+i);
	for ( int i=0;i<n;i++){
		scanf("%d",&niz2[i].val);
		niz2[i].loc=i;
	}
	sort(niz2,niz2+n);
	phase1=false;
	for ( int i=0;i<n;i++){
		int ind=upper_bound(niz2,niz2+n,map(niz1[i],0))-niz2;	
		ind--;
		while ( ind >=0 && niz2[ind].val==niz1[i] ){
			int v=tree.find(0,niz2[ind].loc-1);
			int a=max(tree.find(niz2[ind].loc,niz2[ind].loc),v+1);
			tree.set(niz2[ind].loc,a);
			ind--;
			}
		}
	printf("%d\n",tree.find(0,n));
	return 0;
}
