#define _CRT_SECURE_NO_WARNINGS 1

#include"Contact.h"


//��ʼ�����ǰ�������СΪ0������������Ԫ��Ϊ0
void Initialization(struct Contact *ps)
{
    int i = 0;
    ps->size = 0;

        memset(ps->data, 0, sizeof(ps->data));//ֻ����0�������ֽڶ����ó�0��ps->data(���������ǵ�ַ����sizeof����������������������Ĵ�С
}

//������ݣ���size����
void Add(struct Contact * ps)
{
    if (MAX_SIZE == ps->size)
        printf("�ڴ�����");
    else
    {
        printf("����������>:"); scanf("%s", ps->data[ps->size].name);
        printf("�������Ա�>:"); scanf("%s", ps->data[ps->size].sex);
        printf("����������>:"); scanf("%d", &ps->data[ps->size].age);
        printf("���������>:"); scanf("%s", ps->data[ps->size].tele);
        printf("�������ַ>:"); scanf("%s", ps->data[ps->size].addr);
    }
    ps->size++;
    printf("��ӳɹ�\n");
}

static int Find(const struct Contact *ps)//��̬�����������ڵ�ǰ�ļ���ʹ�ã������ڴ��ļ���������緢��
{
     char name[MAX_NAME];
    scanf("%s", name);
    int i = 0;
    for (i; i < MAX_SIZE; i++)
    {
        if (0 == strcmp(ps->data[i].name,name))
        {
            return i;
        }
    }
    return -1;
}

void Del(struct Contact *ps)
{
    int i = 0;
    printf("��������>:");
    scanf("%d", &i);
    if (i < 0 && i >= ps->size)
    {
        printf("���ݲ�����\n");
    }
    else
    {
        //printf("���ڸ�����,�Ƿ�ɾ����Y\N��\n");
        //printf("%-20s\t%-10s\t%-5d\t%-20s\t%-30s\n", ps->data[i].name, ps->data[i].sex, ps->data[i].age, ps->data[i].tele, ps->data[i].addr);
        //scanf()
        int i = 0;
        for (i ; i < MAX_SIZE - 1; i++)
        {
            ps->data[i] = ps->data[i++];
        }
        ps->size--;//������һ������С��һ
        printf("ɾ���ɹ�");
    }
}

void Show(const struct Contact *ps)
{
    if (ps->size == 0)
        printf("������\n");
    else
    {
        printf("NO:     %-10s\t%-5s\t%-5s\t%-20s\t%-30s\n", 
            "name",
            "sex",
            "age", 
            "tele", 
            "addr");
        for (int i = 0; i < ps->size; i++)
        {
            printf("NO.%-d\t%-10s\t%-5s\t%-5d\t%-20s\t%-30s\n",
                i+1,
                ps->data[i].name,
                ps->data[i].sex,
                ps->data[i].age, 
                ps->data[i].tele,
                ps->data[i].addr);
        }
    }
}

void Search(const struct Contact *ps)
{
    printf("��������ҵĶ���>:\n");

    int i = Find(ps);
    if (i == -1)
    {
        printf("���ݲ�����\n");
    }
    else
    {
        printf("NO.%-d\t%-20s\t%-10s\t%-5d\t%-20s\t%-30s\n",
            i+1,
            ps->data[i].name,
            ps->data[i].sex, 
            ps->data[i].age, 
            ps->data[i].tele, 
            ps->data[i].addr);
    }
}

void Mod(struct Contact *ps)
{
    int i = 0;
    printf("��������>:");
    scanf("%d", &i);
    if (i < 0 && i >= ps->size)
    {
        printf("���ݲ�����\n");
    }
    else
    {
        printf("����������>:"); scanf("%s", ps->data[i-1].name);
        printf("�������Ա�>:"); scanf("%s", ps->data[i-1].sex);
        printf("����������>:"); scanf("%d", &ps->data[i-1].age);
        printf("���������>:"); scanf("%s", ps->data[i-1].tele);
        printf("�������ַ>:"); scanf("%s", ps->data[i-1].addr);
        printf("�޸ĳɹ�\n");
    }
}

