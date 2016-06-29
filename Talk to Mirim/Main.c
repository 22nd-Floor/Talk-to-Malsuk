#include "Header.h"

// 메인 함수
int main()
{
	int i; // for문에 사용
	int whatspeed; // 시간 선택
	int speed = NORMAL; // 변경된 시간 (초기값은 50)
	int percent;
	char ch; // Yes No Help 선택
	char one_more; // 한 번 더?
	char enter; // 엔터를 입력했는가?

start:;

	// 초기 설정
	setcursortype(NOCURSOR);
	system("title Talk To Mirim");
	system("color F0"); // 0 = 검정색 1 = 파랑색 2 = 초록색 3 = 옥색 4 = 빨강색 5 = 자주색 6 = 노랑색 7 = 흰색 8 = 회색 9 = 연한 파랑
	system("cls");      // A = 연한 초록색 B = 연한 옥색 C = 연한 빨강색 D = 연한 자주색 E = 연한 노랑색 F = 밝은 흰색
	system("mode con:lines=25");

	// 초기 창
	NewLine(8);
	puts("\t\t┌───────┐");
	puts("\t\t│ Talk to Mirim│You Are Junpil.");
	puts("\t\t│  Ver. 3.0.0  │Do you want to talk to Mirim?");
	puts("\t\t└───────┘");
	printf("\t\t\t  (Yes = y / No = n / Help = h)");
	
	ch = getch();

	// YES
	if (ch == 'y' || ch == 'Y'){
		system("title 초기설정");
		system("cls");
		NewLine(6);
		intro("초기 설정 창입니다.\n\n", speed);
		intro("말의 속도를 골라 주십시오.\n", speed);
		puts("\t\t(Enter를 누를 시 보통의 빠르기로 설정됩니다.)\n");
		puts("\t\t1. 천천히 2. 보통 3. 빠르게");
		
		while (1){
			whatspeed = getch();
			system("cls");
			if (whatspeed == '1'){
				speed = SLOW;
				NewLine(6);
				puts("\t\t1. 천천히 2. 보통 3. 빠르게\n");
				intro("말의 속도가 적당하신가요?\n\n", speed);
				intro("적당하면 Enter를\n", speed);
				intro("적당하지 않다면 다른 번호를 눌러주세요.", speed);
			}
			else if (whatspeed == '2'){
				speed = NORMAL;
				NewLine(6);
				puts("\t\t1. 천천히 2. 보통 3. 빠르게\n");
				intro("말의 속도가 적당하신가요?\n\n", speed);
				intro("적당하면 Enter를\n", speed);
				intro("적당하지 않다면 다른 번호를 눌러주세요.", speed);
			}
			else if (whatspeed == '3'){
				speed = FAST;
				NewLine(6);
				puts("\t\t1. 천천히 2. 보통 3. 빠르게\n");
				intro("말의 속도가 적당하신가요?\n\n", speed);
				intro("적당하면 Enter를\n", speed);
				intro("적당하지 않다면 다른 번호를 눌러주세요.", speed);
			}
			else if (whatspeed == 13)
				break;
			else if (whatspeed == 's' || whatspeed == 'S')
				goto restart;
		}

		system("cls");
		printf("%49s", "▲ 엔터 입력 문구");
		help(speed);
		intro("엔터 문구는 위에 있습니다.", speed);

		Enter;

		NewLine(6);
		intro("잘 했습니다!\n\n", speed);
		intro("엔터를 연타하여 생기는 오류에 대한 \n", speed);
		intro("책임은 사용자에게 있습니다.\n\n", speed);
		intro("엔터를 입력하면 시작합니다.", speed);

		Enter;

	restart:;

		// 난수 설정
		srand((unsigned)time(NULL));
		percent = (rand() % (100 - 1) + 1);

		say("오늘은 꼭 미림이에게 전번을 따겠어!\n", speed);

		Enter;

		NewLine(10);
		intro("    (준필이는 페이스북 메신저를 열었다.)", speed);

		Enter;

		msg(1); // 이름 활동시간
		Sleep(1000);
		printf("%45s\n", "오후 6:37");
		Right_Box("\a안녕");

		Enter;

		say("아 보내버렸어...!\n", speed);

		Enter;

		say("정말 떨린다....", speed);

		Enter;

		msg(2); // 안녕
		Sleep(1000);
		printf("%45s\n", "오후 7:13");
		Left_Box("\aㅎㅇ");

		Enter;

		say("오!!!!!!!!!!! 답장왔다!!!!!!!!!\n", speed);

		Enter;

		say("기분 존나 섹스운지하노 이기야!!", speed);

		Enter;

		msg(3); // ㅎㅇ
		Sleep(1000);
		printf("%45s\n", "오후 7:27");
		Right_Box("\a전번점ㅋㅋ");

		Enter;

		say("이렇게 멋진 나의 전번받기 기술에", speed);
		n_say("넘어오지 않은 여자가 없지....", speed);

		Enter;

		say("우리학교 절세미인 유미림이라도", speed);
		n_say("나에게 넘어올 수 밖에 없어!", speed);

		Enter;

		NewLine(10);
		printf("\t\t\t4시간 후"); Sleep(1000);
		printf("."); Sleep(1000);
		printf("."); Sleep(1000);
		printf("."); Sleep(1000);
		system("cls");
		say("왜 이렇게 답장이 안 오지?", speed);

		Enter;

		NewLine(10);
		puts("\t\t\t\a(페메 알림음)\n");
		Sleep(500);
		system("cls");
		say("오오오 답장 왔다!!", speed);

		Enter;

		say("역시 미림이도 나에게 반한 모양이군....", speed);

		Enter;

		msg(4); // 전번점ㅋㅋ
		Sleep(1000);
		printf("%46s\n", "오후 11:14");
		Left_Box("\a싫어미안ㅋㅋ");

		Enter;

		say("...............?", speed);

		Enter;

		say("내가 잘못 본 건가........?", speed);

		Enter;

		NewLine(10);
		intro("\t(준필이는 페메를 다시 열었다. )", speed);

		Enter;

		msg(5); // 싫어미안ㅋㅋ
		n_say("(이것은 사실입니다. )", 100);

		Enter;

		say("시빨!!!!!!!!!!!!!!!!!!!", speed);

		Enter;

		say("차리리 답장을 하지 말지ㅠㅠㅠㅠㅠㅠ", speed);

		Enter;

		msg(5);// 싫어미안ㅋㅋ
		Sleep(1000);
		Right_Box("\aㅇ..어 ㅈㅅ");
		Sleep(1000);
		Right_Box("\a잘자");

		Enter;

		say("하...............", speed);

		Enter;

		say("존나 쓰레기 같은 인생....", speed);

		Enter;

		msg(6); // 잘자
		Sleep(1000);
		Left_Box("\a미안다음에줄께");
		Sleep(1000);
		Left_Box("\a너도잘자");
		puts(" Messenger에서 보냄");

		Enter;

		say("하... 기분 좆나 좋네.", speed);

		Enter;

		say("존나 미림이랑 섹스하고 싶다.", speed);

		Enter;

		msg(7); // 너도 잘자
		puts(" Messenger에서 보냄");
		puts("-------------------------------------------------------------------------------");
		printf(" 메세지 쓰기 : "); Sleep(1000);
		printf("ㄴ");     Sleep(TIME);
		printf("\b\b나"); Sleep(TIME);
		printf("ㄹ");     Sleep(TIME);
		printf("\b\b라"); Sleep(TIME);
		printf("\b\b랑"); Sleep(TIME);
		printf(" ");      Sleep(TIME);
		printf("ㅅ");     Sleep(TIME);
		printf("\b\b세"); Sleep(TIME);
		printf("\b\b섹"); Sleep(TIME);
		printf("ㅅ");     Sleep(TIME);
		printf("\b\b스"); Sleep(TIME);
		printf("ㅎ");     Sleep(TIME);
		printf("\b\b하"); Sleep(TIME);
		printf("\b\b할"); Sleep(TIME);
		printf("ㄹ");     Sleep(TIME);
		printf("\b\b래"); Sleep(TIME);
		printf("?");      Sleep(TIME);
		printf("%49s\n", "<보내기>");
		printf("-------------------------------------------------------------------------------");

		Enter;

		say("앗!", speed);

		Enter;

		NewLine(10);
		intro("    (준필이는 <보내기>를 눌러 버렸다.)", speed);

		Enter;
		// if (enter == '1') percent = 1;

		msg(7); // 너도 잘자
		Sleep(1000);
		Right_Box("\a나랑 섹스할래?");

		if (percent > 10){
			Sleep(1500);
			Left_Box("\a병신새끼 ㅉㅉ 왜사냐");
			puts(" Messenger에서 보냄");

			Enter;

			say("아... 자살해야겠다.", speed);

			Enter;

			say("잘 있어라 이세상아!", speed);

			Enter;

			system("color 4C");
			system("title 준필이 엠생 ㅇㅈ?");
			system("cls");
			for (i = 0; i <= 131; i++)
				printf("자살하셨습니다 ");
		}
		else{
			Sleep(1500);
			Left_Box("\a우리집에 라면먹으러 올래?");
			puts(" Messenger에서 보냄");

			Enter;

			say("예!!! 썪쎾쓰!!!!!", speed);

			Enter;

			say("잘 있어라 아다들아!", speed);

			Enter;

			system("color FE");
			system("title 준필이 후다 ㅊㅊ!");
			system("cls");
			for (i = 0; i <= 131; i++)
				printf("섹스하셨습니다 ");
		}
		Enter;

		NewLine(10);
		printf("%55s\n", "Do you want to talk, One more? y/n");
		
		while (1){
			one_more = getch();
			if (one_more == 'y' || one_more == 'Y')
				goto restart;
			else if (one_more == 'n' || one_more == 'N')
				break;
		}

	}
	else if (ch == 'n' || ch == 'N'){
		system("CLS");
		NewLine(9);
		printf("%44s\n", "┌─────┐");
		printf("%44s\n", "│ Shut down│");
		printf("%44s\n", "└─────┘");
		enter = getch();
		return 0;
	}
	else if (ch == 'h' || ch == 'H'){
		system("cls");
		help(speed);
		puts("\t\t아무 키나 입력하면 돌아갑니다");
		enter = getch();
		goto start;
	}
	else if (ch == 'c' || ch == 'C'){
		system("title Credit");
		system("cls");
		credit();
		puts("아무 키나 입력하면 돌아갑니다");
		enter = getch();
		goto start;
	}
	
	// 종료
	system("title Credit");
	system("cls");
	credit();
	system("PAUSE");
	return 0;
}