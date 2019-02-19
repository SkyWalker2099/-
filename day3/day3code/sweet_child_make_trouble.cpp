#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


int D[801][5000] = {0};
int len[801] = {0};



void initit(int i){
    /*
    int middle[500] = {0};
    int l == len[i-1]+len[i-2]-1;
    for(int k=0;k<len[i-1];k++)
        for(int j=0;j<len[i-2];j++)
           middle[i+j] += DD[k-1][i]*DD[k-2][j];
    for(int j=0;j<=l;j++){
        if(middle[k]>=0){
            middle[k+1]+=middle[k]/10;
            middle[k]%=10;
        }
    }

    if(middle[l+1]!=0){
        l++;
    }

    */
    int l = max(len[i-1],len[i-2]);
    for(int k=0;k<l;k++){
        D[i][k] += D[i-1][k]+D[i-2][k];
        if(D[i][k]>=10){
            D[i][k+1]+=D[i][k]/10;
            D[i][k]%=10;
        }
    }
    if(D[i][l]!=0){
        l++;
    }
   // cout<<"add: ";
   // for(int s=l-1;s>=0;s--){
   //     cout<<D[i][s];
    //}cout<<endl;

    int middle[5000] = {0};

    int g = i-1;
    for(int k=0;k<l;k++){
        D[i][k]*=g;
    }

    int aa = 0;
    while(g/10){
        aa++;
        g/=10;
    }

    for(int k=0;k<l+aa;k++){
        if(D[i][k]>=10){
            D[i][k+1] += D[i][k]/10;
            D[i][k]%=10;
        }
    }

    for(l=5000;l>=0;l--){
        if(D[i][l]!=0)
            break;
    }

    len[i] = l+1;;

    //for(int s=l;s>=0;s--){
    //        cout<<D[i][s];
    //    }cout<<endl;

}



void init(){

    for(int i=3;i<=800;i++){
         initit(i);
         //cout<<i<<"\t"<<len[i]<<endl;
        //cout<<"-----------------"<<endl;
    }

}

int main(){
memset(D,0,sizeof(D));
len[1] = 0;
D[1][0] = 0;
len[2] = 1;
D[2][0] = 1;
init();
//cout<<"finfished"<<endl;
int n;
while(cin>>n){
    if(n == -1)
    break;
    if(n == 1 || n == 0){
        cout<<0<<endl;
        continue;
    }
    for(int i = len[n]-1;i>=0;i--)
        cout<<D[n][i];

    cout<<endl;
}
return 0;
}
