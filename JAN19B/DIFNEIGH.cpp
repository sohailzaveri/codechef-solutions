#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define loop(i,a,b) for(ull i=a;i<b;i++)
#define test() ull t;cin>>t;while(t--)
#define pb push_back
#define mkp make_pair
#define nl cout<<endl
#define MOD 1000000007
#define trace(s,a) cout<<s<<a,nl

void display(ll* a, ll n){
    for(ll i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
	fastio();
// 	freopen("input.txt", "r", stdin);
 
//     	//Printing the Output to output.txt file
//     freopen("output1.txt", "w", stdout);



    ll t;
    cin>>t;

    while(t--){
    	ll n,m;

    	cin>>n>>m;

    	if((n==1 && (m==1 || m==2))||(m==1 && (n==1 || n==2))){
    		cout<<1<<endl;
    	}else if((n==2 || m==2) && !(n==2 && m==2)){
    		cout<<3<<endl;
    	}else if((n==1 && !(m==1 || m==2))||(m==1 && !(n==1 || n==2))){
    		cout<<2<<endl;
    	}else if(n==2 && m==2){
    		cout<<2<<endl;
    	}else
    	cout<<4<<endl;


    	ll a[2][4][2]={1,1,3,3,2,2,4,4,2,2,4,4,1,1,3,3};

    	if(!(m==2 || n==2)){
    		if(n<=m){
    			for(ll i=0; i<n; i++){
    				for(ll j=0; j<m; j++){
    					cout<<a[(j%4)/2][i%4][j%2]<<" ";
    				}
    				cout<<endl;
    			}
    		}else{
    			for(ll i=0; i<n; i++){
    				for(ll j=0; j<m; j++){
    					cout<<a[(i%4)/2][j%4][i%2]<<" ";
    				}
    				cout<<endl;
    			}	
    		}
    	}else{
    		if(n==2){
    			for(ll i=0; i<2; i++){
    				for(ll j=0; j<m; j++){
    					cout<<j%3 + 1<<" ";
    				}
    				cout<<endl;
    			}
    		}else{
    			for(ll i=0; i<n; i++){
    				for(ll j=0; j<2; j++){
    					cout<<i%3 + 1<<" ";
    				}
    				cout<<endl;
    			}
    		}

    	}

    }
}