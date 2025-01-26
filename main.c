#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"
#include "QueueNodes.h"
#include "DisplayFunctions.h"
#include "project.h"

int main() {
    Node *root=NULL;
    root= load(root);
    menu(root);
    root= destruct(root);
    return 0;
}
