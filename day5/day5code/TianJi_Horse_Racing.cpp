#include<iostream>
#include<algorithm>
using namespace std;
int main(){

    int h1[1001];
    int h2[1001];
    int n;
    while(cin>>n){

        if(n == 0){
            break;
        }

        for(int i=1;i<=n;i++)
            cin>>h1[i];
        sort(h1+1,h1+n+1);

        for(int j=1;j<=n;j++)
            cin>>h2[j];
        sort(h2+1,h2+n+1);


      /*  for(int i=1;i<=n;i++)
            cout<<h1[i]<<" ";
        cout<<endl;
        for(int i=1;i<=n;i++)
            cout<<h2[i]<<" ";
        cout<<endl;
        */

        int h1n = n;
        int h2n = n;
        int h11 = 1;
        int h21 = 1;
        int result = 0;
        while(h1n>=h11 && h2n>=h21){

            if(h1[h11] > h2[h21]){
                result += 200;
                h11++;
                h21++;
                continue;
            }

            if(h1[h11] < h2[h21]){
                result -= 200;
                h11++;
                h2n--;
                continue;
            }


            if(h1[h1n] > h2[h2n]){
                result += 200;
                h1n--;
                h2n--;
                continue;
            }

            if(h1[h1n] < h2[h2n]){
                result -= 200;
                h11++;
                h2n--;
                continue;
            }

            if(h1[h11]<h2[h2n]){
                result -= 200;
                h11++;
                h2n--;
            }else if(h1[h11] == h2[h2n]){
                h11++;
                h2n--;
            }

        }

        cout<<result<<endl;


    }

}
