# include <iostream>

using namespace std;

void ReplaceBlank(char string[], int length)
{
	if (string == NULL || length <= 0)
		return;
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;

	while (string[i] != '\0')
	{
		++ originalLength;
		if (string[i] == ' ')
			++ numberOfBlank;
		++i;
	}

	int newLength = originalLength + numberOfBlank * 2;
	int indexOfOrigin = originalLength;
	int indexOfNew = newLength;

	if (newLength > length)
		return;

	while (indexOfOrigin >= 0 && indexOfNew > indexOfOrigin)
	{
		if (string[indexOfOrigin] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
		{
			string[indexOfNew--] = string[indexOfOrigin];
		}
		--indexOfOrigin;
	}
}

int main()
{
	char string[20] = "We are happy";
	for (size_t i = 0; string[i] != '\0'; i++)
	{
		cout << string[i];
	}
	cout << endl;

	ReplaceBlank(string, 20);

	for (size_t i = 0; string[i] != '\0'; i++)
	{
		cout << string[i];
	}
	cout << endl;
	return 0;
}