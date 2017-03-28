# include <iostream>
using namespace std;

//һ�����ָ�����������߲�1���������ѭ��
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

//���ַ�����Ҫ�ƶ�32�Σ���Ϊint����ռ32λ
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

//һ������1����ԭ��������������������ұ������һ��1��Ϊ0
//����취ѭ��ֻ��Ҫ�����ж���λ�ͽ��ж��ٴ�
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