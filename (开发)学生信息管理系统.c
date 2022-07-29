#include<stdio.h>
#include<stdlib.h>
#include<string.h>//strcmp、
#include<dos.h>
#include<conio.h>//控制台输入输出函数库 getch、
#define LEN sizeof(struct student)
#define FORMAT "%s-%d-%d-%d-%s-%s-%s-%s-%d-%s-5.1%lf-5.1%lf-%s-5.1%lf\n"
#define DATA stu[i].name,stu[i].age,stu[i].year,stu[i].mouth,stu[i].p_num,stu[i].address,stu[i].school,stu[i].major,stu[i].num,stu[i].subject,stu[i].score,stu[i].credit,stu[i].teacher,stu[i].gpa
struct student
{
	
	char name[15];	/*姓名*/
    int age;//年龄2
	int year;
	int mouth;//出生年月年月34
	char p_num[20];//手机号5
	char address[50];//地址6
	char school[15];//学校7
	char major[15];//专业8
	int num;		//学号9
	char subject[15];//科目10
	double score;	//成绩11
	double credit;//学分12
	char teacher[15];	//教师13
	double gpa;		/*平均学分*///14
}stu[50];

void in();				/*录入学生成绩信息*/
int show();			/*显示学生信息*/
int order();			/*按总分排序*/
int del();				/*删除学生成绩信息*/
int modify();			/*修改学生成绩信息*/
int menu();			/*主菜单*/
int insert();			/*插入学生信息*/
int total();			/*计算总人数*/
int search();			/*查找学生信息*/


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
    menu();/*执行完功能再次显示菜单界面*/
    scanf("%d",&n);
	
}




int menu()//目录
{
	printf("学生信息管理系统\n");
	printf("\n");
	printf("1.录入学生信息\n");
	printf("2.查找学生信息\n");
	printf("3.删除学生信息\n");
	printf("4.改学生信息\n");
	printf("5.插入学生信息\n");
	printf("6.排序\n");
	printf("7.统计学生总数\n");
	printf("8.显示所有学生信息\n");
	printf("9.退出系统\n");
	printf("\n");
	printf("请选择（0-9）：");
}


/**************************************************************/
void in()//输入学生信息
{
	int i,m=0;
	char ch=0;
	FILE *fp;
	//首先判断文件是否存在
	//a+使当前代码无作用，data.txt自动创建，（改版了）
	if((fp=fopen("data.txt","a+"))==NULL)
	{	printf("文件不存在！\n");
	return;
	}
	//当文件存在后，判断位置指针位置
	while(!feof(fp))//feof位置在最后，返回值为1
	{
		if(fread(&stu[m],LEN,1,fp)==1){
			m++;//记录已记录信息的个数
		}
	}
	fclose(fp);//关闭才能进行下一步文件操作
	//综上判断之前有无所有学生信息并显示
	if(m==0){
		printf("文件中没有记录\n");
	}
	else{
		show();//调用显示所有学生信息模块
	}
	if((fp=fopen("data.txt","wb"))==NULL)
  	{
	  	printf("文件不存在！\n");
	  	return;
 	 }

	
	printf("输入学生信息(y/n):");
	getchar();
	scanf("%c",&ch);
	while(ch=='Y'||ch=='y')/*判断是否要录入新信息*/
	{
		printf("number:");
		scanf("%d",&stu[m].num);/*输入学生学号*/
		//判断是否有重复输入
		for(i=0;i<m;i++)
		{
			if(stu[i].num==stu[m].num)
			{
				printf("number已经存在了，按任意键继续!");
				getch();
				fclose(fp);
				return;//有重复后重新开始in模块
			}
		}
		//在正常情况下继续
		scanf("%s",&stu[m].name[15]);	/*姓名*/
		getchar();
		scanf("%d",&stu[m].age);//年龄
		getchar();
		scanf("%d",&stu[m].year);
		getchar();
		scanf("%d",&stu[m].mouth);//出生年月年月
		getchar();
		scanf("%d",&stu[m].p_num);//手机号
		getchar();
		scanf("%s",&stu[m].address[50]);//地址
		getchar();
		scanf("%s",&stu[m].school[15]);//学校
		getchar();
		scanf("%s",&stu[m].major[15]);//专业
		getchar();
		scanf("%d",&stu[m].num)	;
		getchar();	//学号
		scanf("%s",&stu[m].subject[15]);
		getchar();//科目
		scanf("%d",&stu[m].score);
		getchar();	//成绩
		scanf("%d",&stu[m].credit);
		getchar();//学分
		scanf("%s",&stu[m].teacher[15]);
		getchar();//教师
		scanf("%s",&stu[m].gpa);
		getchar();
		/*平均学分*/
		//输入数据后录入
		if(fwrite(&stu[m],LEN,1,fp)!=1)/*将新录入的信息写入指定的磁盘文件*/
     	{
		 	printf("不能保存!");
		 	getch();
	 	}
     	else
	 	{
		 	printf("%s 被保存!\n",stu[m].name);
		 	m++;
	 	}
		printf("继续?(y/n):");/*询问是否继续*/
		scanf("%s",ch);
	
	}
		fclose(fp);
  	printf("OK!\n");

}




int show()//显示所有学生信息
{ 
	FILE *fp;
	int i,m=0;
	fp=fopen("data.txt","rb");
  	 
	//  	if((fp=fopen("data.txt","a+"))==NULL)/*打开指定文件*/
	//  	{ 
	//	  	printf("文件不存在！\n");
	//	  	return;
	//  	}
	//  	fclose(fp);
	//  	if(m==0)
	//	  	printf("文件中没有记录!\n");
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
		printf(FORMAT,DATA);/*将信息按指定格式打印*/
    }
}
int order(){;}			/*按总分排序*/
int del(){;}				/*删除学生成绩信息*/
int modify(){;}			/*修改学生成绩信息*/

int insert(){;}		/*插入学生信息*/
int total(){;}			/*计算总人数*/
int search(){;}			/*查找学生信息*/
