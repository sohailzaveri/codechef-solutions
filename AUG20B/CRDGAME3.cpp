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

ll cnt(ll x){
	if( x <= 9 ) return 1;
	if( x%9 == 0 ) return x/9;
	return x/9 + 1;
}

int main(){
	// fastio();
	// freopen("input.txt", "r", stdin);

	// //Printing the Output to output.txt file
	// freopen("output1.txt", "w", stdout);

	test(){
		ll pc, pr;
		cin>>pc>>pr;

		ll ac = cnt(pc);
		ll ar = cnt(pr);
		// cout<<ar<<" "<<ac<<endl;
		if( ac >= ar ){
			cout<<1<<" "<<ar<<endl;
		}else{
			cout<<0<<" "<<ac<<endl;
		}
		// cout<<endl;
	}

}