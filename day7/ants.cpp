#include<iostream>
using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){

        int n,m;
        int latest = -1;
        int earliest = -1;
        cin>>n>>m;
        int temp;
        for(int i = 0;i<m;i++){
            cin>>temp;
            int b = max(n-temp,temp);
            int s = min(n-temp,temp);
            if(b>latest)
                latest = b;

            if(s>earliest)
                earliest = s;
        }

        cout<<earliest<<" "<<latest<<endl;


    }

    return 0;
}
