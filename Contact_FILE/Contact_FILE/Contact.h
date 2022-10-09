#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

        
#define DEFAULT_SZ 1000
#define MAX_NAME 10   
#define MAX_SEX 5
#define MAX_TELE 20
#define MAX_ADDR 30
//#define MAX_SIZE 1000  //size��С


//����������
enum option{ EXIT, ADD, DEL, SEARCH, MOD, SHOW ,SAVE};


//��Ա��Ϣ//name sex age tele address
struct PeopleInformation
{
    char name[MAX_NAME];
    char sex[MAX_SEX];
    int age;
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};

//ͨѶ¼��Ϣ
struct Contact
{
    int size;
    int capacity;//����
    struct PeopleInformation *data;//ֻ�ܴ�Ԥ����ָ��ı�����
};

//��ʼ��
void Initialization(struct Contact *ps);


//�������
void Add(struct Contact * ps);


//ɾ������
void Del(struct Contact *ps);

//��ʾ����
void Show(const struct Contact *ps);

//��������
void Search(const struct Contact *ps);

//�޸�����
void Mod(struct Contact *ps);

//���ٿռ�
void Destroy(struct Contact *ps);

//�洢���ļ�
void Save(struct Contact *ps);

//�������������
void CheckCapacity(struct Contact*ps);