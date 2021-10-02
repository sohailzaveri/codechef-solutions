#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define loop(i,a,b) for(ull i=a;i<b;i++)
#define test() ull t;cin>>t;while(t--)
#define pb push_back
#define mkp make_pair
#define nl cout<<endl
#define MOD 1000000007
#define trace(s,a) cout<<s<<a,nl

bool check(ll k, vector<ll> &v, ll h){
	ll n = v.size();
	ll hrs = 0;
	for(int i=0; i<n; i++){
		if(v[i] == 0) continue;
		if(v[i] % k == 0){
			hrs += v[i]/k;
		}else{
			hrs += v[i]/k + 1;
		}
	}
	if(hrs <= h) return true;
	return false;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
    	ll n, h;
    	cin>>n>>h;
    	vector<ll> v;
    	ll mx = 0;
    	for(ll i=0; i<n; i++){
    		ll x;
    		cin>>x;
    		v.pb(x);
    		mx = max(mx, x);
    	}
    	ll l = 1; 
    	ll r = mx;
    	if(check(l, v, h)){
    		cout<<l<<endl;
    		return 0;
    	}
    	while(r - l > 1){
    		ll mid = (l+r)>>1;
    		if(check(mid, v, h)) r = mid;
    		else l = mid;
    	}
    	cout<<r<<endl;
    }
}