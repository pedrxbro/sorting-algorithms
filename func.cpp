#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// Variáveis globais
int* arr = nullptr;
int n = 0;

void createArray() {
    cout << "Digite o tamanho do array: ";
    cin >> n;

    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Digite o valor da posicao " << i << ": ";
        cin >> arr[i];
    }
}

void printArray() {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "]";
    cout << endl;
}

void insertionSort(int* tempArr) {
    for (int i = 1; i < n; i++) {
        int key = tempArr[i];
        int j = i - 1;
        while (j >= 0 && tempArr[j] > key) {
            tempArr[j + 1] = tempArr[j];
            j = j - 1;
        }
        tempArr[j + 1] = key;
    }
}

void shellSort(int* tempArr) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = tempArr[i];
            int j;
            for (j = i; j >= gap && tempArr[j - gap] > temp; j -= gap) {
                tempArr[j] = tempArr[j - gap];
            }
            tempArr[j] = temp;
        }
    }
}

void bubbleSort(int* tempArr) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tempArr[j] > tempArr[j + 1]) {
                int temp = tempArr[j];
                tempArr[j] = tempArr[j + 1];
                tempArr[j + 1] = temp;
            }
        }
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int low, int high, int* tempArr) {
    int pivot = tempArr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (tempArr[j] < pivot) {
            i++;
            swap(&tempArr[i], &tempArr[j]);
        }
    }
    swap(&tempArr[i + 1], &tempArr[high]);
    return (i + 1);
}

void quickSort(int low, int high, int* tempArr) {
    if (low < high) {
        int pi = partition(low, high, tempArr);
        quickSort(low, pi - 1, tempArr);
        quickSort(pi + 1, high, tempArr);
    }
}

void selectionSort(int* tempArr) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (tempArr[j] < tempArr[minIdx]) {
                minIdx = j;
            }
        }
        swap(&tempArr[minIdx], &tempArr[i]);
    }
}

void heapify(int n, int i, int* tempArr) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && tempArr[left] > tempArr[largest])
        largest = left;

    if (right < n && tempArr[right] > tempArr[largest])
        largest = right;

    if (largest != i) {
        swap(&tempArr[i], &tempArr[largest]);
        heapify(n, largest, tempArr);
    }
}

void heapSort(int* tempArr) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i, tempArr);

    for (int i = n - 1; i > 0; i--) {
        swap(&tempArr[0], &tempArr[i]);
        heapify(i, 0, tempArr);
    }
}

void merge(int l, int m, int r, int* tempArr) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = tempArr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = tempArr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            tempArr[k] = L[i];
            i++;
        } else {
            tempArr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        tempArr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        tempArr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int l, int r, int* tempArr) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(l, m, tempArr);
        mergeSort(m + 1, r, tempArr);
        merge(l, m, r, tempArr);
    }
}

void executeSort(int algorithmOption, int* tempArr) {
    switch (algorithmOption) {
        case 1:
            insertionSort(tempArr);
            break;
        case 2:
            shellSort(tempArr);
            break;
        case 3:
            bubbleSort(tempArr);
            break;
        case 4:
            quickSort(0, n - 1, tempArr);
            break;
        case 5:
            selectionSort(tempArr);
            break;
        case 6:
            heapSort(tempArr);
            break;
        case 7:
            mergeSort(0, n - 1, tempArr);
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
    }
}

int menuAlgorithm() {
    int option;
    cout << "Escolha o algoritmo de ordenacao:" << endl;
    cout << "1. Insercao direta" << endl;
    cout << "2. Shell Sort" << endl;
    cout << "3. Bubble Sort" << endl;
    cout << "4. Quick Sort" << endl;
    cout << "5. Selecao Direta" << endl;
    cout << "6. Heap Sort" << endl;
    cout << "7. Merge Sort" << endl;
    cout << "Escolha uma opcao: ";
    cin >> option;
    return option;
}

void menu() {
    createArray();

    int algorithmOption = menuAlgorithm();
    double totalTime = 0.0;
    int reps = 0;

    cout << "Quantas vezes voce quer rodar o algoritimo? ";
    cin >> reps;

    cout << "Array de entrada" << endl;
    printArray();

    // Array temporário para restaurar o estado inicial a cada iteração
    int* tempArray = new int[n];

    for (int i = 0; i < reps; i++) {
        // Copiar o array original para o array temporário
        for (int j = 0; j < n; j++) {
            tempArray[j] = arr[j];
        }

        // Medindo o tempo de execução
        high_resolution_clock::time_point start = high_resolution_clock::now();
        executeSort(algorithmOption, tempArray);
        high_resolution_clock::time_point end = high_resolution_clock::now();

        duration<double> elapsed = end - start;
        totalTime += elapsed.count();
    }

    cout << "Array ordenado" << endl;
    printArray();

    cout << "Tempo total: " << totalTime << " segundos" << endl;
    cout << "Media de tempo de execucao: " << totalTime / reps << " segundos" << endl;

    delete[] tempArray;
}
