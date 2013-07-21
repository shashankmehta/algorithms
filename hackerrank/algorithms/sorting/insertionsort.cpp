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
void display(vector <int> ar){
    for (int m = 0; m<ar.size(); m++)
        cout << ar[m] << " ";
    cout << endl;
}

void insertionSort(vector <int>  ar, int size) {
    int count = 0;
    for (int j = 1; j<size; j++){
        int key = ar[j];
        int i = j-1;
        while(i>=0 && ar[i]>key){
            ar[i+1]=ar[i--];
            count++;
        }
        ar[i+1]=key;
        // display(ar, size);
    }
    display(ar);
}
/* Tail starts here */
int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
}

insertionSort(_ar, _ar_size);
   
   return 0;
}