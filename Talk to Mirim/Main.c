#include "Header.h"

// ���� �Լ�
int main()
{
	int i; // for���� ���
	int whatspeed; // �ð� ����
	int speed = NORMAL; // ����� �ð� (�ʱⰪ�� 50)
	int percent;
	char ch; // Yes No Help ����
	char one_more; // �� �� ��?
	char enter; // ���͸� �Է��ߴ°�?

start:;

	// �ʱ� ����
	setcursortype(NOCURSOR);
	system("title Talk To Mirim");
	system("color F0"); // 0 = ������ 1 = �Ķ��� 2 = �ʷϻ� 3 = ���� 4 = ������ 5 = ���ֻ� 6 = ����� 7 = ��� 8 = ȸ�� 9 = ���� �Ķ�
	system("cls");      // A = ���� �ʷϻ� B = ���� ���� C = ���� ������ D = ���� ���ֻ� E = ���� ����� F = ���� ���
	system("mode con:lines=25");

	// �ʱ� â
	NewLine(8);
	puts("\t\t������������������");
	puts("\t\t�� Talk to Mirim��You Are Junpil.");
	puts("\t\t��  Ver. 3.0.0  ��Do you want to talk to Mirim?");
	puts("\t\t������������������");
	printf("\t\t\t  (Yes = y / No = n / Help = h)");
	
	ch = getch();

	// YES
	if (ch == 'y' || ch == 'Y'){
		system("title �ʱ⼳��");
		system("cls");
		NewLine(6);
		intro("�ʱ� ���� â�Դϴ�.\n\n", speed);
		intro("���� �ӵ��� ��� �ֽʽÿ�.\n", speed);
		puts("\t\t(Enter�� ���� �� ������ ������� �����˴ϴ�.)\n");
		puts("\t\t1. õõ�� 2. ���� 3. ������");
		
		while (1){
			whatspeed = getch();
			system("cls");
			if (whatspeed == '1'){
				speed = SLOW;
				NewLine(6);
				puts("\t\t1. õõ�� 2. ���� 3. ������\n");
				intro("���� �ӵ��� �����ϽŰ���?\n\n", speed);
				intro("�����ϸ� Enter��\n", speed);
				intro("�������� �ʴٸ� �ٸ� ��ȣ�� �����ּ���.", speed);
			}
			else if (whatspeed == '2'){
				speed = NORMAL;
				NewLine(6);
				puts("\t\t1. õõ�� 2. ���� 3. ������\n");
				intro("���� �ӵ��� �����ϽŰ���?\n\n", speed);
				intro("�����ϸ� Enter��\n", speed);
				intro("�������� �ʴٸ� �ٸ� ��ȣ�� �����ּ���.", speed);
			}
			else if (whatspeed == '3'){
				speed = FAST;
				NewLine(6);
				puts("\t\t1. õõ�� 2. ���� 3. ������\n");
				intro("���� �ӵ��� �����ϽŰ���?\n\n", speed);
				intro("�����ϸ� Enter��\n", speed);
				intro("�������� �ʴٸ� �ٸ� ��ȣ�� �����ּ���.", speed);
			}
			else if (whatspeed == 13)
				break;
			else if (whatspeed == 's' || whatspeed == 'S')
				goto restart;
		}

		system("cls");
		printf("%49s", "�� ���� �Է� ����");
		help(speed);
		intro("���� ������ ���� �ֽ��ϴ�.", speed);

		Enter;

		NewLine(6);
		intro("�� �߽��ϴ�!\n\n", speed);
		intro("���͸� ��Ÿ�Ͽ� ����� ������ ���� \n", speed);
		intro("å���� ����ڿ��� �ֽ��ϴ�.\n\n", speed);
		intro("���͸� �Է��ϸ� �����մϴ�.", speed);

		Enter;

	restart:;

		// ���� ����
		srand((unsigned)time(NULL));
		percent = (rand() % (100 - 1) + 1);

		say("������ �� �̸��̿��� ������ ���ھ�!\n", speed);

		Enter;

		NewLine(10);
		intro("    (�����̴� ���̽��� �޽����� ������.)", speed);

		Enter;

		msg(1); // �̸� Ȱ���ð�
		Sleep(1000);
		printf("%45s\n", "���� 6:37");
		Right_Box("\a�ȳ�");

		Enter;

		say("�� �������Ⱦ�...!\n", speed);

		Enter;

		say("���� ������....", speed);

		Enter;

		msg(2); // �ȳ�
		Sleep(1000);
		printf("%45s\n", "���� 7:13");
		Left_Box("\a����");

		Enter;

		say("��!!!!!!!!!!! ����Դ�!!!!!!!!!\n", speed);

		Enter;

		say("��� ���� ���������ϳ� �̱��!!", speed);

		Enter;

		msg(3); // ����
		Sleep(1000);
		printf("%45s\n", "���� 7:27");
		Right_Box("\a����������");

		Enter;

		say("�̷��� ���� ���� �����ޱ� �����", speed);
		n_say("�Ѿ���� ���� ���ڰ� ����....", speed);

		Enter;

		say("�츮�б� �������� ���̸��̶�", speed);
		n_say("������ �Ѿ�� �� �ۿ� ����!", speed);

		Enter;

		NewLine(10);
		printf("\t\t\t4�ð� ��"); Sleep(1000);
		printf("."); Sleep(1000);
		printf("."); Sleep(1000);
		printf("."); Sleep(1000);
		system("cls");
		say("�� �̷��� ������ �� ����?", speed);

		Enter;

		NewLine(10);
		puts("\t\t\t\a(��� �˸���)\n");
		Sleep(500);
		system("cls");
		say("������ ���� �Դ�!!", speed);

		Enter;

		say("���� �̸��̵� ������ ���� ����̱�....", speed);

		Enter;

		msg(4); // ����������
		Sleep(1000);
		printf("%46s\n", "���� 11:14");
		Left_Box("\a�Ⱦ�̾Ȥ���");

		Enter;

		say("...............?", speed);

		Enter;

		say("���� �߸� �� �ǰ�........?", speed);

		Enter;

		NewLine(10);
		intro("\t(�����̴� ��޸� �ٽ� ������. )", speed);

		Enter;

		msg(5); // �Ⱦ�̾Ȥ���
		n_say("(�̰��� ����Դϴ�. )", 100);

		Enter;

		say("�û�!!!!!!!!!!!!!!!!!!!", speed);

		Enter;

		say("������ ������ ���� �����ФФФФФ�", speed);

		Enter;

		msg(5);// �Ⱦ�̾Ȥ���
		Sleep(1000);
		Right_Box("\a��..�� ����");
		Sleep(1000);
		Right_Box("\a����");

		Enter;

		say("��...............", speed);

		Enter;

		say("���� ������ ���� �λ�....", speed);

		Enter;

		msg(6); // ����
		Sleep(1000);
		Left_Box("\a�̾ȴ������ٲ�");
		Sleep(1000);
		Left_Box("\a�ʵ�����");
		puts(" Messenger���� ����");

		Enter;

		say("��... ��� ���� ����.", speed);

		Enter;

		say("���� �̸��̶� �����ϰ� �ʹ�.", speed);

		Enter;

		msg(7); // �ʵ� ����
		puts(" Messenger���� ����");
		puts("-------------------------------------------------------------------------------");
		printf(" �޼��� ���� : "); Sleep(1000);
		printf("��");     Sleep(TIME);
		printf("\b\b��"); Sleep(TIME);
		printf("��");     Sleep(TIME);
		printf("\b\b��"); Sleep(TIME);
		printf("\b\b��"); Sleep(TIME);
		printf(" ");      Sleep(TIME);
		printf("��");     Sleep(TIME);
		printf("\b\b��"); Sleep(TIME);
		printf("\b\b��"); Sleep(TIME);
		printf("��");     Sleep(TIME);
		printf("\b\b��"); Sleep(TIME);
		printf("��");     Sleep(TIME);
		printf("\b\b��"); Sleep(TIME);
		printf("\b\b��"); Sleep(TIME);
		printf("��");     Sleep(TIME);
		printf("\b\b��"); Sleep(TIME);
		printf("?");      Sleep(TIME);
		printf("%49s\n", "<������>");
		printf("-------------------------------------------------------------------------------");

		Enter;

		say("��!", speed);

		Enter;

		NewLine(10);
		intro("    (�����̴� <������>�� ���� ���ȴ�.)", speed);

		Enter;
		// if (enter == '1') percent = 1;

		msg(7); // �ʵ� ����
		Sleep(1000);
		Right_Box("\a���� �����ҷ�?");

		if (percent > 10){
			Sleep(1500);
			Left_Box("\a���Ż��� ���� �ֻ��");
			puts(" Messenger���� ����");

			Enter;

			say("��... �ڻ��ؾ߰ڴ�.", speed);

			Enter;

			say("�� �־�� �̼����!", speed);

			Enter;

			system("color 4C");
			system("title ������ ���� ����?");
			system("cls");
			for (i = 0; i <= 131; i++)
				printf("�ڻ��ϼ̽��ϴ� ");
		}
		else{
			Sleep(1500);
			Left_Box("\a�츮���� �������� �÷�?");
			puts(" Messenger���� ����");

			Enter;

			say("��!!! ���徲!!!!!", speed);

			Enter;

			say("�� �־�� �ƴٵ��!", speed);

			Enter;

			system("color FE");
			system("title ������ �Ĵ� ����!");
			system("cls");
			for (i = 0; i <= 131; i++)
				printf("�����ϼ̽��ϴ� ");
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
		printf("%44s\n", "��������������");
		printf("%44s\n", "�� Shut down��");
		printf("%44s\n", "��������������");
		enter = getch();
		return 0;
	}
	else if (ch == 'h' || ch == 'H'){
		system("cls");
		help(speed);
		puts("\t\t�ƹ� Ű�� �Է��ϸ� ���ư��ϴ�");
		enter = getch();
		goto start;
	}
	else if (ch == 'c' || ch == 'C'){
		system("title Credit");
		system("cls");
		credit();
		puts("�ƹ� Ű�� �Է��ϸ� ���ư��ϴ�");
		enter = getch();
		goto start;
	}
	
	// ����
	system("title Credit");
	system("cls");
	credit();
	system("PAUSE");
	return 0;
}