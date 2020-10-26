#include<bits/stdc++.h>

#include<string.h>

using namespace std;
struct Node
{
    string tag;
    struct Node *parent,*children[100];
};
//struct Node* parser();
void parser();
void operation1(string tagstr);
void operation(string str);

//void operation1(string str);
//operation(string str);
