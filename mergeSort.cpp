#include <stdio.h>
void merge(int arr[], int s, int f);
void combine (int arr[], int s, int mid, int f);

int main(){
	int n=0;
	scanf("%d", &n);
	int arr[n]={0};
	for(int i=0;i<n;i++){
	 	scanf("%d", arr+i);
	}
	merge(arr, 0, n-1);
	for(int i=0;i<n;i++){
		printf("%d\n", arr[i]);
	}
	return 0;
}

void merge(int arr[], int s, int f){ //arr[start] ~ arr[finish]
	if(s<f){
		int mid=(s+f)/2;
		merge(arr, s, mid);
		merge(arr, mid+1, f);
		combine(arr, s, mid+1, f);
	}	
}

void combine (int arr[], int s, int mid, int f){//mid==두번째 배열의 첫번째 원소 
	int left=s, right=mid, n=0;
	int newArr[f-s+1]={0};
	
	while(1){
		if(left<mid && right<=f){
			if(arr[left]<arr[right]){
				newArr[n]=arr[left];
				n++; left++;
			}
			else{
				newArr[n]=arr[right];
				n++; right++;
			}
		}
		else break;		
	}
	
	if(left>=mid){//첫번째 배열이 끝나고 두번째 배열은 남은 경우 
		for(int i=right;i<=f;i++){
			newArr[n]=arr[i];
			n++;
		}
	}
	else{//첫번째 배열은 남은 경우 
		for(int i=left;i<mid;i++){
			newArr[n]=arr[i];
			n++;
		}
	}
	
	int temp=0;
	for(int i=s;i<=f;i++){
		arr[i]=newArr[temp];
		temp++;
	}
}
