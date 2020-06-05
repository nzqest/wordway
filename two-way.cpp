#include"Two-way.h"


//1、双向链表的初始化
bool initDoubleLink(LinkList* &L)
{	
	L = new LinkList;
	if (!L)return false;

	L->next =NULL;
	L->prev = NULL;
	L->date = -1;
	
	return true;
}

//2、双向链表前端插入元素
bool front_insertDoublelink(LinkList*& L, LinkList* Node) {
	if (!L || !Node)return false;

	if (L->next == NULL) {
		Node->next = NULL;
		Node->prev = L;
		L->next = Node;
	}
	else {
		
		L->next->prev = Node;
		Node->next = L->next;
		Node->prev = L;
		L->next = Node;
	}
	return true;


	}

//3、双向链表的遍历
bool double_print(LinkList* L) {
	
	if (!L)return false;

	LinkList* p=L;
	
	//顺序输出
	cout << "顺序输出:\t";
	while (p->next) {
		cout << p->next->date << "\t";
		p = p->next;
	}
	cout << endl;

	//逆向输出
	cout << "逆向输出:\t";
	while (p!=L) {
	
		cout << p->date << "\t";
		p = p->prev;
		}

	return true;


}
//4、尾部插入元素
bool end_insetDoubleLink(LinkList* &L, LinkList* Node) {
	if (!L)return false;

	//找到最后一个元素
	LinkList* Last=L;

	while (Last->next) {
		Last = Last->next;
	}

	Node->next = NULL;
	Node->prev = Last;
	Last->next = Node;
	return true;

}

//5、指定位置插入元素
bool pos_insertDouble(LinkList* &L, int pos, LinkList* Node) {
	
	if (!L || !L->next)return false;
	//找到哪个要插入的位置并且判断该位置是否存在
	if (pos < 1)return false;
	int i = 0;
	LinkList* p=L;
	
	while (i <pos&&p->next) {
		p = p->next;
		i++;
	}
	if (i != pos)return false;
	if (!(p->next) ) {
		
		Node->prev = p;
		Node->next = p->next;
		p->next = Node;
	}
	else {
		p->next->prev = Node;
		Node->prev = p;
		Node->next = p->next;
		p->next = Node;
	}
	return true;



}
//6、元素的获取
bool pos_getfact(LinkList* L, int pos, LinkList* &Node) {
	if (!L||!L->next||pos<1)return false;

	int count = 0, j = 0;

	LinkList* p=L;

	while ((p->next)) {
		p = p->next;
		count++;
	}

	if (count < pos)return false;

	p = L;

	while (j != pos) {
		p = p->next;
		j++;

		}
	//获取元素
	Node = p;
	return true;
	
}

//7、删除元素
bool delete_fact(LinkList* L, int pos) {
	if (!L || !(L->next)||pos < 1)return false;

	

	int count = 0, j = 0;

	LinkList* p = L;
	LinkList* d;
	while ((p->next)) {
		p = p->next;
		count++;
	}

	if (count < pos)return false;

	p = L;

	while (j != pos) {
		p = p->next;
		j++;

	}
	if (!(p->next)) {

		p->prev->next = NULL;
		d = p;
		delete d;
	}
	else {

		p->prev->next = p->next;
		p->next->prev = p->prev;

		d = p;
		delete d;
	}
	
	return true;


}
//8、链表的销毁
void destored_list(LinkList*& L) {
	/*if (!L)return;
	LinkList *d,*p;
	p = L;

	while (p) {
		p = L->next;

		
		delete p;
		p = L;
	}*/
	LinkList* p;
	p = L;
	while (p)
	{
		L = L->next;
		cout << "销毁元素:" << p->date << endl;
		delete p;
		p = L;
	}
	

}