#include "Header.h"

// 커서 변경 함수 
void SetCursorType(CURSOR c)
{
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

// 현재 커서 좌표 찾는 함수
COORD GetCursorPosition()
{
	CONSOLE_SCREEN_BUFFER_INFO buffInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buffInfo);
	
	return buffInfo.dwCursorPosition;
}

// 커서 이동 함수
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// 초기 설정 함수
void Setting()
{
	static char *name = "홍길동";
	
	// 혹시 초기화되지 않은 전역변수에 접근할까봐 초기화
	Name = name;
	Speed = NORMAL;

	SetCursorType(NOCURSOR);		// 커서 설정
	system("title Talk to Malsuk"); // 콘솔 타이틀 설정
	system("mode con:lines=25");	// 콘솔 크기 설정
	srand((unsigned)time(NULL));	// 난수 시드 설정
}

// 엔터 함수
void Enter(int x, int y)
{
	gotoxy(x, y); printLetter("<Enter>", Speed);
	Sleep(500);
	gotoxy(x, y); printf("       ");
	Sleep(500);
	while (1){
		if (kbhit() == 1 && getch() == 13)
			break;
		gotoxy(x, y); printf("<Enter>");
		Sleep(500);
		gotoxy(x, y); printf("       ");
		Sleep(500);
	}
}

// 파일 생성 함수
void makeFiles(char *name, char speed)
{
	FILE *writeName;	// 이름 파일
	FILE *writeSpeed;	// 속도 파일

	// 필요한 폴더 생성
	system("md \"C:\\Talk to Malsuk\"");
	system("md \"C:\\Talk to Malsuk\\Data\"");
	// 이름 파일 작성
	writeName = fopen("C:\\Talk to Malsuk\\Data\\name.txt", "w");
	fputs(name, writeName);
	// 속도 파일 작성
	writeSpeed = fopen("C:\\Talk to Malsuk\\Data\\speed.txt", "w");
	fputc(speed, writeSpeed);
	// 열린 파일 스트림 닫음
	fclose(writeName); 
	fclose(writeSpeed);
}

// 파일 읽기 함수
DATA readFiles()
{
	FILE *readname;		// 파일로 입력되는 이름
	FILE *readspeed;	// 파일로 입력되는 속도
	FILE *checkingFile;	// 파일이 있는지 없는지 확인함
	DATA data;			// 리턴할 데이터
	char name[20];		// 첫 실행 시 설정되는 이름
	char speed = '2';	// 첫 실행 시 설정되는 속도
	char whatSpeed;		// 이름 설정에 쓰이는 char

	// 파일을 열고
	readname = fopen("C:\\Talk to Malsuk\\Data\\name.txt", "r");
	readspeed = fopen("C:\\Talk to Malsuk\\Data\\speed.txt", "r");

	// 만약 하나라도 없으면 
	if (readname == NULL || readspeed == NULL){
		gotoxy(16, 7);  printLetter("첫 실행이군요! 반갑습니다.", NORMAL);
		gotoxy(16, 10);	printLetter("당신의 이름은 무엇인가요? : ", NORMAL);
		gets(name);
		gotoxy(16, 13); printLetter("말 속도는 뭘로 할까요? (1. 천천히 2. 보통 3. 빠르게)", NORMAL);
		while (1){
			if ((whatSpeed = getch()) == '\r')
				break;
			else if (whatSpeed == '1' || whatSpeed == '2' || whatSpeed == '3' || whatSpeed == 'f'){
				gotoxy(16, 15); puts("                                                        ");
				gotoxy(16, 15); printLetter("속도가 적당하십니까? (적당하면 Enter / 아니면 다른 속도)", toSpeed(whatSpeed));
				speed = whatSpeed;
			}
		}
		system("cls");
		// 파일을 만들고
		makeFiles(name, speed);
		// 다시 연다
		readname = fopen("C:\\Talk to Malsuk\\Data\\name.txt", "r");
		readspeed = fopen("C:\\Talk to Malsuk\\Data\\speed.txt", "r");
		checkingFile = fopen("C:\\Talk to Malsuk\\system info.txt", "r");
	}
	// 파일로부터 읽고 저장
	fscanf(readname, "%s", data.name);
	fscanf(readspeed, "%c", &data.speed);
	// 열린 파일 스트림 닫고
	fclose(readname); 
	fclose(readspeed); 
	// 저장된 데이터 돌려줌
	return data;
}

