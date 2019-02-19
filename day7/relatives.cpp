#include<iostream>
using namespace std;
typedef long long ll;
int u[1000000] = {0};

bool itis(ll n){

    if(n == 1 || n == 0)
        return false;


    for(int i=2;i*i<=n;i++){
        if(n%i == 0)
            return false;
    }

    return true;
}

ll pow(int n,int k){

    ll result = 1;
    while(k--)
        result*=n;
    return result;

}

int main(){
    int i;
    u[1] = 1;
    for(int i = 2;i<1000000;i++){

        if(u[i] == 0){
           // cout<<i<<endl;
            for(int j=2;i*j<1000000;j++){
                u[i*j] = 1;
            }
        }

    }

    ll result;
    ll n;
    while(cin>>n){

        if(n == 0)
            break;

        result = 1;
        int st;

        if((n<1000000 && u[n] == 0)||itis(n)){
            cout<<n-1<<endl;
            continue;
        }

        for(st=2;st<=n/2;st++){
            //cout<<st<<endl;
            if(u[st] == 0 && n%st == 0){
                int ecount = 0;
                while(n%st == 0){
              //      cout<<" "<<st<<endl;
                    ecount++;
                    //result *=(st-1);
                    n/=st;
                }
               // cout<<ecount<<endl;
                result*=(st-1)*pow(st,ecount-1);
                //cout<<"result:"<<result<<endl;
                if((n<1000000 && u[n] == 0)||itis(n)){
                //    cout<<" "<<n<<endl;
                    result*=(n-1);
                  //  cout<<"result:"<<result<<endl;
                    break;
                }
            }
        }

        cout<<result<<endl;

    }

    return 0;
}
