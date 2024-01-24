#include "Laba3.h"

void CreateHistogram(Sequence<Person>* seq, IDictionary<string, int>* dict, int rangeStart, int rangeEnd, int subsetSize, string parameter) {

	int numSubsets = (rangeEnd - rangeStart) / subsetSize;

	for (int i = 0; i < numSubsets; i++) {
		int subsetCount = 0;
		for (int j = 0; j < seq->GetLength(); j++) {
			if (parameter == "age")
			{
				if (seq->Get(j).GetAge() >= rangeStart + i * subsetSize && seq->Get(j).GetAge() < rangeStart + (i + 1) * subsetSize) {
					subsetCount++;
				}
			}
			if (parameter == "salary")
			{
				if (seq->Get(j).GetSalary() >= rangeStart + i * subsetSize && seq->Get(j).GetSalary() < rangeStart + (i + 1) * subsetSize) {
					subsetCount++;
				}
			}
		}

		string range = std::to_string(rangeStart + i * subsetSize) + "-" + std::to_string(rangeStart + (i + 1) * subsetSize);
		dict->Add(range, subsetCount);
	}

	return;
}

void CreateHistogramPerson(Person& person, IDictionary<string, int>* dict, int rangeStart, int rangeEnd, int subsetSize, string parameter) {

	int numSubsets = (rangeEnd - rangeStart) / subsetSize;

	for (int i = 0; i < numSubsets; i++) {
		int rangeIntStart = rangeStart + i * subsetSize;
		int rangeIntEnd = rangeStart + (i + 1) * subsetSize;
		if (person.GetAge() >= rangeIntStart && person.GetAge() < rangeIntEnd) {
			string range = std::to_string(rangeIntStart) + "-" + std::to_string(rangeIntEnd);
			if (dict->ContainsKey(range) == false) dict->Add(range, 1);
			else
			{
				(*dict)[range]++;
			}
				
		}
		else
		{
			string range = std::to_string(rangeIntStart) + "-" + std::to_string(rangeIntEnd);
			if (dict->ContainsKey(range) == false) dict->Add(range, 0);	
		}
		
	}



	return;
}

void graph(IDictionary<string, int>* dict, int rangeStart, int rangeEnd, int subsetSize)
{
	int numSubsets = (rangeEnd - rangeStart) / subsetSize;
	for (int i = 0; i < numSubsets; i++)
	{
		string range = std::to_string(rangeStart + i * subsetSize) + "-" + std::to_string(rangeStart + (i + 1) * subsetSize);
		cout << range << " ";
		for (int j = 0; j < dict->Get(range) * 0.5; j++)
		{
			cout << "#";
		}
		cout << endl;
	}
}


