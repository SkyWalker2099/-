#include<iostream>
using namespace std;
int prime[3000009] = {0};
int s[1000001] = {0};
int maxn = 3000009;
int main(){
    int ind = 0;
    prime[1] = 1;
    for(int i=2;i<=maxn;i++){
        if(prime[i] == 0){
            //prime_num[ind++] = i;

            for(int j=2;j*i<maxn;j++){
                prime[j*i] = 1;
            }


        }


    }

    for(int i=1;i<=1000000;i++){
        s[i] = s[i-1]+(1-prime[i*3+7]);
    }

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
       // cout<<n*3+7<<" "<<prime[n*3+7]<<endl;
        cout<<s[n]<<endl;

    }

}
