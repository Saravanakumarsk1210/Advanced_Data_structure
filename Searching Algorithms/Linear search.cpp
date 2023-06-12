#include<iostream>
using namespace std;
void LinearSearchint(int arr[], int len, int item){
    for(int i=0;i<len;i++){
        if(arr[i] == item){
            cout << item << " Found at index : " << i;
            return;
        }
    }
    cout << "Not found";
}
void LinearSearchchar(char arr[], int len, char item){
    for(int i=0;i<len;i++){
        if(arr[i] == item){
            cout << item << " Found at index : " << i;
            return;
        }
    }
    cout << "Not found";
}
int main(void)
{
    int x;
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
            int len = sizeof(array)/sizeof(array[0]);
            int item;
            cout<<"enter the element to be searched";
            cin>>item;
            LinearSearchint(array, len, item);
            break;
        }
        case 2:
        {
            int n;
            cout << "\nEnter the number of characters: ";
            cin >> n;
            char array[n];
            cout << "Enter elements:" << endl;
            for(int i = 0; i<n; i++)
            {
                cin >> array[i];
            }
            int len = sizeof(array)/sizeof(array[0]);
            char item;
            cout<<"enter the element to be searched";
            cin>>item;
            LinearSearchchar(array, len, item);
            break;
        }
    }while(x!=2);
}



