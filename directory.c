#include "directory.h"
enum MuneSelect {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	DISPLAY
};
int main()
{
	int input = 0;
	//enum MuneSelect muneselect1;
	//Directory directory1;
	Directory* pdirectory1 = calloc(MAX_PEO, sizeof(Directory));
	if (pdirectory1 == NULL)
	{
		perror("main");
		return 0;
	}

	Directory directory1 = *pdirectory1;
	InitializeDirectory(&directory1);
	//int findnum[MAX_PEO] = { 0 };
	do {
		mune();
		//输入流的控制
		int ret;
		ret = scanf_s("%d", &input);
		switch(input) {
			case EXIT:
				break;
			case ADD:
				AddDirectory(&directory1);
				break;
			case DEL:
			//	DelDirectory(&directory1,findnum);
			DelDirectory(&directory1);

				break;
			case SEARCH:
				SearchDirecory(&directory1);
				break;
			case MODIFY:

				break;
			case DISPLAY:
				DisplayDirectory(&directory1);
				break;
			default:
				printf(" 选择错误，请重新输入\n");
				break;
		}
	} while (input);
	free(&directory1);
	return 0;
}
