#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
class player{
	private:
		int num;			//玩家序号 
		bool ired;			//是否为红方 
		bool ideath;		//是否被放逐 
		int sumvote;		//得票 
		bool imanager;		//是否为村长 
		bool iopen;			//是否睁眼 
	public:
		void setnum(int n){
			num=n;
		}
		void setired(int n){
			ired=n;
		}
		void offnum(){
			cout<<num;
		}
		int offired(){
			if(ired==1)	return 1;
			else		return 0;	
		}
}peo[100];
int main(){
	srand((int)time(0));		//设定随机数 
	int pnum;
	cout<<"请输入玩家人数：";
	cin>>pnum;
	int nblk=pnum/2, nred=pnum/2;
	if(pnum%2==1)	nred++;
	int nb=nblk, nr=nred;
	for(int i=0; i<pnum; i++){
		peo[i].setnum(i+1);
	}
	for(int i=0; i<pnum; i++){
		int sc=rand()%100;
		sc%=2;
		if(sc==1){
			if(nr>0){
				peo[i].setired(1);
				nr--;
			}
			else{
				peo[i].setired(0);
				nb--;
			}
		}
		else if(sc==0){
			if(nb>0){
				peo[i].setired(0);
				nb--;
			}
			else{
				peo[i].setired(1);
				nr--;
			}
		}
	}
	cout<<endl;
	for(int i=0; i<pnum; i++){
		peo[i].offnum();
		if(peo[i].offired()==1)	cout<<" 红"<<endl;
		else if(peo[i].offired()==0)	cout<<" 黑"<<endl;
	}
	return 0;
}
