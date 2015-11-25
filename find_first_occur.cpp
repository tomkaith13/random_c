#include <iostream>
using namespace std;

int find_last_occurrence(int* A, int asize, int k) {
	int l =0, r = asize-1;
	int m =0;

	if ((l == r) && (l==0)) {
		if (A[l] == k)
			return(l);
		else
			return(-1);
	} 

	while(l<r) {

		m = l + ((r-l)/2);
		cout<<"l:"<<l<<" r:"<<r<<endl;
		cout<<"m:"<<m<<endl;

		if (k < A[m]) {
			r = m-1;			
		} else if (k > A[m]) {
			l = m + 1;
		} else if (k == A[m]) {
			if (A[m] == A[m+1])
				l = m + 1;
			else
				return (m);
		}
	}
	if (A[l] == k)
		return (l);
	else
		return(-1);
}

int 
find_first_occurrence(int *A, int asize, int k) {
	int l=0, r = asize-1;
	int m=0;

	cout<<"l:"<<l<<" r:"<<r<<endl;;

	if ((l==r) && (l==0)) {
		if (A[l] == k)
			return l;
		else
			return(-1);
	}

	while(l<r) {

		m = l + ((r-l)/2);

		if (k < A[m])
			r = m - 1;
		else if (k > A[m])
			l = m + 1;
		else if (k == A[m]) {
			if (A[m] == A[m-1])
				r = m-1;
			else
				return (m);
		}
	}

	if (A[l] == k)
		return(l);
	else
		return(-1);
}
int main() {

	int arr[] = {1,2,2,3,4,5,5,6,7,7,8,9};
	int k;
	int lo, hi;
	k=1;

	

	lo = find_first_occurrence(arr, (sizeof(arr)/sizeof(int)), k);
	hi = find_last_occurrence(arr, (sizeof(arr)/sizeof(int)), k);
	cout<<k<<" occurs first at position:"<<lo<<endl;
	cout<<k<<" occurs last at position:"<<hi<<endl;
	return (0);
}