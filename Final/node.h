#include<bits/stdc++.h>

#include<string.h>

using namespace std;
struct Node
{
    string tag;
    bool isprint1;

   Node *parent,*children[40];

   Node (){


           isprint1=false;}
};
//struct Node* parser();
int gethtml();
void parser();
void operation1(string tagstr);
void operation(string str);

//void operation1(string str);
//operation(string str);
