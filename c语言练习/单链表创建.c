//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<malloc.h>
////https://blog.csdn.net/m0_68111267/article/details/127017405
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node, * PNode;
//PNode Init_1_Node() {
//	PNode head;
//	head = NULL;//因为不带头结点，所以我们只要让头结点为空
//	return head;
//}
//PNode Init_2_Node() {
//	PNode head;
//	head = (PNode)malloc(sizeof(Node));//申请一个头结点
//	head->next = NULL;//头结点指针域指向空
//	return head;
//}
//void Creat_1_Node(PNode* head)						//不带头结点我们用头指针的地址来保存单链表
//{
//	int i, n;
//	printf("（头插法）请输入不带头节点的链表结点个数：");
//	scanf("%d", &n);								//输入不带头结点单链表的结点个数
//	for (i = 1; i <= n; i++) {
//		PNode Pnew = (PNode)malloc(sizeof(Node));	 //创建一个新的结点
//		Pnew->next = NULL;							//指针域指向空
//		printf("第%d个结点的元素为：", n + 1 - i);
//		scanf("%d", &Pnew->data);
//		if (*head == NULL) //判断头指针是否指向空
//		{
//			*head = Pnew;//如果是则让头指针指向第一个有效结点
//		}
//		else  //当头指针指向非空时
//		{
//			Pnew->next = *head;//将新的结点插入到头指针所指结点的前面
//			*head = Pnew;//头指针指向新插入的结点
//		}
//	}
//}
//void Creat_2_Node(PNode* head) {
//	PNode Last=NULL;
//	int i, n;
//	printf("（尾插法）请输入不带头节点的链表结点个数：");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++) {
//		PNode Pnew = (PNode)malloc(sizeof(Node));
//		Pnew->next = NULL;
//		printf("第%d个结点的元素为：", i);
//		scanf("%d", &Pnew->data);
//		if (*head == NULL) {
//			*head = Pnew;
//			Last = Pnew;
//		}
//		else {
//			Last->next = Pnew;
//			Last = Pnew;
//		}
//	}
//}
//void Creat_3_Node(PNode head) {
//	PNode p = head;
//	int i, n;
//	printf("（头插法）请输入带头节点的链表结点个数：");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++) {
//		PNode Pnew = (PNode)malloc(sizeof(Node));
//		Pnew->next = NULL;
//		printf("第%d个结点的元素为：", n + 1 - i);
//		scanf("%d", &Pnew->data);
//		Pnew->next = p->next;
//		p->next = Pnew;
//	}
//}
//void Creat_4_Node(PNode head) {
//	PNode p = head;
//	PNode Last;
//	Last = p;
//	int i, n;
//	printf("（尾插法）请输入带头节点的链表结点个数：");
//	scanf("%d", &n); 
//	for (i = 1; i <= n; i++) {
//		PNode Pnew = (PNode)malloc(sizeof(Node));
//		Pnew->next = NULL;
//		printf("第%d个结点的元素为：", i);
//		scanf("%d", &Pnew->data);
//		Last->next = Pnew;
//		Last = Pnew;
//	}
//}
//void Print_1_Node(PNode head) {
//	PNode p = head;
//	printf("新的链表为：");
//	while (p != NULL) {
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//void Print_2_Node(PNode head) {
//	PNode p = head->next;
//	printf("新的链表为：");
//	while (p != NULL) {
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//int main() {
//	PNode H1, H2, H3, H4;
//	H1 = Init_1_Node();
//	Creat_1_Node(&H1);
//	Print_1_Node(H1);
//	H2 = Init_1_Node();
//	Creat_2_Node(&H2);
//	Print_1_Node(H2);
//	H3 = Init_2_Node();
//	Creat_3_Node(H3);
//	Print_2_Node(H3);
//	H4 = Init_2_Node();
//	Creat_4_Node(H4);
//	Print_2_Node(H4);
//	return 0;
//}