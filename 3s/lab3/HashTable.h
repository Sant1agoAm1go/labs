#pragma once 
#include "IHasher.h"
#include "STLHasher.h"
#include "IDictionary.h"
#include "Pair.h"
#include "ArraySequence.h"
#include "Array.h"
template <typename Tkey, typename Tvalue>
class HashTable : public IDictionary<Tkey, Tvalue> {
    private:
        DynamicArray<ArraySequence<Pair<Tkey, Tvalue>>>* associativeArray;
        IHasher<Tkey>* hasher;
        int count;
    public:
        HashTable() {
            count = 0;
            this->associativeArray = new DynamicArray<ArraySequence<Pair<Tkey, Tvalue>>>(1);
            //this->associativeArray->Resize(1);
            hasher = new STLHasher<Tkey>();
        }

        HashTable(int capacity) {
            count = 0;
            this->associativeArray = new DynamicArray<ArraySequence<Pair<Tkey, Tvalue>>>(capacity);
            //this->associativeArray->Resize(capacity);
            this->hasher = new STLHasher<Tkey>();
        }

        HashTable(const HashTable<Tkey, Tvalue>& other) {
            this->associativeArray = other.associativeArray;
            this->hasher = other.hasher;
            this->count = other.count;
        }

        HashTable(HashTable<Tkey, Tvalue>&& other) {
            this->associativeArray = std::exchange(other.associativeArray, nullptr);
            this->hasher = std::exchange(other.hasher, nullptr);
            this->count = std::exchange(other.count, 0);
        }

        ~HashTable() {
            delete associativeArray;
            delete hasher;
        }

        HashTable<Tkey, Tvalue>& operator=(const HashTable<Tkey, Tvalue>& other) {
            delete this->associativeArray;
            this->associativeArray = other.associativeArray;
            delete this->hasher;
            this->hasher = other.hasher;
            this->count = other.count;
        }

        HashTable<Tkey, Tvalue>& operator=(HashTable<Tkey, Tvalue>&& other) {
            delete this->associativeArray;
            this->associativeArray = std::exchange(other.associativeArray, nullptr);
            delete this->hasher;
            this->hasher = std::exchange(other.hasher, nullptr);
            this->count = std::exchange(other.count, 0);
        }

        int GetCount() const {
            return count;
        }

        int GetCapacity() const {
            return associativeArray->GetSize();
        }
        
        Tvalue& Get(const Tkey& key) const {
            ArraySequence<Pair<Tkey, Tvalue>>& CollisionList = (*associativeArray)[Hash(key)];
            for(int i = 0; i < CollisionList.GetLength(); i++) {
                Pair<Tkey,Tvalue>& record = CollisionList.Get(i);
                if(record.Get1() == key) {
                    return record.item2;
                }
            }
            throw std::out_of_range("Value was not found");
        }

        bool ContainsKey(const Tkey& key) const {
            ArraySequence<Pair<Tkey, Tvalue>>& CollisionList = (*associativeArray)[Hash(key)];
            for(int i = 0; i < CollisionList.GetLength(); i++) {
                Pair<Tkey,Tvalue>& record = CollisionList.Get(i);
                if(record.Get1() == key) {
                    return true;
                }
            }
            return false;
        }


        int Hash(const Tkey& key) const {
            return hasher->Hash(key) % this->GetCapacity();
        }

        bool NeedToReconstruct() const {
            return count > 0.8*this->GetCapacity();
        }

    IDictionary<Tkey, Tvalue>* Add(Pair<Tkey, Tvalue> record) {
        if (associativeArray->GetSize() == 0) {
            associativeArray->Resize(1);
        }
        if (ContainsKey(record.Get1())) {
            throw std::invalid_argument("Key already is in table");
        }
        if (NeedToReconstruct()) {
            DynamicArray<ArraySequence<Pair<Tkey, Tvalue>>>* newTable = new DynamicArray<ArraySequence<Pair<Tkey, Tvalue>>>(associativeArray->GetSize() * 2);
            //newTable->Resize(associativeArray->GetSize() * 2);
            for (int i = 0; i < associativeArray->GetSize(); i++) {
                ArraySequence<Pair<Tkey, Tvalue>>& CollisionList = associativeArray->Get(i);
                if(CollisionList.GetLength()!=0 && CollisionList != ArraySequence<Pair<Tkey, Tvalue>>()) {
                    for (int i = 0; i < CollisionList.GetLength(); i++) {
                        Pair<Tkey, Tvalue>& listRecord = CollisionList.Get(i);
                        ((*newTable)[hasher->Hash(listRecord.Get1()) % newTable->GetSize()]).Append(listRecord);
                    }
                }
                else {
                    continue;
                }
            } 
            delete this->associativeArray;
            this->associativeArray = newTable;
        }
        ((*associativeArray)[Hash(record.Get1())]).Append(record);
        this->count++;
        return this;
    }

    void Remove(const Tkey& key) {
        if (ContainsKey(key) == false) 
            throw std::out_of_range("Key was not found");
        ArraySequence<Pair<Tkey, Tvalue>>& CollisionList = (*associativeArray)[Hash(key)];
        for (int i = 0; i < CollisionList.GetLength(); i++) {
            if ((CollisionList[i]).Get1() == key) {
                CollisionList.Remove(i);
                break;
            }
        }
        this->count--;
    }
};