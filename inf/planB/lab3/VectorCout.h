#include "Laba3.h"

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    int i = 0;
    out << "[ ";
    for (const auto& elem : vec) {
        if (i % 2 == 0)
        {
            out << "|Page: ";
            out << elem << " ";
        }

        if (i % 2 != 0)
        {
            out << "Line: ";
            out << elem << "| ";
        }
        i++;
    }
    out << "]";
    return out;
}