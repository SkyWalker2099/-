#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main(){


string str;
//memset(str,0,sizeof(str))
while(cin>>str){

    if(str == "#"){
        break;
    }

    int len = str.length();
  //cout<<len<<endl;
    int i;
    bool flag = true;
    for(i = len-1;i>=1;i--){
        if(str[i-1]>=str[i]){
            continue;
        }else{
            flag = false;
            break;
        }
    }

    if(flag){
        cout<<"No Successor"<<endl;
        continue;
    }
    int j;
    for(j = len-1;j>=i;j--){
        if(str[j]>str[i-1]){
            swap(str[j],str[i-1]);

            for(int n = len-1;n>i;n--)
                for(int m =i;m<n;m++)
                    if(str[m]>str[m+1])
                        swap(str[m],str[m+1]);
            cout<<str<<endl;
            break;
        }

    }

}
}
