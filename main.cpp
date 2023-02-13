#include <iostream>
#include "SortClass.h"



int main()
{

    SortClass  st(50);

    cout << st << endl;
    ShellSort(st, 1);
    cout << "------\n";
    cout << st << endl;
    cout << "Swap count : " << st.getSwapCount() << endl;

    return 0;
}