#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int maxn = 1000002;
int prime[1000002];
int dprime[1000002] = {0};
int u[1000002] = {0};
int num[1000002] = {0};
bool is_digit(int n){

    int result = 0;
    while(n){
        result+=n%10;
        n/=10;
    }


    if(u[result] == 0){
            //cout<<result<<" ";
        return true;
    }else{
        return false;
    }

}
int main(){

int k = 0;
int dk = 0;
for(int i=2;i<=maxn;i++){
    num[i] = num[i-1];
    if(u[i] == 0){
        prime[k++] = i;
        if(is_digit(i)){
            //cout<<i<<endl;
            dprime[i] = 1;
            num[i]++;
        }
        //for(int j = 2;j*i<=maxn;j++){
       //     u[i*j] = 1;
        //}
    }

    for(int j=0;j<k;j++){
            if(i*prime[j]>maxn)
                break;
            u[i*prime[j]] = 1;
            if(i%prime[j] == 0)
                break;
        }

}

//for(int i=0;i<dk;i++)
   // cout<<dprime[i]<<" ";


int t;
scanf("%d",&t);
while(t--){

    int st,en;
    scanf("%d %d",&st,&en);
    int result = 0;
    //for(int i=st;i<=en;i++){
   //     if(dprime[i] == 1)
   //         result++;
   // }
   result = num[en] - num[st];
    printf("%d\n",result);

}

return 0;
}

