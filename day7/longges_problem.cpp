#include<iostream>
#include<string.h>
#include<stdio.h>
//#include<cmath>
using namespace std;
typedef long long ll;
int u[1000000] = {0};
ll num[1005][2] = {0};
ll prime[1000000],len;
int cnt;
//154137354357
//631090657533
ll pow(ll a,ll b)
{
    ll ans=1;

    while(b>0)
    {
        if ((b&1)==1)
 		ans=(ans*a);
 		b>>=1;
 		a=(a*a);
    }
   return ans;
}
void init(ll n){

    cnt = 0;
    memset(num,0,sizeof(num));
    for(ll i=0;prime[i]*prime[i]<=n&&i<len;i++){

        if(n%prime[i] == 0){
            num[cnt][0] = prime[i];
            //n/=i;
            //cout<<i<<endl;
            while(n%prime[i] == 0){
                num[cnt][1]++;
                n/=prime[i];
            }
            cnt++;
        }
    }

    if(n!=1){
        num[cnt][0] = n;
        num[cnt++][1] = 1;
    }

}

int main(){
    int i;
    u[1] = 0;
    len = 0;
    for(int i = 2;i<1000000;i++){

        if(u[i] == 0){// cout<<i<<endl;
        prime[len] = i;
        len++;
        }

        for(int j=0;j<len && i*prime[j]<1000000;j++){
            u[prime[j]*i] = 1;
            if(i%prime[j] == 0)
                break;
        }

    }
    //cout<<"finished"<<endl;
    ll n;
    while(~scanf("%lld",&n)){

        ll result = 1;

        //cout<<n<<endl;

        init(n);
        for(ll i = 0;i<cnt;i++){
            //cout<<num[i]<<endl;
            ll res = pow(num[i][0], num[i][1]);
            result*=(res+num[i][1]*res- num[i][1]*res/num[i][0]);
            //cout<<num[i]<<endl;
        }

        printf("%lld\n",result);

    }

    return 0;
}
