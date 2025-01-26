typedef struct {
    int front,rear,numberitems;
    int capacity;
    Node** n;    //array of pointer to nodes
}Queue;
Queue *initQ(long long x)
{
    Queue *q= malloc(sizeof (Queue));
    q->capacity=x;
    q->n= malloc(x*sizeof (Node));
    q->front=0;
    q->rear=0;
    q->numberitems=0;
    return q;
}
int isempty(Queue *q)
{
    if(q->numberitems==0)
    {
        q->front=0;
        q->rear=0;
        return 1;
    }
    return 0;
}
int isfull(Queue *q)
{
    if(q->numberitems ==q->capacity)
        return 1;
    return 0;
}
void enqueue(Queue *q,Node *x)
{
    if(isfull(q))
    {
        printf("Queue is full \n");
        return;
    }

    q->n[q->rear]=x;
    q->rear=  (q->rear+1) % q->capacity;
    q->numberitems++;
}
Node *dequeue(Queue *q)
{
    if(isempty(q))
    {
        printf("Queue is empty\n");
        return NULL;
    }
   Node *data =q->n[q->front];
    q->front=(q->front+1) % q->capacity;
    q->numberitems --;
    return data;
}
Node *front(Queue *q)
{
    return q->n[q->front];
}
void FreeBTS(Node *root)
{
    if(root==NULL)
        return ;
    long long x= pow(2, height(root)+1)-1 ;
    Queue *q= initQ(x);
    enqueue(q,root);
    while (!isempty(q))
    {
        Node *curr=NULL;
        curr=  dequeue(q);
        if(curr->left!=NULL)
            enqueue(q,curr->left);
        if(curr->right!=NULL)
            enqueue(q,curr->right);

        free(curr->data); //free the malloced string
        free(curr);       //free the node itself
        curr=NULL;
    }
    root=NULL;
}
#ifndef TREE_QUEUENODES_H
#define TREE_QUEUENODES_H
#endif //TREE_QUEUENODES_H
