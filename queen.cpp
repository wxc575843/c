//爬山发解决皇后问题
#include<string.h> 
#include<stdlib.h> 
#include<time.h> 
#include<iostream> 
using namespace std;
const int size=1000000; 
int board[size],ru[size*2],rd[size*2],n;

int f(){//统计对角线需要调整的皇后数
	int i,r=0; 
	memset(ru,0,sizeof(ru)); 
	memset(rd,0,sizeof(rd)); 
	for(i=0;i<n;i++){ 
		ru[board[i]-i+n-1]++; //负对角线
		rd[board[i]+i]++; //正对角线
	} 
	for(i=0;i<2*n-1;i++){ 
		if(ru[i]>1) r+=ru[i]-1; 
		if(rd[i]>1) r+=rd[i]-1; 
	} 
	return r;
} 

void randgen(){ // 随即生成全排列
	for(int i=0;i<n;++i)
		board[i]=i;
	for(int i=0;i<n;++i){
		int pos=rand()%n;
		swap(board[i],board[pos]);
	}
} 

int main(){ 
	srand((unsigned)time(NULL)); 
	int i,j,temp,now,t1,t2,fnow; 
	while(cin>>n){
		if(n==2 || n==3){
			cout<<"No answer"<<endl;
			continue;
		}
		while(1){ 
			randgen(); 
			now=f(); 
		label:
			if(now==0) 
				break;
			//尝试通过交换减少需要调整皇后数
			for(i=0;i<n-1;i++){ 
				for(j=i+1;j<n;j++){ 
					int fnow=now;
					--ru[board[i]-i+n-1];
					if(ru[board[i]-i+n-1])
						--fnow;
					--rd[board[i]+i];
					if(rd[board[i]+i])
						--fnow;
					++ru[board[i]-j+n-1];
					if(ru[board[i]-j+n-1]>1)
						++fnow;
					++rd[board[i]+j];
					if(rd[board[i]+j]>1)
						++fnow;
					--ru[board[j]-j+n-1];
					if(ru[board[j]-j+n-1])
						--fnow;
					--rd[board[j]+j];
					if(rd[board[j]+j])
						--fnow;
					++ru[board[j]-i+n-1];
					if(ru[board[j]-i+n-1]>1)
						++fnow;
					++rd[board[j]+i];
					if(rd[board[j]+i]>1)
						++fnow;
					swap(board[i],board[j]);
					if(fnow<now){
						now=fnow;
						goto label;
					}
					swap(board[i],board[j]);
					--rd[board[j]+i];
					--ru[board[j]-i+n-1];
					++rd[board[j]+j];
					++ru[board[j]-j+n-1];
					--rd[board[i]+j];
					--ru[board[i]-j+n-1];
					++rd[board[i]+i];
					++ru[board[i]-i+n-1];
				} 
			} 
		} 
		cout<<"("<<board[0]+1;
		for(int i=1;i<n;++i){
			cout<<","<<board[i]+1;
		}
		cout<<")"<<endl;
	}
	return 0; 
} 