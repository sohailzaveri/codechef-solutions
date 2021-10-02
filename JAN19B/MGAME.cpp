#include<bits/stdc++.h>
#include<stdio.h>
#include<string>
#include<algorithm>

#define ll long long int

using namespace std;

void display(ll* a, ll n){
    for(ll i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){

// 	freopen("input.txt", "r", stdin);
 
//     	//Printing the Output to output.txt file
//     freopen("output1.txt", "w", stdout);

    ll t;
    cin>>t;

    while(t--){
    	ll n, p;
    	cin>>n>>p;

    	if(n==1 || n==2){
    		cout<<p*p*p<<endl;
    	}else{
    		ll m=(n-1)/2;
    		cout<<(p-m)*(p-m)+(p-n)*(p-m)+(p-n)*(p-n)<<endl;
    	}

    }

}