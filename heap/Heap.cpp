//
// Created by Paolo Octoman on 3/21/23.
//
#ifndef HEAP_HEAP_CPP
#define HEAP_HEAP_CPP
#include "Heap.h"

template<typename T>
Heap<T>::Heap() {

}

template<typename T>
void Heap<T>::reheapingUp(int childIndex) {
    int parentIndex = getParent(childIndex);
    if (heap[childIndex] > heap[parentIndex]){
        swapHeap(childIndex, parentIndex);
        reheapingUp(parentIndex);
    }
}

template<typename T>
int Heap<T>::getParent(int childIndex) {
    return ( (childIndex - 1) / 2);
}

template<typename T>
int Heap<T>::getLeftChild(int parentIndex) {
    return (2*parentIndex) + 1;
}

template<typename T>
int Heap<T>::getRightChild(int parentIndex) {
    return (2*parentIndex) + 2;
}

template<typename T>
int Heap<T>::getMaxChild(int parentIndex) {
    int left = getLeftChild(parentIndex);
    int right = getRightChild(parentIndex);

    if (left < size() && right < size()){
        if (heap[left] > heap[right]){
            return left;
        }
        else {
            return right;
        }

    }
    else if (left < size() && right >= size()){

        if (heap[left] > heap[parentIndex]){
            return left;
        }
        else
        return parentIndex;
    }
    else if (left >= size() && right < size()){

        if (heap[right] > heap[parentIndex]){
            return right;
        }
        else
            return parentIndex;
    }
    else if (left >= size() && right >= size()){
            return parentIndex;
    }

}


template<typename T>
void Heap<T>::reheapingDown(int parentIndex) {
    int max = getMaxChild(parentIndex);
    if (heap[max] > heap[parentIndex]){
        swapHeap(max, parentIndex);
        reheapingDown(max);
    }
}

template<typename T>
void Heap<T>::swapHeap(int childIndex, int parentIndex) {
    T temp  = heap[childIndex];
    heap[childIndex] = heap[parentIndex];
    heap[parentIndex] = temp;

}

template<typename T>
void Heap<T>::push(const T &item) {
    heap.push_back(item);
    reheapingUp(heap.size() -1);
}

template<typename T>
void Heap<T>::pop() {
    if (heap.empty()){

    }
    else if (heap.size() == 1){
        heap.pop_back();
    }
    else {
        swapHeap(0, heap.size()-1);
        heap.pop_back();
        reheapingDown(0);
    }

}

template<typename T>
  T &Heap<T>::top() {
    if (!heap.empty()){
        return heap[0];
    }
}

template<typename T>
int Heap<T>::size() {
    return heap.size();
}

template<typename T>
bool Heap<T>::empty() {
    return heap.empty();
}

template<typename T>
void Heap<T>::operator+=(const T &data) {
    push(data);
}

template<typename T>
const std::vector<T> &Heap<T>::getHeap() const {
    return heap;
}


#endif //HEAP_HEAP_H
