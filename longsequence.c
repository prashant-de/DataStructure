#include<stdio.h>

//Function to short the array in ascending order. 
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {  
        for (int j = 0; j < n - i - 1; j++) {  
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// This function check the largest sequence of number from the array that hold the different number of sequences. 

void largestSequence (int seq[], int n) {
   int largest = 0;

   printf("\n The sequenses were: \n");
    for (int i = 0; i < n; i++) {
        if (largest < seq[i]) {
            largest = seq[i];
        }
        printf(" %d ", seq[i]);
    }
    printf("\n The longest sequience in the array is %d.", largest);
   
}

// Function to count the sequence and store each sequence in a array. 

void sequence(int arr[], int n) {
    int count = 1, seqn = 0, seq[n];
    for (int i = 0; i < n - 1; i ++) {

        if ( (arr[i] + 1) == arr[i+1]) {
            count++;
        }
        else {
            seq[seqn] = count;
            count = 1;
            seqn++;
        }

    }
    if (seqn == 0) {
        printf("\n The longest sequience in the array is %d", count);
    }
    else {
    largestSequence(seq, seqn);
    }


}

int main()
{
    int n;
    printf("\n Enter the array size:");
    scanf("%d", &n);

    int arr[n];
    
    printf("\n Enter  %d numbers:", n);
    for(int i = 0; i < n; i++){
    
        scanf("%d", &arr[i]);
    }

    sortArray(arr, n);

    printf(" \nThe shorted array are:\n");
    for(int i = 0; i < n ; i++)
    {
        printf(" %d  ", arr[i]);
    }

    sequence(arr, n);



}