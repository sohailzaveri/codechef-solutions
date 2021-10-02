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
#define MAXN 100005

bool oe(ll a){
	ll cnt = 0;
	if(a&1)
		cnt++;
	for(ll i=0; i<17; i++){
		a = a>>1;
		if(a&1)
			cnt++;
	}
	return (! (cnt&1) );
}

int main(){
	fastio();

    test(){
    	ll q;
    	cin>>q;
    	map< ll, vector<ll> > mp1;
    	map<ll, ll> mp2;
    	ll e =0, o = 0;
    	for(ll i=0; i<q; i++){
    		ll a;
    		cin>>a;
    		if(mp1.count(a) || mp2.count(a)){
    			// cout<<"case 1 "<<endl;
    			cout<<e<<" "<<o<<endl;
    			continue;
    		}
    		else{
    			mp1[a].pb(1);
    			mp1[a].clear();

    			if( oe(a) ) e++;
    			else o++;

    			map<ll, vector<ll> > :: iterator itr;

    			for(itr = mp1.begin(); itr != mp1.end(); itr++){
    				if(itr->first == a) continue;

    				ll c = itr->first;
    				if( mp1.count( c^a ) || mp2.count(c^a) ) continue; //check later

    				mp1[a].pb( c^a );
    				mp2[c^a] = a;

    				if( oe(c^a) ) e++;
    				else o++;
    				// cout<<c<<" ->";
    				vector<ll> v = itr->second;
    				ll n = v.size();
    				for(ll j =0; j<n; j++){
    					ll x = mp1[c][j];
    					// cout<<x<<" ";
    					if(mp1.count(x^a) || mp2.count(x^a)) continue;
    					mp1[a].pb(a^x);
    					mp2[a^x] = a;
    					// cout<<"xa "<<x<<" "<<a<<" "<<(x^a)<<endl;
    					if( oe(x^a) ){
    						e++;
    						// cout<<"e increased"<<endl;
    					}
    					else o++;
    				}
    			}
    			cout<<e<<" "<<o<<endl;
    			// cout<<a<<" -> "<<mp1[a].size()<<endl;
    		}
    	}
    }
    
}