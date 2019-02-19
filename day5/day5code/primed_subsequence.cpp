#include<iostream>
#include<cmath>
using namespace std;
int maxn = 100000001;
int prime[100000001];
long long sum[10002] = {0};
int num[10001];
int u[100000001] = {0};
int main(){

int k = 0;
for(int i=2;i<=maxn;i++){
    if(u[i] == 0){
        prime[k++] = i;
       // for(int j = 2;j*i<=maxn;j++){
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

//for(int i=2;i<1000;i++)
  //  if(u[i] == 0)
 //   cout<<i<<" ";
cout<<1<<endl;
int t;
cin>>t;
while(t--){

    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){

        cin>>num[i];
        sum[i] = num[i]+sum[i-1];

    }

    int i,j;
    bool flag = false;
    for(i = 2;i<=n;i++){
        for(j=1;j<=n-i+1;j++){
            if(u[sum[j+i-1]-sum[j-1]]==0){

                //cout<<i<<" "<<j<<" "<<sum[j+i-1]-sum[j-1]<<endl;
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }

    if(flag){
        cout<<"Shortest primed subsequence is length "<<i<<":";
        for(int z=0;z<i;z++)
            cout<<" "<<num[j+z];
        cout<<endl;
    }else{
        cout<<"This sequence is anti-primed."<<endl;
    }

}

return 0;
}

