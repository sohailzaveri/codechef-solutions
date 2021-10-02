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

bool check( ll l, ll r, string &s ){
	if( l == r ){
		if( s[l] == '0' ) return false;
		else return true;
	}
	if( l > r ) return false;
	if( s[l] == '0' ) return check(l+1, r, s);
	if( s[r] == '0' ) return check(l, r-1, s);
	if( s[l+1] == '0' ) s[l+1] = '1';
	else s[l+1] = '0';
	if( s[r-1] == '0' ) s[r-1] = '1';
	else s[r-1] = '0';
	return check(l+1, r-1, s);
}

int main(){
	fastio();

    
    // cout<<ceil(log2(3))<<endl;
    test(){
    	string s;
    	cin>>s;
    	ll n = s.length();
    	ll flag = 0;
    	for(ll i=0; i<n; i++){
    		if( s[i] == '1' ){
    			flag = 1;
    			break;
    		}
    	} 
    	if( flag == 0 ){
    		cout<<"LOSE"<<endl;
    		continue;
    	}
    	if( check(0, n-1, s) ) cout<<"WIN";
    	else cout<<"LOSE";
  		nl;
    }
}