# include <iostream>

using namespace std;

void SortAges(int * ages, int length)
{
	const int oldestAge = 99;
	int timesOfAge[oldestAge + 1];
	for (size_t i = 0; i < oldestAge + 1; i++)
	{
		timesOfAge[i] = 0;
	}

	for (size_t i = 0; i < length; i++)
	{
		int age = ages[i];
		if (age <= 0 || age > 99)
			throw new exception("age out of range");
		timesOfAge[age]++;
	}

	int index = 0;
	for (size_t i = 1; i < oldestAge + 1; i++)
	{
		for (size_t j = 0; j < timesOfAge[i]; j++)
		{
			ages[index] = i;
			index++;
		}
	}
}

int main()
{
	int ages[10] = { 20, 19, 23, 28, 25, 25, 26, 28, 20, 20 };
	SortAges(ages, 10);
	for (size_t i = 0; i < 10; i++)
	{
		cout << ages[i] << endl;
	}
	return 0;
}