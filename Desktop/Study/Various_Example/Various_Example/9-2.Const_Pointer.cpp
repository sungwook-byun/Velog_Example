#include<stdio.h>

int main()
{
	void* pVoid = nullptr;
	float* pFloat = nullptr;

	{
		int a = 0;
		float f = 0.f;
		double d = 0.;
		long long ll = 0;

		pVoid = &a;
		pVoid = &f;
		pVoid = &d;
		pVoid = &ll;
	}






	return 0;
}