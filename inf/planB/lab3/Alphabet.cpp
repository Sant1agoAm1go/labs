#include "Laba3.h"

void readBookFile(int page, const string& fileName, unordered_map<string, vector<int>>& wordOccurrences, vector<string>& pages, IDictionary<string, vector<int>>* dict)
{
    int numPage = 1;
    int numString = 0;
    int numWord = 0;
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        numString++;
        string word;
        while (iss >> word) {
            numWord++;
            pages.push_back(word);
            if (numWord == page * numPage) {
                numPage++; numString = 0;
            }

            if (dict->ContainsKey(word) == false)
            {
                dict->Add(word, {numPage, numString});
            }
            else
            {
                (*dict)[word].push_back(numPage);
                (*dict)[word].push_back(numString);
            }
        }
    }
    file.close();
}


void CreateDictAlphabet(unordered_map<string, vector<int>>& wordOccurrences, IDictionary<string, vector<int>>* dict)
{
	for (const auto& pair : wordOccurrences) {
		dict->Add(pair.first, pair.second);
	}
}