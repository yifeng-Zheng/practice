#include"directory.h"
void mune()
{
	printf("*******************************************\n");
	printf("*****    1.ADD          2.DEL        ******\n");
	printf("*****    3.SEARCH       4.MODIFY     ******\n");
	printf("*****    5.DISPLAY                   ******\n");
	printf("*****            0.EXIT              ******\n");
	printf("*******************************************\n");

}

void InitializeDirectory(Directory* pdirectory)
{
	assert(pdirectory);
	pdirectory->length = 0;
	memset(&(pdirectory->date), 0, sizeof(pdirectory->date));
}
void DisplayDirectory(const Directory* pdirectory) 
{
	printf("%-5s\t %-3s\t %-3s\t %-10s\t %-15s\n","����","�Ա�","����","�绰","��ַ");
	for (int i = 0; i < (pdirectory->length); i++)
	{
	
		printf("%-5s\t %-3s\t %-3d\t %-10s\t %-15s\n",
			&(pdirectory->date[i].name), 
			&(pdirectory->date[i].sex), 
			pdirectory->date[i].age, 
			&(pdirectory->date[i].telephone),
			&(pdirectory->date[i].address));
	}
}
void AddDirectory(Directory* pdirectory) {
	if (pdirectory->length == MAX_PEO) {
		//printf("ͨѶ¼�������޷����\n");
		Directory* ret = NULL;
		ret =(Directory*)realloc(pdirectory,(pdirectory->length+2)*sizeof(Directory));
		if (ret == NULL)
		{
			printf("�ڴ濪��ʧ��\n");

			//ferror("main");
		}
		pdirectory = ret;

	}
	printf("����������\n");
	scanf_s("%s",pdirectory->date[pdirectory->length].name,MAX_NAME);
	
	printf("�������Ա�\n");
	scanf_s("%s", pdirectory->date[pdirectory->length].sex,MAX_SEX);

	printf("����������\n");
	scanf_s("%d",&( pdirectory->date[pdirectory->length].age));

	printf("������绰\n");
	scanf_s("%s", pdirectory->date[pdirectory->length].telephone,MAX_TELEPHONE);
	
	printf("�������ַ\n");
	scanf_s("%s", pdirectory->date[pdirectory->length].address,MAX_ADDRESS);

	printf("��ӳɹ�\n");
	pdirectory->length++;
}
//void InitializeIntNum(int* num,int x) {
//	assert(num);
//	for (int k = 0; k < MAX_PEO; k++)
//	{
//		num[k] = x;
//	}
//}
//void FindName(Directory* directory1,int*fnum) 
//{
//	printf("��������ϵ�˵�����\n");
//	char input[MAX_NAME] = { 0 };
//	InitializeIntNum(fnum,-1);
//	int j = 0;
//	scanf_s("%s", input, MAX_NAME);
//	assert(input&&directory1&&fnum);
//	for (int i = 0; i < directory1->length; i++)
//	{
//		int cmp = strcmp(input, directory1->date[i].name);
//		if (cmp == 0)
//		{
//			fnum[j] = i;
//			j++;
//		}
//	}
//
//}
int FindName(const Directory* directory1)
{
	printf("��������ϵ�˵�����\n");
	char input[MAX_NAME] = { 0 };
	int j = 0;
	scanf_s("%s", input, MAX_NAME);
	assert(input && directory1);
	for (int i = 0; i < directory1->length; i++)
	{
		int cmp = strcmp(input, directory1->date[i].name);
		if (cmp == 0)
		{
			return i;
		}

	}
	return -1;
}

void DelDirectory(Directory* directory1) 
{
	assert(directory1);
	if (directory1->length == 0)
	{
		printf("�绰��Ϊ��\n");
		return;
	}
	int num = FindName(directory1);
	if (num == -1)
	{
		printf("δ�ҵ���ϵ��\n");
		return;
	}

	if (num == MAX_PEO)
		{
			directory1->length--;
			printf("ɾ���ɹ�\n");
			return;
		}
	int i = 0;
	for (i = num; i < directory1->length ;i++)
	{
		strcpy(directory1->date[i].name, directory1->date[i+ 1].name);
		strcpy(directory1->date[i].sex, directory1->date[i+ 1].sex);
		directory1->date[i].age = directory1->date[i+ 1].age;
		strcpy(directory1->date[i].telephone, directory1->date[i+ 1].telephone);
		strcpy(directory1->date[i].address, directory1->date[i+ 1].address);
	}
	directory1->length--;
	printf("ɾ���ɹ�\n");
	return;
}
void SearchDirecory(const Directory* directory1)
{
	int pos = FindName(directory1);
	if (pos == -1)
	{
		printf("δ�ҵ���ϵ��\n");
		return;
	}
	printf("%-5s\t %-3s\t %-3s\t %-10s\t %-15s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	printf("%-5s\t %-3s\t %-3d\t %-10s\t %-15s\n",
		&(directory1->date[pos].name),
		&(directory1->date[pos].sex),
		directory1->date[pos].age,
		&(directory1->date[pos].telephone),
		&(directory1->date[pos].address));
}