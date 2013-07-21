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
void display(vector <int> arr){
    for (int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";
}

void partition(vector <int>  ar, int size) {
    vector <int> left;
    vector <int> right;
    int pivot = ar[0];
    for (int i=0; i<size;i++){
        if(ar[i] >= pivot)
            right.push_back(ar[i]);
        else
            left.push_back(ar[i]);
    }
    display(left);
    display(right);
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

partition(_ar, _ar_size);
   
   return 0;
}