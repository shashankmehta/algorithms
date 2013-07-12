#include <iostream>
#include <fstream>

using namespace std;

int countSplitInv(long a[], int p, int half, int q){
	int size1 = half-p+1; 
	int size2 = q-half; 
	long long count = 0;

	long left[size1];
	long right[size2];

	for(int i=0; i<size1; i++){
		left[i] = a[p+i];
	}
	for(int i=0; i<size2; i++){
		right[i] = a[half+1+i];
	}

	int x = 0;
	int y = 0;
	int i = p;
	for(; i<=q; i++){
		if(left[x] < right[y]){
			a[i] = left[x];
			x++;
		}
		else {
			a[i] = right[y];
			y++;
			count = count + size1 - x;
		}
		if(x >= size1 || y >= size2)
			break;
	}
	i++;
	if(x < size1) {
		while(i <= q) {
			a[i++] = left[x++];
		}
	}
	return count;
}

long count(long a[], int p, int q) {
	if(q>p){
		long long half = (p+q)/2;
		long long x = count(a, p, half);
		long long y = count(a, half+1, q);
		long long z = countSplitInv(a, p, half, q);
		return x + y + z;
	}
	else
		return 0;
}

int main() {
	ifstream infile("IntegerArray.txt");
	long a[100000];
	int i=0;
	while(infile>>a[i])
		i++;
	int size = sizeof(a)/sizeof(a[0]);
	cout<<count(a,0, size-1)<<endl;
	return 0;
}