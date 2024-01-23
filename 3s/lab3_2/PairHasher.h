#pragma once  
#include "IHasher.h"
#include <functional>
#include <utility>
template <typename Tkey>
class PairHasher : public IHasher<std::pair<Tkey, Tkey>> {
public:
    int Hash(const std::pair<Tkey, Tkey>& key) const {
        return (std::hash<Tkey>{}(key.first) + std::hash<Tkey>{}(key.second));
    }

};