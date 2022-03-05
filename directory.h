#pragma once
#pragma warning(disable : 4996)
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#define MAX_PEO 2
#define MAX_NAME 20 
#define MAX_SEX 5
#define MAX_TELEPHONE 5
#define MAX_ADDRESS 5

void mune();
typedef struct PeopleInformation {
	char name[MAX_NAME];
	char sex[MAX_SEX];
	 int age;
	char telephone[MAX_TELEPHONE];
	char address[MAX_ADDRESS];
}PeoInf;
typedef struct Directory {
	PeoInf date[MAX_PEO];
	int length;
}Directory;
void InitializeDirectory(Directory* pdirectory);
void DisplayDirectory(const Directory* pdirectory);
void AddDirectory(Directory* pdirectory);
//void DelDirectory(Directory* directory1,int*findnum);
//void FindName(Directory* directory1,int*findnum);
// 
void DelDirectory(Directory* directory1);
int FindName(const Directory* directory1);
void SearchDirecory(const Directory* directory1);