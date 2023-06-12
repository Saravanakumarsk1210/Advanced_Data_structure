#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
public:
    int data;
    node*left;
    node*right;
node* InsNode(node *root,int item)
{
    if(root==NULL)
    {
        node*nn=new node();
        nn->data=item;
        nn->left=NULL;
        nn->right=NULL;
        root=nn;
        return root;
    }
    if(root->data<item)
    {
        root->right=InsNode(root->right,item);
    }
    else if(root->data>item)
    {
        root->left=InsNode(root->left,item);
    }
    return root;

}

void searchh(node *root, int d)
 {
   int depth = 0;
   node *temp = new node;
   temp = root;
   while(temp != NULL)
    {
      depth++;
      if(temp->data == d)
      {
         cout<<"\nItem found at depth: "<<depth;
         return;
      }
      else if(temp->data > d)
         temp = temp->left;
      else
         temp = temp->right;
   }
   cout<<"\n Item not found";
   return;
}

node* minValueNode(node* root)
{
    node* current = root;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
node* deleteNode(node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {

        if (root->left==NULL and root->right==NULL)
            return NULL;

        else if (root->left == NULL)
            {
               node* temp = root->right;
               free(root);
               return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }

        node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
node* inorder(node*root)
{
    if (root == NULL)
    return 0;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
};
int main()
{
    int choice;
    int item,s,del;
    node*root=NULL;
    node n;
    while(choice!=0)
    {
        cout<<"\n ~BINARY SEARCH TREE~";
        cout<<"\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit";
       cout<<"\nEnter your Choice: ";
      cin>>choice;
      switch(choice)
      {
      case 1:
        cout<<"\nEnter Elements to insert:";
        cin>>item;
        root=n.InsNode(root,item);
         cout<<"\nElements are:";
        n.inorder(root);
        break;
      case 2:
        cout<<"\nEnter Element to search: ";
        cin>>s;
        n.searchh(root,s);
        break;
      case 3:
        cout<<"\nEnter element to delete: ";
        cin>>del;
        root=n.deleteNode(root, del);
        break;
      case 4:
        n.inorder(root);
        break;
      case 5:
        exit(0);

      }
    }
    return 0;
}
