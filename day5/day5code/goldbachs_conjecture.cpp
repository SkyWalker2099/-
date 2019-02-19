#include<iostream>
#include<cmath>
using namespace std;
int maxn = 1000002;
int prime[1000002];
int u[1000002] = {0};
int main(){

///int maxn = 100002;
///int prime[100002];
///int u[100002] = {0};
int k = 0;
//cout<<k<<endl;
for(int i=2;i<=maxn;i++){
    if(u[i] == 0){
        prime[k++] = i;
        for(int j = 2;j*i<=maxn;j++){
            u[i*j] = 1;
        }
    }
}
//cout<<k<<endl;
///for(int i=0;i<k;i++)
  //  cout<<prime[i]<<" ";

int n;
while(cin>>n){

    if(n == 0){
        break;
    }
    bool flag = false;
    for(int i=0;i<k;i++){
        if(u[n-prime[i]] == 0){
            cout<<n<<" = "<<prime[i]<<" + "<<n-prime[i]<<endl;
            flag = true;
            break;
        }
    }
    if(!flag){
        cout<<"Goldbach's conjecture is wrong."<<endl;
    }

}

return 0;
}
