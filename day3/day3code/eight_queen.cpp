#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
int chess[8][8];
int queen[8] = {0};
int total;
int maxn;
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
    //cout<<n<<endl;
    for(int i=0;i<8;i++){
        if(av(n,i)){
            queen[n] = i;
            total += chess[n][i];
            if(n == 7){
                maxn = max(maxn,total);
                total -= chess[n][i];
            }else{
                f(n+1);
                total -= chess[n][i];
            }
        }
    }
}
int main(){

    int k;
    cin>>k;
    while(k--){

        memset(chess, 0, sizeof(chess));
        for(int i=0;i<8;i++)
        for(int j=0;j<8;j++){
            cin>>chess[i][j];;
        }
        maxn = -1;
        total = 0;

        f(0);
        cout.width(5);
        cout<<maxn<<endl;

    }


}
