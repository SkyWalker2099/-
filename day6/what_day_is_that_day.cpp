#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long ll;
ll pow(int n,int k){
    n%=7;
    ll result = 1;
    while(k --){
        result*=n;
        result%=7;
    }

    return result;

}
int main(){

    int num[295] = {0,
1,5,11,15,18,19,19,20,21,25,27,28,34,34,35,37,42,43,48,49,49,50,54,55,59,63,69,69,70,71,74,76,82,83,83,84,86,88,89,91,97,97,98,102,108,112,115,116,116,117,118,122,124,125,131,131,132,134,139,140,145,146,146,147,151,152,156,160,166,166,167,168,171,173,179,180,180,181,183,185,186,188,194,194,195,199,205,209,212,213,213,214,215,219,221,222,228,228,229,231,236,237,242,243,243,244,248,249,253,257,263,263,264,265,268,270,276,277,277,278,280,282,283,285,291,291,292,296,302,306,309,310,310,311,312,316,318,319,325,325,326,328,333,334,339,340,340,341,345,346,350,354,360,360,361,362,365,367,373,374,374,375,377,379,380,382,388,388,389,393,399,403,406,407,407,408,409,413,415,416,422,422,423,425,430,431,436,437,437,438,442,443,447,451,457,457,458,459,462,464,470,471,471,472,474,476,477,479,485,485,486,490,496,500,503,504,504,505,506,510,512,513,519,519,520,522,527,528,533,534,534,535,539,540,544,548,554,554,555,556,559,561,567,568,568,569,571,573,574,576,582,582,583,587,593,597,600,601,601,602,603,607,609,610,616,616,617,619,624,625,630,631,631,632,636,637,641,645,651,651,652,653,656,658,664,665,665,666,668,670,671,673,679,679};;
    int total = 0;
    total = num[294];
    total%=7;



    //cout<<"finished"<<endl;
    int t;
    cin>>t;
    string ss[7] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};

    while(t--){

        ll n;
        scanf("%lld",&n);

        int result = 0;
        int m = n/294;
        result += m*total;

        n%=294;
        result += num[n];

        result%=7;
        //cout<<result<<endl;
        //cout<<ss[result]<<endl;
        printf("%s\n",ss[result].c_str());

    }


}