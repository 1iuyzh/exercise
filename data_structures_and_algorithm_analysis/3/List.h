#ifndef LIST_H
#define LIST_H

#include<iostream>
using namespace std;

template <typename Object>
class List {

private:
    struct Node;

public:
    class const_iterator;
    class iterator;

public:
    List();
    List(const List &rhs);
    List(List &&rhs);
    List& operator=(const List &rhs);
    List& operator=(List &&rhs);
    ~List();

    iterator begin() {
        return {head->next};    //列表表达式
    }
    const_iterator begin() const {
        return {head->next};
    }
    iterator end() {
        return {tail};
    }
    const_iterator end() const {
        return {tail};
    }

    int size() const {
        return theSize;
    }
    bool empty() const {
        return size() == 0;
    }
    void clear() {
        while (!empty())
            pop_front();
    }

    Object& front() {
        return *begin();
    }
    const Object& front() const {
        return *begin();
    }
    Object& back() {
        return *--end();
    }
    const Object& back() const {
        return *--end();
    }

    void push_front(const Object &x) {
        insert(begin(), x);
    }
    void push_front(Object &&x) {
        insert(begin(), std::move(x));
    }
    void push_back(const Object &x) {
        insert(end(), x);
    }
    void push_back(Object &&x) {
        insert(end(), std::move(x));
    }
    void pop_front() {
        erase(begin());
    }
    void pop_back() {
        erase(--end());
    }

    iterator insert(iterator itr, const Object &x);
    iterator insert(iterator itr, Object &&x);
    iterator erase(iterator itr);
    iterator erase(iterator from, iterator to);

private:
    int theSize;
    Node* head;
    Node* tail;
    void init();
};

template <typename Object>
//List or List<Object>
struct List<Object>::Node {
    Object data;
    Node *prev;
    Node *next;

    Node(const Object &d = Object(), Node *p = nullptr, Node *n = nullptr)
        : data(d), prev(p), next(n) {}
};

template <typename Object>
class List<Object>::const_iterator {
public:
    const_iterator() : current(nullptr) {}
    const Object& operator*() const {
        return current->data;
    }
    const_iterator& operator++() {
        current = current->next;
        return *this;
    }
    const_iterator operator++(int) {
        const_iterator old = *this;
        ++(*this);
        return old; //返回右值?
    }
    const_iterator& operator--() {
        current = current->prev;
        return *this;
    }
    const_iterator operator--(int) {
        const_iterator old = *this;
        --(*this);
        return old;
    }
    bool operator==(const const_iterator &rhs) const {
        return current == rhs.current;
    }
    bool operator!=(const const_iterator &rhs) const {
        return !(*this == rhs);
    }

protected:
    Node *current;
    Object& retrieve() const {
        return current->data;
    }
    const_iterator(Node *p) : current(p) {}
    friend class List<Object>;
};

template <typename Object>
class List<Object>::iterator : public const_iterator {
public:
    iterator() {}
    Object& operator*() {
        return const_iterator::retrieve();
    }
    const Object& operator*() const {
        return const_iterator::operator*();
    }

    iterator& operator++() {
        this->current = this->current->next;
        return *this;
    }
    iterator operator++(int) {
        iterator old = *this;
        ++(*this);
        return old;
    }
    iterator& operator--() {
        this->current = this->current->prev;
        return *this;
    }
    iterator operator--(int) {
        iterator old = *this;
        ++(*this);
        return old;
    }

protected:
    iterator(Node *p) : const_iterator(p) {}
    friend class List<Object>;
};

template <typename Object>
List<Object>::List() {
    init();
}

template <typename Object>
List<Object>::~List() {
    clear();
    delete head;
    delete tail;
}

template <typename Object>
List<Object>::List(const List &rhs) {
    init();
    for (auto &x : rhs)
        push_back(x);
}

template <typename Object>
List<Object>::List(List &&rhs) : theSize(rhs.theSize), head(rhs.head), tail(rhs.tail) {
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

template <typename Object>
List<Object>& List<Object>::operator=(const List &rhs) {
    List copy = rhs;
    std::swap(*this, copy);
    return *this;
}

template <typename Object>
List<Object>& List<Object>::operator=(List &&rhs) {
    std::swap(theSize, rhs.theSize);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
    return *this;
}

template <typename Object>
void List<Object>::init() {
    theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

template <typename Object>
typename List<Object>::iterator List<Object>::insert(iterator itr, const Object &x) {
    Node *p = itr.current;
    theSize++;
    p->prev = p->prev->next = new Node(x, p->prev, p);
    return {p->prev};
}

template <typename Object>
typename List<Object>::iterator List<Object>::insert(iterator itr, Object &&x) {
    Node *p = itr.current;
    theSize++;
    return {p->prev = p->prev->next = new Node(std::move(x), p->prev, p)};
}

template <typename Object>
typename List<Object>::iterator List<Object>::erase(iterator itr) {
    Node *p = itr.current;
    iterator retVal(p->next);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    theSize--;
    return retVal;
}

template <typename Object>
typename List<Object>::iterator List<Object>::erase(iterator from, iterator to) {
    for (iterator itr = from; itr != to;)
        itr = erase(itr);
    return to;
}

#endif
