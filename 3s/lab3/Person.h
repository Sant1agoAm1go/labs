#pragma once
#include <iostream>
#include <string.h>
template <typename ID>
class Person {
private:
    int years;
    ID id;
    std::string name;

public:
    Person() {
        years = int();
        id = ID();
        name = std::string();
    }

    Person(int years2, ID id2, std::string name2) {
        years = years2;
        id = id2;
        name = name2;
    }

    Person(const Person<ID>& other) {
        years = other.years;
        id = other.id;
        name = other.name;
    }

    Person(Person<ID>&& other) {
        years = std::move(other.years);
        id = std::move(other.id);
        name = std::move(other.name);
    }

    int GetYear() {
        return years;
    }
    ID GetID() {
        return id;
    }

    std::string GetName() {
        return name;
    }
    
    bool operator <(int &other) {
        return years < other;
    }

    bool operator >(int &other) {
        return years > other;
    }

    bool operator<=(int &other) {
        return years <= other;
    }

    bool operator >=(int& other) {
        return years >= other;
    }
};