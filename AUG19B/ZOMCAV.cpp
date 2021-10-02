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
// // 
// struct Compare {
//     constexpr bool operator()(pair<int, int> const & a,
//                               pair<int, int> const & b) const noexcept
//     { return (a.first > b.first) || (a.first==b.first && a.second > b.second); }
// };




int main(){
	fastio();
    
    // cout<<ceil(log2(3))<<endl;
    test(){
    	ll n;
    	cin>>n;
    	// cout<<n<<endl;
    	ll as[n] = {0}, rad[n] = {0}, h[n];
    	for(ll i=0; i<n; i++){
    		ll c;
    		cin>>c;
    		as[ max( i - c, (ll)0 ) ]++;
    		if( i + c < n-1 ){
    			as[ i+c+1 ]--;
    		}
    	}
    	ll add = 0;
    	map<ll, ll> mp;
    	mp.clear();
    	for(ll i = 0; i<n; i++){
    		add += as[i];
    		rad[i] += add;
    		if( mp.count( rad[i] ) ){
    			mp[ rad[i] ]++;
    		}else{
    			mp[ rad[i] ] = 1;
    		}
    	}
    	// for( ll i=0; i<n; i++ ){
    	// 	cout<<rad[i]<<" ";
    	// }
    	// cout<<endl;
    	ll flag = 0;
    	map<ll, ll> :: iterator itr;
    	// for(itr = mp.begin(); itr != mp.end(); itr++){
    	// 	cout<<itr->first<<" "<<itr->second<<endl;
    	// }
    	for(ll i=0; i<n; i++){
    		cin>>h[i];
    	}
    	for(ll i=0; i<n; i++){
    		// cin>>h[i];
    		if( !mp.count( h[i] ) ){
    			// cout<<h[i]<<" . "<<endl;
    			flag = 1;
    			break;
    		}else{
    			mp[ h[i] ]--;
    			if( mp[ h[i] ] == 0 ) mp.erase(h[i]);
    		}
    	}
    	if( flag == 1 ){
    		cout<<"NO"<<endl;
    	}else{
    		cout<<"YES"<<endl;
    	}
    }
}