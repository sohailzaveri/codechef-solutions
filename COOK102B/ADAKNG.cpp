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

void display(vector<ll> v){
	for(vector<ll>:: iterator it=v.begin(); it!=v.end(); it++){
		cout<<*it<<" ";
	}
	cout<<"\n";
}

void displaya(ll* a, ll n){
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
    // fastio();
    // freopen("input.txt", "r", stdin);
 
    //     //Printing the Output to output.txt file
    // freopen("output1.txt", "w", stdout);

    ll t;
    cin>>t;
    while(t--){

        ll r, c, k;
        cin>>r>>c>>k;

        ll count=0;
        for(ll i=1; i<=8; i++){
            for(ll j=1; j<=8; j++){
                ll ai, aj;
                if(i<=r)
                    ai=r-i;
                else
                    ai=i-r;
                if(j<=c)
                    aj=c-j;
                else
                    aj=j-c;

                if(ai<=k && aj<=k)
                    count++;
            }
        }
        cout<<count<<endl;
    }

}