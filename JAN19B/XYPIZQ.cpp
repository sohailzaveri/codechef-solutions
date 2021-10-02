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

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main(){

	fastio();
// 	freopen("input.txt", "r", stdin);
 
//     	//Printing the Output to output.txt file
//     freopen("output1.txt", "w", stdout);

    ll t;
    cin>>t;

    while(t--){
    	ll n, t, x, y, z;

    	cin>>n>>t>>x>>y>>z;

    	ll m=2*n+1;

    	if(t==1){
    		if(y==0){
    			cout<<1<<" "<<m<<endl;
    		}
    		else if(x==z && x!=0 && y>x){
    			cout<<(y-1)/gcd(y-1,m)<<" "<<m/gcd(y-1,m)<<endl;
    		}else if(x>z || x<z){
    			cout<<(m-2*(y)+x)/gcd((m-2*(y)+x),m)<<" "<<m/gcd((m-2*(y)+x),m)<<endl;
    		}else{
    			cout<<(y+1)/gcd(y+1,m)<<" "<<m/gcd(y+1,m)<<endl;
    		}
    	}else if(t==2){
    		cout<<(m-2*y)/gcd(m-2*y,m)<<" "<<m/gcd(m-2*y,m)<<endl;
    	}else if(t==3){
    		if(x==0){
    			cout<<1<<" "<<1<<endl;
    		}else if(x==z){
    			cout<<(x)/gcd(x,m)<<" "<<m/gcd(x,m)<<endl;
    		}else{
    			cout<<(m-2*y+z)/gcd((m-2*y+z),m)<<" "<<m/gcd((m-2*y+z),m)<<endl;
    		}
    	}else if(t==4){
    		cout<<(m-2*y)/gcd((m-2*y), m)<<" "<<m/gcd(m-2*y,m)<<endl;
    	}

    }

}