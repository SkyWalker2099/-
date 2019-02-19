#include<iostream>
using namespace std;
int count=0;
int queen[8]={-1,-1,-1,-1,-1,-1,-1,-1};
bool available(int pointi,int pointj){//判断某个皇后是否与已有皇后冲突
    for(int i=0;i<pointi;i++){
        if(pointi==i)return false;//同一行拒绝
        if(pointj==queen[i])return false;//同一列拒绝
        if((pointi-i)==(pointj-queen[i]))return false;//同一主对角线拒绝
        if((pointi-i)+(pointj-queen[i])==0)return false;//同一副对角线拒绝
    }
    return true;
}
int main(){
    int j=0;
    for(int i=0;i<8;i++){//对于每一行
        if(i==-1)break;//这才是真正退出循环的出口
        for(;j<8;j++){
            if(available(i,j)){
                queen[i]=j;
                if(i==7){
                    count++;
                    if(j==7){//如果最后一行最后一格试完就往前回溯
                        j=queen[--i];
                        j++;
                        queen[i]=-1;
                        i--;
                        break;
                    }
                    else
                        continue;
                }
                j=0;
                break;
            }
            else
                if(i==7&&j==7){
                    j=queen[--i];
                    j++;
                    queen[i]=-1;
                    i--;
                    break;
                }
        }
        if(j==8){
                j=queen[--i];
                j++;
                queen[i]=-1;
                i--;
        }
    }
    cout<<count<<endl;
    return 0;
}
