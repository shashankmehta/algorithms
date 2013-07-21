#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */
void display(vector <int> arr, int p, int q){
    for (int i=p; i<=q; i++)
        cout << arr[i] << " ";
}

void quickSort(vector <int> & ar, int p, int q) {
    if (p >= q)
        return;

    int pivot = ar[p];
    vector <int> left;
    vector <int> right;
    for (int i = p+1; i <= q; i++){
        if(ar[i] > pivot)
            right.push_back(ar[i]);
        else if(ar[i] < pivot)
            left.push_back(ar[i]);
    }

    int m = p + left.size();
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());
    
    for (int i = p; i <= q; i++){
        ar[i] = left[i-p];
    }

    quickSort(ar, p, m - 1);
    quickSort(ar, m + 1, q);
    
    display(ar, p, q);
    cout << endl;
}

/* Tail starts here */
int main() {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
}

quickSort(_ar, 0, _ar_size-1);
   
   return 0;
}