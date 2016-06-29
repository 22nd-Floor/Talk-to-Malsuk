#include "Header.h"
/*  beta. 1.5.1.0  */

int main()
{	
	// 초기 설정
	Setting();
	// 타이틀 출력
	Title();
	// 파일을 읽어 데이터에 저장
	Data = readFiles();
	// 나중에 사용할 전역변수 초기화
	Speed = toSpeed(Data.speed);
	Name = Data.name;
	// 수정할까?
	Modify();
	// 본 내용 시작
	puts(".....");
	// 정상 종료
	return 0;
}