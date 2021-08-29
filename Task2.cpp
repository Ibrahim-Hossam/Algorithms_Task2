#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Insertion_Sort(int arr[]){
	int i, j, temp, M; // M to mark the unsorted element
	float ST, ET, TT; // ST stands for start time, ET for end time and TT for time taken
	ST = clock();
	for(i = 1; i < 100000; i++){   //the for loop that stores the sorted elements
		M = arr[i];
		for (j = i-1; j >= 0; j--){
			if(arr[j] > M){     // the condition is used to enter the unsorted element into it's place
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
		arr[j] = M;
	}
	ET = clock();
	TT = (ET - ST)/CLOCKS_PER_SEC;
	printf("The time taken by Insertion sort is %f seconds", TT);
}


void Quick_Sort(int arr[],int first,int last){
	int i, j, P, temp;
	if(first<last){
		P=first;
		i=first;
		j=last;
		while(i<j){
			while(arr[i]<=arr[P]&&i<last)
				i++;
			while(arr[j]>arr[P])
				j--;
			if(i<j){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		temp=arr[P];
		arr[P]=arr[j];
		arr[j]=temp;
		Quick_Sort(arr,first,j-1);
		Quick_Sort(arr,j+1,last);
	}
}

int main()
{	int arr[100000];
	for(int i = 0; i < 100000; i++){
		arr[i] = rand();
	};
	printf("The array of 100000 numbers is initialized\n");
	Insertion_Sort(arr);
	float ST, ET, TT; // ST stands for start time, ET for end time and TT for time taken
	ST = clock();
	Quick_Sort(arr, 0, 100000);
	ET = clock();
	TT = (ET - ST)/CLOCKS_PER_SEC;
	printf("\nThe time taken by Quicksort is %f seconds", TT);
	

return 0;
}
