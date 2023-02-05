#define _CRT_SECURE_NO_WARNINGS 1


////喝水问题
//#include<stdio.h>
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	scanf("%d", &money);
//	total = money;//买回来水
//	empty = total;//水喝掉
//	while (empty>=2)
//	{
//	total += empty / 2; 
//	empty = empty / 2 + empty % 2;
//	}
//	printf("用这些钱一共能喝：%d瓶水\n", total);
//	return 0;
//		 
//}
// -----------------------------------------------------------------------------------
//LeeCode题1两数之和
// *************************************
// 有一些问题，比如变量名没有规范，也比如没有动态开辟空间使用，只是实现了最基本的功能
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
//LeeCode题2两数相加
#include<stdio.h>
#include<math.h>
#include<malloc.h>
 typedef struct Node {
   int val;
   struct Node* next;
 }Node;
 typedef struct Node* ListNode;

 //struct ListNode* addTwoNumbers(ListNode l1, ListNode  l2) {
 //   //第一种思考方式**************
 //   //一位一位输出，输出完后相加，但要考虑逆序的排序问题和加法进位的问题,比较复杂
 //    int i;
 //        //创建一个和的链表
 //    ListNode sum;
 //    //链表1输出第i个结点的值
 //        int j;
 //        j= 1;//计数器
 //    ListNode p1;//声明一个新结点
 //    p1 = l1->next;//p1指向第一个结点
 //    int val1 = 0;//用来输出数据的val1
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
 //    //链表2输出第i个结点的值

 //    //链表1和链表2第i个元素相加（进位）
 //    //输出和的链表
 //    return sum;

     //第二种思考方式，直接从第一个链表中读出第一个数，再从第二个链表中读出第二个数，数字直接相加，再返回到和的链表当中
     //存在的问题1、如何从逆序排列的数字中正确的读取数
     //2、如何将数拆分成数字并存储到链表中
     // **************************下面代码经过测试满足题目要求，且比题目要求更加具有可互动性，便于调试*********************************
     // 经过仔细思考后，下面代码存在一定问题，就是如果输入的两个链表所含元素过多，即转换的int类型数字过大，就会导致
     // 超过int类型变量能表示的范围-2147483648至 2147483647，所以这种思考方式是得不到正确答案的
 //初始化头结点的链表
 ListNode Init_2_Node() 
 {
        ListNode head;
        head = (ListNode)malloc(sizeof(Node));//申请一个头结点
        head->next = NULL;//头结点指针域指向空
        return head;
}
  
 //创建一个链表
 void Creat_4_Node(ListNode head) {
     ListNode p = head;
     ListNode Last;
     Last = p;
     int i, n;
     printf("（尾插法）请输入带头节点的链表结点个数：");
     scanf("%d", &n);
     for (i = 1; i <= n; i++) {
         ListNode Pnew = (ListNode)malloc(sizeof(Node));
         Pnew->next = NULL;
         printf("第%d个结点的元素为：", i);
         scanf("%d", &Pnew->val);
         Last->next = Pnew;
         Last = Pnew;
     }
 }
 //输出链表
 void Print_2_Node(ListNode head) 
 {
        ListNode p = head->next;
        printf("新的链表为：");
        while (p != NULL)
        {
            printf("%d ", p->val);
            p = p->next;
        }
        printf("\n");
}
 //两数求和
 ListNode addTwoNumbers(ListNode l1, ListNode  l2)
 {
    
     //输出链表长度
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
     //从链表1中读数
     int value1 = 0;
     int temp1 = 0;
     ListNode p_1;
     p_1 = l1->next;//指向第一个元素
     for (int i=0;i<count1;i++)//按位读数
     {

         //从链表1里按位读取数字，用temp1接收
         temp1 = p_1->val;
         value1 = pow(10,i) * temp1 + value1;
         p_1 = p_1->next;
                  
     }
    //--------------------------------
     //从链表2中读数
     int value2 = 0;
     int temp2 = 0;
     ListNode p_2;
     p_2 = l2->next;//指向第一个元素
     for (int i = 0; i < count2; i++)//按位读数
     {

         //从链表1里按位读取数字，用temp1接收

         temp2 = p_2->val;
         value2 = pow(10,i) * temp2 + value2;
         p_2 = p_2->next;

     }
     //两个数字相加
     int sumvalue = 0;
     sumvalue = value1 + value2;
     int sum_temp = sumvalue;
     //数字放到数组里（单链表添加元素）
     //1、求sum的位数
     int sum_count = 0;
     do {
         sum_temp = sum_temp / 10;
         sum_count++;
     } while (sum_temp > 0);
     
     //2、动态开辟内存存放各位数字 
     int* ptr = NULL;
     ptr = (int*)malloc(sum_count * sizeof(int));
     if (NULL != ptr)//判断ptr指针是否为空
     {
         int i = 0;
         for (i = 0; i < sum_count; i++)
         {

             *(ptr + i) =sumvalue%10;
             sumvalue /= 10;
         }
     }
     //3、往链表里存放数字(逆序)
     //先创建链表，再存放
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
     //4、释放内存 
     free(ptr);
     ptr = NULL;
     //返回求和链表
     return sum;
 }
 //调试*********************


 int main()
 {
     //初始化两个链表
     ListNode l1 = Init_2_Node();
     ListNode l2 = Init_2_Node();
     Creat_4_Node(l1);
     Creat_4_Node(l2);


     //调用函数
     ListNode p = addTwoNumbers(l1, l2);
     Print_2_Node(l1);
     Print_2_Node(l2);
     Print_2_Node(p);
 }