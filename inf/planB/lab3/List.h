#include "Laba3.h"

template <class T> class LinkedList
{
    struct Node {
        T data;
        Node* next;
        //~Node() {
        //    if constexpr (std::is_pointer<T>::value) {
       //         delete data;
       //     }
       // }
    };

private:
    Node* head;

public:

    LinkedList(T* items, int count)
    {
        this->head = NULL;

        Node* p = this->head;
        for (int i = 0; i < count; i++)
        {
            if (p == NULL) { p = new Node; this->head = p; }
            else { p->next = new Node; p = p->next; }
            p->data = items[i];
            p->next = NULL;
        }
        return;
    }

    LinkedList()
    {
        this->head = NULL;
        return;
    }

    LinkedList(const LinkedList <T>& list) //const?
    {
        this->head = NULL;

        Node* p = list.head;
        Node* p2 = NULL;
        while (p != NULL)
        {
            if (this->head == NULL) { p2 = new Node; this->head = p2; }
            else { p2->next = new Node; p2 = p2->next; }
            p2->data = p->data;
            p2->next = NULL;
            p = p->next;
        }

        return;
    }

    ~LinkedList()
    {
        //cout << "HERE LinkedList " << this->GetLength() << endl;
        Node* p = this->head;
        Node* p2 = NULL;
        while (p != NULL)
        {
            p2 = p->next;
            delete p;
            p = p2;
        }
        return;
    }

    void print() const
    {
        int count = 0;
        Node* p = this->head;
        while (p != NULL)
        {
            cout << " {" << count << "}=" << p->data;
            count++;
            p = p->next;
        }
        cout << "count=" << count;
        cout << endl;
        return;
    }

    T& GetFirst()
    {
        if (this->head == NULL) throw (string)"empty list";
        if (this->GetLength() == 0) throw (string)"empty list";
        return this->head->data;
    }

    T& GetLast()
    {
        if (this->head == NULL) throw (string)"empty list";
        if (this->GetLength() == 0) throw (string)"empty list";
        Node* p = this->head;
        Node* lp = NULL;
        while (p != NULL)
        {
            lp = p;
            p = p->next;
        }
        return lp->data;
    }

    int GetLength()
    {
        int count = 0;
        Node* p = this->head;
        while (p != NULL)
        {
            count++;
            p = p->next;
        }
        return count;
    }

    T& Get(int index)
    {
        if (index < 0) throw index;
        if (index >= this->GetLength()) throw index;
        if (this->GetLength() == 0) throw (string)"empty list";
        Node* p = this->head;

        int i = 0;
        while (i < index)
        {
            p = p->next;
            i++;
        }
        return p->data;
    }

    void DelItem(int index)
    {

        if (index < 0) throw index;
        if (index >= this->GetLength()) throw index;
        Node* p = this->head;
        Node* pp = NULL;
        int count = 0;
        while (p != NULL)
        {
            if (count == index)
            {
                if (pp == NULL)
                {
                    this->head = p->next;
                    delete p; // free?
                    p = this->head;
                }
                else
                {
                    pp->next = p->next;
                    delete p;
                    p = pp->next;
                }
            }
            else
            {
                pp = p;
                p = p->next;
            }
            count++;
        }

        return;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex)
    {

        if (startIndex < 0) throw startIndex;
        if (endIndex < 0) throw endIndex;
        if (startIndex >= this->GetLength()) throw startIndex;
        if (endIndex >= this->GetLength()) throw endIndex;
        if (startIndex > endIndex) throw (string)"startIndex > endIndex";
        LinkedList <T>* newList = new LinkedList <T>{};
        Node* p = this->head;
        Node* p2 = NULL;

        int i = 0;
        while (i <= endIndex)
        {
            if (i >= startIndex)
            {
                if (newList->head == NULL) { p2 = new Node; newList->head = p2; }
                else { p2->next = new Node; p2 = p2->next; }
                p2->data = p->data;
                p2->next = NULL;
            }
            p = p->next;
            i++;
        }
        
        return  newList;
    }

    void Append(T item)
    {
        Node* np = new Node;
        np->data = item;
        np->next = NULL;

        Node* p = this->head;
        Node* lp = NULL;
        while (p != NULL)
        {
            lp = p;
            p = p->next;
        }
        if (lp == NULL) this->head = np; else lp->next = np;
        return;
    }

    void Prepend(T& item)
    {
        Node* pp = new Node;
        pp->data = item;
        pp->next = this->head;
        this->head = pp;
        return;
    }

    void Set(int index, T& item)
    {
        if (index < 0) throw index;
        if (index >= this->GetLength()) throw index;
        Node* p = this->head;
        int i = 0;
        while (i <= index)
        {
            if (i == index)
            {
                p->data = item;
                break;
            }
            p = p->next;
            i++;
        }
    }

    void InsertAt(T& item, int index)
    {
        if (index < 0) throw index;
        if (index >= this->GetLength()) throw index;
        Node* np = new Node;
        np->data = item;
        np->next = NULL;

        Node* p = this->head;
        Node* pp = NULL;
        int i = 0;
        while (i <= index)
        {
            if (i == index)
            {
                if (pp == NULL)
                {
                    np->next = this->head;
                    this->head = np;
                }
                else
                {
                    pp->next = np;
                    np->next = p;
                }
                break;
            }
            pp = p;
            p = p->next;
            i++;
        }
        return;
    }

    LinkedList<T>* Concat(LinkedList<T>* list)
    {
        Node* p = list->head;
        while (p != NULL)
        {
            this->Append(p->data);
            p = p->next;
        }

        return this;
    }

};

