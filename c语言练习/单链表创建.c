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
//	head = NULL;//��Ϊ����ͷ��㣬��������ֻҪ��ͷ���Ϊ��
//	return head;
//}
//PNode Init_2_Node() {
//	PNode head;
//	head = (PNode)malloc(sizeof(Node));//����һ��ͷ���
//	head->next = NULL;//ͷ���ָ����ָ���
//	return head;
//}
//void Creat_1_Node(PNode* head)						//����ͷ���������ͷָ��ĵ�ַ�����浥����
//{
//	int i, n;
//	printf("��ͷ�巨�������벻��ͷ�ڵ�������������");
//	scanf("%d", &n);								//���벻��ͷ��㵥����Ľ�����
//	for (i = 1; i <= n; i++) {
//		PNode Pnew = (PNode)malloc(sizeof(Node));	 //����һ���µĽ��
//		Pnew->next = NULL;							//ָ����ָ���
//		printf("��%d������Ԫ��Ϊ��", n + 1 - i);
//		scanf("%d", &Pnew->data);
//		if (*head == NULL) //�ж�ͷָ���Ƿ�ָ���
//		{
//			*head = Pnew;//���������ͷָ��ָ���һ����Ч���
//		}
//		else  //��ͷָ��ָ��ǿ�ʱ
//		{
//			Pnew->next = *head;//���µĽ����뵽ͷָ����ָ����ǰ��
//			*head = Pnew;//ͷָ��ָ���²���Ľ��
//		}
//	}
//}
//void Creat_2_Node(PNode* head) {
//	PNode Last=NULL;
//	int i, n;
//	printf("��β�巨�������벻��ͷ�ڵ�������������");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++) {
//		PNode Pnew = (PNode)malloc(sizeof(Node));
//		Pnew->next = NULL;
//		printf("��%d������Ԫ��Ϊ��", i);
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
//	printf("��ͷ�巨���������ͷ�ڵ�������������");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++) {
//		PNode Pnew = (PNode)malloc(sizeof(Node));
//		Pnew->next = NULL;
//		printf("��%d������Ԫ��Ϊ��", n + 1 - i);
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
//	printf("��β�巨���������ͷ�ڵ�������������");
//	scanf("%d", &n); 
//	for (i = 1; i <= n; i++) {
//		PNode Pnew = (PNode)malloc(sizeof(Node));
//		Pnew->next = NULL;
//		printf("��%d������Ԫ��Ϊ��", i);
//		scanf("%d", &Pnew->data);
//		Last->next = Pnew;
//		Last = Pnew;
//	}
//}
//void Print_1_Node(PNode head) {
//	PNode p = head;
//	printf("�µ�����Ϊ��");
//	while (p != NULL) {
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//void Print_2_Node(PNode head) {
//	PNode p = head->next;
//	printf("�µ�����Ϊ��");
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