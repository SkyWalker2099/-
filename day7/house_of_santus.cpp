#include<iostream>
using namespace std;
int p[6][6] = {0,0,0,0,0,0,
                0,0,1,1,0,1,
                0,1,0,1,0,1,
                0,1,1,0,1,1,
                0,0,0,1,0,1,
                0,1,1,1,1,0};
int has[6][6] = {0};
int floor = 0;
int text[9];
void f(int n){

    for(int i=1;i<=5;i++){
        if(p[n][i] && has[n][i] == 0 && has[i][n] == 0){
            text[floor] = i;
            floor++;
            has[n][i] = 1;
            has[i][n] = 1;
                if(floor == 9){
                    for(int i=0;i<=8;i++)
                        cout<<text[i];
                    cout<<endl;
                    }else{

                        f(i);
                    }
            floor--;
            text[floor] = 0;
            has[n][i] = 0;
            has[i][n] = 0;
        }
    }

}

int main(){



    floor = 1;
     /*for(int i=1;i<=5;i++){




        text[0] = i;
        f(i);
    } */
    text[0] = 1;
    f(1);

    cin>>floor;

    return 0;

}
