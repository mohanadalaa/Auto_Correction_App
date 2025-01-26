#include <math.h>
#include <limits.h>
typedef struct Node{
    char *data;
    struct Node *left;
    struct Node *right;
}Node;
Node *newNode(char *x)
{
    Node *n= malloc(sizeof (Node));
    n->data= malloc(strlen(x)+1);
    strcpy(n->data,x);
    n->right=NULL;
    n->left=NULL;
    return n;

}
Node *insert(Node *root,char *data) // NOLINT(*-no-recursion)
{
    if(root==NULL)
        return newNode(data);

    if(strcasecmp(data,root->data) <0)
    {
        root->left= insert(root->left,data);
    }
    else if(strcasecmp(data,root->data) >0) {
        root->right= insert(root->right,data);
    }
    return root;
}
Node *searchTree(Node *root,char* data) { // NOLINT(*-no-recursion)
    if (root == NULL) {
        return NULL;
    }
    else if (strcasecmp(root->data,data)==0){
        return root;
      }
    else if (strcasecmp(data,root->data) <0){
        return searchTree(root->left,data);
    }
    else{  //right
        return searchTree(root->right,data);
    }
}
Node *findMin(Node* root)
{
    if(root==NULL)
        return NULL;
    Node *temp=root;
    while(temp->left!=NULL) {
        temp = temp->left;
    }
    return temp;
}
/*Node *findMin(Node *root)  // NOLINT(*-no-recursion)
{
    if(root==NULL)
        return NULL;

    else if (root ->left ==NULL) //next left node is null
    {
        return root;
    }
    else
    {
        return findMin(root->left);
    }
}*/
Node *findMax(Node *root)
{
    if(root==NULL)
        return NULL;
    Node *temp=root;
    while(temp->right!=NULL) {
        temp = temp->right;
    }
    return temp;
}
/*Node* findMax(Node *root) // NOLINT(*-no-recursion)
{
    if(root==NULL) {
        return NULL;
    }
    else if(root->right==NULL){
        return root;
    }
    else {
        return findMax(root->right);
      }
}*/
int height (Node *root) {
    if (root == NULL) {
        return -1;
    }
    else {
        int left = height (root->left);
        int right = height (root->right);

        int height = (left < right) ? right+1 : left+1;
        return height;
    }
}

Node *DeleteNode(Node *root, char* data) { // NOLINT(*-no-recursion)
    if (root == NULL)
        return NULL;
    else if (data < root->data)
        root->left = DeleteNode(root->left, data);
    else if (data > root->data)
        root->right = DeleteNode(root->right, data);
    else // node found
    {
        // case 1: no child (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
            // case 2: one child
        else if (root->left == NULL) {
            Node *temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            Node *temp = root;
            root = root->left;
            free(temp);
        }
            // case 3: 2 children
        else {
            Node *temp = findMin(root->right);
             strcpy(root->data,temp->data);
            root->right = DeleteNode(root->right, temp->data);
        }
    }
    return root;
}
Node *getSuccessor(Node *root, Node *pre) {
    Node *curr=pre;
    if (curr == NULL)
        return NULL;

    // Case 1: Node has right subtree
    if (curr->right != NULL) {
        return findMin(curr->right);
    }
        // Case 2: Node does not have a right subtree
    else {
        Node *succ = NULL;
        Node *anc = root;
        while (anc != curr) {
            if (strcasecmp(curr->data , anc->data) <0) {
                succ = anc;
                anc = anc->left;
            }
            else  {
                anc = anc->right;
            }
        }

        return succ;
    }
}
Node *getPredecessor(Node*root ,Node *pre)
{
    Node *curr=pre;
    if (curr == NULL)
        return NULL;
    // Case 1: Node has left subtree
    if(curr->left!=NULL)
        return findMax(curr->left);
        //case 2 : has no left subtree
    else {
        Node *temp = NULL;
        Node *anc = root;
        while (anc != curr) {
            if (strcasecmp(curr->data , anc->data) >0) {
                temp = anc;
                anc = anc->right;
            }
            else  {
                anc = anc->left;
            }
        }

        return temp;
    }
}
Node *destruct(Node *root)
{
    if(root==NULL)    //post order traversal
        return NULL;
    root->left=destruct(root->left);
    root->right=destruct(root->right);
    free(root->data);
    free(root);
    return NULL;
}
#ifndef TREE_BINARYTREE_H
#define TREE_BINARYTREE_H
#endif //TREE_BINARYTREE_H

