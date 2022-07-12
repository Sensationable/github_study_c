#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

#define DEFAULT_SZ 3
#define INC_SZ 2
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX  10
#define MAX_TELE 12
#define MAX_ADDR 30

//人的信息类型
typedef struct PeoInof
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
} PeoInof;

//通讯录的类型

//1.静态版本
//typedef struct Contact
//{
//	PeoInof date[MAX];
//	int count;//记录当前通讯录中的实际人数
//}Contact;

//2.动态版本
typedef struct Contact
{
	PeoInof* data;
	int count;//记录当前通讯录中的实际人数
	int capacity;//当前通讯录的容量
}Contact;

//初始化通讯录
int InitContact(Contact* pc);

//增加通讯录信息
void AddContact(Contact* pc);

//打印通讯录
void ShowContact(const Contact* pc);

//删除通讯录信息
void DelContact(Contact* pc);

//查找联系人信息
void FindContact(Contact* pc);

//修改联系人信息
void ModifyContact(Contact* pc);

//联系人按照名字排序
void SortContact(Contact* pc);
