#include<iostream>
#include<map>
using namespace std;
int main(){
	
	
	int seat[100005];
	int t;
	cin>>t;
	while(t--){
		int num,time;
		long min_total;
		long total = 0;
		int postion;
		map<long,int> need;
		map<long,int>::iterator it;
		int n,p;
		long m;
		cin>>n>>m>>p;
		postion = m;
		for(int i=1;i<=n;i++)
		cin>>seat[i];
		
		for(int i=1;i<=p;i++){
			cin>>num>>time; //队伍号码
			//该位置需要加一
			
			if(seat[num]<=time%m){
				need[seat[num]+m-time%m]++;
				total = total + (seat[num] - time%m +m)%m;
			}else{
				need[seat[num] -time%m]++;
				total = total + (seat[num] - time%m)%m;
			}
			
//			cout<<"增加"<<
//			total = total + seat[num]%m; // 总的怒气增加，假设刚开始位置在最后一个 
		}
		
//		cout<<"在最大处total值为"<<total<<endl;
//		cout<<"最大处need"<<need[postion]<<endl; 
		min_total = total;
//		for(long i = 1; i<m;i++){
			
		for(it = need.begin(); it!= need.end(); it++){
		
//			if(need[i]==0)
//			continue;
//			cout<<"-----------"<<endl;
//			cout<<i<<" "<<need[i]<<endl; 
//			cout<<"-----------"<<endl;
			long i = it -> first;
			
			int cha;
			if(i<postion){
				cha = i;
			}else{
				cha = i-postion;
			}
			
//			cout<<i<<"处"<<(total - cha*(p - need[postion]) + need[postion]*(postion%m+m-cha))<<endl;
//			
//			cout<<"cha:"<<cha<<" need:"<<need[i]<<" needp:"<<postion<<" "<<need[postion]<<endl;
//			cout<<"-------------------"<<endl; 
			
			if(min_total>(total - cha*(p - need[postion]) + need[postion]*(postion%m+m-cha))){
				
				min_total = (total - cha*(p - need[postion]) + need[postion]*(postion%m+m-cha));
				 
			}
			total = (total - cha*(p - need[postion]) + need[postion]*(postion%m+m-cha));
			postion = i;
		} 
		
		cout<<min_total<<endl;
//	cout<<"________________________________________________________________"<<endl;	 
		
	}
	return 0;
} 