// 데이터 출력 함수
void printData()
{
	if (Data.name[0] == -52 || Data.speed == -52){
		DATA DefaultData = { '2', "홍길동" };
		
		FILE *name = fopen("C:\\Talk to Malsuk\\Data\\name.txt", "w");
		FILE *speed = fopen("C:\\Talk to Malsuk\\Data\\speed.txt", "w");
		
		fputs(DefaultData.name, name);
		fputc(DefaultData.speed, speed);
		
		Data = DefaultData;

		gotoxy(16, 8); printLetter("강제 종료 또는 프로그램에 필요한 파일 조작이 의심됨!!", NORMAL);
		gotoxy(16, 10); printLetter("앞으로 너의 이름은 홍길동이다!!", NORMAL);
		getch(); system("cls");
		fclose(name);
		fclose(speed);
	}
	gotoxy(16, 8);
	printLetter("당신의 이름은 ", Speed); printLetter(Name, Speed); printLetter("이고 말의 속도는 ", Speed);
	if (Data.speed == '1') printLetter("느림입니다.", Speed);
	else if (Data.speed == '2') printLetter("보통입니다.", Speed);
	else if (Data.speed == '3') printLetter("빠름입니다.", Speed);
	else if (Data.speed == 'f') printLetter("Ultra Fucking Fast입니다.", Speed);
}

// 이름 재설정 함수
void setName()
{
	FILE *writeName;
	static char name[20];
	
	gotoxy(16, 8); printLetter("재설정할 이름을 입력하세요 : ", Speed);
	gets(name);
	
	writeName = fopen("C:\\Talk to Malsuk\\Data\\name.txt", "w");
	fputs(name, writeName);
	
	Name = name;

	gotoxy(16, 12);	printLetter("현재 설정된 이름은 ", Speed);
	printLetter(Name, Speed);
	printLetter("입니다.", Speed);
	
	fclose(writeName);

	int x = GetCursorPosition().X;
	int y = GetCursorPosition().Y;
	Enter(x + 2, y);
	system("cls");
}

// 속도 재설정 함수
void setSpeed()
{
	char whatSpeed;
	FILE *writeSpeed;
	
	gotoxy(16, 7);  printLetter("말의 속도를 재설정합니다.", Speed);
	gotoxy(16, 10); printLetter("말의 속도를 골라 주십시오.", Speed);
	//gotoxy(16, 11); printLetter("(Enter를 누를 시 현재 빠르기로 설정됩니다.)", Speed);
	gotoxy(16, 12); printLetter("1. 천천히 2. 보통 3. 빠르게", Speed);

	writeSpeed = fopen("C:\\Talk to Malsuk\\Data\\name.txt", "w");

	while (1){
		whatSpeed = getch();
		system("cls");
		if (whatSpeed == '1' || whatSpeed == '2' || whatSpeed == '3'){
			for (int i = 0; i < 5; i++){
				gotoxy(16, 12 - i); puts("1. 천천히 2. 보통 3. 빠르게");
				Sleep(toSpeed(whatSpeed));
				gotoxy(16, 12 - i); puts("                          ");
			}
			fputc(whatSpeed, writeSpeed);
			Speed = toSpeed(whatSpeed);
			gotoxy(16, 7); puts("1. 천천히 2. 보통 3. 빠르게");
			gotoxy(16, 9); printLetter("말의 속도가 적당하신가요?", Speed);
			gotoxy(16, 12); printLetter("적당하면 Enter를", Speed);
			gotoxy(16, 14); printLetter("적당하지 않다면 다른 번호를 눌러주세요.", Speed);
		}
		else if (whatSpeed == 'f'){
			fputc(whatSpeed, writeSpeed);
			Speed = 1;
			gotoxy(28, 9); printLetter("ULTRA FUCKING FAST MODE", Speed);
		}
		else if (whatSpeed == '\r')
			break;
	}
	fclose(writeSpeed);
}

