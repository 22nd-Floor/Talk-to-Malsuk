#include "Header.h"

// 五昔 敗呪
int main()
{
	int i; // for庚拭 紫遂
	int whatspeed; // 獣娃 識澱
	int speed = NORMAL; // 痕井吉 獣娃 (段奄葵精 50)
	int percent;
	char ch; // Yes No Help 識澱
	char one_more; // 廃 腰 希?
	char enter; // 殖斗研 脊径梅澗亜?

start:;

	// 段奄 竺舛
	setcursortype(NOCURSOR);
	system("title Talk To Mirim");
	system("color F0"); // 0 = 伊舛事 1 = 督櫛事 2 = 段系事 3 = 秦事 4 = 察悪事 5 = 切爽事 6 = 葛櫛事 7 = 避事 8 = 噺事 9 = 尻廃 督櫛
	system("cls");      // A = 尻廃 段系事 B = 尻廃 秦事 C = 尻廃 察悪事 D = 尻廃 切爽事 E = 尻廃 葛櫛事 F = 項精 避事
	system("mode con:lines=25");

	// 段奄 但
	NewLine(8);
	puts("\t\tΓΑΑΑΑΑΑΑΔ");
	puts("\t\tΒ Talk to MirimΒYou Are Junpil.");
	puts("\t\tΒ  Ver. 3.0.0  ΒDo you want to talk to Mirim?");
	puts("\t\tΖΑΑΑΑΑΑΑΕ");
	printf("\t\t\t  (Yes = y / No = n / Help = h)");
	
	ch = getch();

	// YES
	if (ch == 'y' || ch == 'Y'){
		system("title 段奄竺舛");
		system("cls");
		NewLine(6);
		intro("段奄 竺舛 但脊艦陥.\n\n", speed);
		intro("源税 紗亀研 茨虞 爽淑獣神.\n", speed);
		puts("\t\t(Enter研 刊研 獣 左搭税 匙牽奄稽 竺舛桔艦陥.)\n");
		puts("\t\t1. 探探備 2. 左搭 3. 匙牽惟");
		
		while (1){
			whatspeed = getch();
			system("cls");
			if (whatspeed == '1'){
				speed = SLOW;
				NewLine(6);
				puts("\t\t1. 探探備 2. 左搭 3. 匙牽惟\n");
				intro("源税 紗亀亜 旋雁馬重亜推?\n\n", speed);
				intro("旋雁馬檎 Enter研\n", speed);
				intro("旋雁馬走 省陥檎 陥献 腰硲研 喚君爽室推.", speed);
			}
			else if (whatspeed == '2'){
				speed = NORMAL;
				NewLine(6);
				puts("\t\t1. 探探備 2. 左搭 3. 匙牽惟\n");
				intro("源税 紗亀亜 旋雁馬重亜推?\n\n", speed);
				intro("旋雁馬檎 Enter研\n", speed);
				intro("旋雁馬走 省陥檎 陥献 腰硲研 喚君爽室推.", speed);
			}
			else if (whatspeed == '3'){
				speed = FAST;
				NewLine(6);
				puts("\t\t1. 探探備 2. 左搭 3. 匙牽惟\n");
				intro("源税 紗亀亜 旋雁馬重亜推?\n\n", speed);
				intro("旋雁馬檎 Enter研\n", speed);
				intro("旋雁馬走 省陥檎 陥献 腰硲研 喚君爽室推.", speed);
			}
			else if (whatspeed == 13)
				break;
			else if (whatspeed == 's' || whatspeed == 'S')
				goto restart;
		}

		system("cls");
		printf("%49s", "＜ 殖斗 脊径 庚姥");
		help(speed);
		intro("殖斗 庚姥澗 是拭 赤柔艦陥.", speed);

		Enter;

		NewLine(6);
		intro("設 梅柔艦陥!\n\n", speed);
		intro("殖斗研 尻展馬食 持奄澗 神嫌拭 企廃 \n", speed);
		intro("奪績精 紫遂切拭惟 赤柔艦陥.\n\n", speed);
		intro("殖斗研 脊径馬檎 獣拙杯艦陥.", speed);

		Enter;

	restart:;

		// 貝呪 竺舛
		srand((unsigned)time(NULL));
		percent = (rand() % (100 - 1) + 1);

		say("神潅精 伽 耕顕戚拭惟 穿腰聖 魚畏嬢!\n", speed);

		Enter;

		NewLine(10);
		intro("    (層琶戚澗 凪戚什栽 五重煽研 伸醸陥.)", speed);

		Enter;

		msg(1); // 戚硯 醗疑獣娃
		Sleep(1000);
		printf("%45s\n", "神板 6:37");
		Right_Box("\a照括");

		Enter;

		say("焼 左鎧獄携嬢...!\n", speed);

		Enter;

		say("舛源 恭鍵陥....", speed);

		Enter;

		msg(2); // 照括
		Sleep(1000);
		printf("%45s\n", "神板 7:13");
		Left_Box("\aぞし");

		Enter;

		say("神!!!!!!!!!!! 岩舌尽陥!!!!!!!!!\n", speed);

		Enter;

		say("奄歳 糎蟹 悉什錘走馬葛 戚奄醤!!", speed);

		Enter;

		msg(3); // ぞし
		Sleep(1000);
		printf("%45s\n", "神板 7:27");
		Right_Box("\a穿腰繊せせ");

		Enter;

		say("戚係惟 鈷遭 蟹税 穿腰閤奄 奄綬拭", speed);
		n_say("角嬢神走 省精 食切亜 蒸走....", speed);

		Enter;

		say("酔軒俳嘘 箭室耕昔 政耕顕戚虞亀", speed);
		n_say("蟹拭惟 角嬢臣 呪 鉱拭 蒸嬢!", speed);

		Enter;

		NewLine(10);
		printf("\t\t\t4獣娃 板"); Sleep(1000);
		printf("."); Sleep(1000);
		printf("."); Sleep(1000);
		printf("."); Sleep(1000);
		system("cls");
		say("訊 戚係惟 岩舌戚 照 神走?", speed);

		Enter;

		NewLine(10);
		puts("\t\t\t\a(凪五 硝顕製)\n");
		Sleep(500);
		system("cls");
		say("神神神 岩舌 尽陥!!", speed);

		Enter;

		say("蝕獣 耕顕戚亀 蟹拭惟 鋼廃 乞丞戚浦....", speed);

		Enter;

		msg(4); // 穿腰繊せせ
		Sleep(1000);
		printf("%46s\n", "神板 11:14");
		Left_Box("\a夙嬢耕照せせ");

		Enter;

		say("...............?", speed);

		Enter;

		say("鎧亜 設公 沙 闇亜........?", speed);

		Enter;

		NewLine(10);
		intro("\t(層琶戚澗 凪五研 陥獣 伸醸陥. )", speed);

		Enter;

		msg(5); // 夙嬢耕照せせ
		n_say("(戚依精 紫叔脊艦陥. )", 100);

		Enter;

		say("獣察!!!!!!!!!!!!!!!!!!!", speed);

		Enter;

		say("託軒軒 岩舌聖 馬走 源走ばばばばばば", speed);

		Enter;

		msg(5);// 夙嬢耕照せせ
		Sleep(1000);
		Right_Box("\aし..嬢 じさ");
		Sleep(1000);
		Right_Box("\a設切");

		Enter;

		say("馬...............", speed);

		Enter;

		say("糎蟹 床傾奄 旭精 昔持....", speed);

		Enter;

		msg(6); // 設切
		Sleep(1000);
		Left_Box("\a耕照陥製拭匝臆");
		Sleep(1000);
		Left_Box("\a格亀設切");
		puts(" Messenger拭辞 左蛙");

		Enter;

		say("馬... 奄歳 楚蟹 疏革.", speed);

		Enter;

		say("糎蟹 耕顕戚櫛 悉什馬壱 粛陥.", speed);

		Enter;

		msg(7); // 格亀 設切
		puts(" Messenger拭辞 左蛙");
		puts("-------------------------------------------------------------------------------");
		printf(" 五室走 床奄 : "); Sleep(1000);
		printf("い");     Sleep(TIME);
		printf("\b\b蟹"); Sleep(TIME);
		printf("ぉ");     Sleep(TIME);
		printf("\b\b虞"); Sleep(TIME);
		printf("\b\b櫛"); Sleep(TIME);
		printf(" ");      Sleep(TIME);
		printf("さ");     Sleep(TIME);
		printf("\b\b室"); Sleep(TIME);
		printf("\b\b悉"); Sleep(TIME);
		printf("さ");     Sleep(TIME);
		printf("\b\b什"); Sleep(TIME);
		printf("ぞ");     Sleep(TIME);
		printf("\b\b馬"); Sleep(TIME);
		printf("\b\b拝"); Sleep(TIME);
		printf("ぉ");     Sleep(TIME);
		printf("\b\b掘"); Sleep(TIME);
		printf("?");      Sleep(TIME);
		printf("%49s\n", "<左鎧奄>");
		printf("-------------------------------------------------------------------------------");

		Enter;

		say("粧!", speed);

		Enter;

		NewLine(10);
		intro("    (層琶戚澗 <左鎧奄>研 喚君 獄携陥.)", speed);

		Enter;
		// if (enter == '1') percent = 1;

		msg(7); // 格亀 設切
		Sleep(1000);
		Right_Box("\a蟹櫛 悉什拝掘?");

		if (percent > 10){
			Sleep(1500);
			Left_Box("\a佐重歯晦 すす 訊紫劃");
			puts(" Messenger拭辞 左蛙");

			Enter;

			say("焼... 切詞背醤畏陥.", speed);

			Enter;

			say("設 赤嬢虞 戚室雌焼!", speed);

			Enter;

			system("color 4C");
			system("title 層琶戚 織持 しじ?");
			system("cls");
			for (i = 0; i <= 131; i++)
				printf("切詞馬写柔艦陥 ");
		}
		else{
			Sleep(1500);
			Left_Box("\a酔軒増拭 虞檎股生君 臣掘?");
			puts(" Messenger拭辞 左蛙");

			Enter;

			say("森!!! ���緇�!!!!!", speed);

			Enter;

			say("設 赤嬢虞 焼陥級焼!", speed);

			Enter;

			system("color FE");
			system("title 層琶戚 板陥 ずず!");
			system("cls");
			for (i = 0; i <= 131; i++)
				printf("悉什馬写柔艦陥 ");
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
		printf("%44s\n", "ΓΑΑΑΑΑΔ");
		printf("%44s\n", "Β Shut downΒ");
		printf("%44s\n", "ΖΑΑΑΑΑΕ");
		enter = getch();
		return 0;
	}
	else if (ch == 'h' || ch == 'H'){
		system("cls");
		help(speed);
		puts("\t\t焼巷 徹蟹 脊径馬檎 宜焼逢艦陥");
		enter = getch();
		goto start;
	}
	else if (ch == 'c' || ch == 'C'){
		system("title Credit");
		system("cls");
		credit();
		puts("焼巷 徹蟹 脊径馬檎 宜焼逢艦陥");
		enter = getch();
		goto start;
	}
	
	// 曽戟
	system("title Credit");
	system("cls");
	credit();
	system("PAUSE");
	return 0;
}