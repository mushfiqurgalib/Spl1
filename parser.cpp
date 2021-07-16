/*#include<iostream>
#include<fstream>*/
#include<string>
#include"node.h"
//
using namespace std ;


/*struct Node
{
    string tag ;
    Node *parent,*children[10] ;
};*/
string emptyTagList[] = {"<br>", "<hr>", "<img>", "<input>", "<link>", "<meta>", "<source>"} ;
int flagForEmptyTag = 0 ;
fstream newfile;
 string tabinitial="\\begin{tabular}\n {c c c }";


Node *root, *current;
int headcount=0,buttoncount=0,count1=0,linkcount=0,colcount=0;

void createLinkList()
{
    root = NULL ;
    current = NULL ;
}


Node* createNode(string tag)
{

    Node *temp = new Node ;

    temp->tag = tag ;

    for(int i=0 ; i<20 ; i++)
    {
        temp->children[i] = NULL ;
    }
    temp->parent = NULL ;

    return temp ;
}
void insertNode(Node *newNode , int flag)
{
    newNode->parent = current ;
    for(int i=0 ; i<20 ; i++)
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
void operation1(string tag)
{

//   fstream newfile;

 if(tag[0]=='<' && tag[1]=='h' && tag[2]=='2')
    {
        //newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
        fstream fork("latex.tex",std::fstream::app);
        fork<<"\\subsection*"<<endl;
    }
if(tag[0]=='<' && tag[1]=='h' && tag[2]=='1')
    {
        //newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
          fstream fork("latex.tex",std::fstream::app);
        fork<<"\\section*"<<endl;

    }
      if(tag[0]=='<' && tag[1]=='a' && tag[2]=='>')
    {
         fstream fork2("latex.tex",std::fstream::app);
        fork2<<"\\"<<endl;
    }
     if(tag[0]=='<' && tag[1]=='s' && tag[2]=='u' && tag[3]=='p')
    {
        fstream fork("latex.tex",std::fstream::app);
        fork<<"\\textsuperscript"<<endl;

    }

if(tag[0]=='<' && tag[1]=='h' && tag[2]=='3')
    {
         fstream fork("latex.tex",std::fstream::app);
        fork<<"\\subsubsection*"<<endl;

    }

    if(tag[0]=='<' && tag[1]=='h' && tag[2]=='4')
    {
         fstream fork("latex.tex",std::fstream::app);
        fork<<"\\paragraph"<<endl;

    }
    if(tag[0]=='<' && tag[1]=='h' && tag[2]=='5')
    {
         fstream fork("latex.tex",std::fstream::app);
        fork<<"\\subparagraph"<<endl;

    }

    if(tag[0]=='<' && tag[1]=='h' && tag[2]=='6')
    {
         fstream fork("latex.tex",std::fstream::app);
        fork<<"\\subsection*"<<endl;

    }

    if(tag[0]=='<' && tag[1]=='i')
    {
         fstream fork("latex.tex",std::fstream::app);
        fork<<"\\itshape"<<endl;

    }
    if(tag[0]=='<' && tag[1]=='b' && tag[2]=='>')
    {
         fstream fork("latex.tex",std::fstream::app);
        fork<<"\\bfseries"<<endl;

    }
    if(tag[0]=='<' && tag[1]=='e' && tag[2]=='m')
    {
         fstream fork("latex.tex",std::fstream::app);
        fork<<"\\emph"<<endl;

    }

      if(tag[0]=='<' && tag[1]=='u' && tag[2]=='>')
    {
         fstream fork("latex.tex",std::fstream::app);
        fork<<"\\underline"<<endl;

    }

     if(tag[0]=='<' && tag[1]=='s' && tag[2]=='u' && tag[3]=='b')
    {
        fstream fork("latex.tex",std::fstream::app);
        fork<<"\\textsubscript"<<endl;

    }
    if(tag[0]=='<' && tag[1]=='p' && tag[2]=='>')
    {
        // newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
        fstream fork("latex.tex",std::fstream::app);
        fork<<"\\\\"<<endl;

    }
/*

    if(tagstr[0]=='<' && tagstr[1]=='i')
    {
        // newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
        newfile<<"\\itshape"<<endl;
    }
    if(tagstr[0]=='<' && tagstr[1]=='b' && tagstr[2]=='>')
    {
        // newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
        newfile<<"\\bfseries"<<endl;
    }
    if(tagstr[0]=='<' && tagstr[1]=='e' && tagstr[2]=='m')
    {
        // newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
        newfile<<"\\emph"<<endl;
    }

    if(tagstr[0]=='<' && tagstr[1]=='u' && tagstr[2]=='>')
    {
        // newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
        newfile<<"\\underline"<<endl;
    }

    if(tagstr[0]=='<' && tagstr[1]=='s' && tagstr[2]=='u' && tagstr[3]=='b')
    {
        // newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
        newfile<<"\\textsubscript"<<endl;
    }

    if(tagstr[0]=='<' && tagstr[1]=='i' && tagstr[2]=='m' && tagstr[3]=='g')
    {
        newfile<<"\\includegraphics"<<endl;
    }
    if(tagstr[0]=='<' && tagstr[1]=='l' && tagstr[2]=='i' && tagstr[3]=='>')
    {
        // newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
        newfile<<"\\begin{itemize}"<<endl;



        newfile<<"\\item"<<endl;

        newfile<<"\\end{itemize}"<<endl;
    }



    /* if(str[0]=='<' && str[1]=='t' && str[2]=='i')
     {
         newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
         getTagAttributeOrString(current,"<title>",'~');
         newfile << "\\title"<<latex_attr<<endl;
     }
      if(str[0]=='<' && str[1]=='b' && str[2]=='o')
     {newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
     //   return;
     }/*
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
     }
     */








}

void lekhalekhi5(string s1)
{
    fstream fork4("latex.txt",std::fstream::app);


    fork4<<tabinitial+s1+"\\end{tabular}";

}
void lekhalekhi4(string s1)
{
    fstream fork3("latex.tex",std::fstream::app);
    string s2 = "\\includegraphics";
    int afk=s1.size();
    s1.replace(afk-1,1,"}");
    s1.replace(afk-2,1,"");
    s1.replace(afk-3,1,"");
    s1.replace(afk-4,1,"");
    s1.replace(afk-5,1,"");
    s1.replace(0,1,"");
    s1.replace(1,1,"");
    s1.replace(2,1,"");
    s1.replace(0,1,"");
    s1.replace(0,1,"{");

    s2+=s1;
    fork3<<s2;
}
void lekhalekhi3(string s1)
{
    int axx;
    axx=s1.size();
    //cout<<axx;
    fstream fork2("latex.tex",std::fstream::app);
    string s2="\\";
    s1.replace(5,1,"{");
    s1.replace(4,1," ");
    s1.replace(axx-1,1,"");
    // s1.replace(s1.end()-2,1,"");
   string  s3="";//"{This is a link}";
    s2+=s1+'}'+s3;
    fork2<<s2;
}
void lekhalekhi6(string s1)
{
    int axx1;
    axx1=s1.size();
    //cout<<axx;
    fstream fork6("latex.tex",std::fstream::app);
    string s2="\\";
    s1.replace(0,1,"");
    s1.replace(1,1,"{");
    s1.replace(axx1-2,1,"}");
    //s1.replace(axx-1,1,"");
    // s1.replace(s1.end()-2,1,"");
  // string  s3="{This is a link}";
    s2+=s1+'}';
    fork6<<s2;
}

void lekhalekhi(string s1)
{
    fstream fork("latex.tex",std::fstream::app);
    string s2 = "{";
    s2+=s1+"}";
    fork<<s2;
    fork<<"\\\\";

}

void lekhalekhi7(string s1)
{
    fstream fork("latex.tex",std::fstream::app);
    string s2 = "{";
    s2+=s1+"}";
    fork<<s2;

}
void lekhalekhi2()
{
    fstream fork1("latex.tex",std::fstream::app);
    fork1<<"\\end{document}";
}
/*void insertNode(Node *newNode, int flag)
{
    newNode->parent = current ;
    for(int i=0 ; i<20 ; i++)
    {
        if(current->children[i]==NULL)
        {
            current->children[i] = newNode ;
            if(flag==1)
                current = newNode ;
            break ;
        }
    }
}*/




void getTagAttributeOrString(Node *current,string tagStr,char ch)
{
    //string *passingPointer = s;

    if(current->tag == tagStr)
    {
        string str ;
        for(int i=0 ; i<20 ; i++)
        {
            if((current->children[i])!=NULL )
            {
                str = current->children[i]->tag ;
                if(str[0]==ch)
                {

                    string latex_attr_spcl=str;
                    str.replace(0,1,"") ;

                    latex_attr = str;
                   // cout << latex_attr << "\t\t" ;
                    if(tagStr[0]=='<' && tagStr[1]=='a' && tagStr[2]=='>' && latex_attr_spcl[0]=='!' && latex_attr_spcl[1]=='h')
                    {
                        //operation1(str);
                        lekhalekhi3(latex_attr);
                    }
                  /*  if(tagStr[0]=='<' && tagStr[1]=='a' && tagStr[2]=='>' && latex_attr_spcl[0]=='~')
                    {
                        //operation1(str);
                        lekhalekhi6(latex_attr_spcl);
                    }*/
                    else if(tagStr[0]=='<' && tagStr[1]=='i' && tagStr[2]=='m')
                    {
                        lekhalekhi4(latex_attr);
                    }
                    else if(tagStr[0]=='<' && tagStr[1]=='h')
                    {
                        lekhalekhi7(latex_attr);
                    }

                    else if(tagStr[0]=='<' && tagStr[1]=='t' && tagStr[2]=='d')
                    {
                        lekhalekhi5(latex_attr);
                    }
                    else
                    {


                        lekhalekhi(latex_attr);
                    }
                }
            }

            else
                return;
        }
    }

    for(int i=0 ; i<20 ; i++)
    {

        if((current->children[i])!=NULL)
        {
            getTagAttributeOrString(current->children[i],tagStr, ch);
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




    if(str[0]=='<' && str[1]=='h' && str[2]=='t')
    {

        newfile.open("latex.tex",std::fstream::in | std::fstream::out | std::fstream::app);
        newfile<<"\\documentclass{article}"<<endl;
        newfile<<"\\usepackage{hyperref}"<<endl;
        newfile<<"\\usepackage{graphicx}"<<endl;
        newfile<<"\\usepackage{tabularx}"<<endl;
        newfile<<"\\begin{document}"<<endl;
        return;
    }
   // cout << current->tag << endl;
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
    if(str[0]=='<' && str[1]=='t' && str[2]=='r')
    {
        colcount++;
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

    if(str[0]=='<')
        flag = 1 ;
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
    iFile.open("b.html") ;

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

            else
                ch = flag ;

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
                        else
                            s = s + ">" ;
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

            if(flag == '<')
                operation(str) ;
            // operation1(str);
        }
    }

    else
        cout << "Can't open file" << endl ;

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
            getTagParentsChildrensSiblings(current->children[i],tagStr, flag) ;
        }
    }

}