// 데이터 수정 함수 public
void Modify()
{
	char input;

	while (1){
		printData();
		gotoxy(16, 10); printLetter("바꾸기 원하십니까?", Speed);
		gotoxy(16, 12); printLetter("1. 이름을 바꾸고 싶어!", Speed);
		gotoxy(16, 13); printLetter("2. 말의 속도를 바꾸고 싶어!", Speed);
		gotoxy(16, 14); printLetter("3. 지금이 좋아!", Speed);
		
		input = getch(); system("cls");
		if (input == '1') {
			setName();
		}
		else if (input == '2'){
			setSpeed();
		}
		else if (input == '3') {
			break;
		}
	}
}

// (char) 속도 모드를 (int) 속도로 변환 함수
int toSpeed(char speed)
{
	switch (speed)
	{
	case '1':
		return SLOW;
	case '2':
		return NORMAL;
	case '3':
		return FAST;
	case 'f':
		return 1;
	default:
		return NORMAL;
	}
}

// 페메 왼쪽 박스
void LeftBox(char *str)
{
	int i, length, realen;

	realen = strlen(str);

	if (str[0] == 7)
		realen--;
	if (realen % 2 == 0)
		length = realen / 2;
	else
		length = (realen + 1) / 2;

	printf(" ┌");
	for (i = 1; i <= length; i++)
		printf("─");
	printf("┐");

	puts("");

	printf(" │");
	if (realen % 2 == 1)
		printf(" ");
	printf("%s", str);
	printf("│");

	puts("");

	printf(" └");
	for (i = 1; i <= length; i++)
		printf("─");
	printf("┘");

	puts("");
}

// 페메 오른쪽 박스
void RightBox(char *str)
{
	int i, length, length2, realen;

	realen = strlen(str);

	if (str[0] == 7)
		realen--;

	if (realen % 2 == 0){
		length = realen / 2;
		length2 = 75 - realen;
	}
	else{
		length = (realen + 1) / 2;
		length2 = 74 - realen;
	}
	for (i = 1; i <= length2; i++)
		printf(" ");
	printf("┌");
	for (i = 1; i <= length; i++)
		printf("─");
	printf("┐");

	puts("");

	for (i = 1; i <= length2; i++)
		printf(" ");
	printf("│");
	if (realen % 2 == 1)
		printf(" ");
	printf("%s", str);
	printf("│");

	puts("");

	for (i = 1; i <= length2; i++)
		printf(" ");
	printf("└");
	for (i = 1; i <= length; i++)
		printf("─");
	printf("┘");

	puts("");
}

// 시간 설정함수
void setTime()
{
	time_t t;
	
	time(&t);
	Hour[0] = localtime(&t)->tm_hour;
	Min[0] = localtime(&t)->tm_min;

	Hour[1] = Hour[0];
	Min[1] = Min[0] + 36;
	if (Min[1] >= 60){
		Min[1] -= 60;
		Hour[1]++;
	}

	Hour[2] = Hour[1];
	Min[2] = Min[1] + 14;
	if (Min[2] >= 60){
		Min[2] -= 60;
		Hour[2]++;
	}

	Hour[3] = Hour[2] + 3;
	Min[3] = Min[2] + 47;
	if (Min[3] >= 60){
		Min[3] -= 60;
		Hour[3]++;
	}
}

