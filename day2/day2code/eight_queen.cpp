#include<iostream>
using namespace std;
int count=0;
int queen[8]={-1,-1,-1,-1,-1,-1,-1,-1};
bool available(int pointi,int pointj){//�ж�ĳ���ʺ��Ƿ������лʺ��ͻ
    for(int i=0;i<pointi;i++){
        if(pointi==i)return false;//ͬһ�оܾ�
        if(pointj==queen[i])return false;//ͬһ�оܾ�
        if((pointi-i)==(pointj-queen[i]))return false;//ͬһ���Խ��߾ܾ�
        if((pointi-i)+(pointj-queen[i])==0)return false;//ͬһ���Խ��߾ܾ�
    }
    return true;
}
int main(){
    int j=0;
    for(int i=0;i<8;i++){//����ÿһ��
        if(i==-1)break;//����������˳�ѭ���ĳ���
        for(;j<8;j++){
            if(available(i,j)){
                queen[i]=j;
                if(i==7){
                    count++;
                    if(j==7){//������һ�����һ���������ǰ����
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
