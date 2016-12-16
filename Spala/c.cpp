#include <bits/stdc++.h>
using namespace std;

long long M,N,K;
char choic[15];
char res[14];
long long deck[14][8];
char opt[2]={'B','T'};

bool backtrack(int d,long long r,bool realWay){
	r%=M;
	if ( d== N ){
		if ( r<=K || r>=M-K)
			return true;
		return false;
	}	
	for ( int o=0;o<2;o++){
		if ( realWay ) 
			res[d]=opt[o];  
		int om=(o+1)%2;
		int ch=rand()%2;
		long long mv[2];
		bool goodFirst=(choic[d] == opt[ch]);

		for ( int i=0;i<2;i++){
			ch++;
			ch%=2;
			mv[i]=r+r*deck[d][om*4+2*ch]+deck[d][om*4+2*ch+1];
		}
		if (backtrack(d+1,mv[0],goodFirst && realWay) && backtrack(d+1,mv[1],!goodFirst && realWay) ){
			return true;
		}
	}	
	return false;
}

int main(){
	scanf("%I64d %I64d %I64d",&N,&M,&K);
	scanf("%s",choic);
	for ( int i=0;i<N;i++)
		for ( int j=0;j<8;j++)
			scanf("%I64d",deck[i]+j);

	backtrack(0,0,true);
	for ( int i=0;i<N;i++)
		printf("%c",res[i]);
	printf("\n");
	return 0;
}
