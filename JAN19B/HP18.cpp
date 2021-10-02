#include<bits/stdc++.h>
#include<stdio.h>
#include<string>

#define ll long long int

using namespace std;

int main(){
// 	freopen("input.txt", "r", stdin);
 
//     	//Printing the Output to output.txt file
//     freopen("output1.txt", "w", stdout);

    ll t;
    cin>>t;

    while(t--){
    	ll n, a, b;
    	cin>>n>>a>>b;

    	ll ca=0, cb=0, cc=0;
    	ll c;
    	for(ll i=0; i<n ; i++){
    		cin>>c;
    		if(c%a==0){
    			ca++;
    			if(c%b==0)
    				cc++;
    		}
    		if(c%b==0){
    			cb++;
    		}
    	}

    	if(cc!=0){
    		ca++;
    	}

    	if(ca>cb){
    		cout<<"BOB"<<endl;
    	}else
    		cout<<"ALICE"<<endl;

    }
}