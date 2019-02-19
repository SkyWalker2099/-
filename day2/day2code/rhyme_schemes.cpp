//#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
const int maxn = 100;
//char a[maxn + 5], b[maxn + 10];
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

string jian1(string n){


    int len = n.length();



    while(1){
        if(n[len-1] >= '1'){
            n[len-1] = n[len-1] - 1;
            break;
        }else{

            n[len-1] = '9';
            len--;
        }
    }

    return n;
}

/*int S(int n, int k){

    if(n == k||k == 1)
        return 1;

    return S(n-1,k-1) + k*S(n-1,k);

}*/

string int2str(int n){

    memset(z,0,sizeof(z));
    int i=0;
    while(n){
        z[i++] = n%10;
        n = n/10;
    }

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

string S(string n, string k){

    if(n == k||k == "1")
        return "1";

    ///return S(n-1,k-1) + k*S(n-1,k);
    return add(S(jian1(n),jian1(k)), mult(k,S(jian1(n),k)));

}
int main () {
     int n;
     while(cin>>n){


        string total = "0";
        string num = int2str(n);
        cout<<num<<endl;
        for(int k=1;k<=n;k++){

            string knum = int2str(k);
            cout<<knum<<endl;
            total = add(total, S(num, knum));
            cout<<total<<endl;
        }

       cout<<total<<endl;
     }

	return 0;
}

