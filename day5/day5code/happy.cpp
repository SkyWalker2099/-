#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
typedef long long ll;
int GCD(int a, int b){

    if(a == 0)
        return b;
    else
        return GCD(b%a, a);

}
int num[1000001];
int main(){

    int m,k;
    //cout<<GCD(2006,2007)<<endl;
    while(cin>>m>>k){

        //memset(u,0,sizeof(u));
        //memset(num,0,sizeof(num));
        int total = 0;
        for(int i=1;i<=m;i++)
            if(GCD(i,m) == 1){
                //u[i] = 1;
               	total++;
                num[total] = i;
            }
		//cout<<total<<endl;
		 
 
//        if(k>total && total !=0){
//            s = k/total;
//            k%=total;
//        }

        if(k%total == 0){
        	cout<<(k/total-1)*m+num[total]<<endl;
		}else{
			cout<<(k/total)*m+num[k%total]<<endl;
		}

    }

}
