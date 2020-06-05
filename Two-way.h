#pragma once
#include<iostream>
using namespace std;


typedef struct _DoublelinkNode {
	
	int date;
	struct _DoublelinkNode* next;
	struct _DoublelinkNode* prev;
	
}LinkList,LinkNode;

bool initDoubleLink(LinkList* &L);
bool front_insertDoublelink(LinkList*& L, LinkList* Node);
bool double_print(LinkList* L);
bool end_insetDoubleLink(LinkList*& L, LinkList* Node);
bool pos_insertDouble(LinkList*& L, int pos, LinkList* Node);
bool pos_getfact(LinkList* L, int pos,LinkList* &Node);
bool delete_fact(LinkList* L, int pos);
void destored_list(LinkList* &L);