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

ll exp(ll a, ll b){
	if(b == 0)
		return 1;

	ll half = exp(a, b/2);

	if(b&1)
		return half*half*a;
	else
		return half*half;
}

ll mod(ll* a, ll n, ll len){
	ll ans = 0;
	ll c = 1;
	for(ll i=len-1; i>=0; i--){
		if(i == len-1){
			c = 1;
		}else{
			c = (c*10)%n; 
		}
		ans = (ans + (c*a[i])%n)%n;
	}
	return ans;
}

int main(){
	fastio();
    
 	test(){
 		ll n;
 		cin>>n;
 		// memset(k, -1, sizeof(k));
 		string s;
 		cin>>s;
 		ll len = s.length();
 		ll k[len];
 		// cout<<len<<endl;
 		for(ll i=0; i<len; i++){
 			k[i] = s[i] - '0';
 			// cout<<k[i];
 		}
 		// nl;
 		// cout<<mod(k, n, len);
 		// cout<<exp(10, 0)<<" "<<exp(10, 2)<<" "<<exp(10, 1)<<endl;
 		ll m = mod(k, n, len);
//  		cout<<m<<endl;
 		if(n == 2){
 			if(m == 1)
 				cout<<1<<endl;
 			else
 				cout<<0<<endl;
 			continue;
 		}
 		if(m == 0){
 			cout<<0<<endl;
 		}else if(m == n/2){
 			cout<<n-1<<endl;
 		}else if(m < n/2){
 			cout<<2*m<<endl;
 		}else if(m == n-1){
 			cout<<2<<endl;
 		}else if(n&1){
 			ll ans = n-1;
 			// ans--;
 			m = m%(n/2);
 			m--;
 			ans--;
 			if(m == 0){
 				cout<<ans<<endl;
 				continue;
 			}
 			m--;
 			ans--;
 			if(m == 0){
 				cout<<ans<<endl;
 				continue;
 			}
 			ans = ans - 2*m;
 			cout<<ans<<endl;
 		}else{
 			ll ans = n-1;
 			m = m%(n/2);
 			m--;
 			ans--;
 			ans = ans - 2*m;
 			cout<<ans<<endl;
 		}
 	}   
}