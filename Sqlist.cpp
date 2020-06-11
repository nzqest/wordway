#include<iostream>
#include<Windows.h>
#include<iomanip>


using namespace std;

#define MAX_SIZE 5

typedef	int DateType;

typedef struct _Qnode{//节点结构
	
	DateType date;
	_Qnode *next;

}Qnode; 

typedef Qnode* Qnodeptr;

typedef struct Queue{
	
	int length;
	Qnodeptr front;
	Qnodeptr rear;

}LinkQueue;

//1、初始化队列链表
void initQueue(LinkQueue *LQ){
	if(!LQ)return ;

	LQ->front=NULL;
	LQ->rear=NULL;
	LQ->length=0;

}

//2、判断队列是否为空
bool ifempty(LinkQueue *LQ){
	if(!LQ)return false;

	if(LQ->length==0)return true;
	
	return false;
	
}

//3、判断队列是否已满
bool iffull(LinkQueue *LQ){
	if(!LQ)return false;

	if(LQ->length==MAX_SIZE)return true;

	return false;
}

//4、插入如元素
bool insertQueue(LinkQueue *LQ,DateType date){

	if(!LQ)return false;

	if(iffull(LQ)){
		cout<<"队列已满无法插入入"<<endl;
		return false;
	}

	_Qnode* node =new _Qnode;
	node->date=date;
	node->next=NULL;

	//主义判断空的队列的情况
	if(ifempty(LQ)){
		LQ->rear=LQ->front=node;
	}else{
	LQ->rear->next=node;
	LQ->rear=node;
	}

	LQ->length++;

	return true;
	

}

//4、删除队首元素
bool delete_front(LinkQueue *LQ,DateType* date){
	_Qnode* tmp=NULL;

	if(!LQ||ifempty(LQ))return false;

	if(!date)return false;

	tmp=LQ->front;

	LQ->front=LQ->front->next;

	if(!LQ->front)LQ->rear=NULL;
	
	*date=tmp->date;
	LQ->length--;

	delete tmp;
	return true;

	
}

//5、元素的遍历
void queueprint(LinkQueue *LQ){
	
	if(!LQ||ifempty(LQ))return ;

	Qnode *p=NULL;
	p=LQ->front;


	while(p){
		
		cout<<p->date<<setw(4);
		p=p->next;
		
	
	}


}

//6、获取队列元素的格式
int getlength(LinkQueue *LQ){
	if(!LQ)return 0;

	return LQ->length;


}

//7、获取队首元素
bool getfrontqueue(LinkQueue *LQ,DateType *date){


	if(!LQ||ifempty(LQ))return false;

	if(!date)return false;

	*date=LQ->front->date;
	return true;

}

//8、销毁元素
void destoredqueue(LinkQueue *LQ){
	

	if(!LQ)return ;


	Qnode *tmp;
	Qnode *tmp1;

	tmp=LQ->front;
	
	
	while(tmp){

		LQ->front=tmp;
		tmp1=tmp->next;

		delete tmp;
		
		tmp=tmp1;

		


	}

	LQ->front=LQ->rear=NULL;
	LQ->length=0;
	

	/*if(!LQ)return ;

	while(LQ->front){
		Qnodeptr tmp = LQ->front->next;
		delete LQ->front;
		LQ->front=tmp;
	
	}

	LQ->front=LQ->rear=NULL;
	LQ->length=0;
	cout<<LQ->length<<endl;
*/

}

int main(void){

	LinkQueue *LQ=new LinkQueue;
	DateType date =-1;
	
	//初始化队列
	initQueue(LQ);

	for(int i=0;i<10;i++){
		
		if(insertQueue(LQ,10*i)){
			cout<<"元素插入成功"<<endl;
		}else{
		cout<<"元素插入失败"<<endl;
		}
	
	}

	//遍历元素
	queueprint(LQ);

	

	//删除元素
	destoredqueue(LQ);

	queueprint(LQ);

	system("pause");
	return 0;
	}