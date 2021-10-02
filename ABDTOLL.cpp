#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type)) 
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define loop(i,a,b) for(ull i=a;i<b;i++)
#define test() ull t;cin>>t;while(t--)
#define pb push_back
#define mkp make_pair
#define nl cout<<endl
#define MOD 1000000007
#define trace(s,a) cout<<s<<a,nl
#define MAXN 100002

vector<ll> g[MAXN];
ll k;
ll parent[MAXN];
ll d[MAXN];
ll tl[MAXN];
ll v[MAXN];
ll cnt;
ll s = 0;
ll ind = 0;
bool vis[MAXN];
ll inz=0;

void clearg(){
	for(ll i=0; i<MAXN; i++){
		tl[i] = 0;
		g[i].clear();
		parent[i] = -1;
		vis[i] = false;
		cnt = 0;
		inz = 0;
	}
} 

void addEdge(ll u, ll v){
	g[u].pb(v);
	g[v].pb(u);
}

void DFS(ll x){
	v[ind] = x;
	// cout<<ind<<" : "<<v[ind]<<endl;
	if(inz>ind)
	    inz = ind;
	ind++;
	// cout<<"entered dfs "<<x<<endl;
	vis[x] = true;
	s = s + d[x];
	if(g[x].size() == 1 && vis[g[x][0]]==true){
		// cout<<"entered if "<<x<<endl;
		if(s > k){
			// cout<<"entered for "<<x<<" "<<s<<endl;
			cnt = s - k;
			// cout<<"stack size: "<<v.size()<<endl;
			for(ll i=inz; i<ind; i++){
				if(d[v[i]] >= cnt){
					d[v[i]]-=cnt;
					if(d[v[i]] == 0)
					    inz = i+1;
					// cout<<v[i]<<" "<<d[v[i]]<<endl;
					break;
				}else{
					cnt -= d[v[i]];
					d[v[i]] = 0;
					inz = i+1;
				}
			}
			s = k;
		}
		ind--;
		s = s - d[x];
		return;
	}else{
		for(ll i=0; i<g[x].size(); i++){
			if(vis[g[x][i]] == false)
				DFS(g[x][i]);
		}
	}
	s = s-d[x];
	ind--;
}

int main(){

    test(){
    	clearg();
    	s = 0;
    	ll n, x;
    	cin>>n>>x>>k;
    	for(ll i=1; i<=n; i++){
    		cin>>tl[i];
    		d[i] = tl[i];
    	}
    	for(ll i=0; i<n-1; i++){
    		ll u, v;
    		cin>>u>>v;
    		addEdge(u, v);
    	}

    	DFS(x);

    	ll min = 0; 
    	for(ll i=1; i<=n; i++){
    		min += tl[i] - d[i];
    	}
    	cout<<2*min<<endl;
	}	
}