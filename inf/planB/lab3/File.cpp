#include "Laba3.h"


void writeStringFile(int numStrings, const string& fileName)
{
    std::ofstream file(fileName); 

    if (!file.is_open()) { 
        cout << "Error opening file" << endl;
        return;
    }

    string alphabet = "abcdefghijklmnopqrstuvwxyz"; 

    srand((unsigned int)time(nullptr));

    for (int i = 0; i < numStrings; i++) {
        int length = rand() % 10 + 1; 
        string str;

        for (int j = 0; j < length; j++) {
            int index = rand() % alphabet.length(); 
            str += alphabet[index]; 
        }

        file << str << endl; 
    }

    file.close(); 
}

void writeWordsFile(int numStrings, const string& fileName)
{

    vector<string> availableWords = {
        "apple", "banana", "cat", "dog", "elephant", "fish",
        "gorilla", "house", "ball", "jungle", "kangaroo",
        "lion", "monkey", "bird", "ocean", "penguin", "queen",
        "rabbit", "snake", "tiger", "umbrella", "goose", "whale",
        "foot", "yacht", "zebra"
    };

    std::ofstream file(fileName);

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    for (int i = 0; i < numStrings; i++) {
        string str;
        str += availableWords[rand() % availableWords.size()];
        file << str << endl;
    }
    file.close();
}


void readStringFile(int numStrings, const string& fileName, vector<string>& arr)
{
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    string line;
    int i = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            arr.push_back(word);
        }
    }
    file.close();
}


