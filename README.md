# DataStructure
This is the repository where I will post practice questions of Data structure in c.

### Problem Statement:
#### Given an integer array arr of size N and an integer K, rotate the array to the right by K steps.
 To rote the array by k steps: rotate.c

 #### Given an unsorted array of integers arr of size N, find the length of the longest consecutive sequence of numbers.
 ##### longsequence.c

 To solve this problem in a simple way I have use the following sequence:
 + First: Sort the array in the ascending order. function: void sortArray(int arr[], int n);
 + Second: Compare the array element to following element and if the first element + 1 is equel to second, they are in sequence. So, increment the sequence. If the sequence break save it in a array and count another sequence, and do the same.
 + Third: find the largest among the sequence and print it. 
