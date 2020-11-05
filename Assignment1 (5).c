#include <stdio.h> 
#include <stdlib.h> 
// merge sort function
void merge(double arr[], int l, int m, int r) 
{ 
    int k,
        i,
        j, 
        n1 = m - l + 1, 
        n2 = r - m; 

    double L[n1], 
           R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
 
    i = 0; 
    j = 0; 
    k = l; 
 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
// function used to decide wether to use insertion or merge sort  
void mergeSort(double arr[], int l, int r) 
{ 
   if(r-l>6){
    if (l < r) { 

        int m = l + (r - l) / 2; 

        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
   }
   else{
      insertionSort(arr,r+1);
   }
} 
// function for insertion sort  
void insertionSort(double arr[], int n) 
{ 

    double key;
    int j; 
    for (int i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

//for looop function used to print arrays
void printArray(double A[], int size, int character) 
{ 
   FILE *fp;
   fp = fopen("Out1.txt", "w+");
    for (int i = 0; i < character; i++) 
        fprintf(fp, "%.2lf ", A[i]); 
        fprintf(fp, "\n"); 

    fclose(fp);
} 

int main() 
{ 
    // scan document to figure out how many nubers are in array
     FILE *fp;
    fp = fopen("Data1.txt", "r");
    int ch;
    int character = 0;
    while ((ch = fgetc(fp)) != EOF)
        {
            if(ch == ' '){
            character++;
            }
        }
        character++;
    fclose(fp);
    int numinArray; //how many numbers are in the list
    double arr[500];


    fp = fopen("Data1.txt", "r"); 
    // scan document for array
    for (int i = 0; i < character; i++){
        fscanf(fp, "%lf", &arr[i]);
    }
    fclose(fp);
    

    //find the size of the array
    int arr_size = character; 
    //sizeof(arr) / sizeof(arr[0]); 

    //Call to sort the array
    mergeSort(arr, 0, arr_size - 1); 
    //output the now sorted array
    printf("\nSorted: \n"); 
    printArray(arr, arr_size, character); 
    return 0; 
}

