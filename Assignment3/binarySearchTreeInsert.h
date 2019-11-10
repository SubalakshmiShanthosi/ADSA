#ifndef binary_search_tree
#define binary_search_tree
struct node* createNode(int value);
struct node* insertNode(struct node* aNode,int value);
void printNodes(struct node* root);
int height(struct node* aNode);
int countNodes(struct node* root);
void printLevelOrder(struct node* root,int size);
#endif
