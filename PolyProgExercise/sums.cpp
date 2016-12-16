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


typedef long double T;
T PI=2*acos(0.0L);
T rnd (T x ) { return x< 0.0? ceil(x-0.5): floor(x+0.5);}


struct Complex {
	
	T re, im;
	Complex(){}
	Complex(T r): re(r),im(0){}
	Complex(T r, T i): re(r), im(i){}	
	Complex operator * (const Complex &c) const{
		return Complex(re*c.re-im*c.im,re*c.im+c.re*im);
	}
	Complex operator + (const Complex &c) const{
		return Complex(re+c.re,im+c.im);
	}
	Complex operator - (const Complex &c) const{
		return Complex(re-c.re,im-c.im);
	}
};

T real(Complex x){
	return x.re;
}

void FFT(Complex *a,int N ,int dir){
	int lgN;
	for (lgN=1; (1<<lgN)<N;lgN++);
	FOR(i,N){
		int j=0;
		FOR(k,lgN){
			j |= ((i>>k)&1) << (lgN -1-k);
		}
		if ( i < j ) swap(a[i],a[j]);
	}
	FORI(s,lgN){
		int h=1<<(s-1);
		Complex t, w, w_m(cos(dir*PI/h),sin(dir*PI/h));
		for (int k=0;k<N;k+=h+h){
			w=1;
			FOR(j,h){
				t=w*a[k+j+h];
				a[k+j+h]=a[k+j] - t;
				a[k+j]=a[k+j]+t;
				w=w*w_m;
			}
		}
	}
}

vector<ll> convolve(vector<ll> & a1, vector<ll>& a2){
	int N=8;
	while( N <SZ(a1)+SZ(a2)+2) N*=2;
	Complex *t1 = new Complex[N], *t2=new Complex[N];
	FOR(i,N) t1[i]= t2[i]=0;
	FOR(i,SZ(a1)) t1[i]=a1[i];
	FOR(i,SZ(a2)) t2[i]=a2[i];
	FFT(t1,N,1);
	FFT(t2,N,1);
	FOR(i,N) t1[i]=t1[i]*t2[i];
	delete[]t2;
	FFT(t1,N,-1);
	vector<ll> res(SZ(a1)+SZ(a2)-1);
	FOR(i,SZ(res)) res[i]=(ll)rnd(real(t1[i])/N);
	delete [] t1;
	return res;
}

int main(){
	vector <ll> first,second;
	first.push_back(1);
	first.push_back(2);
	second.push_back(1);
	second.push_back(2);
	vector<ll> prod=convolve(first,second);
	for ( int i=0;i<SZ(prod);i++)
		printf("%d %d\n",i,prod[i]);
	
	return 0;
}

