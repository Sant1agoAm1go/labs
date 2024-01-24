#include "Laba3.h"

int menu(){
    int type = 1;
    cout << "\033[33mSelect type (1 - sparce vector || CTRL+D - exit): \033[0m";
    while (cin >> type){
        if (cin.eof()) exit(0);
        int size = 1000000;
        int print = 1;
        int* arr = new int[size];
        if (type != 1) return 1;
        switch (type){
        case 1:
            cout << "\033[33mInput size: \033[0m";
            cin >> size;
            for(int i = 0; i < size; ++i){
                arr[i] = rand() % 10;
                arr[i+1] = 0;
                ++i;
            }
            GenerateSparseVector(size, arr);
            IDictionary<int, int>* dictSparceVector = new IDictionary<int, int>;
            CreateDictSparseVector(arr, size, dictSparceVector);
            cout << "\033[32mThe sparce vector: \033[0m" << endl;
            dictSparceVector->PrintInOrder();
            cout << "\033[33mOutput the initial vector(0 - no, 1 - yes): \033[0m"; cin >> print;
            if (print == 1)
            {
                cout << "\033[32mThe initial vector: \033[0m" << endl;
                for (int i = 0; i < size; i++)
                {
                    cout << "[" << i << "]" << " " << arr[i] << "  ";
                }
                cout << endl;
            }
            delete[] arr;
            break;
        }
        cout << "\033[33mSelect type (1 - sparce vector || CTRL+D - exit): \033[0m";
    }
    
    return 1;
}