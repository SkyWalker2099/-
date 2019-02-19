#include<iostream>
#include<string.h>
#include<cmath>
#include<stdio.h>
using namespace std;
int queen[8] = {0};
int qi,qj;
int indexx;
void show(){
    cout<<"------------------------"<<endl;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(j == queen[i])
                cout<<1<<" ";
            else cout<<0<<" ";
        }cout<<endl;
    }
    cout<<"----------------------------"<<endl;

}

bool q2q(int i,int j){
    if(i == j || queen[i] == queen[j])
        return true;
    if(abs(i-j) == abs(queen[i]-queen[j]))
        return true;
    return false;
}
bool av(int n,int p){
    for(int i=0;i<n;i++){
        queen[n] = p;
        if(q2q(n,i)){
            return false;
        }
    }
    return true;
}
void f(int n){

    if(n == qi){
        queen[n] = qj;
        if(av(n,qj)){
            if(n == 7){

               // cout<<" "<<indexx++<<"\t";
                printf("%2d     ",indexx++);
                for(int i=0;i<8;i++){
                    //if(i)
                    cout<<" ";
                    cout<<queen[i]+1;
                }
                cout<<endl;
                //show();
                return;
            }else{
                f(n+1);
                return;
            }
        }else{
            return;
        }
    }
    for(int i=0;i<8;i++){
        if(av(n,i)){
            queen[n] = i;

            if(n == 7){
                //cout<<" "<<indexx++<<"\t";
                printf("%2d     ",indexx++);
                for(int i=0;i<8;i++){
                    //if(i)
                    cout<<" ";
                    cout<<queen[i]+1;
                }

                cout<<endl;
                //show();
            }else{
                f(n+1);
            }
        }
    }
}
int main(){

    int k;
    cin>>k;
    while(k--){

        cin>>qi>>qj;
        swap(qi,qj);
        qi--;
        qj--;
        indexx = 1;
        cout<<"SOLN       COLUMN"<<endl;
        cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
        f(0);
        if(k)
        cout<<endl;
    }

 return 0;
}
