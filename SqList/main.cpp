#include <stdio.h>

#define MaxSize 50
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

void PrintSqList(SqList sqList)
{
    if(sqList.length == 0)
    {
        return;
    }
    for(int i=0;i<sqList.length;i++)
    {
        printf("%3d",sqList.data[i]);
    }
    printf("\n");
}

void InsertList(SqList &sqList,ElemType e)
{
    for(int i=sqList.length;i>1;i--)
    {
        sqList.data[i] = sqList.data[i-1];
    }
    sqList.data[1] = e;
    sqList.length++;
}

bool DeleteList(SqList &sqList,int DeletePos)
{
    if(DeletePos < 0 || DeletePos == 0 || DeletePos > sqList.length)
    {
        return false;
    }
    for(int i=DeletePos-1;i<sqList.length-1;i++)
    {
        sqList.data[i] = sqList.data[i+1];
    }
    sqList.length--;
    return true;
}

int main() {
    SqList sqList;
    ElemType e;
    int DeletePos;
    sqList.data[0] = 1;
    sqList.data[1] = 2;
    sqList.data[2] = 3;
    sqList.length = 3;
    scanf("%d",&e);
    InsertList(sqList,e);
    PrintSqList(sqList);
    scanf("%d",&DeletePos);
    if(DeleteList(sqList,DeletePos))
    {
        PrintSqList(sqList);
    } else{
        printf("false\n");
    }
    return 0;
}
