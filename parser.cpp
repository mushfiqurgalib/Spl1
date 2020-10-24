/*#include<iostream>
#include<fstream>*/

#include"node.h"
//
using namespace std ;


/*struct Node
{
    string tag ;
    Node *parent,*children[10] ;
};*/
string emptyTagList[] = {"<br>" , "<hr>" , "<img>" , "<input>" , "<link>" , "<meta>" , "<source>"} ;
int flagForEmptyTag = 0 ;

Node *root , *current;
int headcount=0,buttoncount=0,count1=0,linkcount=0;

void createLinkList()
{
    root = NULL ;
    current = NULL ;
}


Node* createNode(string tag)
{

    Node *temp = new Node ;

    temp->tag = tag ;

    for(int i=0 ; i<10 ; i++)
    {
        temp->children[i] = NULL ;
    }
    temp->parent = NULL ;

    return temp ;
}
void lekhalekhi(string s1){
	fstream fork("latex.txt",std::fstream::app);
	string s2 = "{";
	s2+=s1+"}";
	fork<<s2;
}
void insertNode(Node *newNode , int flag)
{
    newNode->parent = current ;
    for(int i=0 ; i<10 ; i++)
    {
        if(current->children[i]==NULL)
        {
            current->children[i] = newNode ;
            if(flag==1) current = newNode ;
            break ;
        }
    }
}

string latex_attr;

void getTagAttributeOrString(Node *current,string tagStr,char ch)
{
    //string *passingPointer = s;

    if(current->tag == tagStr)
    {
        string str ;
        for(int i=0 ; i<10 ; i++)
        {
            if((current->children[i])!=NULL )
            {
                str = current->children[i]->tag ;
                if(str[0]==ch)
                {
                    str.replace(0,1,"") ;

		    latex_attr = str;
		    cout << latex_attr << "\t\t" ;
		    lekhalekhi(latex_attr);
                }
            }

            else return;
        }
    }

    for(int i=0 ; i<10 ; i++)
    {

        if((current->children[i])!=NULL)
        {
            getTagAttributeOrString(current->children[i] ,tagStr , ch);
        }
    }

}

/*string latexAtribute(Node *current,string tagStr,char ch)
{
	getTagAttributeOrString(current, tagStr, ch);
	return latex_attr;
}*/


void operation(string str)
{

fstream newfile;



if(str[0]=='<' && str[1]=='h' && str[2]=='t')
    {

    newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
            newfile<<"\\documentclass{article}"<<endl;
           return;}
            if(str[0]=='<' && str[1]=='t' && str[2]=='i')
            {
                newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
		getTagAttributeOrString(current,"<title>",'~');
    newfile << "\\title"<<latex_attr<<endl;

            }
         /*  if(str[0]=='<' && str[1]=='b' && str[2]=='o')
{newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
    newfile<<"\\begin{article}"<<endl;
 //   return;
}
if(str[0]=='<' && str[1]=='h' && str[2]=='1')
{
    newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
    newfile<<"\\section"<<endl;
}
if(str[0]=='<' && str[1]=='h' && str[2]=='2')
{
    newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
    newfile<<"\\subsection{Heading 2}"<<endl;
}
if(str[0]=='<' && str[1]=='h' && str[2]=='3')
{
    newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
    newfile<<"\\subsubsection{Heading 3}"<<endl;
}
if(str[0]=='<' && str[1]=='h' && str[2]=='4')
{
    newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
    newfile<<"\\paragraph{Heading 4}"<<endl;
}
if(str[0]=='<' && str[1]=='h' && str[2]=='5')
{
    newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
    newfile<<"\\subparagraph{Heading 5}"<<endl;
}
if(str[0]=='<' && str[1]=='h' && str[2]=='6')
{
    newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
    newfile<<"\\subsection{Heading 6}"<<endl;

}
if(str[0]=='<' && str[1]=='u' && str[2]=='l')
{
     newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
     newfile<<"\\begin{itemize}"<<endl;

}
if(str[0]=='<' && str[1]=='l' && str[2]=='i'  && str[3]=='>')
{
     newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
     newfile<<"\\item Coffee"<<endl;
    newfile<<"\\item Tea"<<endl;

     newfile<<"\\item Milk"<<endl;

}
if(str[0]=='<' && str[1]=='/' && str[2]=='u' )
{
     newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
     newfile<<"\\end{itemize}"<<endl;
}
if(str[0]=='<' && str[1]=='o' && str[2]=='l')
{
     newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
     newfile<<"\\begin{enumerate}"<<endl;

}
   if(str[0]=='<' && str[1]=='l' && str[2]=='i'  && str[3]=='>')
{
     newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
     newfile<<"\\item Coffee"<<endl;
    newfile<<"\\item Tea"<<endl;

     newfile<<"\\item Milk"<<endl;

}
if(str[0]=='<' && str[1]=='/' && str[2]=='u' )
{
     newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
     newfile<<"\\end{enumerate}"<<endl;
}
*/
newfile<<"\\end{document)"<<endl;











    cout << current->tag << endl;
    if(str[0]=='<' && str[1]=='h' && str[2]=='e')
    {
        headcount++;
    }
    if(str[0]=='<' && str[1]=='b'  && str[2]=='u')
    {
        buttoncount++;
    }
    if(str[0]=='<' && str[1]=='/')
    {
        count1++;
    }
    if(str[0]=='<' && str[1]=='/'  && str[2]=='a')
    {
        linkcount++;
    }
    if(flagForEmptyTag == 1 &&  str[0] == '<')
    {
        flagForEmptyTag = 0 ;
        current = current->parent ;
    }

    if(str[1]=='/')
    {
        if(current->parent == NULL)
        {
            current = NULL ;
            return ;
        }
        current = current->parent ;

        return ;
    }

    int flag=0 ;

    if(str[0]=='<') flag = 1 ;
    int i ;
    for(i=0 ; i < 7 ; i++)
    {
        if(str.compare(emptyTagList[i])==0)
        {
            flagForEmptyTag = 1 ;
        }
    }

    Node *newNode = createNode(str) ;
    insertNode(newNode,flag) ;
}

