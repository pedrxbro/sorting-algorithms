#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// Variáveis globais
int* arr = nullptr;
int n = 0;

void createArray(){
    cout << "Digite o tamanho do array: ";
    cin >> n;

    arr = new int[n];
    for(int i = 0; i < n; i++){
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
void insertionSort(){
    if (arr == nullptr) {
        cout << "Array nao foi criado. Por favor, crie o array primeiro." << endl;
        return;
    }

    cout << "Array desordenado: ";
    printArray();

    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    cout << "Array ordenado: ";
    printArray();
}
void shellSort(){
    if (arr == nullptr) {
        cout << "Array nao foi criado. Por favor, crie o array primeiro." << endl;
        return;
    }
    cout << "Array desordenado: ";
    printArray();
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

    cout << "Array ordenado: ";
    printArray();
}
void bubbleSort(){
    if (arr == nullptr) {
        cout << "Array nao foi criado. Por favor, crie o array primeiro." << endl;
        return;
    }
    cout << "Array desordenado: ";
    printArray();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Array ordenado: ";
    printArray();
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
    cout << "Array desordenado: ";
    printArray();

    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
    cout << "Array ordenado: ";
    printArray();
    
}  
void selectionSort(){
    if (arr == nullptr) {
        cout << "Array nao foi criado. Por favor, crie o array primeiro." << endl;
        return;
    }
    cout << "Array desordenado: ";
    printArray();

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(&arr[minIdx], &arr[i]);
    }

    cout << "Array ordenado: ";
    printArray();
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
    if (arr == nullptr) {
        cout << "Array nao foi criado. Por favor, crie o array primeiro." << endl;
        return;
    }
    cout << "Array desordenado: ";
    printArray();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(i, 0);
    }
    cout << "Array ordenado: ";
    printArray();
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
    if (arr == nullptr) {
        cout << "Array nao foi criado. Por favor, crie o array primeiro." << endl;
        return;
    }
    cout << "Array desordenado: ";
    printArray();

    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
    cout << "Array ordenado: ";
    printArray();
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
            cout << "Iniciando Insercao Direta..." << endl;
            insertionSort();
            break;
        case 2:
            cout << "Iniciando Shell Sort..." << endl;
            shellSort();
            break;
        case 3:
            cout << "Iniciando Bubble Sort..." << endl;
            bubbleSort();
            break;
        case 4:
            cout << "Iniciando Quick Sort..." << endl;
            quickSort(0, n - 1);
            break;
        case 5:
            cout << "Iniciando Selecao Direta..." << endl;
            selectionSort();
            break;
        case 6:
            cout << "Iniciando Heap Sort..." << endl;
            heapSort();
            break;
        case 7:
            cout << "Iniciando Merge Sort..." << endl;
            mergeSort(0, n - 1);
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
    }
}
void menu() {
    int arraysCount;
    cout << "Quantos arrays deseja criar? ";
    cin >> arraysCount;

    int algorithmOption = menuAlgorithm();
    double totalTime = 0.0;

    for (int i = 0; i < arraysCount; i++) {
        cout << "Criando o array " << i + 1 << "..." << endl;
        createArray();

        cout << "Executando ordenacao..." << endl;
        auto start = high_resolution_clock::now();

        executeSort(algorithmOption);

        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;
        totalTime += elapsed.count();

        delete[] arr;
        arr = nullptr;
    }

    cout << "Media de tempo de execucao: " << totalTime / arraysCount << " segundos." << endl;
    menu();
}
