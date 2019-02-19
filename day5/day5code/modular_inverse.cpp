#include<iostream>
using namespace std;
int exgcd(int a, int b,int &x, int &y){

    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int t=exgcd(b,a%b,x,y);
    int x0=x,y0=y;
    x=y0;
    y=x0-(a/b)*y0;
    return t;

}
int main(){

    int t;
    cin>>t;
    while(t--){

        int a,m;
        cin>>a>>m;
        if(m == 1){
           cout<<"Not Exist"<<endl;
            continue;
       }
        int x=0,y=0;
        if(exgcd(a,m,x,y) != 1){
            cout<<"Not Exist"<<endl;
        }else{
            if(x<=0)
                x+=m;
            cout<<x<<endl;
           // cout<<x*a<<endl;
        }


    }

}
