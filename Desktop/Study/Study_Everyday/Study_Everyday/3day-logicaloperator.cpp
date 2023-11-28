int main()
{
	int a = 0;
	int data = 0;

	a = 10;
	data = ++a;
	data = a++;

	data = 0;
	data--;
	data--;

	// 논리 연산자
	// !(역), &&(and), ||(or)
	// 참(true), 거짓(false)
	// 참   : 0이 아닌값, 주로 1
	// 거짓 : 0

	int truefalse1 = true; // 1이 들어감

	true;  // 1
	false; // 0

	bool truefalse = false; // 불리언은 참과 거짓만 다루는 전용 자료형
	bool IsTrue = 100; // 불리언은 0,1만 저장할수 있어서 1로 받아들임 고로 1바이트의 크기를 가짐

	IsTrue = true;
	IsTrue = !IsTrue;
 


	return 0;
}