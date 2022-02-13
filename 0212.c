#include <stdio.h>
#include <stdlib.h>


int main()
{
    typedef struct _node 
    {
        int data;
        struct _node* next; //typedef 되기 전이므로 node*가 아닌 _node* 사용ㅇ
    }node;//-> 이렇게 옆에 쓰는 것은 typedef struct{};일때 사용 -> 그냥 struct{};일때 쓰면 struct 변수 선언임!
    //왜 포인터 변수? = 동적으로 메모리 할당해서 유동적으로 형성하는 것이 연결리스트의 핵심이니까

    node* head = NULL;
    node* current = NULL;
    node* tail = NULL;
    node* making = NULL;
    node* dummy = NULL;//추가된 더미
    //node * latest = NULL;
    //head 없으면 헤드 추가 동시에 헤드로, 헤드 있으면 새로 만든 블록을 최근에 넣은 곳에 향하기, 새로 만든 것은 헤드로
    int list[5] = {3,2,7,8,5};
    for(int i = 0 ; i <5; i++)
    {
        making = (node*)malloc(sizeof(node)); // node* making = (node*)malloc(sizeof(node))
        making->data = list[i];
        making->next = NULL;//처음 만들 때는 화살표의 방향을 null로 지정하기 : 쓰레기값으로 채우면 에러발생 가능성 높음
        if(head == NULL)
        {
            head = making;
            tail = head;
        }
        else
        {
            making->next = head;//제일 최근에 만든게 head이니 latest같은 새 변수 x 그냥 헤드로 향하면 됨
            head = making;
        }
        //latest = making; //32785 순으로 넣어서 58723 순서대로 넣기
    }    
    //출력
    if(head == NULL)
    {
        printf("it doesnt exist head\n");
    }
    else
    {
        current=head;
        printf("data = %d\n",current->data);
        while(current->next != NULL) //조건문에서 반복하고 싶을 때? -> 조건문에 void 타입의 명령문일때->단순한 변수비교는 x
        {
            current = current->next;//다음 블록 지시
            printf("data = %d\n",current->data);
        }
    }




}