#define _CRT_SECURE_NO_WARNINGS 1

#include"Contact.h"



void loadContact(struct Contact*ps)//�����ļ���¼
{
    int i = 0;
    FILE*pf = fopen("Contact.txt", "r");
    if (pf == NULL){
        perror("�ļ������ڣ���ʼ��");
        fclose(pf);
        pf = NULL;
        return;
    }
        struct PeopleInformation tmp = { 0 };
        while (fread(&tmp, sizeof(struct PeopleInformation), 1, pf))
        {
            ps->data[ps->size] = tmp;
            ps->size++;
            CheckCapacity(ps);
        }
    fclose(pf);
    pf = NULL;
}

//��ʼ�����ǰ�������СΪ0������������Ԫ��Ϊ0
void Initialization(struct Contact *ps)
{
    //int i = 0;
    //memset(ps->data, 0, sizeof(ps->data));//ֻ����0�������ֽڶ����ó�0��ps->data(���������ǵ�ַ����sizeof����������������������Ĵ�С

    ps->data = (struct PeopleInformation*)malloc(DEFAULT_SZ*sizeof(struct PeopleInformation));
    if (ps->data == NULL){
        perror("��ʼ������ʧ��");
        return;
    }
    ps->size = 0;
    ps->capacity = DEFAULT_SZ;
    loadContact(ps);
}

void CheckCapacity(struct Contact*ps)//��鲢����
{
    if (ps->capacity <= ps->size){
        //printf("�ڴ�����\n");
    }
    else{
        return;
    }
    struct PeopleInformation* ptr = (struct PeopleInformation*)realloc(ps->data, (ps->capacity + 2)*sizeof(struct PeopleInformation));
    if (ptr != NULL){             //���ݳɹ�����ִ����һ��
        ps->data = ptr;
        ps->capacity += 2;
        printf("���ݳɹ�\n");
    }
    else{
        perror("����ʧ��");
        return;
    }
}

//������ݣ���size����
void Add(struct Contact * ps)
{
    CheckCapacity(ps);//ֵ���ݣ���ַ����ȥ�ˣ�����NULL�����ⲻ��
        printf("����������>:"); 
        scanf("%s", ps->data[ps->size].name);
        printf("�������Ա�>:"); 
        scanf("%s", ps->data[ps->size].sex);
        printf("����������>:"); 
        scanf("%d", &(ps->data[ps->size].age));
        printf("���������>:"); 
        scanf("%s", ps->data[ps->size].tele);
        printf("�������ַ>:"); 
        scanf("%s", ps->data[ps->size].addr);
    ps->size++;
    printf("��ӳɹ�\n");
}

static int Find(const struct Contact *ps)//��̬�����������ڵ�ǰ�ļ���ʹ�ã������ڴ��ļ���������緢��
{
     char name[MAX_NAME];
    scanf("%s", name);
    int i = 0;
    for (i; i < ps->size; i++)
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
        for (i ; i < ps->size - 1; i++)
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

void Destroy(struct Contact *ps)
{
    free(ps->data);
    ps->data = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

void Save(struct Contact *ps)
{
    int i = 0;
    FILE*pf = fopen("Contact.txt", "w");
    if (pf == NULL)
    {
        perror("���ļ�ʧ��");
        return;
    }
    for ( i = 0; i < ps->size; i++)
    {
        fwrite(ps->data + i, sizeof(struct PeopleInformation), 1, pf);
    }
    fclose(pf);
    pf = NULL;
    printf("�ļ�����ɹ�\n");
}