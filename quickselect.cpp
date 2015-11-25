#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void swap(int *a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int
partition(int* arr, int l, int r) {	
	int pivot;
	int d = r-l;	

	if (l == r)
		return l;

	srand(time(NULL));
	pivot = rand()%d + l;
	//pivot = 4;
	cout<<"pivot:"<<pivot<<endl;
	swap(arr[pivot], arr[r]);
	
	pivot = r;
	r = pivot-1;
	
	while(l < r) {
		while (arr[l] <= arr[pivot]) {
			if (l < r)
				l++;	
			else
				break;		
		}		
		
		while (arr[r] > arr[pivot]) {
			if (l<r)
				r--;
			else 
				break;			
		}		
		swap(arr[l], arr[r]);		
	}
	
	if (arr[pivot] < arr[l]) {
		swap(arr[pivot], arr[l]);
		return (l);
	} else
		return(pivot);	
}

int
partition_kth(int* arr, int l, int r, int k) {
	int piv;
	int split;
	int n;	
		
	
	cout<<"l:"<<l<<" r:"<<r<<endl;	
	cout<<"k:"<<k<<endl;
	split = partition(arr, l, r);
	
	cout<<"split = "<<split<<endl;
	cout<<"split element is:"<<arr[split]<<endl;

	for (int i=0; i < 7;i++)
		cout<<"post part arr:"<<arr[i]<<endl;
	
	//return(split);	

	
	if (split == k) {
		cout<<"final call"<<endl;
		return (split);
	} else if (k < split) {
		return (partition_kth(arr, l, split-1, k));
	} else {
		return (partition_kth(arr, split + 1, r, k));
	
	}
	
	


	
}


int find_kth_smallest(int* arr, int asize, int k) {	
	int element;
	for(int i=0;i<asize;i++)
		cout<<"pre arr:"<<arr[i]<<endl;
	element = partition_kth(arr, 0, asize-1, k-1);
	return (element);

}
int main() {

	int arr[] = {700, 200, 500, 300, 900, 400, 100};
	int i,x;
	int k=1;
	
	x = find_kth_smallest(arr, sizeof(arr)/sizeof(int), k);
	cout<<"kth smallest is:"<<arr[x]<<endl;

	for (int i=0; i < 7;i++)
		cout<<"final arr:"<<arr[i]<<endl;
	


	return (0);
}