#include "Header.h"
#include <Windows.h>

#define VER "beta. 1.5.1.0"


int main()
{
	// 초기 설정
	Setting();
	// 타이틀 출력
	Title(VER);
	// 파일 읽기
	readFiles();
	// 수정할까?
	Modify();
	// 본 내용 시작
	while (Dialog() == 1);
	// 정상 종료
	return 0;
}