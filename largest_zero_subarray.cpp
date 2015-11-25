/* Find the largest sub-array */
#include <iostream>
#include <algorithm>
using namespace std;

void find_lzero(int a[], int n) {
	int piv1,piv2;
	int sum1=0, sum2=0;
	sort(a,a+n);

	for (int i=0;i<n;i++) {
		if (a[i] < 0) {
			piv1 = i;
			sum1 += a[i];
		} else {
			break;
		}
	}

	for(int i=piv1;i<n;i++) {
		if (sum2 < -sum1) {
			piv2 = i;
			sum2 += a[i];
		} else {
			break;
		}
	}

	cout<<"piv1:"<<piv1<<endl;
	cout<<"sum1:"<<sum1<<endl;
	cout<<"piv2:"<<piv2<<endl;

}
int main() {

	int arr[] = {15,-2,2,-8,1,7,10,23};

	find_lzero(arr, sizeof(arr)/sizeof(int));
	
	return(1);
}

