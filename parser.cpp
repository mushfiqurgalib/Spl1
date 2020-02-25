#include <bits/stdc++.h>
using namespace std;
#include <stack>
#include <string.h>
#include <algorithm>
#include<stdlib.h>
#include<stdbool.h>
#include"node.h"

using namespace std;
string  headbody;
string bodybody;
string titlebody;

struct Node *root,*current;

void createLinkList()
{
    root=NULL;
    current=NULL;
}

struct Node* createNode(char *tag)
{

    struct Node* temp;
    // struct Node  *temp=malloc(sizeof(struct Node));
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->tag=tag;
    //temp->tag=tag;
    int i=0;
    for(i=0; i<100; i++)
    {
        temp->children[i]=NULL;

    }
    temp->parent=NULL;
    return temp;

}

void insertNode(struct Node *newNode , int flag)
{
    newNode->parent = current ;
    int i = 0 ;
    for(i=0 ; i<100 ; i++){
        if(current->children[i]==NULL)
        {
            current->children[i] = newNode ;
            if(flag==1) current = newNode ;
            break ;
        }
    }
}

void outputTreePreOrder(Node *parent)
{
   printf("%s\n",parent->tag);

    for(int i=0 ; i<100 ; i++){

        if((parent->children[i])!=NULL)
        {
            outputTreePreOrder(parent->children[i]) ;
        }
    }
}

void operation(char *str)
{
    printf("%s\n",str);

 /*   if(str[1]=='/')
    {
        if(current->parent==NULL)
            current=NULL;
            return;
    }
    current=current->parent;
    return;

    int flag;

    if(str[0]=='<')
        flag=1;
    Node *newNode=createNode(str);
    insertNode(newNode,flag);*/
   /* if(str[0]=='<' || str[0]=='~')
    {
        current=current->parent;
    }

    if(root==NULL)
    {
        struct Node *newNode=createNode(str);
        root=newNode;
        current=newNode;
        return;
    }
        int f=0;
        if(str[0]=='<')
            f=1;
      //  printf("%s",current->tag);
        struct Node *newNode=createNode(str);
        insertNode(newNode,f);
       // printf("%s",current->tag);*/


  //  return;
}

