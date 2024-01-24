#include "Laba3.h"
template <class T> class DynamicArray;
template <class T> class LinkedList;
template <class T> class Sequence;
template <class T> class ArraySequence;
template <class T> class LinkedListSequence;
class Person;


int GenerateINT();
double GenerateDOUBLE();
//string GenerateUUID();

void GenerateSparseVector(int size, int* sparceVector);

void writeWordsFile(int numStrings, const string& fileName);
void writeStringFile(int numStrings, const string& fileName);
void readStringFile(int numStrings, const string& fileName, vector<string>& arr);
//void readBookFile(int page, const string& fileName, unordered_map<string, vector<int>>& wordOccurrences, vector<string>& pages);
void readBookFile(int page, const string& fileName, unordered_map<string, vector<int>>& wordOccurrences, vector<string>& pages, IDictionary<string, vector<int>>* dict);

void GeneratePeople(Sequence<Person>* seq, int size);

void CreateDictAlphabet(unordered_map<string, vector<int>>& wordOccurrences, IDictionary<string, vector<int>>* dict);
void CreateHistogram(Sequence<Person>* seq, IDictionary<string, int>* dict, int rangeStart, int rangeEnd, int numSubsets, string parameter);

void CreateHistogramPerson(Person& person, IDictionary<string, int>* dict, int rangeStart, int rangeEnd, int subsetSize, string parameter);

void CreateDictSparseVector(int* sparceVector, int size, IDictionary<int, int>* dict);
void graph(IDictionary<string, int>* dict, int rangeStart, int rangeEnd, int subsetSize);
int TestDictionary();
int TestSparceVector();
int TestHistagrams();
int TestBook();

int menu();