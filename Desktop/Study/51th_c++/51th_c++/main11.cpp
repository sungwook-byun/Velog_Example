#include <stdio.h>

// �޸�

// ����
// ������
// ROM (�ڵ�, ���ڿ� ��) 



struct PlayerInfo
{
	int CurHp;
	int MaxHp;
	int CurMp;
	int MaxMp;
	int Att;
	int Def;
};



void Add(int a, int b, int* _Out)
{
	*_Out = a + b;


}


// ��ü�� �����ؿ��°� �ƴ� �ּҸ� �޴� ����� ����ϴ� �����Ͱ� �ξ� ȿ�����̶�� �� �� ����
void OutputPlayerInfo(const PlayerInfo* _pinfo)
{	
	printf("�÷��̾� ü�� %d / %d \n", _pinfo->CurHp, _pinfo->MaxHp);
	printf("�÷��̾� ���� %d / %d \n", _pinfo->CurMp, _pinfo->MaxMp);

	printf("�÷��̾� ���ݷ� %d / %d \n", _pinfo->Att, _pinfo->Att);
	printf("�÷��̾� ���� %d / %d \n", _pinfo->Def, _pinfo->Def);
}


void TestFunc(const int*)
{




}

int main()
{
	int Result = 0;

	// ��ȯ���� void������ �ּҰ��� �Ѱܼ� �޾ұ� ������ ���� �����
	Add(100, 200, &Result); 

	PlayerInfo info = {};

	info.CurHp = 40;
	info.MaxHp = 100;

	info.CurMp = 40;
	info.MaxMp = 50;

	info.Att = 1000;
	info.Def = 500;

	// �ּҸ� �޾ư�
	OutputPlayerInfo(&info);

	


	// ���ڿ�
	char szString[10] = "abcdef";

	// ���ڿ��� �ּҰ��̴�.
	// �ڵ�� �����ϴ� ���ڿ��� ������ ROM�� ����ȴ�.
	// ���ڿ��� ROM�� �ִ� ���ڿ� �������� �ּҸ� �ǹ��Ѵ�.
	// char, Wchar_t Ÿ�� �迭�� �ʱ�ȭ �� ���ڿ��� �����ϴ°��
	// �迭�� �� ��Ҹ� ���ڿ��� �� ���ڷ� �ʱ�ȭ �ϰڴٴ� �ǹ� 

	// �����Ϳ� �־ ������ ���ٴ°� �ּҸ� �޴� �������̹Ƿ� �ᱹ ���ڿ��� �ּҰ��̶�� ����� ���´�.
	const char* pString = "abcdef";

	// a�� ����
//	char c = *pString;


	char c = 0;

	// ���ڿ��� �ʱ�ȭ ���� �迭�� �ι�° ���ڸ� �о ���� c�� �����ϴ� ���
	c = szString [1];  //	c = *(szString + 1);
	szString[1] = 'a';

	// ���� ���ڿ��� �����ؼ� �ι�° ���ڸ� �о ���� c�� �����ϴ� ���
	c = pString[1];		//	c = *(pString + 1);
	// ����ĳ�������� �ص� ������ ������ �ȳ����� �����ͷ� ROM������ �б�����޸��ε� �����ߴ� �ѵ� ����� ������ �ɸ��� ����
	// ROM �� �ִ� �ʱ�ȭ�� ���ڿ� ������ �����Ϸ��� �ϱ� ����
	((char*)pString)[1] = 'a'; // ������,��ũ, -> ��Ÿ�ӿ���(���൵�߿� ���� �߻�)


	// ���� ������ ���ڿ��� ������ ���� �ּҸ� ��Ÿ����.
	// �ڵ�󿡼� ������ ���ڿ��� ������ ��������, �ش� ���ڿ��� �޸𸮻� �� 1���� �����Ѵ�.
	const char* pString2 = "abcdef";


	const int value = 100;
	
	const int* pValue = &value;
	 
//	int* pValue1 = pValue;  // constŸ���̴ϱ� const�� ������

	// ���ڿ��� �� NULL���� (���ڿ��� ���� �˸��� �ι��ڰ� �ݵ�� �����ؾ� �Ѵ�.)
	// ���ڿ� �߰��� 0(�ι���)�� ������ ���ڿ��� �����. 

	// char data[6] = "abcdef"; ������ 0���� 7ĭ�� �־�� �ϴµ� 6ĭ�� �ִ� ������ ��
	char data[7] = "abcdef";

	char character = '\0';





	
	return 0;
}