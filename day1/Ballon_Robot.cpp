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
			cin>>num>>time; //�������
			//��λ����Ҫ��һ
			
			if(seat[num]<=time%m){
				need[seat[num]+m-time%m]++;
				total = total + (seat[num] - time%m +m)%m;
			}else{
				need[seat[num] -time%m]++;
				total = total + (seat[num] - time%m)%m;
			}
			
//			cout<<"����"<<
//			total = total + seat[num]%m; // �ܵ�ŭ�����ӣ�����տ�ʼλ�������һ�� 
		}
		
//		cout<<"�����totalֵΪ"<<total<<endl;
//		cout<<"���need"<<need[postion]<<endl; 
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
			
//			cout<<i<<"��"<<(total - cha*(p - need[postion]) + need[postion]*(postion%m+m-cha))<<endl;
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
