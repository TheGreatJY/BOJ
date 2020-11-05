#include <stdio.h>
void bubble(int n, int arr[]);
void swap(int arr[], int i, int j);

int main(){
	int n=0;
	scanf("%d", &n);
	int arr[n]={0};
	for(int i=0;i<n;i++){
		scanf("%d", arr+i);
	}
	bubble(n, arr);
	for(int i=0;i<n;i++){
		printf("%d\n", arr[i]);
	}
	return 0;
}
void bubble(int n, int arr[]){
	for(int i=0;i<n;i++){
		for(int j=1;j<n-i;j++){
			if(arr[j]<arr[j-1]){
				swap(arr, j-1, j);
			}
		}
	}
	
}
void swap(int arr[], int i, int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
