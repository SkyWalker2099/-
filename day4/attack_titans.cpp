#include<iostream>
using namespace std;
typedef long long ll;
ll dp[1000005][3];
ll mob = 1000000007;
int N,M,K;
ll solve(int n,int k){
	//cout<<n<<" "<<k<<endl;
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[0][2] = 0;
	for(int i=1;i<=N;i++){
		ll sum = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mob;
//		for(int j = 0;j<3;j++){			
//			if(j == 0){
//				dp[i][j] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mob;
//				
//			}else if(j == 1){
//				if(i <= n){
//					dp[i][j] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mob;
//				}else if(i == n+1){
//					dp[i][j] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2] - 1)%mob;
//				}else if(i>n+1){
//					dp[i][j] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2]-dp[i-n-1][0]-dp[i-n-1][2])%mob;
//				}
//			}else if(j == 2){
//				if(i <= k){
//					dp[i][j] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mob;
//				}else if(i == k+1){
//					dp[i][j] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2] - 1)%mob;
//				}else if(i>k+1){
//					dp[i][j] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2]-dp[i-k-1][0]-dp[i-k-1][1])%mob;
//				}
//			}
//			dp[i][j]%=mob;
//		}
		
		dp[i][0] = sum;
		
		if(i <= n){
					dp[i][1] = sum;
				}else if(i == n+1){
					dp[i][1] = sum-1;;
				}else if(i>n+1){
					dp[i][1] = (sum-dp[i-n-1][0]-dp[i-n-1][2]);
				}
		
		if(i <= k){
					dp[i][2] = sum;
				}else if(i == k+1){
					dp[i][2] = sum-1;
				}else if(i>k+1){
					dp[i][2] = (sum-dp[i-k-1][0]-dp[i-k-1][1]);
				}
		
	}
	
	return (dp[N][0]+dp[N][1]+dp[N][2])%mob;
}
int main(){
	
	while(cin>>N>>M>>K){
		
		if(N<M){
			cout<<0<<endl;
			continue;
		}
			
		
		int u = M-1;
		int v = K;
		ll ans1 = solve(u,v);
		u = N;
		ll ans2 = solve(u,v);
		cout<<((ans2-ans1)%mob+mob)%mob<<endl;
		
	}
	return 0;
} 
