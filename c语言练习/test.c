#define _CRT_SECURE_NO_WARNINGS 1


////��ˮ����
//#include<stdio.h>
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	scanf("%d", &money);
//	total = money;//�����ˮ
//	empty = total;//ˮ�ȵ�
//	while (empty>=2)
//	{
//	total += empty / 2; 
//	empty = empty / 2 + empty % 2;
//	}
//	printf("����ЩǮһ���ܺȣ�%dƿˮ\n", total);
//	return 0;
//		 
//}
// -----------------------------------------------------------------------------------
//LeeCode��1����֮��
// *************************************
// ��һЩ���⣬���������û�й淶��Ҳ����û�ж�̬���ٿռ�ʹ�ã�ֻ��ʵ����������Ĺ���
// *************************************
//#include<stdio.h>
//int* twoSum(int* nums, int numsSize, int target, int* returnSize)
//{
// 
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = i + 1; j < numsSize ; j++)
//        {
//            if (nums[i] + nums[j] == target)
//            {
//                returnSize[0] = i;
//                returnSize[1] = j;
//                return returnSize;
//            }
//        }
//    }
//}
//int main()
//{
//	int M[2] = { 3,3 };
//	int target = 6;
//    int R[2] = { 0 };
//    twoSum(M, 2, target, R);
//    printf("%d %d", R[0], R[1]);
//}
//**********************************************************************
//LeeCode��2�������
#include<stdio.h>
#include<math.h>
#include<malloc.h>
 typedef struct Node {
   int val;
   struct Node* next;
 }Node;
 typedef struct Node* ListNode;

 //struct ListNode* addTwoNumbers(ListNode l1, ListNode  l2) {
 //   //��һ��˼����ʽ**************
 //   //һλһλ�������������ӣ���Ҫ�����������������ͼӷ���λ������,�Ƚϸ���
 //    int i;
 //        //����һ���͵�����
 //    ListNode sum;
 //    //����1�����i������ֵ
 //        int j;
 //        j= 1;//������
 //    ListNode p1;//����һ���½��
 //    p1 = l1->next;//p1ָ���һ�����
 //    int val1 = 0;//����������ݵ�val1
 //    
 //    
 //    while (p1 && j < i)
 //    {
 //        p1 = p1->next;
 //        ++j;
 //    }
 //    if ((p1==NULL)|| j > i)
 //    {
 //        return 0;
 //    }
 //    val1 = p1->val;
 //    //����2�����i������ֵ

 //    //����1������2��i��Ԫ����ӣ���λ��
 //    //����͵�����
 //    return sum;

     //�ڶ���˼����ʽ��ֱ�Ӵӵ�һ�������ж�����һ�������ٴӵڶ��������ж����ڶ�����������ֱ����ӣ��ٷ��ص��͵�������
     //���ڵ�����1����δ��������е���������ȷ�Ķ�ȡ��
     //2����ν�����ֳ����ֲ��洢��������
     // **************************������뾭������������ĿҪ���ұ���ĿҪ����Ӿ��пɻ����ԣ����ڵ���*********************************
     // ������ϸ˼��������������һ�����⣬������������������������Ԫ�ع��࣬��ת����int�������ֹ��󣬾ͻᵼ��
     // ����int���ͱ����ܱ�ʾ�ķ�Χ-2147483648�� 2147483647����������˼����ʽ�ǵò�����ȷ�𰸵�
 //��ʼ��ͷ��������
 ListNode Init_2_Node() 
 {
        ListNode head;
        head = (ListNode)malloc(sizeof(Node));//����һ��ͷ���
        head->next = NULL;//ͷ���ָ����ָ���
        return head;
}
  
 //����һ������
 void Creat_4_Node(ListNode head) {
     ListNode p = head;
     ListNode Last;
     Last = p;
     int i, n;
     printf("��β�巨���������ͷ�ڵ�������������");
     scanf("%d", &n);
     for (i = 1; i <= n; i++) {
         ListNode Pnew = (ListNode)malloc(sizeof(Node));
         Pnew->next = NULL;
         printf("��%d������Ԫ��Ϊ��", i);
         scanf("%d", &Pnew->val);
         Last->next = Pnew;
         Last = Pnew;
     }
 }
 //�������
 void Print_2_Node(ListNode head) 
 {
        ListNode p = head->next;
        printf("�µ�����Ϊ��");
        while (p != NULL)
        {
            printf("%d ", p->val);
            p = p->next;
        }
        printf("\n");
}
 //�������
 ListNode addTwoNumbers(ListNode l1, ListNode  l2)
 {
    
     //���������
     int count1 = 0;
     int count2 = 0;
     ListNode p1 = l1->next;
     ListNode p2 = l2->next;
     while (p1!=NULL)
     {
         p1 = p1->next;
         count1++;
     }
     while (p2 != NULL)
     {
         p2 = p2->next;
         count2++;
     }
     //������1�ж���
     int value1 = 0;
     int temp1 = 0;
     ListNode p_1;
     p_1 = l1->next;//ָ���һ��Ԫ��
     for (int i=0;i<count1;i++)//��λ����
     {

         //������1�ﰴλ��ȡ���֣���temp1����
         temp1 = p_1->val;
         value1 = pow(10,i) * temp1 + value1;
         p_1 = p_1->next;
                  
     }
    //--------------------------------
     //������2�ж���
     int value2 = 0;
     int temp2 = 0;
     ListNode p_2;
     p_2 = l2->next;//ָ���һ��Ԫ��
     for (int i = 0; i < count2; i++)//��λ����
     {

         //������1�ﰴλ��ȡ���֣���temp1����

         temp2 = p_2->val;
         value2 = pow(10,i) * temp2 + value2;
         p_2 = p_2->next;

     }
     //�����������
     int sumvalue = 0;
     sumvalue = value1 + value2;
     int sum_temp = sumvalue;
     //���ַŵ���������������Ԫ�أ�
     //1����sum��λ��
     int sum_count = 0;
     do {
         sum_temp = sum_temp / 10;
         sum_count++;
     } while (sum_temp > 0);
     
     //2����̬�����ڴ��Ÿ�λ���� 
     int* ptr = NULL;
     ptr = (int*)malloc(sum_count * sizeof(int));
     if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
     {
         int i = 0;
         for (i = 0; i < sum_count; i++)
         {

             *(ptr + i) =sumvalue%10;
             sumvalue /= 10;
         }
     }
     //3����������������(����)
     //�ȴ��������ٴ��
     ListNode sum=Init_2_Node();
     ListNode p = sum;
     ListNode Last;
     Last = p;
     int i;
     for (i = 0; i < sum_count; i++) {
         ListNode Pnew = (ListNode)malloc(sizeof(Node));
         Pnew->next = NULL;
         Pnew->val = ptr[i];
         Last->next = Pnew;
         Last = Pnew;
     }
     //4���ͷ��ڴ� 
     free(ptr);
     ptr = NULL;
     //�����������
     return sum;
 }
 //����*********************


 int main()
 {
     //��ʼ����������
     ListNode l1 = Init_2_Node();
     ListNode l2 = Init_2_Node();
     Creat_4_Node(l1);
     Creat_4_Node(l2);


     //���ú���
     ListNode p = addTwoNumbers(l1, l2);
     Print_2_Node(l1);
     Print_2_Node(l2);
     Print_2_Node(p);
 }