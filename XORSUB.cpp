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

int main(){

	test(){
		ll n, k;
		cin>>n>>k;

		ll a[n];
		for(ll i=0; i<n; i++){
			cin>>a[i];
		}

		ll dp[n][1024] = {0};
		for(ll i=0; i<n; i++){
			dp[i][0] = 1;
		}

		dp[0][a[0]] = 1;

		for(ll i=1; i<n; i++){
			for(ll j=1; j<=1023; j++){
				dp[i][j] = dp[i-1][j] || dp[i-1][j ^ a[i]];
			}
		}

		ll mx = 0;
		for(ll i=0; i<=1023; i++){
			if(dp[n-1][i])
				mx = max(mx, k^i);
		}

		cout<<mx<<endl;

	}
}