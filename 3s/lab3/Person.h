#pragma once
#include <iostream>
#include <string.h>
template<typename ID>
class Person {
    private:
        int years;
        ID id;
        string name;
    public: 
        Person() {
            years = int();
            id = ID();
            name = string();
        }
        Person(int years2, ID id2, string name2) {
            years = years2;
            id = id2;
            name = name2;
        }
        int GetYear() {
            return years;
        }
        ID GetID() {
            return id;
        }
        string GetName() {
            return name;
        }
        bool operator <=(int& other) {
            if(years <= other) {
                return 1;
            }
            else {
                return 0;
            }
        }
        bool operator >=(int& other) {
            if(years >= other) {
                return 1;
            }
            else {
                return 0;
            }
        }
};