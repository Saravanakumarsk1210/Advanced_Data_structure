#include <iostream>
using namespace std;
int binarySearchint(int array[], int x, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] == x)
            return mid;
        if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;}
int binarySearchchar(char array[], int x, int low, char high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] == x)
            return mid;
        if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;}
int main()
{
    int x,choice;
    cout<<"Enter type of search:\n1.int\n2.char"<<endl;
    cin >> x;
    switch(x)
    {
    case 1:
        {
            int n;
            cout << "\nEnter the number of elements: ";
            cin >> n;
            int array[n];
            cout << "Enter elements:" << endl;
            for(int i = 0; i<n; i++)
            {
                cin >> array[i];
            }
            int x;
            cout<<"enter the element to be searched:";
            cin>>x;
            n = sizeof(array) / sizeof(array[0]);
            int result = binarySearchint(array, x, 0, n - 1);
            if (result == -1)
                cout<<"Not found";
            else
                cout<<"Element is found at index:"<<result;
        }
    case 2:
        {
            int n;
            cout << "\nEnter the number of elements: ";
            cin >> n;
            char array[n];
            cout << "Enter elements:" << endl;
            for(int i = 0; i<n; i++)
            {
                cin >> array[i];
            }
            char x;
            cout<<"enter the element to be searched:";
            cin>>x;
            n = sizeof(array) / sizeof(array[0]);
            int result = binarySearchchar(array, x, 0, n - 1);
            if (result == -1)
                cout<<"Not found";
            else
                cout<<"Element is found at index:"<<result;
        }
    }
    }
