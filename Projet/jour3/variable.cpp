
#include <iostream>

using namespace std;

void f()
{
	cout << "Hello World !" << endl;
	int i = 42;
	for (int j=0; j < i; j++)
	{
		cout << j + 1 << endl;
	}
	cout << "Bye World." << endl;
}

int reponse = 42;
void g()
{
	cout << reponse << endl;
}

void h(int increment)
{
	static int variable = 0;
	variable += increment;
	cout << variable << endl;
}

int main()
{
	f();
	g();

	for (int i = 0; i < 5; i ++)
	{
		h(2 * i + 1);
	}
	
	return 0;
}




