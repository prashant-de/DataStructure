#include <stdio.h>

// Function to reverse an array segment
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate the array to the right by K steps
void rotateArray(int arr[], int N, int K) {
    K = K % N;  // Normalize K
    if (K == 0) return;  // No rotation needed

    reverse(arr, 0, N - 1);    // Reverse entire array
    reverse(arr, 0, K - 1);    // Reverse first K elements
    reverse(arr, K, N - 1);    // Reverse remaining elements
}

int main() {

    int N, K;

    printf("\n Enter the size of an array:");
    scanf("%d", &N);
    
    int arr[N];
    printf("\n Enter the %d numbers:", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n Enter the number of rotation:");
    scanf("%d", &K);

    rotateArray(arr, N, K);

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
