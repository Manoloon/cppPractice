// Algoritmos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
//#include "Algoritmos.h"


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// Selection sort
void SelectionSort(int arr[], int arrSize) {
	int minIndex;
	for (int i = 0; i < arrSize - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < arrSize; j--)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
			std::swap(arr[i], arr[minIndex]);
		}
	}
}


// QuickSort 
int Partition(int arr[],int StartIndex,int EndIndex)
{
	// tomamos como pivot el primer dato de la matrix
	int pivot = arr[StartIndex];
	// Sublista derecha e izquierda estan vacias al comienzo.
	int middleIndex = StartIndex;
	// iteramos la matrix como 1 , n , -1;
	for(int i = StartIndex+1 ; i <= EndIndex;i++)
	{
		if(arr[i] < pivot)
		{
			//este item de la matrix se encuentra en la lista izquierda. 
			//preparamos el asiento cambiando el indice medio.
			++middleIndex;
			//intercambiamos el miembro de la lista de la derecha por el miembro de la lista izquierda.
			std::swap(arr[i], arr[middleIndex]);
		}		
	}
	// por ahora el dato de la matrix con indice medio es parte de la lista de la derecha, lo intercambiamos por el item de la lista de la izquierda.
	std::swap(arr[StartIndex], arr[middleIndex]);
	// y devolvemos el pivot para ser usado en el proximo Quicksort.
	return middleIndex;
}

void QuickSort(int arr[], int StartIndex,int EndIndex)
{
	if(StartIndex< EndIndex)
	{
		int pivotIndex = Partition(arr, StartIndex, EndIndex);
		QuickSort(arr, StartIndex, pivotIndex - 1);
		QuickSort(arr, pivotIndex + 1, EndIndex);
	}
}

int main()
{
	int Array[] = { 25,23,41,20,1 };
	int arrSize = sizeof(Array) / sizeof(*Array);

	std::cout << "Array inicial: ";
	for (int i=0;i<arrSize;i++)
		std::cout << Array[i] << " ";
	std::cout << std::endl;

	//QuickSort(Array, 0, arrSize - 1);
	SelectionSort(Array, arrSize);
	std::cout << "Array organizada: ";
	for (int i = 0;i<arrSize;i++)
		std::cout << Array[i] << " ";
	std::cout << std::endl;
	return 0;
}
