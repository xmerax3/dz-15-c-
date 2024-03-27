﻿#include <iostream>
using namespace std;



void pointers()
{
	int x = 10;
	int* p = &x;
	int** pp = &p;
	int*** ppp = &pp;
	int**** pppp = &ppp;
	int***** ppppp = &pppp;
	cout << &x << "\n" << &p << "\n" << &pp << "\n" << &ppp << "\n" << &pppp << "\n" << &ppppp << "\n\n";
	cout << ****ppppp << "\n" << ***ppppp << "\n" << **ppppp << "\n" << *ppppp << "\n" << ppppp << "\n" << &ppppp;
}


void AllocateMemory(int** ar, unsigned int count)              
{
	if (count > 100000) count = 100000;
	(*ar) = new int[count];
	cout << "AllocateMemory\n";
}

void RandomFillArray(int* ar, unsigned int count) {            
	if (ar == nullptr) {
		cout << "Null pointer! RandomFillArray Exit...\n";
		return;
	}
	cout << "RandomFillArray START!\n";
	for (int i = 0; i < count; i++)
	{
		ar[i] = rand() % 100;
	}
	cout << "RandomFillArray DONE!\n";
}

void PrintArray(int* ar, unsigned int count) {                 
	if (ar == nullptr) {
		cout << "Array is empty...\n";
		return;
	}
	cout << "PrintArray START!\n";
	for (int i = 0; i < count; i++)
	{
		cout << ar[i] << ", ";
	}
	cout << "\nPrintArray DONE!\n";
}

void addElement(int** array, int* size, int element) {          
	int* newArray = new int[*size + 1];
	for (int i = 0; i < *size; i++) {
		newArray[i] = (*array)[i];
	}
	newArray[*size] = element;
	delete[] * array;
	*array = newArray;
	(*size)++;
}



void removeElement(int** array, int* size) {                   
	if (*size == 0) {
		return;
	}
	int* newArray = new int[*size - 1];
	for (int i = 0; i < *size - 1; i++) {
		newArray[i] = (*array)[i];
	}
	delete[] * array;
	*array = newArray;
	(*size)--;
}


int main()
{
	int x = 10;
	int* p = &x;

	int** p2 = &p;




	int size;
	cout << "Please, enter count of elements: ";
	cin >> size;
	int* ar = nullptr;
	AllocateMemory(&ar, size);
	RandomFillArray(ar, size);
	PrintArray(ar, size);
	int element;
	cout << "input element: ";
	cin >> element;

	addElement(&ar, &size, element);
	PrintArray(ar, size);
	removeElement(&ar, &size);
	PrintArray(ar, size);
}
