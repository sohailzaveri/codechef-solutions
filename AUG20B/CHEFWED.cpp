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

map<ll, ll> dp;

ll diff(ll i, ll j, ll k, vector<vector<ll> > &cnt){
	if(i == 0) return cnt[j][k];
	return cnt[j][k] - cnt[i-1][k];
}

ll cost(ll i, ll j, vector<vector<ll> > &cnt){
	if(j <= i) return 0;
	ll m = cnt[0].size();
	ll sum = 0;
	for(int k=0; k<m; k++){
		if(diff(i, j, k, cnt) <= 1) continue;
		sum += diff(i, j, k, cnt);
	}
	return sum;
}

ll minCost(ll i, ll j, ll k, vector<vector<ll> > &cnt){
	if( dp.count(i) ) return dp[i];
	if( j == i ) return k;
	if( j < i ) return 0;

	ll mn = LLONG_MAX;
	for(ll x = i; x <= j; x++){
		// cout<<"i-> "<<i<<" x-> "<<x<<" cost->"<<cost(i, x, cnt)<<endl;
		mn = min(mn, cost(i, x, cnt) + k + minCost(x+1, j, k, cnt));
	}
	dp[i] = mn;
	return mn;
}

int main(){
	// fastio();
	// freopen("input.txt", "r", stdin);

	// //Printing the Output to output.txt file
	// freopen("output1.txt", "w", stdout);

	test(){
		dp.clear();
		ll n, k;
		cin>>n>>k;

		vector<ll> v(n);
		ll mx = 0;
		for(int i=0; i<n; i++){
			cin>>v[i];
			mx = max(mx, v[i]);
		}

		vector<vector<ll> > cnt;
		for(int i=0; i<n; i++){
			vector<ll> x(mx+1, 0);
			cnt.pb(x);
		}

		cnt[0][v[0]] = 1;
		for(int i=1; i<n; i++){
			for(int j=0; j<=mx; j++){
				cnt[i][j] = cnt[i-1][j];
			}
			cnt[i][v[i]]++;
		}

		cout<<minCost(0, n-1, k, cnt)<<endl;

	}
}