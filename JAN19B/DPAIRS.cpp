
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

    ll n;
    ll m;

    cin>>n>>m;
    ll min;
    cin>>min;
    ll mini=0;

    for(ll i=1; i<n; i++){
        ll c;
        cin>>c;
        if(c<min){
            mini=i;
            min=c;
        }
    }
    ll max;
    cin>>max;
    ll maxi=0;
    for(ll i=1; i<m; i++){
        ll c;
        cin>>c;
        if(c>max){
            maxi=i;
            max=c;
        }
    }

    for(ll i=0; i<m; i++){
        cout<<mini<<" "<<i<<endl;
    }

    for(ll i=0; i<n; i++){
        if(i==mini)
            continue;
        cout<<i<<" "<<maxi<<endl;
    }

}