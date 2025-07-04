#include <iostream>
#include "ShellSort.h"
int cmp_int(const int& a, const int& b) {
	return a - b;  	
}

int cmp_int_rev(const int& a, const int& b) {
	return (a - b)*(-1);  	
}

int cmp_double(const double& a, const double& b) {
	return (a - b >= 0) ? 1 : -1;
}

int cmp_double_rev(const double& a, const double& b) {
    return (a - b >= 0) ? -1 : 1;
}
int main() {
    srand(time(nullptr));
    int len, count;
    double avg = 0;
    std::cin >> len >> count;
    std::cin.clear();
    MsPtr<int> data = MsPtr<int>(new int[len], len);
    for(int i = 0; i < len; i++) {
        data[i] = rand() % 100;
    }
    UnqPtr<ISorter<int>> sorter (new ShellSorter<int>);
    UnqPtr<Sequence<int>> seq = new ArraySequence<int>(*(data.Get()));
    //std::cout << "Before sort: " << seq.Get() << std::endl;
    clock_t start = clock();
    UnqPtr<Sequence<int>> result = sorter->Sort(seq.Get(), cmp_int_rev);
    double time = (double) (clock() - start) / CLOCKS_PER_SEC;
    std::cout << "time of sort: " << time << std::endl;
    //std::cout << "After sort: " << result.Get() << std::endl;
    std::cout << "Everything is fine" << std::endl;
    return 0;
}