// 페이스북 대화창 함수
void message(MESSAGE m)
{
	switch (m){
	case NAME:
		puts("윾말숙");
		printf("Messenger 1분 전에 활동%55s\n", "☎");
		puts("-------------------------------------------------------------------------------");
		break;
	case FIRSTMSG:
		message(NAME);
		printTime(Hour[0], Min[0]); //"오후 6:37"
		RightBox("안녕");
		break;
	case SECONDMSG:
		message(FIRSTMSG);
		printTime(Hour[1], Min[1]); //"오후 7:13"
		LeftBox("ㅎㅇ");
		break;
	case THIRDMSG:
		message(SECONDMSG);
		printTime(Hour[2], Min[2]); //"오후 7:27"
		RightBox("전번점ㅋㅋ");
		break;
	case FOURTHMSG:
		message(THIRDMSG);
		printTime(Hour[3], Min[3]); //오후 11:14"
		LeftBox("싫어미안ㅋㅋ");
		break;
	case FIFTHMSG:
		message(FOURTHMSG);
		RightBox("ㅇ..어 ㅈㅅ");
		RightBox("잘자");
		break;
	case SIXTHMSG:
		message(FIFTHMSG);
		LeftBox("미안다음에줄께");
		LeftBox("너도잘자");
		break;
	}
}

// 개행 함수 - 삭제 예정
void LineFeed(int a){
	for (int i = 0; i < a; i++)
		puts("");
}

// 한글자씩 출력 함수 
void printLetter(char *str, int time)
{
	int i = 0;

	while (str[i] != '\0'){
		if (str[i] < 0){
			Sleep(time);
			printf("%c%c", str[i], str[i + 1]);
			i += 2;
		}
		else{
			Sleep(time);
			printf("%c", str[i]);
			i++;
		}
	}
}

// 안내 함수 - 삭제 예정
void intro(char *str, int time)
{
	printf("\t\t");
	printLetter(str, time);
	puts("");
}

// 말하기 함수 
void say(char *str, int time)
{
	puts(" 　　　　　　　　　　　 　 　 　 　 　 　 _,,t------､,-----+-､");
	puts("　　　　　　　　　　　　 　 　 　 　 三'::.............. .....::::::`ｙ,.");
	puts("　　　　　　　　 　 　 　 　 　 　 ナ::::::::::::::::::::::::: ::::::::::::ヾ");
	puts("　　　　　　　 　 　 　 |￣|　　 V:::::::::::::_{{ （{∫∬ﾉノｊヾ:::::{");
	puts("　　　　　　 　 　　|￣| |￣| 　 ﾅ:::::::::::i`__,,,,,,ｧ_　 _,,,,,_ t;;:ﾇ");
	puts("　　 　 　　　　　　| 　| |　 |　 イﾍ:::::(ヾ~!,ｬt､　!'''i ｨｔﾝ )=f }ｆ");
	puts(" 　　　　　　 　 　　| 　| | 　| 　 i {t) テ\" ﾍ' '___, ｲ 　ヽ_＿ / 介'");
	puts("　　　　　　　　 　 | 　| |　 |　_,rﾍ_,ｊ|!' 　 　 /ｰ---''! 　　　|'");
	puts("　　　　　　　　 　 |,.ｨ―''''￣　　／| |　 　 　 ／二二ｸ　 　　 !");
	puts("　　　　　　 　 　 /;;:::'';;::''::;;:／ {　!　、　 　 ヾニﾝ　　 　ﾉ＼");
	puts(" 　 　　　 　　 　 /''':::;r|'''::;;;|　　|　!　＼　　　　　 _,,.／|:;;''＼");
	puts(" 　　　　　　 　 /:;;／　|;;;''::;;| 　　丶＼ 　｀_＿＞-ｰ´　 　　!;;;:''::iヽ、");
	puts(" 　　　 　 　 　 i／　　 |'::;;;;''|　　 　 　三 ―''\"　　　 　　　!''::;;;; |/");
	puts("　　　　　　　 /⌒ヽ　 |;;''':::;|　　　　　　　＼　 　 　 　 　 !;;::''|/　 i");
	puts("　 　 　 　 / 　 　 ＼{'';;;::''}　　　　　　　　　￣二ニ＝　 　 !::;;|　　 |");
	puts("　　　 　 　 /ﾍ　　　　 |;;:::::;{　　　　　　　　　　　　‐-　　　 　 !/　 　|");
	puts("　 　 　 　 /　　i　　 　 |:::;;;''!　　　　　　　　　　 　 ー　　 　 　 !　 /");
	puts("　　　　　/　　　l　　 　 |;;'';ｲ　　　　　　　　　　　　　　　　　｝　　 {、");
	puts("-------------------------------------------------------------------------------");

	printf(" <준필> \n\n ");
	printLetter(str, time);
	puts("");
}

