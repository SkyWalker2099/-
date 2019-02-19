#include<iostream>
using namespace std;
typedef long long ll;
ll pow(int n, int k){
    ll result = 1;
    while(k--){
        result*=n;
    }
    return result;
}
ll GCD(ll a, ll b){

    if(a == 0)
        return b;
    else
        return GCD(b%a, a);

}
int exgcd(ll a, ll b,ll &x, ll &y){

    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll t=exgcd(b,a%b,x,y);
    ll x0=x,y0=y;
    x=y0;
    y=x0-(a/b)*y0;
    return t;

}
int main(){



     ll A,B,C,k;
     while(cin>>A>>B>>C>>k){

        if(A+B+C+k == 0)
            break;

        ll k2 = pow(2,k);
        //cout<<k2<<endl;

        ll D = (B-A)%k2;
        ll gcd = GCD(C,k2);

       // if(D == 0){
      //      cout<<0<<endl;
       // }
        if(D%gcd != 0){
            cout<<"FOREVER"<<endl;
            continue;
        }



        C/=gcd;
        k2/=gcd;
        D/=gcd;
        ll x=0,y=0;
        exgcd(C,k2,x,y);
        x*=D;
        //x*=gcd;
        if(x<0)
            x =(x%k2+k2)%k2;
        cout<<x<<endl;
        cout<<x%k2<<endl;
        //cout<<x2 - x1<<endl;

     }


}

