#include <iostream>

using namespace std;

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
void insertionSort(){
    if (arr == nullptr) {
        cout << "Array nao foi criado. Por favor, crie o array primeiro." << endl;
        return;
    }

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
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void shellSort(){
    if (arr == nullptr) {
        cout << "Array nao foi criado. Por favor, crie o array primeiro." << endl;
        return;
    }

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
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubbleSort(){
    if (arr == nullptr) {
        cout << "Array nao foi criado. Por favor, crie o array primeiro." << endl;
        return;
    }

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
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(i, 0);
    }

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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

    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}
void menu(){
    int opcao;
    do {
        cout << "Menu:" << endl;
        cout << "1. Inserir array" << endl;
        cout << "2. Insercao direta" << endl;
        cout << "3. Shell Sort" << endl;
        cout << "4. Bubble Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "6. Selecao Direta" << endl;
        cout << "7. Heap Sort" << endl;
        cout << "8. Merge Sort" << endl;
        cout << "9. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                createArray();
                break;
            case 2:
                insertionSort();
                break;
            case 3:
                shellSort();
                break;
            case 4:
                bubbleSort();
                break;
            case 5:
                break;
            case 6:
                break;
            case 7: 
                break;
            case 8:
                break;
            case 9:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while(opcao != 9);

    delete[] arr;
}
