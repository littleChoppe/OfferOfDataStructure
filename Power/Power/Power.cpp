# include <iostream>
using namespace std;

//只考虑base> 0 而且 exponent > 0 的情况
//当 exponent < 0 时 结果需要取倒数
// 当 exponent < 0 ,且 base = 0 的时候， 0 取倒数不合法
double Power1(double base, int exponent)
{
	double result = 1.0;
	for (size_t i = 0; i < exponent; i++)
	{
		result *= base;
	}
	return result;
}

//base 是 double 所以判断是否为 0 不能直接使用 ==
bool InvalidInput = false;

bool Equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) &&
		(num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

double PowerWithUnsignedExponent1(double base, int exponent)
{
	double result = 1.0;
	for (size_t i = 0; i < exponent; i++)
	{
		result *= base;
	}
	return result;
}

double Power2(double base, int exponent)
{
	InvalidInput = false;
	if (Equal(base, 0.0) && exponent < 0)
	{
		InvalidInput = true;
		return 0.0;
	}
	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);

	double result = PowerWithUnsignedExponent1(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;
	return result;
}

//更高效的写法
double PowerWithUnsignedExponent2(double base, int exponent)
{
	if (exponent == 0)
		return 1.0;
	if (exponent == 1)
		return base;
	double reslut = PowerWithUnsignedExponent2(base, exponent >> 1);
	reslut *= reslut;
	if (exponent & 0x1 == 1)
		reslut *= base;
	return reslut;
}

double Power3(double base, int exponent)
{
	InvalidInput = false;
	if (Equal(base, 0.0) && exponent < 0)
	{
		InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);

	double result = PowerWithUnsignedExponent2(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;
	return result;
}

int main()
{
	cout << Power2(2, -3) << endl;
	cout << Power3(2, -3) << endl;
	return 0;
}