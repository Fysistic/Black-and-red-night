#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
class player{
	private:
		int num;			//玩家序号 
		bool ired;			//是否为红方 
		bool ideath;		//是否被放逐 
		float svote;			//得票 
		float gvote;			//可用票数 
		bool imanager;		//是否为村长 
		bool iopen;			//是否睁眼 
	public:
		void setnum(int n){		//序号操作 
			num=n;
		}
		void printnum(){
			cout<<num;
		}
		void setired(int n){		//阵营操作 
			ired=n;
		}
		int printired(){
			if(ired==1)	return 1;
			else		return 0;	
		}
		void setsvote(float n){		//得票操作 
			svote=n;
		}
		float printsvote(){
			return svote;
		} 
		void setgvote(float n){		//有票操作 
			gvote=n;
		}
		float printgvote(){
			return gvote;
		}
		void setiman(){		//村长身份操作 
			imanager=1;
		}
		int getiman(){
			if(imanager==1)	return 1;
			else			return 0;
		}
}peo[100];
void prepare(int pnum){				//确认身份
	for(int i=0; i<pnum; i++){
		cout<<"||------------------------------||"<<endl;	//length=34 
		cout<<"||         确认身份阶段         ||"<<endl;
		cout<<"||------------------------------||"<<endl;
		cout<<"player"; peo[i].printnum(); cout<<endl;
		cout<<"你的身份是：";
		if(peo[i].printired()==1)	cout<<"红方";
		else					cout<<"黑方";
		cout<<endl<<"请输入： 1-确认"<<endl; 
		int is; cin>>is;
		system("cls"); 
	}
}
void speech1(int pnum){				//首次发言 
	for(int i=0; i<pnum; i++){
		cout<<"||------------------------------||"<<endl; 
		cout<<"||         竞选村长阶段         ||"<<endl;
		cout<<"||------------------------------||"<<endl;
		cout<<"player"; peo[i].printnum(); cout<<endl;
		cout<<"请输入： 1-发言结束"<<endl;
		int is; cin>>is;
		system("cls");
	}
}
void speech2(int pnum, int mnum, bool dirn){		//正常发言 
	int i=mnum;
	if(dirn==1){		//村长之右 增 
		for(; i<pnum; i++){
			cout<<"||------------------------------||"<<endl; 
			cout<<"||           发言阶段           ||"<<endl;
			cout<<"||------------------------------||"<<endl;
			cout<<"player"; peo[i].printnum(); cout<<endl;
			cout<<"请输入： 1-发言结束"<<endl;
			int is; cin>>is;
			system("cls");
		}
		for(int i=0; i<=mnum; i++){
			cout<<"||------------------------------||"<<endl; 
			cout<<"||           发言阶段           ||"<<endl;
			cout<<"||------------------------------||"<<endl;
			cout<<"player"; peo[i].printnum(); cout<<endl;
			cout<<"请输入： 1-发言结束"<<endl;
			int is; cin>>is;
			system("cls");
		}
	}
	else if(dirn==0){		//村长之左 减 
		i-=2;
		for(; i>=0; i--){
			cout<<"||------------------------------||"<<endl; 
			cout<<"||           发言阶段           ||"<<endl;
			cout<<"||------------------------------||"<<endl;
			cout<<"player"; peo[i].printnum(); cout<<endl;
			cout<<"请输入： 1-发言结束"<<endl;
			int is; cin>>is;
			system("cls");
		}
		for(int i=pnum-1; i>=mnum-1; i--){
			cout<<"||------------------------------||"<<endl; 
			cout<<"||           发言阶段           ||"<<endl;
			cout<<"||------------------------------||"<<endl;
			cout<<"player"; peo[i].printnum(); cout<<endl;
			cout<<"请输入： 1-发言结束"<<endl;
			int is; cin>>is;
			system("cls");
		}
	} 
}
void vote(int pnum){		//投票		//需重做
	int getik[100]; 
	for(int i=0; i<pnum; i++)	getik[i]=0; 	//票数重置 
	for(int i=0; i<pnum; i++){
		cout<<"||------------------------------||"<<endl; 
		cout<<"||           投票阶段           ||"<<endl;
		cout<<"||------------------------------||"<<endl;
		cout<<"player"; peo[i].printnum(); cout<<endl;
		cout<<"你拥有的票数："<<peo[i].printgvote()<<endl; 
		cout<<"请输入： 0-弃票  1~"<<pnum<<"-对应序号的人"<<endl;
		int is; cin>>is;
		getik[is]+=peo[i].printgvote();
		system("cls");
	}
	for(int i=0; i<pnum; i++){
		peo[i].setsvote(getik[i]);
	}
}
void ticket(int maxp, int pnum, int night){		//设定票数 		maxp：最初人数 
	for(int i=0; i<pnum; i++){
		if(peo[i].getiman()==1){
			if(night==1){		//红夜红偶or黑夜黑偶 
				peo[i].setgvote(1); 
			}
			else if(night==0&&maxp%2==1){
				peo[i].setgvote(0.5);
			}
			else if(night==0&&maxp%2==0){
				peo[i].setgvote(1.5);
			}
		}
		else{
			peo[i].setgvote(1);
		}
	}
}
int main(){
	srand((int)time(0));		//设定随机数
	cout<<"||------------------------------||"<<endl; 
	cout<<"||            红黑夜            ||"<<endl;
	cout<<"||------------------------------||"<<endl; 
	int pnum;
	cout<<"请输入玩家人数：";
	cin>>pnum;
	system("cls"); 					//窗口刷新 
	int nblk=pnum/2, nred=pnum/2;
	if(pnum%2==1)	nred++;			//nblk:黑方人数 nred:红方人数 pnum:现存玩家数 
	int nb=nblk, nr=nred;
	for(int i=0; i<pnum; i++){		//赋值序号 
		peo[i].setnum(i+1);
	}
	int as[100];					//获取随机数 
	for(int i=0; i<pnum; i++){
		as[i]=rand()%pnum;
	}
	for(int i=0; i<pnum; i++){
		for(int j=0; j<pnum; j++){
			if(i==j)	continue;
			if(as[i]==as[j]){
				as[i]=rand()%pnum;
				i--;
				break;
			}
		}
	}
	for(int i=0; i<pnum; i++)	as[i]+=1;
	for(int i=0; i<pnum; i++){		//获取身份 
		as[i]%=2;
		if(as[i]==1){
			if(nr>0){
				peo[i].setired(1);
				nr--;
			}
			else{
				peo[i].setired(0);
				nb--;
			}
		}
		else if(as[i]==0){
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
	prepare(pnum);		//确认身份 
	speech1(pnum);		//首次发言
	ticket(0,pnum,0);		//设定票数 
	vote(pnum);			//票选村长
	int man1=0, man2=0;
	for(int i=0; i<pnum; i++){	//首次计票 
		if(peo[i].printsvote()>man1){
			man1=peo[i].printsvote();
			man2=i;
		}
	}
	cout<<"player"<<man2<<"被选为村长   得票："<<man1<<endl;
	peo[man2-1].setiman();
	int maxp=pnum, night;	//maxp：初始人数   //night：1-特殊情况， 0-正常情况
	//////////////数据测试 
	night=1;				
	ticket(maxp,pnum,night);
	vote(pnum);
	/////////////
	return 0;
}