void createtreecontrol()
{
    FILE *htmlsearch;
    if((htmlsearch=fopen("hello.html","r"))==NULL)
    {
        printf("Error!Cant open file");
        exit(1);
    }
    char str[10000],ch,flag;
    int s1=0,flagattribute=-1,iter;

    fscanf(htmlsearch,"%c",&ch);
    while(ch!='>')
    {
        while(ch!='>' && ch!=' ')
        {
            str[s1]=ch;
            s1++;
            fscanf(htmlsearch,"%c",&ch);
        }

        if(flagattribute==-1)
        {
            str[s1]='>';
            str[s1+1]='\0';
        }
        else str[s1]='\0';

        char *htmlstring=(char*)malloc(100);

        for( iter=0; iter<strlen(str); iter++)
        {
            htmlstring[iter]=str[iter];
        }
        htmlstring[iter]='\0';
        operation(htmlstring);

        if(ch==' ')
        {
            flagattribute=1;
            fscanf(htmlsearch,"%c",ch);
            s1=0;
            memset(str,0,sizeof(str));
            str[s1]='!';
            s1++;
        }
    }

    char laststr[]="<1html>";

    while(strcmp(laststr,"</html>"))
    {
        if(flag=='0')
        {
            fscanf(htmlsearch,"%c",&ch);
            if(ch=='>')
            {
                fscanf(htmlsearch,"%c",&ch);
            }


            if(ch=='\n' || ch==' ' || ch=='\t')continue;
        }
        else ch=flag;

        int k;
        for(k=strlen(str)-1; k>=0; k--)
        {
            str[k]='\0';
        }

        if(ch=='<')
        {
            fscanf(htmlsearch,"%[^>]s",&str);
            int i,j,doublesign=0;

            if(str[0]==ch)
                doublesign=1;

            for(i=strlen(str);i>0 && doublesign==0;i--)
            {
                str[i]=str[i-1];
            }

            str[0]=ch;
            str[strlen(str)]='>';
            str[strlen(str)+1]='\0';

            flag='0';

        }
        else
        {
            fscanf(htmlsearch,"%[^<]s",&str);
           char c='~';
            for(int i=strlen(str)+1;i>1;i--)
            {
                str[i]=str[i-2];
            }
            str[1]=ch;
            str[0]=c;
            flag='<';
            str[strlen(str)+1]='\0';

            printf("%s\n",str);

        }

        char s[100];
        int flagtag=0,flagtag2=0;
        int i,s2=0;

        for(i=0;i<strlen(str)-1 && flag=='0';i++)
        {
            s[s2]=str[i];
            s2++;
            s[s2]='\0';
            if(str[i]==' ' || str[i+1]=='>')
            {
                if(flagtag==0)
                {
                    if(s[s2-1]==' ')
                    {
                        s[s2-1]='>';
                        s[s2]='\0';
                    }
                    else
                    {
                        s[s2]='>';
                        s[s2+1]='\0';
                    }

                    flagtag=1;

                    for(k=0;k<7;k++)
                    {
                        laststr[k]=s[k];
                    }

                    char *htmlstring=(char*)malloc(100);

                    for(iter=0;iter<strlen(s);iter++)
                    {
                        htmlstring[iter]=s[iter];
                    }
                    htmlstring[iter]='\0';
                    operation(htmlstring);



                }
                else{

                    char c1='!';
                    for(int z=strlen(s);z>0;z--)
                    {
                        s[z]=s[z-1];
                    }
                    s[0]=c1;

                    char *htmlstring=(char*)malloc(100);

                    for(iter=0;iter<strlen(s);iter++)
                    {
                        htmlstring[iter]=s[iter];
                    }

                    if(htmlstring[iter-1]==' ')
                    {
                        htmlstring[iter-1]='\0';
                    }
                    else htmlstring[iter]='\0';

                    operation(htmlstring);

                    memset(s,0,sizeof(s));
                    s2=0;
                }
            }
        }

    }

}

void getTagAttributeOrString(Node *current,string tagStr,char ch){

    if(current->tag == tagStr){
        string str ;
        for(int i=0 ; i<10 ; i++){
            if((current->children[i])!=NULL )
            {
                str = current->children[i]->tag ;
                if(str[0]==ch){
                    str.replace(0,1,"") ;
                    cout << str << "\t\t" ;
                }
            }

            else return ;
        }
    }

    for(int i=0 ; i<10 ; i++){

        if((current->children[i])!=NULL)
        {
            getTagAttributeOrString(current->children[i] ,tagStr , ch) ;
        }
    }

}

void menu(){
    while(true){
        int choice ;
        cout << "\nEnter Your Choice \n1.find tag\n2.get tag's attribute\n3.get tag's String\n4.get tag's parents\n5.get tag's childrens\n6.get tag's sublings\n7. exit \n " ;
        cin >> choice ;

        string tagStr ;
        cout << "Enter Tag Name : "  ;
        cin >> tagStr ;

        if(choice == 1) ;//findTag() ;
        if(choice == 2){
            getTagAttributeOrString(root,tagStr,'!') ;
        }

        if(choice == 3){
            getTagAttributeOrString(root,tagStr,'~') ;
        }

        if(choice == 4){
         //   getTagParentsChildreansSublings(root , tagStr , 1) ;
        }
        if(choice == 5){
//            getTagParentsChildreansSublings(root , tagStr , 2) ;
        }
        if(choice == 6){
//            getTagParentsChildreansSublings(root , tagStr , 3) ;
        }
        if(choice == 7) break;

    }

}


struct Node* parser()
{
    createLinkList();
    createtreecontrol();
     outputTreePreOrder(root) ;
     menu();

   // return root;
}


/* cout << headbody<<endl;
 cout << bodybody<<endl;
 cout<<titlebody<<endl;*/



//fclose(htmlsearch);

//}

