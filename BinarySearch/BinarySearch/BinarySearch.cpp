# include <iostream>

using namespace std;

//注意 midIndex = minIndex + (maxIndex - midIndex) / 2;
//原本为 midIndex = (minIndex + maxIndex) / 2;
//为了防止两个数相加大于类型所能容纳的最大整数导致溢出
int BinarySearch(int * array, int length, int value)
{
	if (array == NULL || length <= 0)
		throw new exception("参数无效");
	int minIndex = 0;
	int maxIndex = length - 1;
	int midIndex = 0;
	while (minIndex <= maxIndex)
	{
		midIndex = minIndex + (maxIndex - midIndex) / 2;
		if (array[midIndex] == value)
			return midIndex;
		else if (array[midIndex] < value)
		{
			minIndex = midIndex + 1;
		}
		else
		{
			maxIndex = midIndex - 1;
		}
	}
	return -1;
}

int MinInOrder(int * numbers, int index1, int index2)
{
	int result = numbers[index1];
	for (size_t i = index1 + 1; i <= index2; i++)
	{
		if (numbers[i] < result)
			result = numbers[i];
	}
	return result;
}

int Min(int * numbers, int length)
{
	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		else
		{
			indexMid = index1 + (index2 - index1) / 2;
			if (numbers[indexMid] == numbers[index1] &&
				numbers[index1] == numbers[index2])
				return MinInOrder(numbers, index1, index2);

			if (numbers[indexMid] >= numbers[index1])
				index1 = indexMid;
			else if (numbers[indexMid] <= numbers[index2])
				index2 = indexMid;
		}
	}
	return numbers[indexMid];
}

int main()
{
	int array[6] = { 1, 2, 3, 4, 5, 6 };
	int array2[5] = { 3, 4, 5, 1, 2 };
	cout << BinarySearch(array, 6, 3) << endl;
	cout << Min(array2, 5) << endl;
	return 0;
}

