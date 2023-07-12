#include<iostream>
using namespace std;
/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/

int partitionArray(int input[], int start, int end) {
	// Write your code here
	int count=0;
	for(int i=start+1;i<=end;i++){
		if(input[i]<=input[start]){
			count++;
		}
	}
	int temp=input[start];
	input[start]=input[start+count];
	input[start+count]=temp;
	int partitonIndex=start+count;
	int x=input[start+count];
	int i=start;
	int j=end;
	while(i<partitonIndex && j>partitonIndex){
		if(input[i]<=x){
			i++;
		}
		else if(input[j]>x){
			j--;
		}
		else{
			int temp=input[i];
			input[i]=input[j];
			input[j]=temp;
			i++;
			j--;
		}
	}
	return partitonIndex;
}

void quickSort(int input[], int start, int end) {
	/*
		Don't write main().
		Don't read input, it is passed as function argument.
		Change in the given array itself.
		Taking input and printing output is handled automatically.
	*/
	if(start>=end){
		return ;
	}
	int pivot=partitionArray(input, start, end);
	quickSort(input, start, pivot-1);
	quickSort(input, pivot+1, end);
}
int main(){
    int arr[]={2,65,43,24,78,1,9,8};
    quickSort(arr,0,7);
    for(int i=0;i<=7;i++){
        cout<<arr[i]<<" ";
    }
}