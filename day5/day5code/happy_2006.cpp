#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
typedef long long ll;
ll GCD(ll a, ll b){

    if(a == 0)
        return b;
    else
        return GCD(b%a, a);

}
int u[1000001];
int num[1000001];
int main(){

    ll m,k;
    //cout<<GCD(2006,2007)<<endl;
    while(cin>>m>>k){

        memset(u,0,sizeof(u));
        ll total = 0;
        for(int i=1;i<m;i++)
            if(GCD(i,m) == 1){
                u[i] = 1;
                total++;
                num[total] = i;
            }

        ll t = 0;
        ll i;
        ll s = 0;
        if(k>total && total !=0){
            s = k/total;
            k%=total;
        }
    /*    for(i=1;;i++){
          if(u[i%m] == 1){
            t++;
          }
          if(t == k)
            break;
        }*/


        cout<<num[k]+m*s<<endl;

    }

}

