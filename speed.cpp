#include<iostream>
#include<Windows.h>

#define MAX_SIZE 5
typedef int Datetype;

//������
typedef struct _QNode{

	int priority;//ÿ���ڵ�����ȼ�,0������ȼ�;9������ȼ�,���ȼ���ͬ��ȡ��һ���ڵ�
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

//1������ĳ�ʼ��
void initqueue(LinkQueue *LQ){
	
	if(!LQ)return ;
	LQ->length=0;
	LQ->front=LQ->rear=NULL;//��ͷβָ���λ��ָ��0

}

//2���ж϶����Ƿ�Ϊ��
bool isEmpty(LinkQueue *LQ){
	if(!isEmpty)return false;
	if(LQ->length==0)return true;//�Ѷ�ͷ�Ͷ�λָ��ָ����
	return false;

}

//3���ж϶����Ƿ�Ϊ��
bool iffuul(LinkQueue *LQ){
	
	if(!LQ)return false;

	if(LQ->length==MAX_SIZE)return true;
	
	return false;

	
}

//4����ӣ���Ԫ�ز��뵽ѭ������SQ��
bool EnterQueue(LinkQueue *LQ,Datetype date,int priority){

	if(!LQ)return false;

	if(LQ->length==MAX_SIZE){
		cout<<"�޷�����Ԫ��"<<endl;
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

//5��ɾ��Ԫ��
bool deletesiz(LinkQueue *LQ,Datetype *date){
	
	QNode **prve=NULL, *Qnode_prve=NULL;
	
	QNode *tmp=NULL,*last =NULL;

	if(isEmpty(LQ)||!LQ){
		cout<<"����Ϊ��ɾ��ʧ�ܣ�"<<endl;
		return false;
	
	}

	if(!date){
	cout<<"���ݲ�����"<<endl;
	return false;
	}


	prve=&(LQ->front);
	printf("�ڵ�ĵ�һ�����ȼ�:%d\n",(*prve)->priority);
	
	last = LQ->front;
	tmp = last->next;

	while(tmp){
		if(tmp->priority>(*prve)->priority){
			printf("ץ��һ����������ȼ�[priority]:%d\n",tmp->priority);
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

//5��ɾ��Ԫ��
bool deletesize(LinkQueue *LQ,Datetype *date){

	QNode **prev =NULL,*node_prev=NULL;
	QNode *tmp=NULL,*last = NULL;


	if(!LQ||isEmpty(LQ)){
		cout<<"����Ϊ��!"<<endl;
		return false;
	}

	if(!date)return false;

	prev = &(LQ->front);
	last = LQ->front;
	tmp = last->next;
	
	while(tmp){
		if(tmp->priority>(*prev)->priority){
			printf("��׽����������ȼ�:%d\n",tmp->priority);
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

	//һ�·�Ϊ�������
	//1����ɾ��Ϊ����Ԫ���Ҷ��еĳ���Ϊ1
	if(LQ->length==0){
		LQ->rear=NULL;
	}

	//2����ɾ����Ϊ��βԪ��
	if(last&&last->next==NULL){
		LQ->rear=last;
	}

}

//6��Ԫ�صı���
void printsize(LinkQueue *LQ){
	
	if(!LQ||isEmpty(LQ))return ;

	QNode *tmp=NULL;
	
	tmp = LQ->front;

	while(tmp){
		
		cout<<"�������ȼ�:"<<tmp->priority<<"\tԪ��Ϊ:"<<tmp->date<<endl;
		tmp=tmp->next;

	}

	return ;
}

// 7����ȡ��Ԫ��
bool getfront(LinkQueue *LQ,Datetype *date){

	if(!LQ||isEmpty(LQ)){
	cout<<"����Ϊ�� ��Ԫ�ػ�ȡʧ��"<<endl;
	return false;
	}
	if(!date)return false;
	cout<<"��Ԫ�ػ�ȡ�ɹ�!"<<endl;

	*date = LQ->front->date;
	return true;


}

//8������Ԫ��
void destoyedsize(LinkQueue *LQ,Datetype *date){

		if(!LQ)return ;

		QNode *tmp = NULL;
		QNode *node = NULL;

		tmp = LQ->front;

		while(tmp){
			cout<<"����Ԫ��:"<<tmp->date<<"\t"<<endl;
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

			cout<<"Ԫ�ز���ɹ���"<<endl;
		}
		

	
	}
	cout<<"������Ԫ�ظ���Ϊ:"<<LQ->length<<endl;

	printsize(LQ);

	//����ɾ��Ԫ��
	for(int i=0;i<5;i++){
	if(deletesize(LQ,&date)){
		cout<<"���ӵ�Ԫ����"<<date<<endl;
	
	}
		}

	printsize(LQ);

	system("pause");
	return 0;
	}