#include <iostream>
#include <algorithm>
#include <chrono>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <windows.h>

using namespace std;
using namespace std::chrono;

//Bubble Sort
int bubble(int *t, int sizeT)
{
    bool swapped = false;
    for (int i= 0; i < sizeT-1; i++){
        if (*(t+i) > *(t+i+1))
        {
            swap(*(t+i), *(t+i+1));
            //cout << *(t + i) << endl;
            swapped = true;
        }
    }
    return swapped;
}

int bubblesort(int *t, int sizeT) {
    while(bubble(t,sizeT));
}

void printT(int *t, int sizeT){
    for(int i = 0; i < sizeT; i++){
        cout << t[i] << " ";
    }
}

//Bucket Sort
int fillBuckets(int *buckets, int *t, int sizeT) {
    for (int i = 0; i < sizeT; i++) {
        if (t[i] <= sizeT) {
            buckets[t[i]]++;
        }
}
}
int printBuckets(int *buckets, int sizeT) {
    for (int i = 0; i < sizeT; i++) {
        for(int j = 1; j <= buckets[i]; j++){
        cout << i << ",";
        }
    }

}

//Quick Sort
int display(int tab[], int tabSize)
{
    for (int i = 0; i < tabSize; i++)
    {
        cout << tab[i] << ",";
    }
    cout << endl;
}

int compare(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

//Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    void insertRecursive(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
        } else {
            if (value < node->data) {
                insertRecursive(node->left, value);
            } else {
                insertRecursive(node->right, value);
            }
        }
    }

    void displayTree(Node* node, int indent = 0) {
        if (node != nullptr) {
            displayTree(node->right, indent + 4);
            std::cout << std::string(indent, ' ') << node->data << std::endl;
            displayTree(node->left, indent + 4);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        insertRecursive(root, value);
    }

    void display() {
        displayTree(root);
    }
};

int main()
{
    int sizeT = 10000;
    int tab1[sizeT];
    int tab2[sizeT];
    int tab3[sizeT];
    int tab4[sizeT];
    int bucket[sizeT];
    double tBubble=0, tBucket=0, tQuick =0, tBinaryTree=0;
    srand(time(0));

    for (int i = 0; i < sizeT; i++) {
        tab1[i] = rand() % 10;
    }
    for (int i=0; i<=sizeT; i++)
        tab2[i] = tab1[i];
    for (int i=0; i<=sizeT; i++)
        tab3[i] = tab1[i];
    for (int i=0; i<=sizeT; i++)
        tab4[i] = tab1[i];
    for (int i=0; i<=sizeT; i++)
        bucket[i] = 0;

    //Bubble Sort
    auto start = high_resolution_clock::now();
    bubblesort(tab1, sizeT);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Bubble: " << duration.count() << endl;

    //Bucket Sort
    start = high_resolution_clock::now();
    Sleep(1);
    fillBuckets(bucket, tab2, sizeT);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Bucket: " << duration.count() - 100 << endl;

    //Quick Sort
    start = high_resolution_clock::now();
    Sleep(1);
    qsort(tab3, sizeT, sizeof(int), compare);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Quick: " << duration.count()-100 << endl;

    //Binary Tree
    start = high_resolution_clock::now();
    BinaryTree tree;
    for (int i = 0; i < 10000; i++)
        tree.insert(tab4[i]);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Binary tree: " << duration.count() << endl;

    return 0;
}
