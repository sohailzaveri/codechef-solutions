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

const ll m = 1000000000;

int main(){
	fastio();

 	test(){
 		cout<<1<<" "<<31623<<endl;
 		ll p;
 		cin>>p;
 		ll a = (31623)*(31623) - p;
 		vector<ll> primes;
 		if( a%2 == 0 ){
 			if(2 > p) primes.pb(2);
 			while( a!=1 && a%2 == 0 ){
 				a = a/2;
 			}
 		}
 		ll x = a;
 		for(ll i = 3; i*i <= x; i+=2){
 			if( x%i == 0 ){
 				if(i > p) primes.pb(i);
 				while( x!=1 && x%i == 0 ){
 					x = x/i;
 				}
 			}
 		}
 		if( x > 1 ) primes.pb(x);
 		ll n = primes.size();
 		if( n == 1 ){
 			cout<<2<<" "<<primes[0]<<endl;
 			string s; 
 			cin>>s;
 			if(s == "Yes") continue;
 			return 0;
 		}

 		map< ll, ll > mp;
//  		ll n = primes.size();
 		ll i;
 		i = ceil( sqrt(primes[n-2]) );
 		for(; i<=1000000000; i++){
 			ll n = primes.size();
 			ll flag = 0;
 			mp.clear();
 			for(ll j= 0; j<n; j++){
 				if( mp.count((i*i)%primes[j]) ){
 					// cout<<i<<" "<<primes[j]<<endl;
 					flag = 1;
 					break;
 				}else{
 					mp[(i*i)%primes[j]] = primes[j];
 					// cout<<(i*i)%primes[j]<<endl;
 				}
 			}
 			if(flag == 0) break;
 		}
 		// cout<<i<<endl;

 		cout<<1<<" "<<i<<endl;
 		cin>>p;
 		if(p == -1) return 0;
 		cout<<2<<" "<<mp[p]<<endl;
 		string s;
 		cin>>s;
 		if(s == "Yes") continue;
 		else
 			return 0;

 	}   
}