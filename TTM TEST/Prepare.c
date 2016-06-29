#include "Prepare.h"

// 타이틀 함수
void Title(char *ver)
{
	char *ttm[13] = {
		"                                                ",
		" ━┳━  ┏━┓  ┃      ┃  ／                 ",
		"   ┃    ┣━┫  ┃      ┣━                   ",
		"   ┃    ┃  ┃  ┗━━  ┃  ＼                 ",
		"                                                ",
		" ━┳━  ┏━┓                                 ",
		"   ┃    ┃  ┃                                 ",
		"   ┃    ┗━┛                                 ",
		"                                                ",
		" ┏┳┓  ┏━┓  ┃      ┏━━  ┃  ┃  ┃  ／ ",
		" ┃┃┃  ┣━┫  ┃      ┗━┓  ┃  ┃  ┣━   ",
		" ┃  ┃  ┃  ┃  ┗━━  ━━┛  ┗━┛  ┃  ＼ ",
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

// 초기 설정 함수
void Setting()
{
	SetCursorType(NOCURSOR);		// 커서 설정
	system("title Talk to Malsuk"); // 콘솔 타이틀 설정
	system("mode con:lines=25");	// 콘솔 크기 설정
	srand((unsigned)time(NULL));	// 난수 시드 설정
}
// 파일 생성 함수
void makeFiles(char *name)
{
	FILE *fp;	// 이름 파일

	// 이름 파일 작성
	fp = fopen(PATH, "w");
	fputs(name, fp);

	// 열린 파일 스트림 닫음
	fclose(fp);
}

// 파일 읽기 함수
void readFiles()
{
	FILE *fp;		// 파일로 입력되는 이름
	char name[20];	// 첫 실행 시 설정되는 이름

	// 파일을 열고
	fp = fopen(PATH, "r");

	// 만약 없으면 
	if (fp == NULL){
		gotoxy(16, 7);  printLetter("첫 실행이군요! 반갑습니다.", SPEED);
		gotoxy(16, 10);	printLetter("당신의 이름은 무엇인가요? : ", SPEED);
		fgets(name, 20, stdin);
		checkName(name);
		system("cls");
		// 파일을 만들고
		makeFiles(name);
		// 다시 연다
		fp = fopen(PATH, "r");
	}
	// 파일로부터 읽고 저장
	fscanf(fp, "%s", Name);
	// 열린 파일 스트림 닫기
	fclose(fp);
}

// 데이터 출력 함수
void printName()
{
	if (Name[0] == -52){
		FILE *name = fopen(PATH, "w");
		fputs("홍길동", name);
		fclose(name);
		gotoxy(16, 8); printLetter("강제 종료 또는 프로그램에 필요한 파일 조작이 의심됨!!", SPEED);
		gotoxy(16, 10); printLetter("앞으로 너의 이름은 홍길동이다!!", SPEED);
		getch(); system("cls");
	}
	gotoxy(20, 8); printLetter(formatToString("당신의 이름은 %s입니다.", Name), SPEED);
}

// 이름 재설정 함수
void setName()
{
	FILE *fp;

	gotoxy(16, 8); printLetter("재설정할 이름을 입력하세요 : ", SPEED);
	fgets(Name, 20, stdin);
	checkName(Name);

	fp = fopen(PATH, "w");
	fputs(Name, fp);
	fclose(fp);

	gotoxy(16, 12);	printLetter(formatToString("현재 설정된 이름은 %s입니다.", Name), SPEED);

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

// 데이터 수정 함수 public
void Modify()
{
	char input;
	int loop = 0;

	while (loop == 0){
		printName();
		gotoxy(20, 12); printLetter("바꾸기 원하십니까? Y/N", SPEED);
		//gotoxy(16, 12); printLetter("1. 이름을 바꾸고 싶어!", SPEED);
		//gotoxy(16, 13); printLetter("2. 말의 속도를 바꾸고 싶어!", SPEED);
		//gotoxy(16, 14); printLetter("3. 지금이 좋아!", SPEED);

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