template <class T> class LinkedListSequence : public Sequence<T>
{
private:
    LinkedList<T>* items;

public:
    LinkedListSequence(T* items, int count)
    {
        this->items = new LinkedList<T>{ items, count };
        return;
    }

    LinkedListSequence()
    {
        this->items = new LinkedList<T>{  };
        return;
    }

    LinkedListSequence(const LinkedList <T>& list)
    {
        this->items = new LinkedList<T>{ list };
        return;
    }

    ~LinkedListSequence()
    {
        //printf("HERE_LIST"); 
        if (items != NULL) { delete items; items = NULL; };
        return;
    }

    void print() const override
    {
        this->items->print();
        return;
    }

    T& GetFirst() const override
    {
        return this->items->GetFirst();
    }

    T& GetLast() const override
    {
        return this->items->GetLast();
    }

    T& Get(int index) const override
    {
        return this->items->Get(index);
    }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {

        LinkedList<T>* tmp = this->items->GetSubList(startIndex, endIndex);
        this->items->~LinkedList();
        this->items = tmp;
        return (Sequence<T>*) this;
    }

    int GetLength() const override
    {
        return this->items->GetLength();
    }

    void Append(T& item) override
    {
        this->items->Append(item);
        return;
    }

    void Prepend(T& item) override
    {
        this->items->Prepend(item);
        return;
    }

    void InsertAt(T& item, int index) override
    {
        this->items->InsertAt(item, index);
        return;
    }

    void DelItem(int index) override
    {
        this->items->DelItem(index);
        return;
    }

    Sequence <T>* Concat(Sequence <T>* list) override
    {
        this->items->Concat(((LinkedListSequence <T>*)list)->items);
        return (Sequence<T>*) this;
    }
    Sequence<T>* ShellSort(bool (*cmp)(T, T)) override
    {
        int n = this->items->GetLength();
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                T temp = this->items->Get(i);
                int j;
                for (j = i; j >= gap && cmp(this->items->Get(j - gap), temp); j -= gap) {
                    this->items->Set(j, this->items->Get(j - gap));
                }
                this->items->Set(j, temp);
            }
        }
        return (Sequence<T>*) this;
    }

    /*
    Sequence<T>* ShellSort(bool (*cmp)(T, T)) override
    {
        int length = this->items->GetLength();
        int gap = length / 2;
        while (gap > 0) {
            for (int i = gap; i < length; i++) {
                T temp = this->items->Get(i);
                T j = i;
                while (j >= gap && cmp(this->items->Get(j - gap), temp)) {
                    this->items->Set(j, this->items->Get(j - gap));
                    j -= gap;
                }
                this->items->Set(j, temp);
            }
            gap /= 2;
            
        }
        return (Sequence<T>*)this;
    }
    */
    Sequence<T>* QuickSort(bool (*cmp1)(T, T), bool (*cmp2)(T, T), int left, int right) override
    {
        int i = left, j = right;
        T tmp;
        T pivot = this->items->Get((left + right) / 2);

   
        while (i <= j) {
            while (cmp1(this->items->Get(i), pivot))
                i++;
            while (cmp2(this->items->Get(j), pivot))
                j--;
            if (i <= j) {
                tmp = this->items->Get(i);
                this->items->Set(i, this->items->Get(j));
                this->items->Set(j, tmp);
                i++;
                j--;
            }
        };

        if (left < j)
            QuickSort(cmp1,cmp2,left, j);
        if (i < right)
            QuickSort(cmp1,cmp2, i, right);
        return (Sequence<T>*)this;
    }
    
    Sequence<T>* SelectionSort(bool (*cmp)(T, T)) override
    {
        int i, j, min_idx;
        int n = this->items->GetLength();
        for (i = 0; i < n - 1; i++) {
            min_idx = i;
            for (j = i + 1; j < n; j++) {
                if (cmp(this->items->Get(j), this->items->Get(min_idx)))
                    min_idx = j;
            }
                
            T tmp = this->items->Get(min_idx);
            this->items->Set(min_idx, this->items->Get(i));
            this->items->Set(i, tmp);
            //swap(&arr[min_idx], &arr[i]);
        }
        return (Sequence<T>*)this;
    }

    virtual T& operator[] (int index) override
    {
        return this->items->Get(index);
    }
};