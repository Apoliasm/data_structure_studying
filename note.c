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
    1. 포인터 변수 : asterisk를 붙여 nump가 가리키는 주소에 있는 변수를 참조하기 위함
    2. asterisk없이 포인터변수만을 지정하는 행위는 주소값을 받기 위함이다.
    3. 포인터 변수끼리의 연산은 주소값의 연산이므로 의미가 없음
    4. 
    */

   int lists[3] = {77,88,99};
   printf("list[0] = %d, *list = %d,lists=%d, &list[0] = %u, list+1 = %u, *(list+1) = %d \n",lists[0],*lists,lists,&lists[0],lists+1,*(lists+1));
   printf("*list+1 = %d\n",*lists+1);
   /*list[0] = 77, *list = 77,lists=6421996, &list[0] = 6421996, list+1 = 6422000, *(list+1) = 88
   *list+1 = 78
   배열과 포인터 : 배열의 이름 = 리스트의 주소값 ->배열의 간접참조시 사용 -> 주소값이므로 당연히 직접참조는 x -> list != list[0]
   *list -> 배열 인덱스에 직접 관여 -> *(list+1) = list[1] 
   주소값 : &list[i] == list+i
   참조값 : list[i] = *(list+i)
   결론 : list = 주소값, *(list) = 주소값 안에 index
   활용 : 함수로 사용 시 int function(int *p).. -> function(list); , function(list), 
   int arr[3] = {..}; , printf("%d",*(arr)); 가능                 //(X) function(&list)
   
   int a = 3;   
   int b = 5;
   int c = 7;
   int *pa[3];
   pa[0] = &a; pa[1]=&b; pa[2]=&c;
   printf("pa[0] = %u, pa[1] = %u, pa[2] = %u\n",pa[0],pa[1],pa[2]);

   /*포인터 배열 = 주소값들을 담아놓은 배열 -> int *pa[3] 같이 선언*/ 
    #define NUMSTD 5
    char lecture[NUMSTD][10] = { "이현수", "김기수", "김범용", "장기태", "이명수" };
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
    //이차원 배열 참조 : *( * (p+i) + j ) ->첫 번째 배열에서 한번 *감싸기 -> 더하고 두 번째 *감싸기

   






   

}