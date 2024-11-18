#include <iostream>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include <random>

using namespace std;
using namespace chrono;

// Variáveis globais
int* arr = nullptr;
int* tempArr = nullptr;
int n = 0;

void createArray(){
    cout << "Digite o tamanho do array: ";
    cin >> n;

    arr = new int[n];
    tempArr = new int[n];

    int option;
    cout << "Escolha a situacao do array:" << endl;
    cout << "1. Melhor caso (ja ordenado)" << endl;
    cout << "2. Pior caso (ordem contraria)" << endl;
    cout << "3. Aleatorio" << endl;
    cout << "Escolha uma opção: ";
    cin >> option;

    switch (option) {
    case 1:
        //Melhor caso
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
        break;
    case 2:
        //Pior caso
        for (int i = 0; i < n; i++) {
            arr[i] = n - i;
        }
        break;
    case 3:
        //Aleatório
        srand(time(0));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000;
        }
        break;
    default:
        cout << "Opção inválida. Criando array aleatório por padrão." << endl;
        srand(time(0));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000;
        }
}
    //Copia o array para tempArr
    for (int i = 0; i < n; i++) {
        tempArr[i] = arr[i];
    }
}
void insertionSort(){
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void shellSort(){
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
void bubbleSort(){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int low, int high) {
    if (arr == nullptr) {
        cout << "Array nao foi criado. Por favor, crie o array primeiro." << endl;
        return;
    }

    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
    
}  
void selectionSort(){
    if (arr == nullptr) {
        cout << "Array nao foi criado. Por favor, crie o array primeiro." << endl;
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(&arr[minIdx], &arr[i]);
    }
}
void heapify(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(n, largest);
    }
}

void heapSort() {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(i, 0);
    }
}
void merge(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
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
void executeSort(int algorithmOption) {
    switch (algorithmOption) {
        case 1:
            insertionSort();
            break;
        case 2:
            shellSort();
            break;
        case 3:
            bubbleSort();
            break;
        case 4:
            quickSort(0, n - 1);
            break;
        case 5:
            selectionSort();
            break;
        case 6:
            heapSort();
            break;
        case 7:
            mergeSort(0, n - 1);
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
    }
}
void menu() {
    bool repeat = true;

    while (repeat) {
        createArray();

        bool sameArray = true;
        while (sameArray) {
            int algorithmOption = menuAlgorithm();
            int reps = 0;
            double totalTime = 0;

            cout << "Quantas vezes deseja executar o algoritmo? ";
            cin >> reps;

            if (reps <= 0) {
                cout << "Número de repetições inválido. Tente novamente." << endl;
                continue;
            }

            for (int i = 0; i < reps; i++) {
                // Reseta o estado do array
                for (int j = 0; j < n; j++) {
                    arr[j] = tempArr[j];
                }

                // Medir o tempo de execução
                auto start = high_resolution_clock::now();

                executeSort(algorithmOption);

                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                totalTime += duration_cast<duration<double>>(end - start).count();
            }

            cout << "Tempo total de execucao: " << totalTime << " segundos" << endl;
            cout << "Tempo medio de execucao: " << totalTime / reps << " segundos" << endl;

            char choice;
            cout << "Deseja usar outro algoritmo de ordenacao com o mesmo array? (s/n): ";
            cin >> choice;

            if (choice != 's' && choice != 'S') {
                sameArray = false;
            }
        }

        char choice;
        cout << "Deseja criar um novo array e testar outro algoritmo de ordenacao? (s/n): ";
        cin >> choice;

        if (choice != 's' && choice != 'S') {
            repeat = false;
        }
    }

    delete[] arr;
    delete[] tempArr;
    cout << "Programa encerrado." << endl;
}