#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define ROW 3
#define COL 3


typedef struct BOOK
{
    int num;
    char name[20];
    int price;
}BOOK;

int main()
{
    void InitData(BOOK* book);
    int MateData(BOOK* book);
    void InitData(BOOK* book);
    void sort(BOOK* book);
    void Search(BOOK* book);
    void Print(BOOK* book);
    void ChangeData(BOOK* book);
    void menu();

    BOOK book[ROW] = { 0, { 0 }, 0 };
    int input = 1;
    while (input)
    {
        menu();
        printf("��ѡ����:");
        scanf("%d", &input);
        switch (input)
        {
        case 1:InitData(&book); break;
        case 2:Print(&book); break;
        case 3:Search(&book); break;
        case 4:ChangeData(&book); break;
        case 0:exit(0);
        }
        system("cls");
    }
    return 0;
}

int MateData(BOOK* book) //ƥ��
{
    int input = 0;
    printf("������ISBN�� ");
    scanf("%d", &input);
    int i = 0;
    for (i = 0; i < ROW; i++)
    {
        if (input == book[i].num)
        {
            return i;
        }
    }
    
}

void InitData(BOOK* book)//init ��ʼ��
{

    int i = 0;
    for (i = 0; i < ROW; i++)
    {
        printf("������ISBN��");
        scanf("%d", &book[i].num);
        printf("������������");
        scanf("%s", &book[i].name);
        printf("������۸�");
        scanf("%d", &book[i].price);
    }
    printf("��ʼ�����,");
    system("pause");
}

void sort(BOOK* book)   //����
{
    int i = 0;
    int j = 0;
    int tmp1 = 0;
    char tmp2[20] = { 0 };
    int tmp3 = 0;
    for (i = 0; i < ROW - 1; i++)
    {
        for (j = i; j <ROW; j++)
        {
            if (book[i].num > book[j].num)
            {
                tmp1 = book[i].num;
                book[i].num = book[j].num;
                book[j].num = tmp1;
                strcpy(tmp2, book[i].name);
                strcpy(book[i].name, book[j].name);
                strcpy(book[j].name, tmp2);
                //strcpy(tmp3, book[i].price);
                //strcpy(book[i].price, book[j].price);
                //strcpy(book[j].price, tmp3);
                tmp3 = book[i].price;
                book[i].price = book[j].price;
                book[j].price = tmp3;
            }
        }
    }
}

void Search(BOOK* book)   //���ֲ���
{
    sort(book);
    int left = 0, right = ROW - 1;
    int mid = 0;
    int input = 0;
    input = MateData(book);
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (input < mid)
            right = mid - 1;
        else if (input > mid)
            left = mid + 1;
        else
        {
            printf("name:%-10s\n", book[input].name);
            printf("price:%-d\n", book[input].price);
            system("pause");
            return;
        }
    }
    printf("\n �Ҳ���");
    system("pause");
}

void Print(BOOK* book)   //������ӡ
{
    sort(book);
    int k = 0;
    for (k = 0; k < ROW; k++)
    {
        //printf("ISBN:%-5d", book[k].num);
        //printf("����:%-s", book[k].name);
        //printf("�۸�:%-5d\n", book[k].price);
        printf("ISBN:%-5d ����:%-10s �۸�%d\n", book[k].num, book[k].name, book[k].price);
    }
    system("pause");
}
void ChangeData(BOOK* book)   //����
{
    //char arr[20] = { 0 };
    int i = MateData(book);
    printf("���޸�ISBN��������");
    //scanf("%d", &book[i].num);
    //scanf("%s", book[i].name);
    //scanf("%d", &book[i].price);
    //scanf("%s", &arr);
    //strcpy(book[i].name, arr);
    scanf("%d%s%d", &book[i].num, book[i].name, &book[i].price);
    printf("�޸����,");
    system("pause");
}

void menu()
{
    printf("*****************************************\n");
    printf("*** 1.��ʼ������   2.��ʾ�Ѵ洢����   ***\n");
    printf("*** 3.��������     4.�޸�����         ***\n");
    printf("*** 0.exit                            ***\n");
    printf("*****************************************\n");

}


