#include <iostream>
using namespace std;
class DisjointSet
{
    public:
        int* rank;
        int* parent;
        int n;
        DisjointSet(int n){
            rank = new int[n];
            parent = new int[n];
            this->n = n;
            makeSet();
        }
        void makeSet();
        int find(int x);
        int PrintRank(int x);
        void Union(int x, int y);
        void NoOfConnectedComponents();
        void Display();
};
void DisjointSet :: makeSet(){
    for (int i = 0; i < n; i++){
        parent[i] = 0;
    }
}
int DisjointSet :: find(int x)
{
    if (parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
int DisjointSet :: PrintRank(int x){
    return rank[x];
}
void DisjointSet :: NoOfConnectedComponents(){
    int count = 0;
    for(int i = 0; i < n; i++){
        if (parent[i] == i)
            count++;
    }
    cout << "No. of Connected Components : " << count << endl;
}
void DisjointSet :: Union(int x, int y)
{
    int xset = find(x);
    int yset = find(y);
    if (rank[xset] < rank[yset]) 
    {
        parent[xset] = yset;
    }
    else if (rank[xset] > rank[yset])
    {
        parent[yset] = xset;
    }
    else
    {
       parent[yset] = xset;
       rank[xset] = rank[xset] + 1;
    }
    cout << "No Cycle Detected \n";

}
void DisjointSet :: Display()
{
    cout << "\n   Set : ";
    for(int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Parent : ";
    for(int i = 0; i < n; i++){
        cout << parent[i] << " ";
    }
    cout << endl;
    cout << "  Rank : ";
    for(int i = 0; i < n; i++){
        cout << rank[i] << " ";
    }
    cout << endl;
}
int main(){
    int num, choice, n1, n2;
    cout << "Enter the Number of Sets : ";
    cin >> num;
    cout << endl;
    DisjointSet obj(num);
cout<<"Disjoint sets";
    cout << "\n1  Union By Rank and Cycle Detection \n";
    cout << "2  Check if Two Numbers Belong to the Same Set \n";
    cout << "3  No. of Connected Components \n";
    cout << "4  Exit \n";
    do{
        cout << "\nENTER THE CHOICE : ";
        cin >> choice;
        switch(choice){

            case 1:
                cout << "Enter The Number 1 : ";
                cin >> n1;
                cout << "Enter The Number 2 : ";
                cin >> n2;
                obj.Union(n1, n2);
            case 2:
                cout << "Enter The Number 1 : ";
                cin >> n1;
                cout << "Enter The Number 2 : ";
                cin >> n2;

                if (n1 >= num || n2 >= num){
                    cout << "Invalid Set ID.\n";
                    break;
                }
                if (obj.find(n1) == obj.find(n2))
                    cout << "Yes\n";
                else
                    cout << "No\n";
                break;
            case 3 :
                obj.NoOfConnectedComponents();
                obj.Display();
                break;
            case 4 :
                break;
        }
    }while(choice != 4);
    return 0;
} 


