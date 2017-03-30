# include<iostream>
using namespace std;

void Swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//第一种
int RandomInRange(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int Partition(int * data, int length, int start, int end)
{
	if (data == NULL || length <= 0 || start < 0 || end >= length)
		throw new exception("Invalid Parameters");
	int index = RandomInRange(start, end);
	Swap(&data[index], &data[end]);
	int small = start - 1;
	for (index = start; index < end; index++)
	{
		if (data[index] < data[end])
		{
			small++;
			if (small != index)
				Swap(&data[index], &data[small]);
		}
	}
	++small;
	Swap(&data[small], &data[end]);
	return small;
}

void QuickSort(int * data, int length, int start, int end)
{
	if (start == end)
		return;
	int index = Partition(data, length, start, end);
	if (index > start)
		QuickSort(data, length, start, index - 1);
	if (index < end)
		QuickSort(data, length, index + 1, end); 
}

//第二种

void InsertionSort(int * array, int length)
{
	int j = 0, p = 0;
	int temp = 0;
	for (p = 1; p < length; p++)
	{
		temp = array[p];
		for (j = p; j > 0 & array[j - 1] > temp; j--)
		{
			array[j] = array[j - 1];
		}
		array[j] = temp;
	}
}

int Median(int * array, int left, int right)
{
	int center = left + (right - left) / 2;
	if (array[left] > array[center])
		Swap(&array[left], &array[center]);
	if (array[left] > array[right])
		Swap(&array[left], &array[right]);
	if (array[center] > array[right])
		Swap(&array[center], &array[right]);

	Swap(&array[center], &array[right - 1]);
	return array[right - 1];
}

void Qsort(int * array, int left, int right)
{
	const int cutoff = 3;
	if (left + cutoff <= right)
	{
		int pivot = Median(array, left, right);
		int i = left, j = right - 1;
		for ( ; ; )
		{
			while (array[++i] < pivot);
			while (array[--j] > pivot);
			if (i < j)
				Swap(&array[i], &array[j]);
			else
				break;
		}
		Swap(&array[i], &array[right - 1]);

		Qsort(array, left, i - 1);
		Qsort(array, i + 1, right);
	}
	else
		InsertionSort(array + left, right - left + 1);

}

void QuickSort(int * array, int length)
{
	Qsort(array, 0, length - 1);
}

int main()
{
	int data[10] = { 8, 1, 4, 9, 0, 3, 5, 2, 7, 6 };
	//QuickSort(data, 10, 0, 10 - 1);

	QuickSort(data, 10);

	for (size_t i = 0; i < 10; i++)
	{
		cout << data[i] << endl;
	}
	return 0;
}