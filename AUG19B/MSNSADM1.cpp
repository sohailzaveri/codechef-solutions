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

    // cout<<ceil(log2(3))<<endl;

    test(){
        ll n;
        cin>>n;
        ll a[n], b[n];
        for(ll i=0; i<n; i++){
            cin>>a[i];
        }
        for(ll i=0; i<n; i++){
            cin>>b[i];
        }
        ll mx = 0;
        for(ll i=0; i<n; i++){
            mx = max( mx, max((ll)0, 20*a[i] - 10*b[i]) );
        }  
        cout<<mx<<endl;
    }

}