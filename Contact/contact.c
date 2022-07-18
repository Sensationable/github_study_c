# define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//通讯录增容（检查通讯录是否需要增容，如果需要，就进行增容）
void Check_capacity(Contact* pc)
{
	if (pc->count == pc->capacity)
	{
		PeoInof* ptr = (PeoInof*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInof));
		if (ptr == NULL)
		{
			printf("AddContact::%s\n", strerror(errno));
			return;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			//此处可开可不开，开了可以提示扩容成功
			//printf("通讯录扩容成功\n");
		}
	}
}

//加载文件信息到通讯录中
void LoadContact(Contact* pc)
{
	assert(pc);
	FILE* pfRead = fopen("contact.txt","rb");
	if (pfRead == NULL)
	{
		perror("LoadContact");
		return;
	}
	PeoInof tmp = { 0 };//先创建临时变量，把读入的数据先放入临时变量，然后进行容量检查（不够进行扩容），再把tmp的数据存入通讯录
	while (fread(&tmp, sizeof(PeoInof), 1, pfRead) == 1)
	{
		Check_capacity(pc); // 通讯录增容（检查通讯录是否需要增容，如果需要，就进行增容）
		pc->data[pc->count] = tmp;
		pc->count++;
	}
	fclose(pfRead);
	pfRead = NULL;
}

//初始化通讯录

//1.静态版本
//void InitContact(Contact* pc)
//{
//	assert(pc);
//	pc->count = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//2.动态版本
int InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	pc->data = (PeoInof*)calloc(DEFAULT_SZ, sizeof(PeoInof));
	if (pc->data == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return 1;
	}
	pc->capacity = DEFAULT_SZ;
	//加载文件信息到通讯录中
	LoadContact(pc);
    return 0;
}

//增加通讯录信息
//1.静态版本
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	if (pc->count == MAX)
//	{
//		printf("通讯录已满，无法添加");
//		return;
//	}
//	printf("请输入姓名：>");
//	scanf("%s", pc->data[pc->count].name);
//	printf("请输入年龄：>");
//	scanf("%d", &(pc->data[pc->count].age));
//	printf("请输入性别：>");
//	scanf("%s", pc->data[pc->count].sex);
//	printf("请输入电话：>");
//	scanf("%s", pc->data[pc->count].tele);
//	printf("请输入地址：>");
//	scanf("%s", pc->data[pc->count].addr);
//
//	pc->count++;
//	printf("添加成功\n");
//}

//2.动态版本
void AddContact(Contact* pc)
{
	assert(pc);
	Check_capacity(pc);//增容
	
	printf("请输入姓名：>");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄：>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别：>");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话：>");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址：>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("添加成功\n");
}
//打印通讯录
void ShowContact(const Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录无内容，无法打印\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n","姓名","年龄","性别","电话","地址");//%s 打印字符串，后面的都为字符串
	int i = 0;
	for (i = 0;i < pc->count;i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name
		                                     , pc->data[i].age
			                                 , pc->data[i].sex
			                                 , pc->data[i].tele
		                                     , pc->data[i].addr);
	}
}

//查找联系人返回下标
int FindByName(Contact* pc ,char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0;i < pc->count;i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
//删除通讯录信息
void DelContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	if (pc->count == 0)
	{
		printf("通讯录为空，没有信息可删除");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("请输入删除联系人的姓名：>");
	scanf("%s", name);
	//查找
	int pos = FindByName(pc,name);
	if (pos == -1)
	{
		printf("删除的人不存在");
		return;
	}
	//删除
	for (i = pos;i < pc->count-1;i++)
	{ 
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
}

//查找联系人的信息
void FindContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找联系人的姓名：>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("删除的人不存在");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");//%s 打印字符串，后面的都为字符串
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[pos].name
		, pc->data[pos].age
		, pc->data[pos].sex
		, pc->data[pos].tele
		, pc->data[pos].addr);
}

//修改联系人信息
void ModifyContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)//空就不用查找了
	{
		printf("通讯录为空，无法修改联系人信息");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改的联系人姓名：>");
	scanf("%s", name);
	//查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("查找的联系人不存在\n");
		return;
	}
	//修改
	printf("请输入您要修改的的信息（1-名字，2-年龄，3-性别，4-电话，5-住址）:>");
	int ret = 0;
	scanf("%d",&ret);
	switch (ret)
	{
	case 1:
		printf("请输入新的名字：>");
		scanf("%s", pc->data[pos].name);
		break;
	case 2:
		printf("请输入新的年龄：>");
		scanf("%s", &(pc->data[pos].age));
		break;
	case 3:
		printf("请输入新的性别：>");
		scanf("%s", pc->data[pos].sex);
		break;
	case 4:
		printf("请输入新的电话：>");
		scanf("%s", pc->data[pos].tele);
		break;
	case 5:
		printf("请输入新的住址：>");
		scanf("%s", pc->data[pos].addr);
		break;
	default:
		printf("输入错误，请重新操作\n");
		return;
	}
	printf("修改成功\n");
}


//按照联系人姓名排序
void SortContact(Contact* pc)
{
	int i = 0;
	int j = 0;
	PeoInof tmp;
	for (i = 0; i < pc->count - 1; i++)
	{
		for (j = 0; j < pc->count - 1 - i; j++)
		{
			if (0 < strcmp(pc->data[j].name, pc->data[j + 1].name))
			{
				tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
			}
		}
	}
}


//销毁通讯录
void DestroyContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}

//保存通讯录到文件
void SaveContact(Contact* pc)
{
	assert(pc);
	FILE* pfWrite = fopen("contact.txt","wb");
	if (pfWrite == NULL)
	{
		perror("SaveContact");
		return;
	}
	//写文件-二进制形式
	int i = 0;
	for (i = 0;i < pc->count;i++)
	{
		fwrite(pc->data+i, sizeof(PeoInof), 1, pfWrite);//pc->data+i  是地址，函数需要地址，不可以用pc->data[i]
	}
	fclose(pfWrite);
	pfWrite = NULL;

}