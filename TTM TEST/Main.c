#include "Header.h"
#include <Windows.h>

#define VER "beta. 1.5.1.0"


int main()
{
	// �ʱ� ����
	Setting();
	// Ÿ��Ʋ ���
	Title(VER);
	// ���� �б�
	readFiles();
	// �����ұ�?
	Modify();
	// �� ���� ����
	while (Dialog() == 1);
	// ���� ����
	return 0;
}