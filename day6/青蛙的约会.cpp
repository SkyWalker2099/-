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


    ll x,y,m,n,L;
    while(cin>>x>>y>>m>>n>>L){
    if(m<n){
        swap(m,n);
        swap(x,y);
    }
    ll a = m-n;
    ll b = L;
    ll c = y-x;

    //cout<<a<<" "<<b<<" "<<c<<endl;
    ll gcd = GCD(a,b);
    if(c % gcd != 0){
        cout<<"Impossible"<<endl;
        return 0;
    }

    a/=gcd;
    b/=gcd;
    c/=gcd;
    ll x0=0,y0=0;
    exgcd(a,b,x0,y0);

    x0*=c;

    if(x0<0)
        cout<<x0%b+b<<endl;
    else
        cout<<x0%b<<endl;
    }
    return 0;
}
