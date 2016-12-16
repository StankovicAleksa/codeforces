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
tor<pii> mst;
ll prim2 (int n, vector<pii> *adj) {
	ll cost = 0; mst.clear(); vector<bool> done(n+1,0);
	priority_queue<pair<int,pii> > q;
	q.push(mp(0,mp(-1,1))); // minus cost, from, to
	while (!q.empty()) {
		int v = q.top().se.se, d = -q.top().fi, from = q.top().se.fi;
		q.pop(); if (done[v]) continue; done[v] = 1; cost += d;
		if (from != -1) mst.pb(mp(from,v));
		FOREACH(it,adj[v]) if (!done[it->fi]) q.push(mp(-it->se,mp(v,it->fi)));
	}
	return cost;
}
int main(){
	return 0;
}
