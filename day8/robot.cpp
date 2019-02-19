#include<iostream>
#include<string.h>
#include<string>
using namespace std;
struct Node{

 int x,y,s;
 int num;

};
int result;
Node node[300000];
int cur;
int len;
int n,m;
int map[51][51];
//int vis[51][51];
int visi[51][51][4];
int move[4][5][3] = {

    // ??????? x,y,???
    {{0,0,1},{0,0,3},{1,0,0},{2,0,0},{3,0,0}},  // ???0
    {{0,0,2},{0,0,0},{0,1,1},{0,2,1},{0,3,1}},  // ???1
    {{0,0,3},{0,0,1},{-1,0,2},{-2,0,2},{-3,0,2}}, // ???2
    {{0,0,0},{0,0,2},{0,-1,3},{0,-2,3},{0,-3,3}}  // ??? 3
};
int bx,by,ex,ey;
string fs;
int get_s(string s){
    if(s == "east")
        return 0;
    else if(s == "south")
        return 1;
    else if(s == "west")
        return 2;
    else
        return 3;
}
int cx,cy,cs,cnum;
int work(){

    node[0].x = bx;
    node[0].y = by;
    node[0].s = get_s(fs);
    //cout<<node[0].s<<" ??????"<<endl;
    node[0].num = 0;
    cur = 0;
    len = 1;
    visi[bx][by][node[0].s] = 1;
    while(1){
        cx = node[cur].x;
        cy = node[cur].y;
        cs = node[cur].s;
        cnum = node[cur].num;
        for(int i=0;i<5;i++){




            if(cx+move[cs][i][0] <1 || cy+ move[cs][i][1]<1 || cx+move[cs][i][0] >=m ||cy+move[cs][i][1] >=n){
                //cout<<"????"<<" x:"<<cx+move[cs][i][0]<<" y:"<<cy+ move[cs][i][1]<<endl;
                break;
            }





            if(visi[cx+move[cs][i][0]][cy+ move[cs][i][1]][move[cs][i][2]] == 1){
                continue;
            }

            if(map[cy+ move[cs][i][1]][cx+move[cs][i][0]] == 1)
                break;



            visi[cx+move[cs][i][0]][cy+ move[cs][i][1]][move[cs][i][2]] = 1;

            node[len].x = cx+move[cs][i][0];
            node[len].y = cy+move[cs][i][1];
            node[len].s = move[cs][i][2];
            node[len].num = cnum+1;

            if(cx+move[cs][i][0] == ex && cy+ move[cs][i][1] == ey){

           //cout<<"??? ??: "<<node[len].x<<" "<<node[len].y<<" ??:"<<node[len].s<<" num:"<<node[len].num<<endl;
                return cnum+1;
            }


                //cout<<"??? ??: "<<node[len].x<<" "<<node[len].y<<" ??:"<<node[len].s<<" num:"<<node[len].num<<endl;
               // ss[cnum+1] = 1;



            len++;


        }

       // vis[node[cur].x][node[cur].y] = 1;
        cur++;
        if(cur == len){
            break;
        }

    }

    return -1;
}


int main(){

while(cin>>n>>m){

    if(n+m == 0)
    break;

   // memset(vis,0,sizeof(vis));
    memset(map,0,sizeof(map));
    memset(visi,0,sizeof(visi));

    int temp;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        cin>>temp;
        if(temp == 1){
           map[i][j] = temp;
        map[i-1][j] = temp;
        map[i][j-1] = temp;
        map[i-1][j-1] = temp;
        }

    }
  /* cout<<"------------------------"<<endl;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++)
            cout<<map[i][j]<<" ";
        cout<<endl;
    }*/
    cin>>by>>bx>>ey>>ex>>fs;
    if(by == ey && bx == ex){
        cout<<0<<endl;
        continue;
    }

    cout<<work()<<endl;
    //cout<<len<<endl;
}
    return 0;
}
