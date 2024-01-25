#pragma once
#include "Laba4.h"
template <class T> class LinkedList
{
    struct Node {
        T data;
        Node* next;
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