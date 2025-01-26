int getSize(Node*root) // NOLINT(*-no-recursion)
{
    if(root==NULL)
        return 0;
    else
        return 1+ getSize(root->left) + getSize(root->right);
}

Node *load(Node*root)
{
    FILE *f= fopen("Dictionary.txt","r");
    if(f==NULL)
    {
        printf("File does not exist \n");
        exit(69696969);
    }
    char *user=malloc(31*sizeof (char ));
    while (fgets(user,31,f)!=NULL){
        if (user[strlen(user) - 1] == '\n')
            user[strlen(user) - 1] = '\0';
        root= insert(root,user);
    }
    fclose(f);
    printf("Dictionary Loaded Successfully!\n");
    line();
    printf("Size : %d\n", getSize(root));
    line();
    printf("Height : %d\n", height(root));
    line();
    free(user);
    return root;
}
Node *searchPreNode(Node *root, char* data) {  //an itterative search function  big O(log(N))
    Node *temp=root;
    Node* preNode = NULL; // Stores the last node searched before finding the target node
    while (temp != NULL) {
        if (strcasecmp(data, temp->data) < 0) {
            preNode = temp;
            temp = temp->left;
        } else if (strcasecmp(data, temp->data) > 0) {
            preNode = temp;
            temp = temp->right;
        } else {                   // Data found, return the node containing the word itself
            return temp;
        }
    }
    return preNode;            //the function returns either the found node or the last node to be searched if the word is not in the bst
}
char *input(char *str)
{
    char *user= malloc(61*sizeof (char ));
    printf("%s",str);
    fgets(user, 61, stdin) ; // Read input using fgets
    if (user[strlen(user) - 1] == '\n')
        user[strlen(user) - 1] = '\0';

    printf("\n");
    return user;
}
void menu(Node *root)
{
    int i=0;
    while(1){
       
     char* user= input("Enter a Sentence : ");
       char *token = strtok(user, " ");
        while (token != NULL) {
            Node *search = searchPreNode(root, token);
            if(strcasecmp(search->data,token) ==0){   //word found
                printf("%s is Correct\n\n",token);
            }
            else {
                Node *pre=getPredecessor(root,search);
                Node *succ=getSuccessor(root,search);
                if(succ==NULL) {
                    printf("%s Incorrect ,Suggestions :%s , %s \n\n",token,search->data, pre->data);
                }
                else if(pre==NULL) {
                    printf("%s Incorrect ,Suggestions :%s , %s \n\n", token, search->data, succ->data);
                }
                else {
                    printf("%s Incorrect ,Suggestions :%s , %s  , %s \n\n",token,search->data, pre->data,succ->data);
                }
                pre=NULL;
                succ=NULL;
            }
            token = strtok(NULL, " ");
        }
        i++;
        free(user);
}
}


#ifndef PROJECT_PROJECT_H
#define PROJECT_PROJECT_H
#endif //PROJECT_PROJECT_H
