# define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


//��ʼ��ͨѶ¼
//1.��̬�汾
//void InitContact(Contact* pc)
//{
//	assert(pc);
//	pc->count = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//2.��̬�汾
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
    return 0;
}

//����ͨѶ¼��Ϣ
//1.��̬�汾
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	if (pc->count == MAX)
//	{
//		printf("ͨѶ¼�������޷����");
//		return;
//	}
//	printf("������������>");
//	scanf("%s", pc->data[pc->count].name);
//	printf("���������䣺>");
//	scanf("%d", &(pc->data[pc->count].age));
//	printf("�������Ա�>");
//	scanf("%s", pc->data[pc->count].sex);
//	printf("������绰��>");
//	scanf("%s", pc->data[pc->count].tele);
//	printf("�������ַ��>");
//	scanf("%s", pc->data[pc->count].addr);
//
//	pc->count++;
//	printf("��ӳɹ�\n");
//}

//2.��̬�汾
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
			printf("ͨѶ¼���ݳɹ�\n");
		}
	}
}
void AddContact(Contact* pc)
{
	assert(pc);
	Check_capacity(pc);//����
	
	printf("������������>");
	scanf("%s", pc->data[pc->count].name);
	printf("���������䣺>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("�������Ա�>");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰��>");
	scanf("%s", pc->data[pc->count].tele);
	printf("�������ַ��>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("��ӳɹ�\n");
}
//��ӡͨѶ¼
void ShowContact(const Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼�����ݣ��޷���ӡ");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n","����","����","�Ա�","�绰","��ַ");//%s ��ӡ�ַ���������Ķ�Ϊ�ַ���
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

//������ϵ�˷����±�
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
//ɾ��ͨѶ¼��Ϣ
void DelContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�û����Ϣ��ɾ��");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("������ɾ����ϵ�˵�������>");
	scanf("%s", name);
	//����
	int pos = FindByName(pc,name);
	if (pos == -1)
	{
		printf("ɾ�����˲�����");
		return;
	}
	//ɾ��
	for (i = pos;i < pc->count-1;i++)
	{ 
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
}

//������ϵ�˵���Ϣ
void FindContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ������ϵ�˵�������>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("ɾ�����˲�����");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");//%s ��ӡ�ַ���������Ķ�Ϊ�ַ���
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[pos].name
		, pc->data[pos].age
		, pc->data[pos].sex
		, pc->data[pos].tele
		, pc->data[pos].addr);
}

//�޸���ϵ����Ϣ
void ModifyContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)//�վͲ��ò�����
	{
		printf("ͨѶ¼Ϊ�գ��޷��޸���ϵ����Ϣ");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸ĵ���ϵ��������>");
	scanf("%s", name);
	//����
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("���ҵ���ϵ�˲�����\n");
		return;
	}
	//�޸�
	printf("��������Ҫ�޸ĵĵ���Ϣ��1-���֣�2-���䣬3-�Ա�4-�绰��5-סַ��:>");
	int ret = 0;
	scanf("%d",&ret);
	switch (ret)
	{
	case 1:
		printf("�������µ����֣�>");
		scanf("%s", pc->data[pos].name);
		break;
	case 2:
		printf("�������µ����䣺>");
		scanf("%s", &(pc->data[pos].age));
		break;
	case 3:
		printf("�������µ��Ա�>");
		scanf("%s", pc->data[pos].sex);
		break;
	case 4:
		printf("�������µĵ绰��>");
		scanf("%s", pc->data[pos].tele);
		break;
	case 5:
		printf("�������µ�סַ��>");
		scanf("%s", pc->data[pos].addr);
		break;
	default:
		printf("������������²���\n");
		return;
	}
	printf("�޸ĳɹ�\n");
}


//������ϵ����������
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

