#pragma once
template <typename T1, typename T2> class Pair {
private:
    T1 item1;
    T2 item2; 
public:
    Pair(T1 value1,T2 value2) {
        item1 = value1;
        item2 = value2;
    }

    T1 Get1() const {
        return item1;
    }

    T2 Get2() const {
        return item2;
    }

    /*Pair<T1,T2> Get() {
        const Pair<T1,T2> pair[2]  = {item1,item2};
        return pair;

    }*/
};