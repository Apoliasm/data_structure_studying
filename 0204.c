#include <stdio.h>
#include <stdlib.h>

int binarysearch(int target)
{
    int arr[10] = {1,3,5,7,11,18,25,30,44,80};
    int first =0;
    int last = 9;
    int point = last/2;


    while (first<=last)
    {
        if(arr[point] == target)
        {
            printf("it's %d",point);
            return 0;
        }
        else if (arr[point] > target)
        {
            last = point-1;  //last = point -> point - 1 : no need to explore old index(int point) 
            point = (first+last)/2;
        }
        else if(arr[point]<target)
        {
            first = point+1; //first = point + 1
            point = (first+last)/2;
        }
        

    }
    return -1;
}

int recursion_factorial(int n)
{
    int result;
    if (n == 1)
    {
        return 0;
    }
    else
        return n*recursion_factorial(n-1);
}

int recursioin_fibonacci(int last)
{
    if(last == 1)
    {
        return 1;
    }
    else if (last == 2)
    {
        return 2;
    }
    
    else
    {
        return recursioin_fibonacci(last-1) + recursioin_fibonacci(last-2);
    }
}
int recursion_binarysearch(int target,int first ,int last)
{
    int arr[11] = {1,3,5,7,11,18,25,30,44,80,99};
    int point = (first+last)/2;
    if(first>last)
    {
        printf("it's -1 \n");
        return 0;
    }
    if(arr[point] == target)
    {
        printf("it's %d\n",point);
        return 0;
    }
    else if(arr[point] > target)
    {
        return recursion_binarysearch(target,first,point-1);
    }
    else if (arr[point]<target)
    {
        return recursion_binarysearch(target,point+1,last);
    }

}
struct setting
{
    int*a_column;
    int*b_column;
    int*c_column;
    int floor;
};
typedef struct setting setting;
void print_hanoi(setting *hanoi,int original)
{
    for(int i =0;i<original;i++)
    {
        printf("%d         %d         %d\n",hanoi->a_column[original-1-i],hanoi->b_column[original-i-1],hanoi->c_column[original-1-i]);
    }    
    printf("\n");
}
void recursion_hanoitop  (setting *hanoi,int original,int floor,char fromcol, char bycol,char tocol)
{
    if (floor == 1)
    {
        printf("move 1 from %c to %c\n",fromcol,tocol);
    }
    else
    {
        recursion_hanoitop(hanoi,original,floor-1,fromcol,tocol,bycol); //move n-1 pieces
        printf("move %d from %c to %c\n",floor,fromcol,tocol);//move the largest piece
        recursion_hanoitop(hanoi,original,floor-1,bycol,fromcol,tocol);//move n-1 on largest
    }
}
int main()
{
    /*int targ ;
    scanf("%d",&targ);
    int ret = binarysearch(targ);
    if (ret == -1)
        printf("its -1");*/

    /*
    for(int i = 1 ; i <15;i++)
    {
        printf("%d = %d \n",i,recursioin_fibonacci(i));
    }*/

    /*
    recursion_binarysearch(1,0,10);
    recursion_binarysearch(9,0,10);
    recursion_binarysearch(11,0,10);
    recursion_binarysearch(18,0,10);
    recursion_binarysearch(45,0,10);
    recursion_binarysearch(99,0,10);
    recursion_binarysearch(111,0,10);*/
    setting basic;
    int floor =8;
    basic.floor = floor;
    basic.a_column = (int*)malloc(sizeof(int)*floor);
    basic.b_column = (int*)malloc(sizeof(int)*floor);
    basic.c_column = (int*)malloc(sizeof(int)*floor);
    for(int i = 0;i<floor;i++)
    {
        basic.a_column[i] = floor-i;
        basic.b_column[i] =0;
        basic.c_column[i] = 0;
    }
    print_hanoi(&basic,floor);
    recursion_hanoitop(&basic,floor,floor,'a','b','c');
    free(basic.a_column);
    free(basic.b_column);
    free(basic.c_column);
    


}

