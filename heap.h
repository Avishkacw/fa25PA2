//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        if (size >= 64) return; //simple guard
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) return -1; // placeholder
        int smallest = data[0];
        size--;
        data[0] = data[size];
        downheap(0, weightArr);
        return smallest;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0 ) {
            int parentPos = (pos - 1) / 2;
            if (weightArr[data[pos]] < weightArr[parentPos]) {
                int temp = data[pos];
                data[pos] = data[parentPos];
                data[parentPos] = temp;
                pos = parentPos;
            } else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true) {
            int leftChild = 2 * pos + 1;
            int rightChild = 2 * pos + 2;
            int smallest = pos;

            if (leftChild < size && weightArr[data[leftChild]] < weightArr[data[smallest]]) smallest = leftChild;
            if (rightChild < size && weightArr[data[rightChild]] < weightArr[data[smallest]]) smallest = rightChild;

            if (smallest != pos) {
                int temp = data[pos];
                data[pos] = data[smallest];
                data[smallest] = temp;
                pos = smallest;
            } else {
                break;
            }
        }
    }
};

#endif