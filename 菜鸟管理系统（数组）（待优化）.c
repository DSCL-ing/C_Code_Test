#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define ROW 3
#define COL 3


int MateData(int num[ROW], char name[ROW][COL]) //ƥ��
{
    int input = 0;
    printf("������ISBN�� ");
    scanf("%d", &input);
    int i = 0;
    for (i = 0; i < ROW; i++)
    {
        if (input == num[i])
        {
            return i;
        }
    }

}

void InitData(int num[ROW],char name[ROW][COL])//init ��ʼ��
{

    int i = 0;
    for ( i = 0; i < ROW; i++)
    {
        printf("������ISBN��");
        scanf("%d", &num[i]);
        printf("������������");
        getchar();
        gets(name[i]);//scanf("%s", &name[ROW][0]);
    }
    printf("��ʼ�����,");
    system("pause");
}

void sort(int num[ROW], char name[ROW][COL])   //����
{
    int i = 0;        
    int j = 0;
    int tmp1 = 0;
    char tmp2[10] = { 0 };
    for ( i = 0; i < ROW-1; i++)
    {
        for ( j = i; j <ROW; j++)
        {
            if (num[i] > num[j])
            {
                tmp1 = num[i];
                num[i] = num[j];
                num[j] = tmp1;
                strcpy(tmp2, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], tmp2);
            }
        }
    }
}

void Search(int num[], char name[][COL])   //���ֲ���
{
    sort(num, name);
    int left = 0, right = ROW-1;
    int mid = 0;
    int input = 0;
    input = MateData(num,name);
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (input < mid)
            right = mid-1;
        else if (input > mid)
            left = mid+1;
        else
        {
            printf("name:%s\n", name[input]);
            system("pause");
            return;
        }
    }
    printf("\n error");
    system("pause");
}

void Print(int num[], char name[][COL])   //������ӡ
{
    sort(num,name);
    int i = 0;
    for ( i = 0; i < ROW; i++)
    {
        printf("ISBN:%-5d ����:%s\n", num[i],name[i]);
    }
    system("pause");
}
void ChangeData(int num[], char name[][COL])   //��������
{
    int i =MateData(num, name);
    printf("���޸�ISBN��������");
    scanf("%d%s", &num[i],name[i]);
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

int main()
{

    int input = 1;
    char name[ROW][COL] = { 0 };
    int num[ROW] = { 0 };

    while (input)
    {
        menu();
        printf("��ѡ����:");
        scanf("%d", &input);
        switch (input)
        {
        case 1:InitData(num,name); break;
        case 2:Print(num,name); break;
        case 3:Search(num,name); break;
        case 4:ChangeData(num, name); break;
        case 0:exit(0);
        }
        system("cls");
    }
    return 0;
}