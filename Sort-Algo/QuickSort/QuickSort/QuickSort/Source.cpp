#include<iostream>


using namespace std;



void CreateMinHeap(int* data, int len)
{
	int tmpData;
	int minIndex;
	int parent;
	int left_child;
	int righ_child;

	parent = len / 2;


	for (int i = parent; i >= 1; i--)
	{
		left_child = 2 * i;
		righ_child = left_child + 1;
		righ_child = (righ_child > len) ? len : righ_child;

		minIndex = i - 1;
		if (data[minIndex] > data[left_child - 1])
			minIndex = left_child - 1;
		if (data[minIndex] > data[righ_child - 1])
			minIndex = righ_child - 1;

		if (minIndex != i - 1)
		{
			tmpData = data[minIndex];
			data[minIndex] = data[i - 1];
			data[i - 1] = tmpData;
		}
	}




}
bool HeapSort(int* data, int len)
{
	int i;

	for (i = 0; i < len - 1; i++)
	{
		CreateMinHeap(data + i, len - i);
	}
	return true;
}


bool Recursive_QuickSort(int* data, int len)
{
	int first = 0;
	int last = len -1;

	int keyData = data[last];//reference data

	//depart into two parts.

	if (len < 2)
		return true;

	while (first < last)
	{
		while ((first < last) && data[first] < keyData)
		{
			first++;
		}

		data[last] = data[first];


		while ((first < last) && data[last] > keyData)
		{
			last--;
		}
		data[first] = data[last];

	}
	data[first] = keyData;



	Recursive_QuickSort(data, first);
	Recursive_QuickSort(data + first + 1, len - first - 1);

	return true;
}



bool MergeSort(int* data,int* back_data, int len)
{
	int low = 0;
	int high = len - 1;
	int mid = (len -1)/ 2;
	int i = 0;
	int j = 0;
	int k = 0;


	if (len < 2)
		return true;

	MergeSort(data, back_data, mid + 1);
	MergeSort(data + mid + 1, back_data, len - mid - 1);

	int* pLeftData = data;
	int* pRigtData = data + mid + 1;

	while (i <= mid && j <= len - mid - 2)
	{
		if (pLeftData[i] < pRigtData[j])
		{
			back_data[k++] = pLeftData[i];
			i++;
		}
		else
		{
			back_data[k++] = pRigtData[j];
			j++;
		}
	}

	while(i <= mid)
		back_data[k++] = pLeftData[i++];

	while (j <= len - mid - 2)
		back_data[k++] = pRigtData[j++];


	for (i = 0; i < len; i++)
	{
		data[i] = back_data[i];
	}

	return true;
}



int main(int argc, char** argv)
{

	int data[] = { 9, 2, 3, 4, 1, 0, 6, 8, 7, 5 };
	int back_data[10];

	//MergeSort(data,back_data, 10);

	HeapSort(data, 10);

	int i = 0;
	while (i < 10)
		cout << data[i++] << " ";
	cout << endl;

	system("pause");

	return 0;
}