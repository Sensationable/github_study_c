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

//�˵���Ϣ����
typedef struct PeoInof
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
} PeoInof;

//ͨѶ¼������

//1.��̬�汾
//typedef struct Contact
//{
//	PeoInof date[MAX];
//	int count;//��¼��ǰͨѶ¼�е�ʵ������
//}Contact;

//2.��̬�汾
typedef struct Contact
{
	PeoInof* data;
	int count;//��¼��ǰͨѶ¼�е�ʵ������
	int capacity;//��ǰͨѶ¼������
}Contact;

//��ʼ��ͨѶ¼
int InitContact(Contact* pc);

//����ͨѶ¼��Ϣ
void AddContact(Contact* pc);

//��ӡͨѶ¼
void ShowContact(const Contact* pc);

//ɾ��ͨѶ¼��Ϣ
void DelContact(Contact* pc);

//������ϵ����Ϣ
void FindContact(Contact* pc);

//�޸���ϵ����Ϣ
void ModifyContact(Contact* pc);

//��ϵ�˰�����������
void SortContact(Contact* pc);
