#include"Two-way.h"


int main(void) {
	//1、双向链表初始化
	LinkList* L=NULL;
	LinkNode* Node=NULL;
	if (initDoubleLink(L)) {
		cout << "sucees init!" << endl;
	}
	//front_insertDoublelink(L, Node)
	//2、链表头部插入元素
	for (int i = 0; i < 3; i++) {
		int x;
		cout << "请输入要插入的元素:" << endl;
		cin >> x;
		Node = new LinkNode;
		Node->date = x;
		if (front_insertDoublelink(L, Node)) {
			cout << "元素插入成功" << endl;
			//3、双向链表的遍历
		
		}
		else {
			cout << "元素插入失败" << endl;
		}

	}
	int pos, elems;
	double_print(L);
	
	for (int i = 0; i < 0; i++) {
		cout << "请输入要插入的元素及位置中间用空格分开" << endl;
		cin >> elems >> pos;
		Node = new LinkNode;
		Node->date = elems;
		
		if (pos_insertDouble(L, pos, Node)) {
			cout << "插入元素成功" << endl;
			double_print(L);

		}
		else {
			cout << "插入元素失败" << endl;
		}

	}
	LinkNode *remmener=NULL;
	int p;
	//
	cout << endl;


	//cout << "请输入获取元素的位置" << endl;
	//cin >> p;
	//if (pos_getfact(L, p, remmener)) {
	//	cout << "获取元素" << remmener->date << endl;
	//}
	//else {
	//	cout << "获取元素失败" << endl;
	//}
	//

	//
	//while (1) {
	//	cout << "请输入要删除的位置:" << endl;
	//	cin >> p;
	//	if (delete_fact(L, p)) {
	//		cout << "元素删除成功" << endl;
	//	}
	//	double_print(L);
	//}

	destored_list(L);
	double_print(L);
	return 0;
}