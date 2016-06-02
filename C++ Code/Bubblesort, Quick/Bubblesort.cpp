#include "Bubblesort.h"

void Bubblesort::Swap(int & ref1, int & ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int Bubblesort::Partition(int arr[], int left, int right)
{
	int pivot = arr[left]; //������ ����(���� ���� ����)
	int low = left+1, high = right; // �ε��� ���� ��Ÿ���� ������ ��ġ������ �� / left +1�� ���� �����̱� ������ +1����

	while (low <= high)
	{
		while (pivot >= arr[low] && low<=right) { //�������� �� ���� ���̱� ����
			low++;
		}
		while (pivot <= arr[high] && high>left) {
			high--;
		}

		if(low<=high)
			Swap(arr[low], arr[high]);
	}
	Swap(arr[left], arr[high]);
	return high;
}

void Bubblesort::BubbleSort(int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				Swap(arr[j], arr[j + 1]);
		}
	}
}

void Bubblesort::QuickSort(int arr[], int left, int right)
{
	if (left >= right)
		return;
	int mid = Partition(arr, left, right);
	QuickSort(arr, left, mid - 1);
	QuickSort(arr, mid + 1, right);
}