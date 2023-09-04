// Max-Heap data structure in C++

#include <iostream>
#include <vector>
using namespace std;

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Function to heapify the tree starting from index i
void heapify(vector<int> &hT, int i)
{
    int size = hT.size();
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // Check if left child is larger than root
    if (l < size && hT[l] > hT[largest])
        largest = l;

    // Check if right child is larger than current largest
    if (r < size && hT[r] > hT[largest])
        largest = r;

    // If the largest element is not the root, swap them and recursively heapify the affected subtree
    if (largest != i)
    {
        swap(&hT[i], &hT[largest]);
        heapify(hT, largest);
    }
}

// Function to insert a new element into the heap
void insert(vector<int> &hT, int newNum)
{
    int size = hT.size();

    // If the heap is empty, simply add the new element
    if (size == 0)
    {
        hT.push_back(newNum);
    }
    else
    {
        // Add the new element to the end of the heap
        hT.push_back(newNum);

        // Heapify the heap starting from the parent of the last element up to the root
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(hT, i);
        }
    }
}

// Function to delete a specific element from the heap
void deleteNode(vector<int> &hT, int num)
{
    int size = hT.size();
    int i;

    // Find the index of the element to be deleted
    for (i = 0; i < size; i++)
    {
        if (num == hT[i])
            break;
    }

    // Swap the element to be deleted with the last element in the heap
    swap(&hT[i], &hT[size - 1]);

    // Remove the last element from the heap
    hT.pop_back();

    // Heapify the heap starting from the parent of the swapped element up to the root
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(hT, i);
    }
}

// Function to print the elements of the heap
void printArray(vector<int> &hT)
{
    for (int i = 0; i < hT.size(); ++i)
        cout << hT[i] << " ";
    cout << "\n";
}

int main()
{
    vector<int> heapTree;

    // Insert elements into the heap
    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);

    cout << "Max-Heap array: ";
    printArray(heapTree);

    // Delete an element from the heap
    deleteNode(heapTree, 4);

    cout << "After deleting an element: ";

    // Print the elements of the modified heap
    printArray(heapTree);
}
