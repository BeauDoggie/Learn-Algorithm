#include<iostream>

using namespace std;

/**********/
/*********/
bool BubbleSort(int* data, int len)
{
	int i, j;
	int flag = 0;
	int tmpData;

	for (i = 1; i < len; i++)
	{
		flag = 0;

		for (j = 0; j < len - i; j++)
		{
			if (data[j] < data[j + 1])
			{
				flag = 1;
				tmpData = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmpData;
			}
		}

		if (flag == 0)
			break;
	}

	return true;
}


bool SelectSort(int* data, int len)
{
	int index;
	int i, j;
	int tmpData;

	for (i = 0; i < len - 1; i++)
	{
		index = i;
		for (j = i + 1; j < len; j++)
		{
			if (data[index] > data[j])
			{
				index = j;
			}
				
		}

		if (i != index)
		{
			tmpData = data[i];
			data[i] = data[index];
			data[index] = tmpData;
		}

	}

	return true;
}


bool InsertSort(int* data, int len)
{
	int i, j;
	int key;
	int index;

	for (i = 1; i < len; i++)
	{
		key = data[i];
		index = i;

		for (j = i-1; j >= 0; j--)
		{
			if (data[j] > key)
			{
				data[j + 1] = data[j];
				index = j;
			}
			
		}
		data[index] = key;
	}

	return true;
}


int main(int argc, char** argv)
{
	int data[10] = { 9, 2, 4, 3, 5, 6, 7, 8, 1, 0 };

	SelectSort(data, 10);

	int i = 0;

	while (i < 10)
		cout << data[i++] << " ";
	cout << endl;
	

	system("pause");


	return 0;
}