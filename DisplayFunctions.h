void levelOrderDisplay(Node *root)
{
    if(root==NULL)
    {
        printf("NULL ROOT \n");
        return;
    }
    int x= pow(2, height(root)+1)-1 ; // NOLINT(*-narrowing-conversions)
    Queue *q= initQ( x);                   //I love it
    enqueue(q,root);  //the logic is we push the root to a queue then pop it and push the two childs of it from left to right then pop left and push her two children then pops right and push her two children
    printf("\nLevel order Binary tree display\n");
    while (!isempty(q))
    {
        Node *curr= front(q);
        dequeue(q);
        printf("%s   ",curr->data);
        if(curr->left!=NULL)
            enqueue(q,curr->left);
        if(curr->right!=NULL)
            enqueue(q,curr->right);
    }
    printf("\n");
}
void preOrderDisplay(Node *root)    //root  -> left -> right NOLINT(*-no-recursion)
{
    if(root==NULL)
        return;
    printf("%s  ",root->data);
    preOrderDisplay(root->left);
    preOrderDisplay(root->right);
}
void inOrderDisplay(Node *root)   // left  -> root -> right NOLINT(*-no-recursion)
{
    if(root==NULL)
        return;
    inOrderDisplay(root->left);
    printf("%s  ",root->data);
    inOrderDisplay(root->right);

}

__attribute__((unused)) void postOrderDisplay(Node *root) //left   -> right -> root
{
    if(root==NULL)
        return;
    postOrderDisplay(root->left);
    postOrderDisplay(root->right);
    printf("%s  ",root->data);
}
void line(){
    printf("================================================================================================\n");
}


#ifndef TREE_DISPLAYFUNCTIONS_H
#define TREE_DISPLAYFUNCTIONS_H
#endif //TREE_DISPLAYFUNCTIONS_H
