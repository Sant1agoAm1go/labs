#include "Laba3.h"

int TestDictionary()
{
	int flag = 1;
	int size = 10;
	vector<string> str;
	readStringFile(size, "testDict.txt", str);
	
	IDictionary<int, string>* dict = new IDictionary<int, string>{};
	for (int i = 0; i < str.size(); i++)
	{
		dict->Add(i, str[i]);
	}

	//Get
	for (int i = 0; i < str.size(); i++)
	{
		if (dict->Get(i) != str[i]) flag = 0;
	}
	//GetCount
	if (dict->GetCount() != str.size()) flag = 0;
	
	//Remove and ContainsKey
	dict->Remove(1);
	dict->Remove(10);
	dict->Remove(25);
	if (dict->ContainsKey(1) == 1 || dict->ContainsKey(10) == 1 || dict->ContainsKey(25) == 1) flag = 0;

	delete dict;
	return flag;
}

int TestSparceVector()
{
	int flag = 1;
	int size = 100000;
	int* arr = new int[size];

	GenerateSparseVector(size, arr);
	IDictionary<string, int>* dictSparceVector = new IDictionary<string, int>;
	CreateDictSparseVector(arr, size, dictSparceVector);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != 0)
		{
			if (dictSparceVector->Get(to_string(i)) != arr[i]) flag = 0;
		}
		
	}
	delete dictSparceVector;
	delete[] arr;
	return flag;
}

int TestHistagrams()
{
	int flag = 1;
	Sequence<Person>* seq = new ArraySequence<Person>{};
	Person p1{ "Stanislav", "Vasilyev",  18,  18000 };
	Person p2{ "Yaroslav", "Petrov",  37,  74398 };
	Person p3{ "Pavel", "Novikov",  54,  36551 };
	Person p4{ "Victor", "Fedorov",  76,  24176 };
	Person p5{ "Peter", "Ivanov",  24,  52518 };
	Person p6{ "Alexey", "Mikhailov",  64,  15000 };
	seq->Append(p1);
	seq->Append(p2);
	seq->Append(p3);
	seq->Append(p4);
	seq->Append(p5);
	seq->Append(p6);
	//seq->print();

	IDictionary<string, int>* dictAge = new IDictionary<string, int>;
	int rangeStart = 0;
	int rangeEnd = 100;
	int subsetSize = 25;
	CreateHistogram(seq, dictAge, rangeStart, rangeEnd, subsetSize, "age");
	if (dictAge->Get("0-25") != 2) flag = 0;
	if (dictAge->Get("25-50") != 1) flag = 0;
	if (dictAge->Get("50-75") != 2) flag = 0;
	if (dictAge->Get("75-100") != 1) flag = 0;

	IDictionary<string, int>* dictSalary = new IDictionary<string, int>;
	rangeStart = 0;
	rangeEnd = 75000;
	subsetSize = 18750;
	CreateHistogram(seq, dictSalary, rangeStart, rangeEnd, subsetSize, "salary");
	if (dictSalary->Get("0-18750") != 2) flag = 0;
	if (dictSalary->Get("18750-37500") != 2) flag = 0;
	if (dictSalary->Get("37500-56250") != 1) flag = 0;
	if (dictSalary->Get("56250-75000") != 1) flag = 0;

	delete dictAge;
	delete dictSalary;
	return flag;
}

int TestBook()
{
	int flag = 1;
	IDictionary<string, vector<int>>* dict = new IDictionary<string, vector<int>>;
	unordered_map<string, vector<int>> wordOccurrences;
	int page = 10;
	vector<string> pages;
	readBookFile(page, "testBook.txt", wordOccurrences, pages, dict);
	//CreateDictAlphabet(wordOccurrences, dict);
	//dict->Print();
	if (dict->Get("gorilla")[0] != 1 && dict->Get("gorilla")[1] != 2 && dict->Get("gorilla")[2] != 3 && dict->Get("gorilla")[3] != 5 && dict->Get("gorilla")[4] != 3 && dict->Get("gorilla")[5] != 6) flag = 0;
	if (dict->Get("apple")[0] != 1 && dict->Get("apple")[1] != 6 && dict->Get("apple")[2] != 9 && dict->Get("apple")[3] != 7) flag = 0;
	if (dict->Get("jungle")[0] != 5 && dict->Get("jungle")[1] != 7 ) flag = 0;

	delete dict;
	return flag;
}