#include<iostream>
 #include<string.h>
 using namespace std;
typedef long long ll;
 ll GCD(ll a, ll b){

    if(a == 0)
        return b;
    else
        return GCD(b%a, a);

}
int u[100000000] = {0};

ll S(ll n){

    ll result = 1;
    for(ll i=2; i*i<=n;i++){
        if(n%i == 0){

            n/=i;
            result*=i-1;
            while(n%i == 0){
                n/=i;
                result *=i;
            }

        }
    }
    if(n>1){
        result *= n-1;
    }

    return result;

}
//ll num[1000000001] = {0};
int main(){

    //num[1] = 0;
    //num[2] = 1;

    ll n;
    while(cin>>n){
        if(n == 0)
            break;
         cout<<S(n)<<endl;
    }

    return 0;
}
