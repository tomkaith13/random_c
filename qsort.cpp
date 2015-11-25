#include <iostream>


using namespace std;


void swap(int* a, int*b) {
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

void 
partition (int* a, int l, int r, int key) {
	
	int pivot = a[key];
	int a_size = r;
	swap(&a[r],&a[key]);
	r--;


	while(l<r) {
		if(a[l] <= pivot) {
			l++;
		}
		else {
			swap(&a[l],&a[r]);
			if (a[l] <= pivot)
				l++;
			else
				r--;
		}

		for (int i=0;i<9;i++)
		cout<<"element:"<<a[i]<<endl;
		cout<<l<<r<<endl;	
		cout<<endl;
	}

	swap(&a[l],&a[a_size]);
}

int main()
{

	int arr[] = {2,5,8,7,1,3,6,9,4};

	partition(arr,0,(sizeof(arr)/sizeof(int))-1, 3);

	for (int i=0;i<9;i++)
		cout<<"element:"<<arr[i]<<endl;

	
	

	return(0);
}