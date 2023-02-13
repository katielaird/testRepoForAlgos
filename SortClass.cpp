#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "SortClass.h"
#include <exception>
#include <math.h>

using namespace std;


SortClass::SortClass(int n, bool genRandom)
{
    swapCount = 0;
    if (genRandom) 
	{
            srand(time(0));
	    for (int i = 0; i < n; i++)
		array.push_back((rand() % 1000) * 1.0);
	}
    else
	{
	    for (int i = 0; i < n; i++)
		array.push_back(0.0);
	}
}

SortClass::SortClass(const SortClass& st)
{
   swapCount = st.swapCount;
   for (int i = 0 ; i < st.array.size(); i++)
	array.push_back(st.array[i]);

}

int SortClass::count()
{
   return array.size();
}

int SortClass::getSwapCount()
{
   return swapCount;
}

void SortClass::clear(bool genRandom)
{
    swapCount = 0;
    if (genRandom) 
	{
            srand(time(0));
	    for (int i = 0; i < array.size(); i++)
		array[i] = rand() * 1.0;
	}
    else
	{
	    for (int i = 0; i < array.size(); i++)
		array[i] = 0.0;
	}
}

bool SortClass::lessthan(int i, int j)
{
   return (array[i] < array[j]);
}

void SortClass::swap(int i, int j)
{
    float temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    swapCount++;
}

ostream& operator<<(ostream& os, SortClass& s)
{
    os.flush();
    for (int i = 0; i < s.array.size(); i++)
	{
	    if (!(i % 10))
		    os << endl;
	    os << s.array[i] << " ";
	}
    return os;
}

istream& operator>>(istream& is, SortClass& s)
{
    for (int i = 0; i < s.array.size(); i++)
	{
	    is >> s.array[i];
	}
    return is;
}

void ShellSort(SortClass &s, int code) {
    if (code > 3 || code < 0) {
        cerr << "Bad input buddy" << endl;
        throw exception();
    }
    else if (code == 0) {
//        insertionSort(s);
    }
    else if (code == 1) {
        caseOne(s);
    }
    else if (code == 2) {
        caseTwo(s);
    }
    else if (code == 3) {
        caseThree(s);
    }
}

void caseOne(SortClass &s) {
    // vector array is the sorted list of descending number of n = 500 integers, the last one being 1
    for (int k = sqrt(s.count()); k >= 1; k--) {
        int h = k*k;
        for (int i = s.count() -1; i >= h; i--) {
            int l = i;
            while ((l > 1) && (s.lessthan(l, l-h))) // array[i] < array[i-h]
            {
                s.swap(l-h, l);
                l = l - h;
            }
        }
    }
    insertionSort(s);
}

void caseTwo(SortClass &s) {
// vector array is the sorted list of descending number of 500 integers, the last one being 1
    double theoreticalk = s.count() + 1;
    theoreticalk = log2(theoreticalk);
    for (int k = sqrt(s.count()); k >= 1; k--) { // the "gap" between the numbers is
        int h = pow(2, k) - 1;
        for (int j = 2; j < s.count(); j++) {
            int i = j;
            while ((i >= 0) && (s.lessthan(i, i-h)))
            {
                s.swap(i-h, i);
                i--;
            }
        }
    }
    insertionSort(s);
}

void caseThree(SortClass &s) {
// vector array is the sorted list of descending number of 500 integers, the last one being 1
double tk = (s.count()*2)+1;
tk = log2(tk)/log2(3);
    for (int k = tk; k >= 1; k--) { // the "gap" between the numbers is
        int h = (pow(3, k) - 1)/2;
        for (int j = 2; j < s.count(); j++) {
            int i = j;
            while ((i >= 0) && (s.lessthan(i, i-h)))
            {
                s.swap(i-h, i);
                i--;
            }
        }
    }
    insertionSort(s);
}

void insertionSort(SortClass &s) {
    for (int j = 1; j < s.count(); j++) {
        int i = j;
        while ((i >= 0) && (s.lessthan(i, i-1)))
        {
            s.swap(i-1, i);
            i--;
        }
    }
}
