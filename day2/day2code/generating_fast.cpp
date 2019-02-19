#include<iostream>
#include<string>
using namespace std;
int main(){

int t;
string str;
cin>>t;
while(t--){
    cin>>str;
    int len = str.length();
    for(int n = len-1;n>0;n--)
            for(int m =0;m<n;m++)
                    if(str[m]>str[m+1])
                        swap(str[m],str[m+1]);
    cout<<str<<endl;

    while(1){


        int i;
    bool flag = true;
    for(i = len-1;i>=1;i--){
        if(str[i-1]>=str[i]){
            continue;
        }else{
            flag = false;
            break;
        }
    }

    if(flag){
        break;
    }
    int j;
    for(j = len-1;j>=i;j--){
        if(str[j]>str[i-1]){
            swap(str[j],str[i-1]);

            for(int n = len-1;n>i;n--)
                for(int m =i;m<n;m++)
                    if(str[m]>str[m+1])
                        swap(str[m],str[m+1]);
            cout<<str<<endl;
            break;
        }

    }

    }

    cout<<endl;
}

}
