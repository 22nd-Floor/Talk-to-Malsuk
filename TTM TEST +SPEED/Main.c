#include "Header.h"
/*  beta. 1.5.1.0  */

int main()
{	
	// �ʱ� ����
	Setting();
	// Ÿ��Ʋ ���
	Title();
	// ������ �о� �����Ϳ� ����
	Data = readFiles();
	// ���߿� ����� �������� �ʱ�ȭ
	Speed = toSpeed(Data.speed);
	Name = Data.name;
	// �����ұ�?
	Modify();
	// �� ���� ����
	puts(".....");
	// ���� ����
	return 0;
}