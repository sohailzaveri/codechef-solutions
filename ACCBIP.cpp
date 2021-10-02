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

vector<ll> computeSums(vector<vector<pair<ll, ll> > > &v){
	ll c = v.size() - 1;
	vector<ll> ans;
	ans.pb(1);
	for(ll i=1; i<=c; i++){
		ll cn = v[i].size();
		ll sum = 0;
		for(int j=0; j<cn; j++){
			for(int k=j+1; k<cn; k++){
				// cout<<v[i][j].second<<"*"<<v[i][k].second<<endl;
				sum += v[i][j].second*v[i][k].second;
			}
		}
		ans.pb(sum);
	}
	return ans;
}

vector<vector<ll> > sortedVector(vector<vector<pair<ll, ll> > > &v){
	ll c = v.size() - 1;
	vector<vector<ll> > ans(c+1);
	for(ll i=1; i<=c; i++){
		ll cn = v[i].size();
		if(cn == 0) continue;
		for(ll j=0; j<cn; j++){
			ans[i].pb(v[i][j].second);
		}
		sort(ans[i].begin(), ans[i].end());
	}
	return ans;
}

vector<vector<ll> > csumsVector(vector<vector<ll> > &v){
	ll c = v.size() - 1;
	vector<vector<ll> > ans(c+1);
	for(ll i=1; i<=c; i++){
		ll cn = v[i].size();
		if(cn == 0) continue;
		ans[i].pb(v[i][0]);
		for(int j = 1; j<cn; j++){
			ll x = v[i][j] + ans[i][j-1];
			ans[i].pb(x);
		}
	}
	return ans;
}

vector<pair<ll, ll> > noOfTriangles(vector<vector<ll> > &csums, vector<vector<ll> > &sv, vector<ll> &sums, ll* v){
	ll c = sv.size() - 1;
	vector<pair<ll, ll> > ans;
	// cout<<"notr : "<<endl;
	for(ll i=1; i<=c; i++){

		ll sum = sums[i];
		ll cn = sv[i].size();

		if(cn == 0) continue;

		ll tsum = csums[i][cn-1];

		// cout<<i<<"-> ";
		for(ll j=0; j<cn; j++){
			ll notr = sum - (sv[i][j]*(tsum-csums[i][j]));
			
			sum = notr;
			// cout<<notr<<" ";
			if(notr == 0) continue;
			for(ll k=0; k<sv[i][j]; k++){
				ans.pb(mkp(notr, v[i]));
			}
		}
		// cout<<endl;
	}

	return ans;

}

ll knapsack(vector<pair<ll, ll> > &v, ll k){
	ll n = v.size();

	ll tsum = 0;
	for(ll i=0; i<n; i++){
		tsum += v[i].first;
	}

	if(k == 0) return tsum;

	ll dp[n][k+1] = {0};

	for(ll i=0; i<n; i++){
		for(ll j=0; j<=k; j++){
			dp[i][j] = 0;
		}
	}

	// cout<<"tsum : "<<tsum<<endl;

	// cout<<"dp: "<<endl;

	if(v[0].second <= k)
		dp[0][ v[0].second ] = v[0].first;

	// for(ll i=0; i<k+1; i++) cout<<dp[0][i]<<" ";

	// cout<<endl;

	for(ll i=1; i<n; i++){

		for(ll j=0; j<=k; j++){

			dp[i][j] = dp[i-1][j];

			ll wt = v[i].second;
			ll val = v[i].first;

			if(j - wt >= 0)
				dp[i][j] = max(dp[i][j], dp[i-1][j-wt] + val);

			// cout<<dp[i][j]<<" ";
		}
		// cout<<endl;

	}

	// cout<<endl;

	ll mx = 0;
	for(ll i=0; i<=k; i++){
		mx = max(mx, dp[n-1][i]);
	}

	// cout<<"mx : "<<mx<<endl;

	return tsum - mx;

}

int main(){

	test(){
		ll n, c, k;
		cin>>n>>c>>k;

		ll a[n], color[n];
		vector<vector<pair<ll, ll> > > an(c+1);
		for(int i=0; i<n; i++){
			ll x;
			cin>>a[i]>>x>>color[i];

			ll col = color[i];
			ll cn = an[col].size();

			int flag = 0;
			for(ll j=0; j<cn; j++){
				ll cola = an[col][j].first;
				// cout<<cola<<" "<<a[i]<<endl;
				if(cola == a[i]){
					// cout<<"added"<<endl;
					an[col][j].second++;
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				an[col].pb(mkp(a[i], 1));
			}
		}

		ll v[c+1] = {0};
		for(ll i=1; i<=c; i++){
			cin>>v[i];
		}

		vector<ll> dsums = computeSums(an);
		// cout<<"sums : "<<endl;
		// for(ll i=1; i<=c; i++){
		// 	cout<<i<<"->"<<dsums[i]<<endl;
		// }
		// cout<<endl;

		vector<vector<ll> > sv = sortedVector(an);
		// cout<<"sorted v : "<<endl;
		// for(ll i=1; i<=c; i++){
		// 	cout<<i<<"-> ";
		// 	for(ll j=0; j<sv[i].size(); j++){
		// 		cout<<sv[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;
		vector<vector<ll> > csums = csumsVector(sv);
		// cout<<"csums : "<<endl;
		// for(ll i=1; i<=c; i++){
		// 	cout<<i<<"-> ";
		// 	for(ll j=0; j<csums[i].size(); j++){
		// 		cout<<csums[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;

		vector<pair<ll, ll> > notr = noOfTriangles(csums, sv, dsums, v);

		// cout<<endl;

		ll len = notr.size();
		// cout<<"len : "<<len<<endl;

		if(len == 0){
			cout<<0<<endl;
			continue;
		}

		// for(ll i=0; i<len; i++){
		// 	cout<<notr[i].first<<" "<<notr[i].second<<endl;
		// }

		cout<<knapsack(notr, k)<<endl;

		// cout<<endl<<endl;

	}
}