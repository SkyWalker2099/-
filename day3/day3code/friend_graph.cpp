#include<iostream>
#include<string.h>
using namespace std;
int main(){

//int rel[3001][3001];
int num[3001];
int t;
cin>>t;
while(t--){

    memset(num,0, sizeof(num));
    int n;
    int temp;
    cin>>n;
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=n-i;j++)
    {
        cin>>temp;
        if(temp == 1){
            num[i]++;
            num[i+j]++;
        }
    }


    bool flag = false;
    if(n>=6){
        cout<<"Bad Team!"<<endl;
        continue;
    }else if(n == 5){
        for(int i=1;i<=n;i++){
            if(num[i]!=2){
                flag = true;
                break;
            }
        }
    }else if(n == 4){
        for(int i=1;i<=n;i++){
            if(num[i]==3 ||  num[i] == 0){
                flag = true;
                break;
            }
        }
    }else if(n == 3){
        for(int i=1;i<=n;i++){
            if(num[i]==2 || num[i] == 0){
                flag = true;
            }else {
                flag = false;
                break;
            }
        }
    }else if(n<=2){
        flag = false;;
    }

    if(!flag){

        cout<<"Great Team!"<<endl;

    }else{
        cout<<"Bad Team!"<<endl;
    }



}


}
