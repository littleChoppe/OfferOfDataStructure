# include <iostream>
using namespace std;

long long Fabonacci(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return Fabonacci(n - 1) + Fabonacci(n - 2);
}

long long FabonacciCircle(unsigned int n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];
	int fabonacciOne = 0;
	int fabonacciTwo = 1;
	int fabonacciN = 0;
	for (size_t i = 2; i <= n; i++)
	{
		fabonacciN = fabonacciOne + fabonacciTwo;
		fabonacciOne = fabonacciTwo;
		fabonacciTwo = fabonacciN;
	}
	return fabonacciN;
}

int main()
{
	cout << Fabonacci(3) << endl;
	cout << FabonacciCircle(4) << endl;
}