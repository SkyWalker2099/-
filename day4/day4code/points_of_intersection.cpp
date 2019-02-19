#include<iostream>
#include<stdio.h>
using namespace std;
long long num[20005];
int main(){


 num[1] = 1;
 for(int i=2;i<=20000;i++){
    num[i] = i+num[i-1];
    //cout<<num[i]<<endl;
 }
 //for(int i=1;i<=100;i++)
 //   cout<<num[i]<<endl;
// cout<<num[20000]<<endl;
 //cout<<1<<endl;
int i,j;
int ind = 1;
while(cin>>i>>j){

    if(i+j == 0)
        break;

    long long result;
    if(i<2|| j<2){
        result = 0;
        cout<<"Case "<<ind++<<": "<<result<<endl;
    }else{
      result = 1;
    for(int k = 3;k<=i;k++)
        result+=(k-1)*num[1];
    for(int k = 3;k<=j;k++)
        result+=(k-1)*num[i-1];
        cout<<"Case "<<ind++<<": "<<result<<endl;
        //printf("%.0f\n",result);

    }





}



 return 0;
}