void menu()
{
    cout<<"total tag count "<<count1<<endl;
    cout<<"total button "<<buttoncount<<endl;
    cout<<"total column "<<colcount<<endl;
    cout<<"total link "<<linkcount<<endl;
    while(true)
    {
        int choice ;

        //  cout<<headcount;

        cout << "\n1.tag's parent\n2.tag's children\n3. tag's sibilings \n4.To get latex part of empty html tags\n5.To get latex part of other tag's String \n6.exit \n" ;
        cin >> choice ;
        if(choice==6)
        {
            lekhalekhi2();
            return;
        }
        string tagStr ;
        cout << "Enter Tag Name : "  ;
        cin >> tagStr ;

        if(choice == 1)
        {
            getTagParentsChildrensSiblings(root, tagStr, 1) ;
        }
        if(choice == 2)
        {
            getTagParentsChildrensSiblings(root, tagStr, 2) ;
        }
        if(choice == 3)
        {
            getTagParentsChildrensSiblings(root, tagStr, 3) ;
        }
        //if(choice == 4);
        if(choice==4)
        {
            //getTagAttributeOrString(root,tagStr,'!');
        }
        if(choice==5)
        {


            operation1(tagStr);

           // getTagAttributeOrString(root,tagStr,'~');

        }


    }

}
void outputTreePreOrder(Node *parent)
{
    cout << parent->tag << endl ;
    string tag=parent->tag;
    if(tag=="<a>")
    {
        getTagAttributeOrString(root,tag,'!');

          getTagAttributeOrString(root,tag,'~');

    }
    else{
    //cout<<tag<<endl;
    operation1(tag);

          getTagAttributeOrString(root,parent->tag,'~');}
    for(int i=0 ; i<20 ; i++){

        if((parent->children[i])!=NULL)
        {
            outputTreePreOrder(parent->children[i]) ;
        }
    }
}

void  parser()
{
    createLinkList() ;
    createTreeControl() ;
    outputTreePreOrder(root) ;

    menu() ;
//    return root;
}
