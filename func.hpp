#ifndef FUNC_HPP
#define FUNC_HPP

void menu();
void createArray();

//Algoritimos de ordenação
void inserctionSort();
void shellSort();
void bubbleSort();

//QuickSort
void quickSort(int low, int high);
int partition(int low, int high);
void swap(int* a, int* b);

//SelectionSort
void selectionSort();

//HeapSort
void heapify(int n, int i);
void heapSort();

//MergeSort
void merge();
void mergeSort();

#endif