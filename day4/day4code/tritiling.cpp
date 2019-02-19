#include<iostream>
using namespace std;
int main(){

    long long dp[31] = {0};
    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 2;
    for(int i=4;i<=30;i+=2){
        dp[i] = 4*dp[i-2] - dp[i-4];
    }
    int n;
    while(cin>>n){

        if(n == -1)
            break;
        if(n%2 !=0)
            cout<<0<<endl;
        else
            cout<<dp[n]<<endl;



    }

    return 0;
}
