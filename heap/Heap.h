//
// Created by Paolo Octoman on 3/21/23.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H
#include <iostream>
#include <vector>

template <typename T>
class Heap {
private:
    std::vector<T> heap;
public:
    const std::vector<T> &getHeap() const;

public:
    Heap();

    int getParent(int childIndex);
    int getLeftChild(int parentIndex);
    int getRightChild(int parentIndex);
    int getMaxChild(int parentIndex);
            //if neither child is bigger, return parent

    void reheapingUp(int childIndex);
    void reheapingDown(int parentIndex);

    void swapHeap(int childIndex, int parentIndex);
    void operator+=(const T& data);
    void push(const T& item);
    void pop() ;
     T& top() ;
    int size();
    bool empty() ;


};




#include "Heap.cpp"

#endif //HEAP_HEAP_H
