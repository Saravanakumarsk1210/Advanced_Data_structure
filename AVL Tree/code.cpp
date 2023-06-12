#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node*left;
    node*right;
    node*InsNode(node*,int);
    bool searchhh(node*,int);
    int height(node*);
    int difference(node*);
    node*ll(node*);
    node*rr(node*);
    node*lr(node*);
    node*rl(node*);
    node*show(node*,int);
    node*balance(node*);
    node*deleteNode(node*,int);

};

node* node::InsNode(node *root,int item)
{
    if(root==NULL)
    {
        node*nn=new node();
        nn->data=item;
        nn->left=nn->right=NULL;
        root=nn;
        return root;
    }
    if(root->data<item)
    {
        root->right=InsNode(root->right,item);
        root=balance(root);
    }
    else if(root->data>item)
    {
        root->left=InsNode(root->left,item);
        root=balance(root);
    }
    return root;

}

int node::height(node*root)
{
    int h=0;
    if(root!=NULL)
    {
    int lh=height(root->left);
    int rh=height(root->right);
    int maxx=max(lh,rh);
    h=maxx+1;
    }

    return h;
}
int node::difference(node*root)
{
    int l_h=height(root->left);
    int r_h=height(root->right);
    int diff=l_h-r_h;
    return diff;
}
node* node::ll(node*root)
{
    node*t;
    t=root->left;
    root->left=t->right;
    t->right=root;
    cout<<endl<<"LL Rotation";
    return t;
}
node* node::rr(node*root)
{
    node*t;
    t=root->right;
    root->right=t->left;
    t->left=root;
    cout<<endl<<"RR Rotation";
    return t;
}
node* node::lr(node*root)
{
    node*t;
    t=root->left;
    root->left=rr(t);
    cout<<endl<<"LR Rotation";
    return ll(root);
}
node* node::rl(node*root)
{
    node*t;
    t=root->right;
    root->right=ll(t);
    cout<<endl<<"RL Rotation";
    return rr(root);
}
node *node::balance(node *root) {
   int bal= difference(root);
   if (bal > 1) {                      //2
      if (difference(root->left) > 0)  // 1
         root = ll(root);
      else                             //-1
         root = lr(root);
   } else if (bal < -1) {
      if (difference(root->right) > 0)
         root = rl(root);
      else
         root = rr(root);
   }
   return root;
}
bool node::searchhh(node *root, int d)
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
         return true;
      }
       else if(temp->data > d)
         temp = temp->left;
         else
            temp = temp->right;
   }
   cout<<"\n Item not found";
   return false;
}
node* minValueNode(node* root)
{
        while(root->left!=NULL)
            root = root->left;

        return root;
}
node* inorder(node*root)
{
    if (root == NULL)
    return 0;
    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
}
node* node::deleteNode(node *root,int data){

        if(root->left == NULL && root->right == NULL){
                if(root->data==data)
                    root = NULL;
            delete root;
            return NULL;
        }

        node *t;
        node *q;
        if(root->data < data){
            root->right = deleteNode(root->right,data);
            root=balance(root);
        }
        else if(root->data > data){
            root->left = deleteNode(root->left,data);
            root=balance(root);
            cout<<"\n";
         
        }
        else{
            if(root->left != NULL)
                {
                q = minValueNode(root->left);
                root->data = q->data;
                root->left=deleteNode(root->left,q->data);
                root=balance(root);
                cout<<"\n";
                inorder(root);
            }

            else{
                q = minValueNode(root->right);
                root->data = q->data;
                root->right = deleteNode(root->right,q->data);
                root=balance(root);
                cout<<"\n";
                inorder(root);
            }
        }
        return root;
    }

int main()
{
    int choice;
    int item,s,del;
    node*root=NULL;
    node n;
    while(choice!=0)
    {
        cout<<"\n BINARY SEARCH TREE ";
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
        inorder(root);
        break;
      case 2:
        cout<<"\nEnter Element to search: ";
        cin>>s;
        n.searchhh(root,s);
        break;
      case 3:
        cout<<"\nEnter element to delete: ";
        cin>>del;
      }
    }
}

