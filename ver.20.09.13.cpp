#include<iostream>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>
#include<iomanip>
#include<cstring>
using namespace std;
class player{
	private:
		int num;			//玩家序号 
		bool ired;		//是否为红方 
		bool ideath;		//是否被放逐 
		float svote;		//得票 
		float gvote;		//可用票数 
		bool imanager;		//是否为村长 
		bool iopen;		//是否睁眼
	public:
		void setnum(int n){		//序号操作 
			num=n;
		}
		void printnum(){
			cout<<num;
		}
		int getnum(){
			return num;
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
void inputcheck1(){			//输入检测I型 
	int n; cin>>n;
	if(n!=1){
		cout<<"非法输入！"<<endl<<"请重新输入：";
		inputcheck1(); 
	}
}
int inputcheck2(int pnum){		//输入检查II型 
	int n; cin>>n; bool exi=0;
	for(int i=0; i<pnum; i++){
		if(peo[i].getnum()==n){
			exi=1;
			break;
		}
	}
	if(exi==0&&n!=0){
		cout<<"非法输入！"<<endl<<"请重新输入：";
		inputcheck2(pnum); 
	}
	else return n;
}
int inputcheck3(){		//输入检测III型 
	int n; cin>>n;
	if(n!=1&&n!=2){
		cout<<"非法输入！"<<endl<<"请重新输入：";
		inputcheck3();
	}
	else return n;
}
int inputcheck4(){
	int n; cin>>n;
	if(n<=3){
		cout<<"人数过少，请重新输入：";
		inputcheck4(); 
	} 
	else if(n>=100){
		cout<<"人数过多，请重新输入：";
		inputcheck4();
	}
	else return n;
}
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
		inputcheck1();
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
		inputcheck1();
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
			inputcheck1();
			system("cls");
		}
		for(int i=0; i<mnum; i++){
			cout<<"||------------------------------||"<<endl; 
			cout<<"||           发言阶段           ||"<<endl;
			cout<<"||------------------------------||"<<endl;
			cout<<"player"; peo[i].printnum(); cout<<endl;
			cout<<"请输入： 1-发言结束"<<endl;
			inputcheck1();
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
			inputcheck1();
			system("cls");
		}
		for(int i=pnum-1; i>=mnum-1; i--){
			cout<<"||------------------------------||"<<endl; 
			cout<<"||           发言阶段           ||"<<endl;
			cout<<"||------------------------------||"<<endl;
			cout<<"player"; peo[i].printnum(); cout<<endl;
			cout<<"请输入： 1-发言结束"<<endl;
			inputcheck1();
			system("cls");
		}
	} 
}
void vote(int pnum){		//投票		//需重做
	float getik[100]; 
	for(int i=0; i<pnum; i++)	getik[i]=0.0; 	//票数重置 
	for(int i=0; i<pnum; i++){
		cout<<"||------------------------------||"<<endl; 
		cout<<"||           投票阶段           ||"<<endl;
		cout<<"||------------------------------||"<<endl;
		cout<<"player"; peo[i].printnum(); cout<<endl;
		cout<<"你拥有的票数："<<peo[i].printgvote()<<endl; 
		cout<<"请输入： 0-弃票  ";
		for(int j=0; j<pnum; j++){
			peo[j].printnum();
			if(j!=pnum-1)	cout<<" ";
		}
		cout<<"-对应序号的玩家"<<endl;		//投票给序号为is的玩家 
		int is; is=inputcheck2(pnum);
		getik[is]+=peo[i].printgvote();
		system("cls");
	}
	for(int i=0; i<pnum; i++){
		peo[i].setsvote(getik[peo[i].getnum()]);
	}
	for(int i=0; i<pnum; i++){
		for(int j=i+1; j<pnum; j++){
			if(peo[i].printsvote()==peo[j].printsvote()&&peo[i].printsvote()!=0&&peo[j].printsvote()!=0){
				cout<<"出现重票，请重新投票"<<endl;		//出现了重复的得票，重新投票 
				Sleep(5*1000);
				system("cls");
				vote(pnum); 
			}
		}
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
int exile(int pnum){		//放逐判定 		a:用于判断是哪个阵营放逐 
	int s;
	float maxp=0.0;
	int number;
	for(int i=0; i<pnum; i++){
		if(peo[i].printsvote()>maxp){
			maxp=peo[i].printsvote();
			number=i;
		}
	}
	cout<<"player"<<peo[number].getnum()<<"被放逐    身份为：";		//身份公示 
	if(peo[number].printired()==1){
		cout<<"红方"; 
		s=1;
	}
	else{
		cout<<"黑方";
		s=0; 
	}
	cout<<endl;
	Sleep(5*1000);
	system("cls");
	if(peo[number].getiman()==1){		//若是村长，则移交身份 
		cout<<"请移交村长身份"<<endl;
		cout<<"请输入移交村长的玩家编号：";
		int ber; ber=inputcheck2(pnum);
		for(int sf=0; sf<pnum; sf++){
			if(peo[sf].getnum()==ber){
				peo[sf].setiman();
				break;
			}
		}
		system("cls"); 
	}
	for(int i=number; i<=pnum; i++){		//删除玩家 
		peo[i]=peo[i+1];
	}
	return s;
}
int brnight(int pnum){		//红黑夜判定
	srand((int)time(0));
	int br=rand()%99, open=0;
	if(br%2==1){
		for(int i=0; i<pnum; i++){
			cout<<"||------------------------------||"<<endl; 
			cout<<"||           进入红夜           ||"<<endl;
			cout<<"||------------------------------||"<<endl;
			cout<<"player"; peo[i].printnum(); cout<<endl;
			cout<<"是否睁眼：  1-是   2-否"<<endl;
			int is; is=inputcheck3();
			if(is==1&&peo[i].printired()==1)	open++;
			system("cls");
		}
		if(open%2==0)		return 1;
		else if(open%2!=0)	return 0;
	}
	else if(br%2==0){
		for(int i=0; i<pnum; i++){
			cout<<"||------------------------------||"<<endl; 
			cout<<"||           进入黑夜           ||"<<endl;
			cout<<"||------------------------------||"<<endl;
			cout<<"player"; peo[i].printnum(); cout<<endl;
			cout<<"是否睁眼：  1-是   2-否"<<endl;
			int is; is=inputcheck3();
			if(is==1&&peo[i].printired()==0)	open++;
			system("cls");
		}
		if(open%2==0)		return 1;
		else if(open%2!=0)	return 0;
	}
	
} 
int main(){
	cout<<"||------------------------------||"<<endl; 
	cout<<"||            红黑夜            ||"<<endl;
	cout<<"||------------------------------||"<<endl; 
	int pnum;
	cout<<"请输入玩家人数：";
	pnum=inputcheck4();
	system("cls"); 					//窗口刷新 
	int nblk=pnum/2, nred=pnum/2;
	if(pnum%2==1)	nred++;			//nblk:黑方人数 nred:红方人数 pnum:现存玩家数 
	int nb=nblk, nr=nred;
	for(int i=0; i<pnum; i++){		//赋值序号 
		peo[i].setnum(i+1);
	}
	srand((int)time(0));		//设定随机数
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
	cout<<"player"<<man2+1<<"被选为村长"<<endl;	//公布竞选结果 
	Sleep(5*1000);			//延时5秒  
	system("cls");
	peo[man2].setiman();
	int maxp=pnum, night;	//maxp：初始人数   //night：1-特殊情况， 0-正常情况
	while(1){
		if(nblk==0||nred==0)	break;
		int s, mnum; 
		for(int i=0; i<pnum; i++){	//找村长 
			if(peo[i].getiman()==1){
				mnum=i+1;
				break;
			}
		}
		night=brnight(pnum);		//晚上了 
		ticket(maxp,pnum,night);
		cout<<"村长决定发言顺序"<<endl;
		cout<<"请输入：  1-右（减）  2-左（增）"<<endl;
		int js; js=inputcheck3();
		js--;
		system("cls");
		speech2(pnum,mnum,js);		//发言 
		vote(pnum);					//投票
		s=exile(pnum);				//放逐
		pnum--;
		if(s==1)		nred--;
		else if(s==0)	nblk--; 
	}
	cout<<"||------------------------------||"<<endl; 
	cout<<"||           游戏结束           ||"<<endl;
	cout<<"||------------------------------||"<<endl; 
	if(nred==0)	 cout<<"             黑方胜利"<<endl;
	else if(nblk==0) 	cout<<"             红方胜利"<<endl; 
	return 0;
}
