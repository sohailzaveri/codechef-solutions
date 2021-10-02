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
		string s, p;
		cin>>s>>p;
		ll ls = s.length();
		ll lp = p.length();
		string ns = s;
		ll cnt[26] = {0};

		for(int i=0; i<ls; i++){
			cnt[ s[i] - 'a' ]++;
		}

		for(int i=0; i<lp; i++){
			cnt[ p[i] - 'a' ]--;
		}

		ll ref = p[0] - 'a';
		
		ll k = 0;
		for(int i=0; i<ref; i++){
			for( int j=0; j<cnt[i]; j++ ){
				ns[k] = i + 'a';
				k++;
			}
		}

		
		
		int flag = 0;
		for(int i=0; i<lp-1; i++){
			if( p[i] != p[i+1] ){
				if( p[i+1] > p[i] ) flag = 2;
				else flag = 1;
				break;
			}
		}
		
		if(flag == 0 || flag == 1){
			for(int i=0; i<lp; i++){
				ns[k] = p[i];
				k++;
			}
			for(int i=0; i<cnt[ ref ]; i++){
				ns[k] = p[0];
				k++;
			}
		}else{
			for(int i=0; i<cnt[ ref ]; i++){
				ns[k] = p[0];
				k++;
			}
			for(int i=0; i<lp; i++){
				ns[k] = p[i];
				k++;
			}
		}
		
		for(int i = ref+1; i<26; i++){
			for( int j=0; j<cnt[i]; j++ ){
				ns[k] = i + 'a';
				k++;
			}
		}

		cout<<ns<<endl;
	}
}