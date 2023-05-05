#pragma once
#include "Array.h" 
#include <variant>
template <typename... T> class Tuple {
private:
    DynamicArray<std::variant<T...>> tuple;

public:
    Tuple() {};
    Tuple(const T... args) {
        tuple.Resize(sizeof...(T));
        int index = 0;
        ((tuple[index++] = args), ...);
    }

    // auto& Get(int index) {
    //     return tuple.Get(index);
    // }


    
    template<int T0>
    auto Get() {
        return std::get<T0>(tuple[T0]);
    }

};