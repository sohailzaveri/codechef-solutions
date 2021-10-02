#include<bits/stdc++.h>
#include<stdio.h>
#include<string>

#define ll long long int

using namespace std;

int main(){
// 	freopen("input.txt", "r", stdin);
 
//     	//Printing the Output to output.txt file
//     freopen("output1.txt", "w", stdout);
     string str; 
      
    
    ll t;
    cin>>t;

    getline(cin,str);

    while(t--){
    getline (cin, str); 

    int flag=0;

   	ll len=str.length();

    for(ll i=0; i<str.length()-2; i++){
    	if(str[i]=='n' && str[i+1]=='o' && str[i+2]=='t'){
    		if(i+2==len-1){
    			if(i==0){
    				flag=1;
    				break;
    			}else if(str[i-1]==' '){
    				flag=1;
    				break;
    			}else{
    				continue;
    			}
    		}else if(i==0){
    			if(i+2==len-1){
    				flag=1;
    				break;
    			}else if(str[i+3]==' '){
    				flag=1;
    				break;
    			}else
    			continue;
    		}else if(str[i-1]==' ' && str[i+3]==' '){
    			flag=1;
    			 break;
    		}else{
    			continue;
    		}
    	}
    }

    if(flag==1){
    	cout<<"Real Fancy"<<endl;
    }else{
    	cout<<"regularly fancy"<<endl;
    }

    }
      
    return 0; 
}