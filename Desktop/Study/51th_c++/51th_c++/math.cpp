
// 이미 메인에도 같은 이름의 전역변수가 있기 때문에 링킹 과정에서 오류가 나온다
//   int g_Global = 0;

static int g_Staitic = 0;

// 외부변수
extern int g_manager;


int Sub(int a, int b)
{
	return a - b;
}

int Add(int a, int b)
{
	return a + b;
}

// 실제로 어딘가에는 extern 전역변수가 존재해야함
int g_manager = 0;