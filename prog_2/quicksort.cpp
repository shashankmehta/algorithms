#include <iostream>
#include <fstream>

using namespace std;

int count = 0;
int pivotType = 3;

int choosePivot(int a[], int l, int r){
	switch(pivotType){
		case 1:
			return a[l];
			break;

		case 2:
			return a[l];
			break;

		case 3:
			int position;
			int left = a[l];
			int right = a[r];

			int m = l+(r-l+1)/2;
			if ((r-l+1)%2 == 0)
				m -= 1;
			int middle = a[m];

			if (left<middle) {
				if (middle<right) {
					position = m;
				} 
				else { 
					if (left<right) {
						position = r;
					} 
					else {
						position = l;
					}     
				}
			} else {
				if (right<middle) {
					position = m;
				} 
				else {  
					if (right>left) {
						position = l;
					} 
					else {
						position = r;
					}   
				}
			}

			int temp = a[l];
			a[l] = a[position];
			a[position] = temp;
			return a[l];
			break;
	}

}

void quickSort(int a[], int l, int r){
	int length = r-l;
	
	if (length <= 0)
		return;

	count += length;	

	int pivot = choosePivot(a, l, r);
	int i = l + 1;
	for(int j = l+1; j<=r; j++){
		if (a[j] < pivot){
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			i++;
		}
	}
	int temp = a[l];
	a[l] = a[i-1];
	a[i-1] = temp;

	quickSort(a, l, i-2);
	quickSort(a, i, r);
}

int main() {
	ifstream infile("QuickSort.txt");
	int size = 10000;
	int a[size];
	int i=0;
	while(infile>>a[i])
		i++;

	quickSort(a, 0, size-1);
	cout << "answer = " << count << endl;

	return 0;
}