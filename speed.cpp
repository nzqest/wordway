#include<iostream>
#include<Windows.h>

#define MAX_SIZE 5
typedef int Datetype;

//数据区
typedef struct _QNode{

	int priority;//每个节点的优先级,0最低优先级;9最高优先级,优先级相同，取第一个节点
	Datetype date;
	struct _QNode *next;

}QNode;

typedef QNode *QueuePtr;

typedef struct Queue{
	int length;
	QueuePtr rear;
	QueuePtr front;
}LinkQueue;

using namespace std;

//1、链表的初始化
void initqueue(LinkQueue *LQ){
	
	if(!LQ)return ;
	LQ->length=0;
	LQ->front=LQ->rear=NULL;//把头尾指针的位置指向0

}

//2、判断队列是否为空
bool isEmpty(LinkQueue *LQ){
	if(!isEmpty)return false;
	if(LQ->length==0)return true;//把队头和对位指针指向零
	return false;

}

//3、判断队列是否为满
bool iffuul(LinkQueue *LQ){
	
	if(!LQ)return false;

	if(LQ->length==MAX_SIZE)return true;
	
	return false;

	
}

//4、入队，将元素插入到循环队列SQ中
bool EnterQueue(LinkQueue *LQ,Datetype date,int priority){

	if(!LQ)return false;

	if(LQ->length==MAX_SIZE){
		cout<<"无法插入元素"<<endl;
		return false;

	}

	QNode *qNode  = new QNode;

	qNode->date=date;
	qNode->priority=priority;
	qNode->next=NULL;

	if(isEmpty(LQ)){
		LQ->front=LQ->rear=qNode;
	
	}else{

		LQ->rear->next=qNode;
		LQ->rear=qNode;
	
	
	}
		LQ->length++;

}

//5、删除元素
bool deletesiz(LinkQueue *LQ,Datetype *date){
	
	QNode **prve=NULL, *Qnode_prve=NULL;
	
	QNode *tmp=NULL,*last =NULL;

	if(isEmpty(LQ)||!LQ){
		cout<<"队列为空删除失败！"<<endl;
		return false;
	
	}

	if(!date){
	cout<<"数据不存在"<<endl;
	return false;
	}


	prve=&(LQ->front);
	printf("节点的第一个优先级:%d\n",(*prve)->priority);
	
	last = LQ->front;
	tmp = last->next;

	while(tmp){
		if(tmp->priority>(*prve)->priority){
			printf("抓到一个更大的优先级[priority]:%d\n",tmp->priority);
			*prve=tmp;
		}
		last = tmp;
		tmp = tmp->next;
	
	}

	*date=(*prve)->date;
	tmp=*prve;
	*prve = (*prve)->next;
	delete tmp;

	LQ->length--;


}

//5、删除元素
bool deletesize(LinkQueue *LQ,Datetype *date){

	QNode **prev =NULL,*node_prev=NULL;
	QNode *tmp=NULL,*last = NULL;


	if(!LQ||isEmpty(LQ)){
		cout<<"队列为空!"<<endl;
		return false;
	}

	if(!date)return false;

	prev = &(LQ->front);
	last = LQ->front;
	tmp = last->next;
	
	while(tmp){
		if(tmp->priority>(*prev)->priority){
			printf("捕捉到更大的优先级:%d\n",tmp->priority);
			prev = &(last->next);
			node_prev = last;
		}

		last = tmp;
		tmp=tmp->next;
		
	
	}

	*date=(*prev)->date;
	tmp = *prev;
	*prev = (*prev)->next;
	node_prev = tmp;
	delete tmp;

	LQ->length--;

	//一下分为两种情况
	//1、若删除为队首元素且队列的长度为1
	if(LQ->length==0){
		LQ->rear=NULL;
	}

	//2、若删除的为队尾元素
	if(last&&last->next==NULL){
		LQ->rear=last;
	}

}

//6、元素的遍历
void printsize(LinkQueue *LQ){
	
	if(!LQ||isEmpty(LQ))return ;

	QNode *tmp=NULL;
	
	tmp = LQ->front;

	while(tmp){
		
		cout<<"队列优先级:"<<tmp->priority<<"\t元素为:"<<tmp->date<<endl;
		tmp=tmp->next;

	}

	return ;
}

// 7、获取首元素
bool getfront(LinkQueue *LQ,Datetype *date){

	if(!LQ||isEmpty(LQ)){
	cout<<"队列为空 首元素获取失败"<<endl;
	return false;
	}
	if(!date)return false;
	cout<<"首元素获取成功!"<<endl;

	*date = LQ->front->date;
	return true;


}

//8、销毁元素
void destoyedsize(LinkQueue *LQ,Datetype *date){

		if(!LQ)return ;

		QNode *tmp = NULL;
		QNode *node = NULL;

		tmp = LQ->front;

		while(tmp){
			cout<<"销毁元素:"<<tmp->date<<"\t"<<endl;
			node = tmp;
			tmp=tmp->next;
			delete node;	

		}
		LQ->front=LQ->rear=NULL;
		LQ->length = 0;
		return ;

		
}





int main(void){

	LinkQueue *LQ= new LinkQueue;
	initqueue(LQ);
	QNode *node = NULL;
	Datetype date=-1 ;
	int priority = 0;

	for(int i=0;i<5;i++){
		if(EnterQueue(LQ,i,i)){

			cout<<"元素插入成功！"<<endl;
		}
		

	
	}
	cout<<"队列中元素个数为:"<<LQ->length<<endl;

	printsize(LQ);

	//测试删除元素
	for(int i=0;i<5;i++){
	if(deletesize(LQ,&date)){
		cout<<"出队的元素是"<<date<<endl;
	
	}
		}

	printsize(LQ);

	system("pause");
	return 0;
	}