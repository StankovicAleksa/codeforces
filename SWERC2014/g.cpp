#include <cstdio>
#include <algorithm>
using namespace std;
int sz[2];
struct vertex{
	int y,x;
	vertex(){}
	vertex(int _y,int _x){
		y=_y;
		x=_x;
	}
};
vertex v[2][501];
int sw;
struct srtx{
	int pos;
};
struct srty{
	int pos;
};

bool operator < (srtx s1, srtx s2){
	return v[sw][s1.pos].x<v[sw][s2.pos].x;
}

bool operator < (srty s1, srty s2){
	return v[sw][s1.pos].y<v[sw][s2.pos].y;
}
srtx posx[501];
srty posy[501];

struct edge{
	int v1,v2;
	int pos;
	void sort(){
		if (v1 > v2 ){
			int c=v1;
			v1=v2;
			v2=c;
		}
	}
};

edge eh1[501];
edge ev1[501];	 
edge eh2[501];
edge ev2[501];
int e1hsz,e1vsz,e2hsz,e2vsz;
bool operator < (edge e1, edge e2){
	return e1.pos<e2.pos;
}
int main(){
	for ( int i=0;i<2;i++){
		scanf("%d",sz+i);
		for ( int j=0;j<sz[i];j++){
			scanf("%d %d",&v[i][j].x,&v[i][j].y);
		}	
	}
	if ( sz[0]!=sz[1]){
		printf("no\n");
		return 0;
	} else{
		int s=sz[0];
		for ( sw=0;sw<2;sw++){
			for ( int i=0;i<s;i++){
				posx[i].pos=i;
				posy[i].pos=i;
			}
			sort(posx,posx+s);
			sort(posy,posy+s);
			int trans=0;
			for ( int i=1;i<s;i++){
				v[sw][posx[i].pos].x-=trans;
				if ( v[sw][posx[i].pos].x!=v[sw][posx[i-1].pos].x ){
					int t=v[sw][posx[i].pos].x-v[sw][posx[i-1].pos].x;
					v[sw][posx[i].pos].x=v[sw][posx[i-1].pos].x+1;
					trans+=t-1;
				}
			}
			trans=0;
			for ( int i=1;i<s;i++){
				v[sw][posy[i].pos].y-=trans;
				if ( v[sw][posy[i].pos].y!=v[sw][posy[i-1].pos].y ){
					int t=v[sw][posy[i].pos].y-v[sw][posy[i-1].pos].y;
					v[sw][posy[i].pos].y=v[sw][posy[i-1].pos].y+1;
					trans+=t-1;
				}
			}
		}
		v[0][s]=v[0][0];
		v[1][s]=v[1][0];
		for( int i=0;i<s;i++){
			if( v[0][i].x ==v[0][i+1].x){
				ev1[e1vsz].v1=v[0][i].y;
				ev1[e1vsz].v2=v[0][i+1].y;
				ev1[e1vsz].pos=v[0][i].x;
				ev1[e1vsz].sort();
				e1vsz++;
			} else{
				//printf("WTF: %d %d %d %d\n",v[0][i].x,v[0][i].y,v[0][i+1].x,v[0][i].y);
				eh1[e1hsz].v1=v[0][i].x;
				eh1[e1hsz].v2=v[0][i+1].x;
				eh1[e1hsz].pos=v[0][i].y;
				eh1[e1hsz].sort();
				e1hsz++;
			}
		}
		for( int i=0;i<s;i++){
			if( v[1][i].x==v[1][i+1].x){
				ev2[e2vsz].v1=v[1][i].y;
				ev2[e2vsz].v2=v[1][i+1].y;
				ev2[e2vsz].pos=v[1][i].x;
				ev2[e2vsz].sort();
				e2vsz++;
			} else{
				eh2[e2hsz].v1=v[1][i].x;
				eh2[e2hsz].v2=v[1][i+1].x;
				eh2[e2hsz].pos=v[1][i].y;
				eh2[e2hsz].sort();
				e2hsz++;
			}
		}
		sort(ev1,ev1+e1vsz);
		sort(eh1,eh1+e1hsz);
		sort(ev2,ev2+e2vsz);
		sort(eh2,eh2+e2hsz);
		bool ok[4];
		for ( int i=0;i<4;i++)
			ok[i]=true;
		for ( int i=0;i<e1hsz;i++){
			if ( ev1[i].v1!=ev2[i].v1 || ev1[i].v2!=ev2[i].v2 ||  ev1[i].pos!=ev2[i].pos )  // 0 degrees
				ok[0]=false;
			if ( ev1[i].v1!=s/2-1-ev2[s/2-1-i].v2 || ev1[i].v2!=s/2-1-ev2[s/2-1-i].v1 || ev1[i].pos != s/2-1-ev2[s/2-1-i].pos )  // 180 degrees
				ok[1]=false;
			if ( eh1[i].v1!=s/2-1-ev2[i].v2 || eh1[i].v2!=s/2-1-ev2[i].v1 || eh1[i].pos != ev2[i].pos )  // 90 degrees
				ok[2]=false;
			if ( eh1[i].v1!=ev2[s/2-1-i].v1 || eh1[i].v2!=ev2[s/2-1-i].v2 || eh1[i].pos != s/2-1-ev2[s/2-1-i].pos )  // 270 degrees
				ok[3]=false;
		}
		if (ok[0] ||ok[1] ||ok[2] ||ok[3] ){
			printf("yes\n");
		}		
		else 
			printf("no\n");
	}
	return 0;
}
