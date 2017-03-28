# include <iostream>
using namespace std;

//一旦出现负数，右移左边补1，会出现死循环
int NumberOfOne1(int n)
{
	int count = 0;
	while (n)
	{
		if (n & 1)
			count++;
		n = n >> 1;
	}
	return count;
}

//这种方法需要移动32次，因为int类型占32位
int NumberOfOne2(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while ( flag )
	{
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

//一个数减1再与原来的数求与会把这个数从右边数起第一个1改为0
//这个办法循环只需要进行有多少位就进行多少次
int NumberOfOne3(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = (n - 1) & n;
	}

	return count;
}

int main()
{
	cout << NumberOfOne1(100) << endl;
	cout << NumberOfOne2(100) << endl;
	cout << NumberOfOne3(100) << endl;
	return 0;
}