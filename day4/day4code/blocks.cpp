#include<iostream>

using namespace std;

long long  pow(int n,int m){
    if(n == 1 || m == 0)
        return 1;

    if(m == 1)
        return n;

    long long  result = 1;
    long long  x = n;
    /*while(m--){
        result*=n;
        if(result>10007){
            result%=10007;
        }
    }*/

    int i = 2;
    while(1){
        if(m<i){
            result = (result - 10007*(result/10007))*pow(n,m);
            result = (result - 10007*(result/10007));
            //if(result>10007){
            //result%=10007;
       // }
            break;
        }
        x = (x - 10007*(x/10007))*(x - 10007*(x/10007));
        //cout<<i<<" "<<x<<endl;
        result = (result - 10007*(result/10007))*x ;
        result = (result - 10007*(result/10007));
        //if(result>10007){
          //  result%=10007;
        //}
        m -= i;
        i = i*2;
        if(m == 0)
            break;
    }

    return result;
}

int main(){


int t;
cin>>t;
while(t--){

    double n;
    cin>>n;
    //cout<<pow(2,n)<<endl;
    //cout<<pow(4,n)<<endl;
    cout<<((pow(4,n)+pow(2,n+1))/4)%10007<<endl;

}

return 0;
}
