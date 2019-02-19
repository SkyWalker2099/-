#include<iostream>
#include<map>
using namespace std;
int main(){

long N;
cin>>N;
long n;
long total = 0;
int num[10005];
map<int, int> nn;
int st, en;
 bool flag = false;
 for(int k=1;k<=N;k++){

    cin>>num[k];

    if(flag){
        continue;
    }



    total+= num[k];
    int ss = total%N;

    if(ss == 0){

        st = 0;
        en = k;
        flag = true;
        continue;

    }

    if(nn[ss]!=0){
        st = nn[ss];
        en = k;
        flag = true;
    }else{
        nn[ss] = k;
    }

 }

 if(en == 0 && st == 0)
 cout<<0<<endl;
 else{
    cout<<en-st<<endl;
 for(int i=st+1;i<=en;i++)
    cout<<num[i]<<endl;
 }



return 0;
}
