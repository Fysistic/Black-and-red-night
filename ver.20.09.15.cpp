#include<iostream>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>
#include<iomanip>
#include<cstring>
using namespace std;
class player{
	private:
		int num;			//������ 
		bool ired;		//�Ƿ�Ϊ�췽 
		float svote;		//��Ʊ 
		float gvote;		//����Ʊ�� 
		bool imanager;		//�Ƿ�Ϊ�峤 
	public:
		void setnum(int n){		//��Ų��� 
			num=n;
		}
		void printnum(){
			cout<<num;
		}
		int getnum(){
			return num;
		} 
		void setired(int n){		//��Ӫ���� 
			ired=n;
		}
		int printired(){
			if(ired==1)	return 1;
			else		return 0;	
		}
		void setsvote(float n){		//��Ʊ���� 
			svote=n;
		}
		float printsvote(){
			return svote;
		} 
		void setgvote(float n){		//��Ʊ���� 
			gvote=n;
		}
		float printgvote(){
			return gvote;
		}
		void setiman(){		//�峤��ݲ��� 
			imanager=1;
		}
		int getiman(){
			if(imanager==1)	return 1;
			else			return 0;
		}
}peo[100];
void inputcheck1(){			//������I�ͣ����ڼ���Ƿ�ֻ������1 
	char ns[200]; cin>>ns;
	int is=strlen(ns);
	if(is!=1||ns[0]!='1'){
		cout<<"�Ƿ����룡"<<endl<<"���������룺";
		inputcheck1(); 
	}
}
int inputcheck2(int pnum){		//������II�ͣ����ڼ�ⳡ�ϸ���ŵ�����Ƿ���� 
	char ns[200]; cin>>ns; bool exi=0;
	int is=strlen(ns);
	int n1=0, n2=1;
	for(int i=0; i<is-1; i++)	n2*=10;
	for(int i=0; i<is; i++){
		n1+=(ns[i]-48)*n2;
		n2/=10;
	}
	for(int i=0; i<pnum; i++){
		if(peo[i].getnum()==n1){
			exi=1;
			break;
		}
	}
	if(is>=3)	exi=0;
	if(exi==0&&n1!=0){
		cout<<"�Ƿ����룡"<<endl<<"���������룺";
		return inputcheck2(pnum); 
	}
	else return n1;
}
int inputcheck3(){		//������III�ͣ����ڼ�����������Ƿ����� 
	char ns[200]; cin>>ns;
	int is=strlen(ns), nx;
	if(is!=1){
		cout<<"�Ƿ����룡"<<endl<<"���������룺";
		return inputcheck3();
	}
	if(is==1&&(ns[0]!='1'&&ns[0]!='2')){
		cout<<"�Ƿ����룡"<<endl<<"���������룺";
		return inputcheck3();
	}
	nx=ns[0]-48;
	return nx;
}
int inputcheck4(){		//������IV�ͣ����ڼ�����������Ƿ���ȷ 
	char ns[200]; cin>>ns;
	int is=strlen(ns), n; bool let=0;
	for(int i=0; i<is; i++){
		if(ns[i]>'9'||ns[i]<'0'){
			let=1;
			break;
		}
	}
	if(let==1){
		cout<<"�Ƿ����룡"<<endl<<"���������룺";
		return inputcheck4();
	}
	else if(let==0){
		int n1=1;
		for(int i=0; i<is-1; i++)	n1*=10;
		for(int i=0; i<is; i++){
			n+=(ns[i]-48)*n1;
			n1/=10;
		}
		if(n<=3){
			cout<<"�������٣����������룺";
			return inputcheck4(); 
		} 
		else if(n>=100){
			cout<<"�������࣬���������룺";
			return inputcheck4();
		}
	}
	return n;
}
int inputcheck5(int pnum, int ma){		//������V�ͣ�ר�����ڼ��峤�ƽ����ʱ��û��Ͷ���Լ� 
	char ns[200]; cin>>ns; bool exi=0;
	int is=strlen(ns);
	int n1=0, n2=1, n3;
	for(int i=0; i<is-1; i++)	n2*=10;
	for(int i=0; i<is; i++){
		n1+=(ns[i]-48)*n2;
		n2/=10;
	}
	for(int i=0; i<pnum; i++){
		if(peo[i].getnum()==n1){
			exi=1;
			n3=i;
			break;
		}
	}
	if(is>=3||peo[n3].getiman()==1)	exi=0;
	if(exi==0){
		cout<<"�Ƿ����룡"<<endl<<"���������룺";
		return inputcheck5(pnum,ma); 
	}
	else return n1;
}
void prepare(int pnum){				//ȷ�����
	for(int i=0; i<pnum; i++){
		cout<<"||------------------------------||"<<endl;
		cout<<"||         ȷ����ݽ׶�         ||"<<endl;
		cout<<"||------------------------------||"<<endl;
		cout<<"player"; peo[i].printnum(); cout<<endl;
		cout<<"�������ǣ�";
		if(peo[i].printired()==1)	cout<<"�췽";
		else					cout<<"�ڷ�";
		cout<<endl<<"�����룺 1-ȷ��"<<endl; 
		inputcheck1();
		system("cls"); 
	}
}
void speech1(int pnum){				//�״η��� 
	for(int i=0; i<pnum; i++){
		cout<<"||------------------------------||"<<endl; 
		cout<<"||         ��ѡ�峤�׶�         ||"<<endl;
		cout<<"||------------------------------||"<<endl;
		cout<<"player"; peo[i].printnum(); cout<<endl;
		cout<<"�����룺 1-���Խ���"<<endl;
		inputcheck1();
		system("cls");
	}
}
void speech2(int pnum, int mnum, bool dirn){		//�������� 
	int i=mnum;
	if(dirn==1){		//�峤֮�� �� 
		for(; i<pnum; i++){
			cout<<"||------------------------------||"<<endl; 
			cout<<"||           ���Խ׶�           ||"<<endl;
			cout<<"||------------------------------||"<<endl;
			cout<<"player"; peo[i].printnum(); cout<<endl;
			cout<<"�����룺 1-���Խ���"<<endl;
			inputcheck1();
			system("cls");
		}
		for(int i=0; i<mnum; i++){
			cout<<"||------------------------------||"<<endl; 
			cout<<"||           ���Խ׶�           ||"<<endl;
			cout<<"||------------------------------||"<<endl;
			cout<<"player"; peo[i].printnum(); cout<<endl;
			cout<<"�����룺 1-���Խ���"<<endl;
			inputcheck1();
			system("cls");
		}
	}
	else if(dirn==0){		//�峤֮�� �� 
		i-=2;
		for(; i>=0; i--){
			cout<<"||------------------------------||"<<endl; 
			cout<<"||           ���Խ׶�           ||"<<endl;
			cout<<"||------------------------------||"<<endl;
			cout<<"player"; peo[i].printnum(); cout<<endl;
			cout<<"�����룺 1-���Խ���"<<endl;
			inputcheck1();
			system("cls");
		}
		for(int i=pnum-1; i>=mnum-1; i--){
			cout<<"||------------------------------||"<<endl; 
			cout<<"||           ���Խ׶�           ||"<<endl;
			cout<<"||------------------------------||"<<endl;
			cout<<"player"; peo[i].printnum(); cout<<endl;
			cout<<"�����룺 1-���Խ���"<<endl;
			inputcheck1();
			system("cls");
		}
	} 
}
void vote(int pnum){		//ͶƱ		//������
	float getik[100]; 
	for(int i=0; i<pnum; i++)	getik[i]=0.0; 	//Ʊ������ 
	for(int i=0; i<pnum; i++){
		cout<<"||------------------------------||"<<endl; 
		cout<<"||           ͶƱ�׶�           ||"<<endl;
		cout<<"||------------------------------||"<<endl;
		cout<<"player"; peo[i].printnum(); cout<<endl;
		cout<<"��ӵ�е�Ʊ����"<<peo[i].printgvote()<<endl; 
		cout<<"�����룺 0-��Ʊ  ";
		for(int j=0; j<pnum; j++){
			peo[j].printnum();
			if(j!=pnum-1)	cout<<" ";
		}
		cout<<"-��Ӧ��ŵ����"<<endl;		//ͶƱ�����Ϊis����� 
		int is; is=inputcheck2(pnum);
		getik[is]+=peo[i].printgvote();
		system("cls");
	}
	for(int i=0; i<pnum; i++){
		peo[i].setsvote(getik[peo[i].getnum()]);
	}
	int maxo=0;
	for(int i=0; i<pnum; i++){
		if(peo[i].printsvote()>maxo)	maxo=peo[i].printsvote();
	}
	for(int i=0; i<pnum; i++){
		for(int j=i+1; j<pnum; j++){
			if(peo[i].printsvote()==peo[j].printsvote()&&peo[i].printsvote()==maxo&&peo[j].printsvote()==maxo){
				cout<<"||------------------------------||"<<endl; 
				cout<<"||     ������Ʊ��������ͶƱ     ||"<<endl;
				cout<<"||------------------------------||"<<endl;		//�������ظ�������Ʊ������ͶƱ 
				Sleep(3*1000);
				system("cls");
				vote(pnum); 
			}
		}
	}
}
void ticket(int maxp, int pnum, int night){		//�趨Ʊ�� 		maxp��������� 
	for(int i=0; i<pnum; i++){
		if(peo[i].getiman()==1){
			if(night==1){		//��ҹ��żor��ҹ��ż 
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
int exile(int pnum){		//�����ж� 		a:�����ж����ĸ���Ӫ���� 
	int s;
	float maxp=0.0;
	int number;
	for(int i=0; i<pnum; i++){
		if(peo[i].printsvote()>maxp){
			maxp=peo[i].printsvote();
			number=i;
		}
	}
	cout<<"||------------------------------||"<<endl; 
	cout<<"||player"<<setw(2)<<peo[number].getnum()<<"������    ���Ϊ��";//��ݹ�ʾ 
	if(peo[number].printired()==1){
		cout<<"�췽"; 
		s=1;
	}
	else{
		cout<<"�ڷ�";
		s=0; 
	}
	cout<<"||"<<endl;
	cout<<"||------------------------------||"<<endl;
	cout<<endl;
	Sleep(3*1000);
	system("cls");
	if(peo[number].getiman()==1){		//���Ǵ峤�����ƽ���� 
		cout<<"||------------------------------||"<<endl; 
		cout<<"||           �ƽ����           ||"<<endl;
		cout<<"||------------------------------||"<<endl;
		cout<<"player"; peo[number].printnum(); cout<<"���ƽ��峤���"<<endl;
		cout<<"�������ƽ��峤����ұ�ţ�";
		int ber; ber=inputcheck5(pnum,number);
		for(int sf=0; sf<pnum; sf++){
			if(peo[sf].getnum()==ber){
				peo[sf].setiman();
				break;
			}
		}
		system("cls"); 
	}
	for(int i=number; i<=pnum; i++){		//ɾ����� 
		peo[i]=peo[i+1];
	}
	return s;
}
int brnight(int pnum){		//���ҹ�ж�
	srand((int)time(0));
	int br=rand()%99, open=0;
	if(br%2==1){
		cout<<"||------------------------------||"<<endl; 
		cout<<"||           �����ҹ           ||"<<endl;
		cout<<"||------------------------------||"<<endl;
		Sleep(3*1000);
		system("cls");
		for(int i=0; i<pnum; i++){
			cout<<"||------------------------------||"<<endl; 
			cout<<"||          ��ҹ�Ǻ�ҹ          ||"<<endl;
			cout<<"||------------------------------||"<<endl;
			cout<<"player"<<setw(2); peo[i].printnum();	cout<<endl<<"��ݣ�";
			if(peo[i].printired()==1)		cout<<"�췽"<<endl;
			else if(peo[i].printired()==0)	cout<<"�ڷ�"<<endl; 
			cout<<"�Ƿ����ۣ�  1-��   2-��"<<endl;
			int is; is=inputcheck3();
			if(is==1&&peo[i].printired()==1)	open++;
			system("cls");
		}
		cout<<"||------------------------------||"<<endl; 
		cout<<"||            ������            ||"<<endl;
		cout<<"||------------------------------||"<<endl;
		Sleep(3*1000);
		system("cls"); 
		if(open%2==0)		return 1;
		else if(open%2!=0)	return 0;
	}
	else if(br%2==0){
		cout<<"||------------------------------||"<<endl; 
		cout<<"||           �����ҹ           ||"<<endl;
		cout<<"||------------------------------||"<<endl;
		Sleep(3*1000); 
		system("cls");
		for(int i=0; i<pnum; i++){
			cout<<"||------------------------------||"<<endl; 
			cout<<"||          ��ҹ�Ǻ�ҹ          ||"<<endl;
			cout<<"||------------------------------||"<<endl;
			cout<<"player"<<setw(2); peo[i].printnum();	cout<<endl<<"��ݣ�";
			if(peo[i].printired()==1)		cout<<"�췽"<<endl;
			else if(peo[i].printired()==0)	cout<<"�ڷ�"<<endl; 
			cout<<"�Ƿ����ۣ�  1-��   2-��"<<endl;
			int is; is=inputcheck3();
			if(is==1&&peo[i].printired()==0)	open++;
			system("cls");
		}
		cout<<"||------------------------------||"<<endl; 
		cout<<"||            ������            ||"<<endl;
		cout<<"||------------------------------||"<<endl;
		Sleep(3*1000);
		system("cls"); 
		if(open%2==0)		return 1;
		else if(open%2!=0)	return 0;
	}
	
} 
int main(){
	cout<<"||------------------------------||"<<endl; 	//length=34 
	cout<<"||            ���ҹ            ||"<<endl;
	cout<<"||------------------------------||"<<endl; 
	int pnum;
	cout<<"���������������";
	pnum=inputcheck4();
	system("cls"); 					//����ˢ�� 
	int nblk=pnum/2, nred=pnum/2;
	if(pnum%2==1)	nred++;			//nblk:�ڷ����� nred:�췽���� pnum:�ִ������ 
	int nb=nblk, nr=nred;
	for(int i=0; i<pnum; i++){		//��ֵ��� 
		peo[i].setnum(i+1);
	}
	srand((int)time(0));		//�趨�����
	int as[100];					//��ȡ����� 
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
	for(int i=0; i<pnum; i++){		//��ȡ��� 
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
	prepare(pnum);		//ȷ����� 
	speech1(pnum);		//�״η���
	ticket(0,pnum,0);		//�趨Ʊ�� 
	vote(pnum);			//Ʊѡ�峤
	int man1=0, man2=0;
	for(int i=0; i<pnum; i++){	//�״μ�Ʊ 
		if(peo[i].printsvote()>man1){
			man1=peo[i].printsvote();
			man2=i;
		}
	}
	cout<<"||------------------------------||"<<endl;
	cout<<"||      player"<<setw(2)<<man2+1<<"��ѡΪ�峤"<<setw(8)<<"||"<<endl;	//������ѡ���
	cout<<"||------------------------------||"<<endl;
	Sleep(3*1000);			//��ʱ3��  
	system("cls");
	peo[man2].setiman();
	int maxp=pnum, night;	//maxp����ʼ����   //night��1-��������� 0-�������
	while(1){
		if(nblk==0||nred==0)	break;
		int s, mnum; 
		for(int i=0; i<pnum; i++){	//�Ҵ峤 
			if(peo[i].getiman()==1){
				mnum=i+1;
				break;
			}
		}
		night=brnight(pnum);		//������ 
		ticket(maxp,pnum,night);
		cout<<"||------------------------------||"<<endl;
		cout<<"||      �峤��������˳��        ||"<<endl;
		cout<<"||------------------------------||"<<endl;
		cout<<"�����룺  1-�ң�����  2-������"<<endl;
		int js; js=inputcheck3();
		js--;
		system("cls");
		speech2(pnum,mnum,js);		//���� 
		vote(pnum);					//ͶƱ
		s=exile(pnum);				//����
		pnum--;
		if(s==1)		nred--;
		else if(s==0)	nblk--; 
	}
	cout<<"||------------------------------||"<<endl; 
	cout<<"||           ��Ϸ����           ||"<<endl;
	cout<<"||                              ||"<<endl;
	if(nred==0)	 		cout<<"||           �ڷ�ʤ��           ||"<<endl;
	else if(nblk==0) 	cout<<"||           �췽ʤ��           ||"<<endl;
	cout<<"||------------------------------||"<<endl; 
	return 0;
}
