#include <iostream>
#include <vector>

using namespace std;

class SortClass {

friend ostream& operator<<(ostream& os, SortClass& s);
friend istream& operator>>(istream& os, SortClass& s);

public:


    SortClass(int n, bool genRandom = true);

    SortClass(const SortClass&);

    void clear(bool genRandom = true);

    int count();
  
    int getSwapCount();  
 
    bool lessthan(int i, int j); // return true if array[i] < array[j]

    void swap(int i, int j);



private:


    int swapCount;
    vector<float> array;

};
void insertionSort(SortClass &s);
void caseOne(SortClass &s);
void caseTwo(SortClass &s);
void caseThree(SortClass &s);
void ShellSort(SortClass&, int code);
