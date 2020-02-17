#include <bits/stdc++.h>
using namespace std;
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
string  headbody;
string bodybody;
string titlebody;

int main()
{
    FILE *htmlsearch;
    htmlsearch = fopen("hello.html","r");
    if(htmlsearch==NULL)
    {
        printf("Error!Cant open file");
        exit(1);
    }
    char  c,bodyc,m;
    string w,cs,t;
    int d =0,f=0,n=0;

    while((c = fgetc(htmlsearch)) != EOF){
        if(c== ' '  || c=='\n'){
            w = w + '\0';
            if(w.at(0)== '<' && w.at(1)== 'h' && w.at(2)== 'e' && w.at(3)== 'a' && w.at(4)=='d' && w.at(5) == '>'){
                d=1;
            }
            else if(w.at(0)== '<' && w.at(1)== '/' && w.at(2)== 'h' && w.at(3)== 'e' && w.at(4)=='a' && w.at(5)=='d' && w.at(6)=='>'){
                break;
            }
            else if(d==1){
                headbody = headbody + w;
            }
            w = "";
        }
        else{
            w = w + c;
        }
    }

    while((bodyc=fgetc(htmlsearch))!=EOF)
    {
        if(bodyc== ' ' || bodyc=='\n')
        {
            cs=cs+'\0';

           if(cs.at(0)=='<' && cs.at(1)=='b' && cs.at(2)=='o' && cs.at(3)=='d' && cs.at(4)=='y' && cs.at(5)=='>')
           {
               f=1;
           }
           else if(cs.at(0)=='<' && cs.at(1)=='/' && cs.at(2)=='b' && cs.at(3)=='o' && cs.at(4)=='d' && cs.at(5)=='y' && cs.at(6)=='>')
           {
               break;
           }
           else if(f==1)
           {
               bodybody=bodybody+cs;
           }
           cs="";
        }
        else {
            cs =cs+bodyc;

        }
    }



 for(int i=0;i<strlen(headbody);i++)
    {
        if(i== ' ' || i=='\n')
        {
            t=t+'\0';

        if(t.at(0)=='<' && t.at(1)=='t' && t.at(2)=='i' && t.at(3)=='t' && t.at(4)=='l' && t.at(5)=='e' && t.at(6)=='>')
        {
           n=1;
        }
        else if(t.at(0)=='<' && t.at(1)=='/' && t.at(2)=='t' && t.at(3)=='i' && t.at(4)=='t' && t.at(5)=='l' && t.at(6)=='e' && t.at(7)=='>')
        {
            break;
        }
        else if(n==1)
        {
            titlebody=titlebody+t;
        }
        t="";
        }



        else{ t=t+m;
    }}

    cout << headbody<<endl;
    cout << bodybody<<endl;
    cout<<titlebody<<endl;



    fclose(htmlsearch);

}
