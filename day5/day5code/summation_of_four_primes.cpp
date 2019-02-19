#include<iostream>
#include<cmath>
using namespace std;
int maxn = 10000002;
int prime[10000002];
int u[10000002] = {0};
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

    //if(n == 0){
    //    break;
   // }

   if(n<8){
    cout<<"Impossible."<<endl;
    continue;
   }

   if(n%2 == 0){
    cout<<2<<" "<<2<<" ";
    n-=4;
   }else{
    cout<<2<<" "<<3<<" ";
    n-=5;
   }

    //bool flag = false;
    for(int i=0;i<k;i++){
        if(u[n-prime[i]] == 0){
            cout<<prime[i]<<" "<<n-prime[i]<<endl;
            //flag = true;
            break;
        }
    }
    //if(!flag){
   //     cout<<"Goldbach's conjecture is wrong."<<endl;
   // }

}

return 0;
}
