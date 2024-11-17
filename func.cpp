#include <iostream>

using namespace std;


void createArray(){
    int n;
    cout << "Digite o tamanho do array: ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cout << "Digite o valor da posicao " << i << ": ";
        cin >> arr[i];
    }
}

void menu(){
    int opcao;
    do {
        cout << "Menu:" << endl;
        cout << "1. Inserir array" << endl;
        cout << "2. Opcao 2" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                createArray();
                break;
            case 2:
                cout << "Voce escolheu a Opcao 2" << endl;
                break;
            case 3:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while(opcao != 3);
}
