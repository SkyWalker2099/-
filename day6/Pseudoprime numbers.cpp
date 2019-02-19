#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef __int64 ll;
ll is_prime(ll p){

    if(p<2)
        return 0;
    for(int i=2;i<=sqrt((float)p);i++){
        if(p%i == 0)
            return 0;
    }

    return 1;
}
__int64 pow1(__int64 a,__int64 b,__int64 c)//?????(a?b????c)
{
    __int64 ans=1;
    a=a%c;
    while(b>0)
    {
        if ((b&1)==1)//?????
 		ans=(ans*a)%c;//????????
 		b>>=1;//b=b/2;
 		a=(a*a)%c;
    }
   return ans;
}
ll pow(ll a,ll p, ll mod){
    //cout<<"a:"<<a<<" p:"<<p<<endl;
    if(p == 0 || a == 1)
        return 1;
    if(p == 1)
        return a%mod;

    ll result = ((a%mod)*(a%mod))%mod;
    ll middle = ((a%mod)*(a%mod))%mod;
    ll t = 2,total = 2;
    p-=2;
    while(t*2<= p){
        //cout<<t<<" "<<p<<endl;
        result =((result%mod) * (middle%mod)*(middle%mod))%mod;
        middle = ((middle%mod)*(middle%mod))%mod;
        //total += t*2;
        t*=2;
        p-=t;
        //cout<<t<<" "<<p<<endl;
    }
    //cout<<result<<endl;
    if(p == 0)
    return result%mod;
    else
    return ((result%mod)*(pow(a,p,mod)%mod))%mod;


}
int main(){

    ll a,p;

    while(cin>>p>>a){
        if(p+a == 0)
        break;

        if(is_prime(p)== 1){
            cout<<"no"<<endl;
            continue;
        }
       // cout<<pow(a,p,p)<<endl;
        if(pow1(a,p,p) == a){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }

    return 0;
}
