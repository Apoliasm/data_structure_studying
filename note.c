#include <stdio.h>

int main()
{
    int num = 15;
    
    int* nump = &num;
    *nump = 25;
    printf("address = %u, num = %d\n",&num,num);
    printf("address = %u, point = %p, num = %d\n",&*nump,*nump,*nump);
    printf("address = %u, point = %p, num=%d\n",&nump,nump,nump);
    printf("*nump = %d\n",*nump);
    printf("nump = %d\n",nump);

    /*
    address = 6422044, num = 25
    address = 6422044, point = 0000000000000019, num = 25
    address = 6422032, point = 000000000061FE1C, num=6422044
    *nump = 25
    nump = 6422044*/

    /*
    basic pointer
    1. ������ ���� : asterisk�� �ٿ� nump�� ����Ű�� �ּҿ� �ִ� ������ �����ϱ� ����
    2. asterisk���� �����ͺ������� �����ϴ� ������ �ּҰ��� �ޱ� �����̴�.
    3. ������ ���������� ������ �ּҰ��� �����̹Ƿ� �ǹ̰� ����
    4. 
    */

   int lists[3] = {77,88,99};
   printf("list[0] = %d, *list = %d,lists=%d, &list[0] = %u, list+1 = %u, *(list+1) = %d \n",lists[0],*lists,lists,&lists[0],lists+1,*(lists+1));
   printf("*list+1 = %d\n",*lists+1);
   /*list[0] = 77, *list = 77,lists=6421996, &list[0] = 6421996, list+1 = 6422000, *(list+1) = 88
   *list+1 = 78
   �迭�� ������ : �迭�� �̸� = ����Ʈ�� �ּҰ� ->�迭�� ���������� ��� -> �ּҰ��̹Ƿ� �翬�� ���������� x -> list != list[0]
   *list -> �迭 �ε����� ���� ���� -> *(list+1) = list[1] 
   �ּҰ� : &list[i] == list+i
   ������ : list[i] = *(list+i)
   ��� : list = �ּҰ�, *(list) = �ּҰ� �ȿ� index
   Ȱ�� : �Լ��� ��� �� int function(int *p).. -> function(list); , function(list), 
   int arr[3] = {..}; , printf("%d",*(arr)); ����                 //(X) function(&list)
   
   int a = 3;   
   int b = 5;
   int c = 7;
   int *pa[3];
   pa[0] = &a; pa[1]=&b; pa[2]=&c;
   printf("pa[0] = %u, pa[1] = %u, pa[2] = %u\n",pa[0],pa[1],pa[2]);

   /*������ �迭 = �ּҰ����� ��Ƴ��� �迭 -> int *pa[3] ���� ����*/ 
    #define NUMSTD 5
    char lecture[NUMSTD][10] = { "������", "����", "�����", "�����", "�̸��" };
    int point[NUMSTD][4] = { { 97, 90, 88, 95 }, { 76, 89, 75, 83 }, { 60, 70, 88, 82 }, { 83, 89, 92, 85 }, { 75, 73, 72, 78 } };
    for(int i = 0 ; i<5;i++)
    {
        char *pname = lecture[i];
        int sum = 0;
        for(int j = 0;j<4;j++)
        {
            int score = *(*(point+i)+j);
            sum += score;
        }
        printf("%s : score = %d, average = %d\n",pname,sum,sum/4);
    }
    //������ �迭 ���� : *( * (p+i) + j ) ->ù ��° �迭���� �ѹ� *���α� -> ���ϰ� �� ��° *���α�

   






   

}