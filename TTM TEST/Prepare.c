#include "Prepare.h"

// Ÿ��Ʋ �Լ�
void Title(char *ver)
{
	char *ttm[13] = {
		"                                                ",
		" ������  ������  ��      ��  ��                 ",
		"   ��    ������  ��      ����                   ",
		"   ��    ��  ��  ������  ��  ��                 ",
		"                                                ",
		" ������  ������                                 ",
		"   ��    ��  ��                                 ",
		"   ��    ������                                 ",
		"                                                ",
		" ������  ������  ��      ������  ��  ��  ��  �� ",
		" ������  ������  ��      ������  ��  ��  ����   ",
		" ��  ��  ��  ��  ������  ������  ������  ��  �� ",
		"                                                "
	};
	system("color f0");
	TITLECOLOR;
	for (int i = 0; i < 13; i++){
		printMiddle(ttm[i], 4 + i);
	}
	MAINCOLOR;
	printMiddle(ver, 18);

	while (!kbhit()){
		printMiddle("press any key!", 20);
		Sleep(500);
		printMiddle("              ", 20);
		Sleep(500);
	}
	getch();
	system("cls");
}

// �ʱ� ���� �Լ�
void Setting()
{
	SetCursorType(NOCURSOR);		// Ŀ�� ����
	system("title Talk to Malsuk"); // �ܼ� Ÿ��Ʋ ����
	system("mode con:lines=25");	// �ܼ� ũ�� ����
	srand((unsigned)time(NULL));	// ���� �õ� ����
}
// ���� ���� �Լ�
void makeFiles(char *name)
{
	FILE *fp;	// �̸� ����

	// �̸� ���� �ۼ�
	fp = fopen(PATH, "w");
	fputs(name, fp);

	// ���� ���� ��Ʈ�� ����
	fclose(fp);
}

// ���� �б� �Լ�
void readFiles()
{
	FILE *fp;		// ���Ϸ� �ԷµǴ� �̸�
	char name[20];	// ù ���� �� �����Ǵ� �̸�

	// ������ ����
	fp = fopen(PATH, "r");

	// ���� ������ 
	if (fp == NULL){
		gotoxy(16, 7);  printLetter("ù �����̱���! �ݰ����ϴ�.", SPEED);
		gotoxy(16, 10);	printLetter("����� �̸��� �����ΰ���? : ", SPEED);
		fgets(name, 20, stdin);
		checkName(name);
		system("cls");
		// ������ �����
		makeFiles(name);
		// �ٽ� ����
		fp = fopen(PATH, "r");
	}
	// ���Ϸκ��� �а� ����
	fscanf(fp, "%s", Name);
	// ���� ���� ��Ʈ�� �ݱ�
	fclose(fp);
}

// ������ ��� �Լ�
void printName()
{
	if (Name[0] == -52){
		FILE *name = fopen(PATH, "w");
		fputs("ȫ�浿", name);
		fclose(name);
		gotoxy(16, 8); printLetter("���� ���� �Ǵ� ���α׷��� �ʿ��� ���� ������ �ǽɵ�!!", SPEED);
		gotoxy(16, 10); printLetter("������ ���� �̸��� ȫ�浿�̴�!!", SPEED);
		getch(); system("cls");
	}
	gotoxy(20, 8); printLetter(formatToString("����� �̸��� %s�Դϴ�.", Name), SPEED);
}

// �̸� �缳�� �Լ�
void setName()
{
	FILE *fp;

	gotoxy(16, 8); printLetter("�缳���� �̸��� �Է��ϼ��� : ", SPEED);
	fgets(Name, 20, stdin);
	checkName(Name);

	fp = fopen(PATH, "w");
	fputs(Name, fp);
	fclose(fp);

	gotoxy(16, 12);	printLetter(formatToString("���� ������ �̸��� %s�Դϴ�.", Name), SPEED);

	Enter(CUR, 0);
	system("cls");
}

void checkName(char *name)
{
	for (int i = 0; i < (int)strlen(name); i++){
		if (name[i] == '\n'){
			name[i] = '\0';
			break;
		}
	}
}

// ������ ���� �Լ� public
void Modify()
{
	char input;
	int loop = 0;

	while (loop == 0){
		printName();
		gotoxy(20, 12); printLetter("�ٲٱ� ���Ͻʴϱ�? Y/N", SPEED);
		//gotoxy(16, 12); printLetter("1. �̸��� �ٲٰ� �;�!", SPEED);
		//gotoxy(16, 13); printLetter("2. ���� �ӵ��� �ٲٰ� �;�!", SPEED);
		//gotoxy(16, 14); printLetter("3. ������ ����!", SPEED);

		while (1)
		{
			input = getch(); 
			if (input == 'Y' || input == 'y') {
				system("cls");
				setName();
				break;
			}
			else if (input == 'N' || input == 'n') {
				system("cls");
				loop = 1;
				break;
			}
		}
	}
}