void createTreeControl(void)
{

    ifstream iFile ;
    iFile.open("hello.html") ;

    string str = "" ;
    char ch,flag='0' ;

    if(iFile.is_open())
    {


        iFile >> ch ;

        while(ch!='>')
        {
            str=str+ch ;
            iFile >> ch ;
        }
        str=str+ch ;

        root = createNode(str) ;
        //count++;
        current = root ;


        while(current!=NULL)
        {
            if(flag == '0')
                iFile >> ch ;

            else ch = flag ;

            str.clear() ;
            if(ch=='<')
            {
                getline(iFile,str,'>') ;
                str = ch + str + ">" ;

                flag = '0' ;
            }

            else
            {
                getline(iFile,str,'<') ;
                char c = '~';
                str = ch + str ;
                str = c + str ;
                flag = '<' ;
            }

            string s ;
            int flagForTag = 0;
            for(int i = 0 ; i<str.size()-1 && flag=='0' ; i++ )
            {
                s = s + str[i] ;

                if(str[i]==' ' || str[i+1]=='>')
                {
                    if(flagForTag == 0)
                    {
                        if(s[s.size()-1]==' ')
                        {
                            s.replace(s.size()-1,1,">") ;
                        }
                        else s = s + ">" ;
                        flagForTag = 1 ;
                       // count++;
                        operation(s) ;
                      //  operation1(s);
                    }

                    else
                    {
                        char c1 = '!';
                        s = c1 + s ;
                        operation(s) ;
                       // operation1(s);
                    }

                    s.clear() ;
                }
            }

            if(flag == '<') operation(str) ;
           // operation1(str);
        }
    }

    else cout << "Can't open file" << endl ;

}


void getTagParentsChildrensSiblings(Node *current,string tagStr,int flag)
{

    if(current->tag == tagStr)
    {
        if(flag==1)
        {
            if(current->parent!=NULL)
                cout <<tagStr <<"'s parent is" <<current->parent->tag << endl ;
            return ;
        }

        else if(flag==2)
        {
            for(int i=0 ; i<10 && current->children[i]!=NULL ; i++)
            {
                string str = current->children[i]->tag ;
                if(str[0]!='~' && str[0]!='!')
                {
                    cout <<tagStr <<"'s children are"<< str << '\t' ;
                }
            }
        }

        else if(flag==3)
        {

            for(int i=0 ; i<10 && current->parent->children[i]!=NULL ; i++)
            {
                string str = current->parent->children[i]->tag ;
                if(str[0]!='~' && str[0]!='!')
                {
                    cout << str << '\t' ;
                }
            }
        }
    }

    for(int i=0 ; i<10 ; i++)
    {

        if((current->children[i])!=NULL)
        {
            getTagParentsChildrensSiblings(current->children[i] ,tagStr , flag) ;
        }
    }

}


void menu()
{ cout<<"total tag count "<<count1<<endl;
cout<<"total button "<<buttoncount<<endl;
cout<<"total link "<<linkcount<<endl;
    while(true)
    {
        int choice ;

        //  cout<<headcount;

        cout << "\n1.tag's parent\n2.tag's children\n3. tag's sibilings \n4.get tag's attribute\n5.get tag's String \n6.exit" ;
        cin >> choice ;

        string tagStr ;
        cout << "Enter Tag Name : "  ;
        cin >> tagStr ;

        if(choice == 1)
        {
            getTagParentsChildrensSiblings(root , tagStr , 1) ;
        }
        if(choice == 2)
        {
            getTagParentsChildrensSiblings(root , tagStr , 2) ;
        }
        if(choice == 3)
        {
            getTagParentsChildrensSiblings(root , tagStr , 3) ;
        }
        //if(choice == 4);
        if(choice==4)
        {
            getTagAttributeOrString(root,tagStr,'!');
        }
        if(choice==5)
        {

            getTagAttributeOrString(root,tagStr,'~');
        }
        if(choice==6)
            break;

    }

}

void  parser()
{
    createLinkList() ;
    createTreeControl() ;
//     outputTreePreOrder(root) ;

    menu() ;
//    return root;
}
