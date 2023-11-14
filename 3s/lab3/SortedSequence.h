#include "Sequence.h"
#include "ArraySequence.h"
#include "ISorter.h"
#include <utility>
template <typename T>
class SortedSequence {
    private:
        Sequence<T>* sequence;
        ISorter<T>* sorter;
        int (*comparator)(const T&, const T&);

    public:
        SortedSequence(Sequence<T>* sequence, ISorter<T>* sorter, int (*comparator)(const T&, const T&)) {
            this->sequence = sorter->Sort(sequence, comparator);
            this->sorter = sorter;
            this->comparator = comparator;

        }

        SortedSequence(const SortedSequence<T>& other) {
            this->sequence = other.sequence;
            this->sorter = other.sorter;
            this->comparator = other.comparator;
        }

        SortedSequence(SortedSequence<T>&& other) {
            this->sequence = std::exchange(other.sequence, nullptr);
            this->sorter = std::exchange(other.sorter, nullptr);
            this->comparator = std::exchange(other.comparator, nullptr);
        }

        SortedSequence<T>& operator=(const SortedSequence<T>& other) {
            this->sequence = other.sequence;
            this->sorter = other.sorter;
            this->comparator = other.comparator;
        }

        SortedSequence<T>& operator=(SortedSequence<T>&& other) {
            this->sequence = std::exchange(other.sequence, nullptr);
            this->sorter = std::exchange(other.sorter, nullptr);
            this->comparator = std::exchange(other.comparator, nullptr);
        }

        int GetLength() const {
            return sequence->GetLength();
        }

        bool IsEmpty() {
            return sequence->GetLength() < 0;
        }

        T& Get(int index) const {
            return sequence->Get(index);
        }

        T& GetFirst() const {
            return sequence->GetFirst();
        }

        T& GetLast() const {
            return sequence->GetLast();
        }

        int IndexOf(T element) {
            for(int i = 0; i < this->GetLength(); i++) {
                if(element == this->Get(i)) {
                    return i;
                }
            }
            return -1;
        }

        SortedSequence<T> GetSubSequence(int startIndex, int endIndex) {
            SortedSequence<T> result = SortedSequence<T>(sequence->GetSubsequence(startIndex, endIndex), sorter, comparator);
            return result;
        }

        void Add(T element) {
            if(IsEmpty()) {
                sequence->Append(element);
                return;

            }
            if(comparator(element, sequence->GetFirst()) <= 0) {
                sequence->Prepend(element);
                return;
            }

            if(comparator(element, sequence->GetLast()) >= 0) {
                sequence->Append(element);
                return;
            }

            for(int i = 0; i < sequence->GetLength(); i++) {
                if(comparator(element, sequence->Get(i)) <= 0) {
                    sequence->InsertAt(element, i);
                    break;
                }
            }
        }

        friend std::ostream& operator << (std::ostream& stream, const SortedSequence<T>& seq) {
    	    stream << "{";
    	    for(int i = 0; i < seq.GetLength() - 1; i++) {
            stream << seq.Get(i) << ", ";
    	    }
		    stream << seq.GetLast() << "}" << std::endl;
		    return stream;
	    }

        ~SortedSequence() {
            delete sequence;
            delete sorter;
        }
};