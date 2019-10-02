#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
using namespace std;

// MergeSort function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd);

// BubbleSort function declaration
void swap (int *a, int *b);
void bubbleSort(int *a, int n);

int main(int argc, char* argv[]) {
    //check if there's more than 3 arguments
    if (argc!= 3){
        cout << "You need to enter 3 arguments in terminal, for example: ./BubbleSort seed length";
        exit(1);
    }
    // get input: first is random seed, second is vector length
    int seed;
    int length;
    seed = atoi(argv[1]);
    length = atoi(argv[2]);
    //cin >> seed >> length;
    srand(seed);
    cout << seed << " " << length << endl;

    vector<int> v(length); // vector to be sorted
    vector<int> t(length); // temporary workspace

    // define an integer pointer dynamically allocate an array of integers
    int *a = new int[length];

    // initialize and print input
    cout << "Unsorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // copy the random list of integers from vector to array
    for(int i = 0; i < length;i++){
        a[i] = v.at(i);
        cout<<a[i]<<'\t';
    }
    cout << endl;

    clock_t start_mergeSort = clock();
    // sort vector using mergeSort
    mergeSort(v,t, 0, v.size() - 1);
    clock_t end_mergeSort = clock();

    // check output, make sure vector is sorted after mergeSort
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    //Unit Test for Swap function
    cout <<"Unit test for swap:"<<endl;
    int s1 = 1;
    int s2 = 2;
    int *t1 = &s1;
    int *t2 = &s2;
    cout << "Before " << s1 << " " << s2 << endl;
    swap(t1, t2);
    cout << "After " << s1 << " " << s2 << endl;
    assert((s1==2) && (s2 == 1));

    clock_t start_bubbleSort = clock();
    // sort array using bubbleSort
    bubbleSort(a,length);
    clock_t end_bubbleSort = clock();

    // check output, make sure array is sorted after bubbleSort

    for(int i = 1; i < length; i++) {
        assert(a[i-1] <= a[i]);
    }

    // print sorted vector after mergeSort
    cout << "Sorted:" << endl;
    for ( int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // print sorted array after bubbleSort
    /* your code here */
    cout << "BubbleSort Sorted: " << endl;
    for (int i = 0; i < length; i++) {
        cout << a[i] << '\t';
    }
    cout << endl;

    // print elapsed time for mergeSort and bubbleSort
    double elapsed_mergeSort = double(end_mergeSort - start_mergeSort) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort = double(end_bubbleSort - start_bubbleSort) / CLOCKS_PER_SEC;

    cout << "Time for Merge Sort: " << elapsed_mergeSort <<endl;
    cout << "Time for Bubble Sort:" << elapsed_bubbleSort << endl;

    return 0;
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmp[tempPos++] = a[leftPos++];
        } else {
            tmp[tempPos++] = a[rightPos++];
        }

    }

    while (leftPos <= leftEnd) {
        tmp[tempPos++] = a[leftPos++];
    }
    while (rightPos <= rightEnd) {
        tmp[tempPos++] = a[rightPos++];
    }

    for (int i = 0; i < numElements; i++, --rightEnd) {
        a[rightEnd] = tmp[rightEnd];
    }
}

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        mergeSortedLists(a, tmp, left, center + 1, right);
    }
}

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = * b;
    *b = temp;
}

// BubbleSort function
void bubbleSort(int *a, int n) {
    bool sort= false;
    while (!sort) {
        for (int j = 0; j <n ; j++) {
            for (int i = 1; i < n; i++) {
                if (a[i - 1] > a[i]) {
                    swap(&a[i - 1], &a[i]);
                }
            }
        }
        sort = true;
    }
}