#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int ind=1;
    while(1){
        int num[7] = {0};
        int total = 0;
        int start;
        for(int i=1;i<=6;i++){
            cin>>num[i];
            if(num[i]>=8){
                if(num[i]%2 == 0){
                    num[i] = 12;
                }else{
                    num[i] = 11;
                }
            }
            total+=i*num[i];
        }




        if(total == 0)
            break;
        if(total%2 != 0){

            cout<<"Collection #"<<ind++<<":"<<endl;
            cout<<"Can't be divided."<<endl<<endl;
            continue;
        }

        for(int i=1;i<=6;i++){
            if(num[i]!=0){
                start = i;
                break;
            }
        }
        //cout<<start<<endl;
        //cout<<num[start]<<endl;
        int price[20005] = {0};



        //cout<<endl<<"------------------------------"<<endl;

        for(int i=0;i<=num[start];i++){
            price[i*start]++;
            //cout<<i*start<<" ";
        }
        //cout<<endl;

        //cout<<endl;
        //cout<<endl<<"------------------------------"<<endl;
        for(int i=start+1;i<=6;i++){
            if(num[i] == 0)
            continue;

                for(int k=20000;k>=0;k--){
                        for(int j=0;j<=num[i];j++){
                    if(k-j*i>=0 && price[k-j*i]!=0){
                       price[k]++;
                    //cout<<k+j*i<<" ";
                    }
                }
            }

            //cout<<endl<<"----------------------"<<endl;
        }

        if(price[total/2] == 0){
            cout<<"Collection #"<<ind++<<":"<<endl;
            cout<<"Can't be divided."<<endl<<endl;
        }else{
            cout<<"Collection #"<<ind++<<":"<<endl;
            cout<<"Can be divided."<<endl<<endl;
        }

    }

}
