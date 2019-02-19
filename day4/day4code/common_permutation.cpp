#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){

    string a;
    string b;
    char ans[1004];
    while(getline(cin, a)&& getline(cin,b)){

        int lena = a.length();
        int lenb = b.length();
        memset(ans,0,sizeof(ans));
        //cout<<lena<<" "<<lenb<<endl;
        int pos = lenb-1;
        int p = 0;
        for(int i= lena-1;i>=0;i--){
            if(a[i] == 32 ||(a[i]>='A' && a[i]<='Z'))
                continue;
            for(int j=lenb-1;j>=0;j--){
                if(b[j] == 32 ||(b[j]>='A' && b[j]<='Z'))
                    continue;
                    if(a[i] == b[j]){
                        ans[p++] = a[i];
                        b[j] = 32;
                        a[i] = 32;
                    }
                }
            }

        //cout<<endl;
        //cout<<ans<<endl;
        sort(ans, ans+p);
        cout<<ans<<endl;

    }



    return 0;
}
