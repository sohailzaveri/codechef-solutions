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

int main(){
	// fastio();
	// freopen("input.txt", "r", stdin);

	// //Printing the Output to output.txt file
	// freopen("output1.txt", "w", stdout);

	test(){
		ll n, k;
		cin>>n>>k;
		ll p[n];
		for(int i=0; i<n; i++){
			cin>>p[i];
		}
		ll mn = LLONG_MAX;
		ll mi = -1;
		for(int i=0; i<n; i++){
			if( k%p[i] ) continue;
			if( k/p[i] < mn ){
				mn = k/p[i];
				mi = p[i];
			}
		}
		
		cout<<mi<<endl;

	}
}