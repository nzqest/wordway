#include"Two-way.h"


int main(void) {
	//1��˫�������ʼ��
	LinkList* L=NULL;
	LinkNode* Node=NULL;
	if (initDoubleLink(L)) {
		cout << "sucees init!" << endl;
	}
	//front_insertDoublelink(L, Node)
	//2������ͷ������Ԫ��
	for (int i = 0; i < 3; i++) {
		int x;
		cout << "������Ҫ�����Ԫ��:" << endl;
		cin >> x;
		Node = new LinkNode;
		Node->date = x;
		if (front_insertDoublelink(L, Node)) {
			cout << "Ԫ�ز���ɹ�" << endl;
			//3��˫������ı���
		
		}
		else {
			cout << "Ԫ�ز���ʧ��" << endl;
		}

	}
	int pos, elems;
	double_print(L);
	
	for (int i = 0; i < 0; i++) {
		cout << "������Ҫ�����Ԫ�ؼ�λ���м��ÿո�ֿ�" << endl;
		cin >> elems >> pos;
		Node = new LinkNode;
		Node->date = elems;
		
		if (pos_insertDouble(L, pos, Node)) {
			cout << "����Ԫ�سɹ�" << endl;
			double_print(L);

		}
		else {
			cout << "����Ԫ��ʧ��" << endl;
		}

	}
	LinkNode *remmener=NULL;
	int p;
	//
	cout << endl;


	//cout << "�������ȡԪ�ص�λ��" << endl;
	//cin >> p;
	//if (pos_getfact(L, p, remmener)) {
	//	cout << "��ȡԪ��" << remmener->date << endl;
	//}
	//else {
	//	cout << "��ȡԪ��ʧ��" << endl;
	//}
	//

	//
	//while (1) {
	//	cout << "������Ҫɾ����λ��:" << endl;
	//	cin >> p;
	//	if (delete_fact(L, p)) {
	//		cout << "Ԫ��ɾ���ɹ�" << endl;
	//	}
	//	double_print(L);
	//}

	destored_list(L);
	double_print(L);
	return 0;
}