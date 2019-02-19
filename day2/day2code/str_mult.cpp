#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
//char a[maxn + 5], b[maxn + 10];

string dp[901][901];
 


int x[maxn + 10], y[maxn + 10], z[maxn * 2 + 10];
string mult(string a, string b){
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    memset(z,0,sizeof(z));
    int len1 = a.length(), len2 = b.length();
	for(int j = 0, i = len1 - 1; i >= 0; i--) {
		x[j++] = a[i] - '0';
	}
	for(int j = 0, i = len2 - 1; i >= 0; i--) {
		y[j++] = b[i] - '0';
	}
	for(int i = 0; i < len1; i++) {
		for(int j = 0; j < len2; j++) {
			z[i + j] = z[i + j] + x[i] * y[j];
		}
	}
	for(int i = 0; i < maxn * 2; i++) {
		if(z[i] > 10) {
			z[i + 1] = z[i + 1] + z[i] / 10;
			z[i] = z[i] % 10;
		}
	}
	int i;
	for(i = maxn * 2; i > 0; i--) {
		if(z[i] == 0) {
			continue;
		}
		else break;
	}
	string result = "";
	for(;i >= 0; i--) {
		//printf("%d", z[i]);
		char ss = '0'+z[i];
		result.append(1,ss);
	}
	return result;

}

string add(string a, string b){

    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    memset(z,0,sizeof(z));
    int len1 = a.length(), len2 = b.length();
	for(int j = 0, i = len1 - 1; i >= 0; i--) {
		x[j++] = a[i] - '0';
	}
	for(int j = 0, i = len2 - 1; i >= 0; i--) {
		y[j++] = b[i] - '0';
	}

    int len = max(len1, len2);
    for(int i=0;i<len;i++){
        int t = x[i]+y[i]+z[i];
        z[i] = t%10;
        z[i+1] = t/10;
    }


	int i;
	for(i = maxn * 2; i > 0; i--) {
		if(z[i] == 0) {
			continue;
		}
		else break;
	}
	string result = "";
	for(;i >= 0; i--) {
		//printf("%d", z[i]);
		char ss = '0'+z[i];
		result.append(1,ss);
	}
	return result;

}

void init(){
	
	memset(dp,0,sizeof(dp));
	for(int i=1;i<maxn;i++){
		dp[1][i] = "0";
		dp[i][1] = "1";
	}
	
	for(int i=2;i<maxn;i++)
	for(int j=2;j<=i;j++){
		
		string jstr = "";
		jstr.append(1,'0'+j);
//		dp[i][j] = dp[i-1][j-1] +dp[i-1][j]*j;
		dp[i][j] = add(dp[i-1][j-1], mult(dp[i-1][j],jstr));
		
	}
	
//	for(int i=1;i<maxn;i++){
//		
//		for(int j=1;j<maxn;j++)
//			cout<<dp[i][j]<<" ";
//		cout<<endl;
//	}
	
} 

int main () {
     
    init();



	return 0;
}
