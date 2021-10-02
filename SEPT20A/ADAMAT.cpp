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
// 	fastio();
// 	freopen("input.txt", "r", stdin);

// 	//Printing the Output to output.txt file
// 	freopen("output1.txt", "w", stdout);

	test(){
		ll n;
		cin>>n;

		// cout<<n<<endl;

		ll a[n][n];
		for(ll i=0; i<n; i++){
			for(ll j=0; j<n; j++)
			{
				// cout<<"took "<<i<<" "<<j<<endl;
				cin>>a[i][j];
			}
		}

		int flip = 0;
		ll cnt = 0;

		for(ll i=n-1; i>=0; i--){
			for(ll j=0; j<=i; j++){
				if(flip == 1){
					if(a[j][i] != i*n + j + 1){
						// cout<<a[j][i]<<" "<<i*n+j+1<<endl;
						flip = 0;
						cnt++;
						break;
					}
				}else{
					if(a[i][j] != i*n + j + 1){
						// cout<<a[i][j]<<" "<<i*n+j+1<<" haha"<<endl;
						flip = 1;
						cnt++;
						break;
					}
				}
			}
		}

		cout<<cnt<<endl;

	}

}