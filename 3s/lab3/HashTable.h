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
        DynamicArray<ArraySequence<Pair<Tkey, Tvalue>>>* AssociativeArray;
        IHasher<Tkey>* hasher;
        int count;
    public:
        HashTable() {
            count = 0;
            this->AssociativeArray = new DynamicArray<ArraySequence<Pair<Tkey, Tvalue>>>(1);
            hasher = new STLHasher<Tkey>();
        }

        HashTable(int count, int capacity) {
            this->count = count;
            this->AssociativeArray = new DynamicArray<ArraySequence<Pair<Tkey, Tvalue>>>(capacity);
            this->hasher = new STLHasher<Tkey>();
        }

        HashTable(const HashTable<Tkey, Tvalue>& other) {
            this->AssociativeArray = other.AssociativeArray;
            this->hasher = other.hasher;
            this->count = other.count;
        }

        HashTable(HashTable<Tkey, Tvalue>&& other) {
            this->AssociativeArray = std::exchange(other.AssociativeArray, nullptr);
            this->hasher = std::exchange(other.hasher, nullptr);
            this->count = std::exchange(other.count, 0);
        }

        ~HashTable() {
            delete AssociativeArray;
            delete hasher;
        }

        HashTable<Tkey, Tvalue>& operator=(const HashTable<Tkey, Tvalue>& other) {
            delete this->AssociativeArray;
            this->AssociativeArray = other.AssociativeArray;
            delete this->hasher;
            this->hasher = other.hasher;
            this->count = other.count;
        }

        HashTable<Tkey, Tvalue>& operator=(HashTable<Tkey, Tvalue>&& other) {
            delete this->AssociativeArray;
            this->AssociativeArray = std::exchange(other.AssociativeArray, nullptr);
            delete this->hasher;
            this->hasher = std::exchange(other.hasher, nullptr);
            this->count = std::exchange(other.count, 0);
        }

        int GetCount() const {
            return count;
        }

        int GetCapacity() const {
            return AssociativeArray->GetSize();
        }
        
        Tvalue& Get(const Tkey& key) const {
            ArraySequence<Pair<Tkey, Tvalue>>& CollisionList = (*AssociativeArray)[Hash(key)];
            for(int i = 0; i < CollisionList.GetLength(); i++) {
                Pair<Tkey,Tvalue>& record = CollisionList.Get(i);
                if(record.Get1() == key) {
                    return record.Get2();
                }
            }
            throw std::out_of_range("Value was not found");
        }

        bool ContainsKey(const Tkey& key) const {
            ArraySequence<Pair<Tkey, Tvalue>>& CollisionList = (*AssociativeArray)[Hash(key)];
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

    IDict<Tkey, Tvalue>* Add(Pair<Tkey, Tvalue> record) {
        if (AssociativeArray->GetSize() == 0) {
            AssociativeArray->Resize(1);
        }
        if (ContainsKey(record.Get1())) {
            throw std::invalid_argument("Key already is in table");
        }

        if (NeedToReconstruct()) {
            DynamicArray<ArraySequence<Pair<Tkey, Tvalue>>>* newTable;
            newTable->Resize(AssociativeArray->GetSize() * 2);
            for (int i = 0; i < AssociativeArray->GetSize(); i++) {
                ArraySequence<Pair<Tkey, Tvalue>>& CollisionList = (*AssociativeArray)[Hash(record.Get1())];
                for (int i = 0; i < CollisionList.GetLength(); i++) {
                    Pair<Tkey, Tvalue>& ListRecord = CollisionList.Get(i);
                    ((*newTable)[hasher->Hash(ListRecord.Get1()) % newTable->GetSize()]).Append(ListRecord);
                }
            } 
            delete this->AssociativeArray;
            this->AssociativeArray = std::exchange(newTable, nullptr);
        }
        ((*AssociativeArray)[Hash(record.GetLeft())]).Append(record);
        this->count++;
        return this;
    }

    void Remove(const Tkey& key) {
        if (ContainsKey(key) == false) {
            throw std::out_of_range("Key was not found");
        }

        ArraySequence<Pair<Tkey, Tvalue>>& CollisionList = (*AssociativeArray)[Hash(key)];

        for (int i = 0; i < CollisionList.GetLength(); i++) {
            if ((CollisionList[i]).Get1() == key) {
                CollisionList.Remove(i);
                break;
            }
        }
        this->count--;
    }
};