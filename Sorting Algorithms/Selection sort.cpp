#include<iostream>
using namespace std;
void swapping(int &a, int &b) {
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i]<<endl;
   cout << endl;
}
void selectionSort(int *array, int size) {
   int i, j, i1;
   for(i = 0; i<size-1; i++) {
      i1= i;
      for(j = i+1; j<size; j++)
         if(array[j] < array[i1])
            i1 = j;
         //placing in correct position
         swap(array[i], array[i1]);
   }}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   selectionSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
}
