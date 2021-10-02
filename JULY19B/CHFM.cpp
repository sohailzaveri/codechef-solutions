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
	fastio();

    test(){
    	ll n;
    	cin>>n;
    	ll a[n];
    	for(ll i=0; i<n; i++){
    		cin>>a[i];
    	}
    	double sum = 0;
    	for(ll i=0; i<n; i++){
    		sum += (double)a[i];
    	}
    	sum = sum/(double)n;
    	int flag = 0;
    	for(ll i=0; i<n; i++){
    		if(a[i] == sum){
    			flag = 1;
    			cout<<i+1<<endl;
    			break;
    		}
    	}
    	if(flag == 0){
    		cout<<"Impossible"<<endl;}
    }
}