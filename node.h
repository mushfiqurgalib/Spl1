#include<string.h>

struct Node
{
    char *tag;
    struct Node *parent,*children[100];
};
struct Node* parser();
int operation();
//operation(string str);
