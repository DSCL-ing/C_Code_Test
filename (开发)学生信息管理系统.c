#include<stdio.h>
#include<stdlib.h>
#include<string.h>//strcmp��
#include<dos.h>
#include<conio.h>//����̨������������� getch��
#define LEN sizeof(struct student)
#define FORMAT "%s-%d-%d-%d-%s-%s-%s-%s-%d-%s-5.1%lf-5.1%lf-%s-5.1%lf\n"
#define DATA stu[i].name,stu[i].age,stu[i].year,stu[i].mouth,stu[i].p_num,stu[i].address,stu[i].school,stu[i].major,stu[i].num,stu[i].subject,stu[i].score,stu[i].credit,stu[i].teacher,stu[i].gpa
struct student
{
	
	char name[15];	/*����*/
    int age;//����2
	int year;
	int mouth;//������������34
	char p_num[20];//�ֻ���5
	char address[50];//��ַ6
	char school[15];//ѧУ7
	char major[15];//רҵ8
	int num;		//ѧ��9
	char subject[15];//��Ŀ10
	double score;	//�ɼ�11
	double credit;//ѧ��12
	char teacher[15];	//��ʦ13
	double gpa;		/*ƽ��ѧ��*///14
}stu[50];

void in();				/*¼��ѧ���ɼ���Ϣ*/
int show();			/*��ʾѧ����Ϣ*/
int order();			/*���ܷ�����*/
int del();				/*ɾ��ѧ���ɼ���Ϣ*/
int modify();			/*�޸�ѧ���ɼ���Ϣ*/
int menu();			/*���˵�*/
int insert();			/*����ѧ����Ϣ*/
int total();			/*����������*/
int search();			/*����ѧ����Ϣ*/


int n;
int main()
{
	menu();
	scanf("%d",&n);
	while(n)
	{
		switch(n)
		{
		case 1:in();break;
		case 2:search();break;
		case 3: del();break;
		case 4: modify();break;
		case 5: insert();break;
		case 6: order();break;
		case 7: total();break;
		case 8: show();break;
		default:break;

		}
	}
 getch();
    menu();/*ִ���깦���ٴ���ʾ�˵�����*/
    scanf("%d",&n);
	
}




int menu()//Ŀ¼
{
	printf("ѧ����Ϣ����ϵͳ\n");
	printf("\n");
	printf("1.¼��ѧ����Ϣ\n");
	printf("2.����ѧ����Ϣ\n");
	printf("3.ɾ��ѧ����Ϣ\n");
	printf("4.��ѧ����Ϣ\n");
	printf("5.����ѧ����Ϣ\n");
	printf("6.����\n");
	printf("7.ͳ��ѧ������\n");
	printf("8.��ʾ����ѧ����Ϣ\n");
	printf("9.�˳�ϵͳ\n");
	printf("\n");
	printf("��ѡ��0-9����");
}


/**************************************************************/
void in()//����ѧ����Ϣ
{
	int i,m=0;
	char ch=0;
	FILE *fp;
	//�����ж��ļ��Ƿ����
	//a+ʹ��ǰ���������ã�data.txt�Զ����������İ��ˣ�
	if((fp=fopen("data.txt","a+"))==NULL)
	{	printf("�ļ������ڣ�\n");
	return;
	}
	//���ļ����ں��ж�λ��ָ��λ��
	while(!feof(fp))//feofλ������󣬷���ֵΪ1
	{
		if(fread(&stu[m],LEN,1,fp)==1){
			m++;//��¼�Ѽ�¼��Ϣ�ĸ���
		}
	}
	fclose(fp);//�رղ��ܽ�����һ���ļ�����
	//�����ж�֮ǰ��������ѧ����Ϣ����ʾ
	if(m==0){
		printf("�ļ���û�м�¼\n");
	}
	else{
		show();//������ʾ����ѧ����Ϣģ��
	}
	if((fp=fopen("data.txt","wb"))==NULL)
  	{
	  	printf("�ļ������ڣ�\n");
	  	return;
 	 }

	
	printf("����ѧ����Ϣ(y/n):");
	getchar();
	scanf("%c",&ch);
	while(ch=='Y'||ch=='y')/*�ж��Ƿ�Ҫ¼������Ϣ*/
	{
		printf("number:");
		scanf("%d",&stu[m].num);/*����ѧ��ѧ��*/
		//�ж��Ƿ����ظ�����
		for(i=0;i<m;i++)
		{
			if(stu[i].num==stu[m].num)
			{
				printf("number�Ѿ������ˣ������������!");
				getch();
				fclose(fp);
				return;//���ظ������¿�ʼinģ��
			}
		}
		//����������¼���
		scanf("%s",&stu[m].name[15]);	/*����*/
		getchar();
		scanf("%d",&stu[m].age);//����
		getchar();
		scanf("%d",&stu[m].year);
		getchar();
		scanf("%d",&stu[m].mouth);//������������
		getchar();
		scanf("%d",&stu[m].p_num);//�ֻ���
		getchar();
		scanf("%s",&stu[m].address[50]);//��ַ
		getchar();
		scanf("%s",&stu[m].school[15]);//ѧУ
		getchar();
		scanf("%s",&stu[m].major[15]);//רҵ
		getchar();
		scanf("%d",&stu[m].num)	;
		getchar();	//ѧ��
		scanf("%s",&stu[m].subject[15]);
		getchar();//��Ŀ
		scanf("%d",&stu[m].score);
		getchar();	//�ɼ�
		scanf("%d",&stu[m].credit);
		getchar();//ѧ��
		scanf("%s",&stu[m].teacher[15]);
		getchar();//��ʦ
		scanf("%s",&stu[m].gpa);
		getchar();
		/*ƽ��ѧ��*/
		//�������ݺ�¼��
		if(fwrite(&stu[m],LEN,1,fp)!=1)/*����¼�����Ϣд��ָ���Ĵ����ļ�*/
     	{
		 	printf("���ܱ���!");
		 	getch();
	 	}
     	else
	 	{
		 	printf("%s ������!\n",stu[m].name);
		 	m++;
	 	}
		printf("����?(y/n):");/*ѯ���Ƿ����*/
		scanf("%s",ch);
	
	}
		fclose(fp);
  	printf("OK!\n");

}




int show()//��ʾ����ѧ����Ϣ
{ 
	FILE *fp;
	int i,m=0;
	fp=fopen("data.txt","rb");
  	 
	//  	if((fp=fopen("data.txt","a+"))==NULL)/*��ָ���ļ�*/
	//  	{ 
	//	  	printf("�ļ������ڣ�\n");
	//	  	return;
	//  	}
	//  	fclose(fp);
	//  	if(m==0)
	//	  	printf("�ļ���û�м�¼!\n");
	//		return;	  	
	while(!feof(fp))
	{
		if(fread(&stu[m] ,LEN,1,fp)==1) 
			m++;
   	}  
   	fclose(fp);
   	printf("number  name           elective    experiment  required    sum\t\n");
   	for(i=0;i<m;i++)
    { 
		printf(FORMAT,DATA);/*����Ϣ��ָ����ʽ��ӡ*/
    }
}
int order(){;}			/*���ܷ�����*/
int del(){;}				/*ɾ��ѧ���ɼ���Ϣ*/
int modify(){;}			/*�޸�ѧ���ɼ���Ϣ*/

int insert(){;}		/*����ѧ����Ϣ*/
int total(){;}			/*����������*/
int search(){;}			/*����ѧ����Ϣ*/