void say_(char *str, int time)
{
	printf(" ");
	printLetter(str, time);
	puts("");
}

// 시간 출력함수
void printTime(int hour, int min)
{
	if (hour == 0 || hour == 24){
		if (min < 10)
			printf("%40s 12:0%d\n", "오전", min);
		else
			printf("%40s 12:%d\n", "오전", min);
	}
	else if (hour < 12){
		if (min < 10)
			printf("%40s %d:0%d\n", "오전", hour, min);
		else
			printf("%40s %d:%d\n", "오전", hour, min);
	}
	else if (hour == 12){
		if (min < 10)
			printf("%40s 12:0%d\n", "오후", min);
		else
			printf("%40s 12:%d\n", "오후", min);
	}
	else if (hour < 24){
		if (min < 10)
			printf("%40s %d:0%d\n", "오후", hour - 12, min);
		else
			printf("%40s %d:%d\n", "오후", hour - 12, min);
	}
	else{
		if (min < 10)
			printf("%40s %d:0%d\n", "오전", hour - 24, min);
		else
			printf("%40s %d:%d\n", "오전", hour - 24, min);
	}
}

// 타이틀 함수
void Title()
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
	printMiddle("beta. 1.5.0.0", 18);

	while (!kbhit()){
		printMiddle("press any key!", 20);
		Sleep(500);
		printMiddle("              ", 20);
		Sleep(500);
	}
	getch(); 
	system("cls");
}

// 크레딧 함수
void Credit()
{
	gotoxy(16, 5); puts("제작 전성우");
	gotoxy(16, 6); puts("원작 황준필과 미림이의 페메 사진");
	gotoxy(16, 8); puts("이 저작물은 배포가 가능합니다.");
	gotoxy(16, 9); puts("단, 배포시 저작물의 원작자를 표시해야 하며");
	gotoxy(16, 10); puts("저작물을 영리 목적으로 이용을 허락하지 않고");
	gotoxy(16, 11); puts("저작물의 변경 또는 2차 저작을 허락하지 않습니다.");
	gotoxy(16, 13); puts("ⓒ 2015 전성우. All rights reserved.\n");
	gotoxy(16, 15);
}

// 헬프 함수 - 삭제 예정
void Help(int time)
{
	gotoxy(16, 3); printLetter("이 프로그램 TTM은\n", time);
	gotoxy(16, 4); printLetter("엔터를 입력하며 진행되는 프로그램이니\n", time);
	gotoxy(16, 5); printLetter("엔터를 연타하시지 마시고\n", time);
	gotoxy(16, 6); printLetter("엔터를 입력하라는 문구를 확인하며 진행해주세요.\n\n\n", time);
}

// 중간 값 알아내기 private
int GetConsoleMiddle(int length)
{
	if (length % 2 == 0){
		return (80 - length) / 2;
	}
	else{
		return (80 - length - 1) / 2;
	}
}

// 중앙 정렬 출력 함수
void printMiddle(char *str, int lineNum)
{
	gotoxy(GetConsoleMiddle(strlen(str)), lineNum); puts(str);
}