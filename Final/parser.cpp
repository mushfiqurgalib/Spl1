/*#include<iostream>
#include<fstream>*/
#include<string>
#include<map>
#include"node.h"
//
using namespace std ;
int cnt;
int htmlcounter;
/*struct Node
{
    string tag ;
    Node *parent,*children[10] ;
};*/
string emptyTagList[] = {"<br>", "<hr>", "<img>", "<input>", "<link>", "<meta>", "<source>"} ;
int flagForEmptyTag = 0 ;
fstream newfile;
string insert_slash(string str)
{
    string returnVal = "";

    for (int i=0; i<str.length(); ++i)
    {
        if (str[i] == '%')
            returnVal += "\\%";
        else
            returnVal += str[i];
    }

    return returnVal;
}

map<string,int>mp;  //map to keep unusual HTML tags

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

    for(int i=0 ; i<40 ; i++)
    {
        temp->children[i] = NULL ;
    }
    temp->parent = NULL ;

    return temp ;
}
void insertNode(Node *newNode, int flag)
{
    newNode->parent = current ;
    for(int i=0 ; i<40 ; i++)
    {
        /*if(current==NULL)

        {break;}*/
        if(current->children[i]==NULL)
        {
            current->children[i] = newNode ;
            if(flag==1)
                current = newNode ;
            break ;
        }
    }
}


string latex_attr;
void operation1(string tag)
{



    if(tag[0]=='<' && tag[1]=='h' && tag[2]=='2')
    {

        fstream fork("latex.txt",std::fstream::app);
        fork<<"\\subsection*"<<endl;
    }
    if(tag[0]=='<' && tag[1]=='h' && tag[2]=='1')
    {
        fstream fork("latex.txt",std::fstream::app);
        fork<<"\\section*"<<endl;

    }
    if(tag[0]=='<' && tag[1]=='a' && tag[2]=='>')
    {
        fstream fork2("latex.txt",std::fstream::app);
        fork2<<"\\\\"<<endl;
    }
    if(tag[0]=='<' && tag[1]=='s' && tag[2]=='u' && tag[3]=='p')
    {
        fstream fork("latex.txt",std::fstream::app);
        fork<<"\\textsuperscript"<<endl;

    }

    if(tag[0]=='<' && tag[1]=='h' && tag[2]=='3')
    {
        fstream fork("latex.txt",std::fstream::app);
        fork<<"\\subsubsection*"<<endl;

    }

    if(tag[0]=='<' && tag[1]=='h' && tag[2]=='4')
    {
        fstream fork("latex.txt",std::fstream::app);
        fork<<"\\paragraph"<<endl;

    }
    if(tag[0]=='<' && tag[1]=='h' && tag[2]=='5')
    {
        fstream fork("latex.txt",std::fstream::app);
        fork<<"\\subparagraph"<<endl;

    }

    if(tag[0]=='<' && tag[1]=='h' && tag[2]=='6')
    {
        fstream fork("latex.txt",std::fstream::app);
        fork<<"\\subsection*"<<endl;

    }

    if(tag[0]=='<' && tag[1]=='i' && tag[2]=='>')
    {
        fstream fork("latex.txt",std::fstream::app);
        fork<<"\\itshape"<<endl;

    }
    if(tag[0]=='<' && tag[1]=='b' && tag[2]=='>')
    {
        fstream fork("latex.txt",std::fstream::app);
        fork<<"\\bfseries"<<endl;

    }
    if(tag[0]=='<' && tag[1]=='e' && tag[2]=='m')
    {
        fstream fork("latex.txt",std::fstream::app);
        fork<<"\\emph"<<endl;

    }

    if(tag[0]=='<' && tag[1]=='u' && tag[2]=='>')
    {
        fstream fork("latex.txt",std::fstream::app);
        fork<<"\\underline"<<endl;

    }

    if(tag[0]=='<' && tag[1]=='s' && tag[2]=='u' && tag[3]=='b')
    {
        fstream fork("latex.txt",std::fstream::app);
        fork<<"\\textsubscript"<<endl;

    }
    if(tag[0]=='<' && tag[1]=='p' && tag[2]=='>')
    {

        fstream fork("latex.txt",std::fstream::app);
        fork<<"\\\\"<<endl;

    }








}

void lekhalekhi5(string s1)
{
    fstream fork4("latex.txt",std::fstream::app);




}
//function to convert images
void lekhalekhi4(string s1)
{
    fstream fork3("latex.txt",std::fstream::app);
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
//function to convert link
void lekhalekhi3(string s1)
{
    int axx;
    axx=s1.size();
    //cout<<axx;
    fstream fork2("latex.txt",std::fstream::app);
    string s2="\\";
    string s4="\\\\";
    s1.replace(5,1,"{");
    s1.replace(4,1," ");
    s1.replace(axx-1,1,"");
    // s1.replace(s1.end()-2,1,"");
    string  s3="";//"{This is a link}";
    s2+=s4+s1+'}'+s3;
    fork2<<s2;
    //s1.erase();
}
void lekhalekhi6(string s1)
{
    int axx1;
    axx1=s1.size();
    //cout<<axx;
    fstream fork6("latex.txt",std::fstream::app);
    string s2="";
    s1.replace(0,1,"{");
    //s1.replace(1,1,"{");
    // s1.replace(axx1-1,1,"}");
    //s1.replace(axx-1,1,"");
    // s1.replace(s1.end()-2,1,"");
    // string  s3="{This is a link}";
    s2+=s1+'}';
    fork6<<s2;
}

void lekhalekhi(string s1)
{
    fstream fork("latex.txt",std::fstream::app);
    string s2 = "{";
    s2+=s1+"}";
    fork<<s2;
    // fork<<"\\\\";

}
void lekhalekhi8(string s1)
{
    fstream fork("latex.txt",std::fstream::app);

    s1.erase();

}

void lekhalekhi7(string s1)
{
    fstream fork("latex.txt",std::fstream::app);
    string s2 = "{";
    s2+=s1+"}";
    fork<<s2;

}
void lekhalekhi2()
{
    // fstream fork("latex.txt",std::fstream::app);
    //fork<<"\\end{document}";
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
        for(int i=0 ; i<40 ; i++)
        {
            if((current->children[i])!=NULL )
            {
                str = current->children[i]->tag ;
                if(str[0]==ch && current->children[i]->isprint1==false)
                {
                    current->children[i]->isprint1=true;
                    string latex_attr_spcl=str;
                    str.replace(0,1,"") ;

                    latex_attr = str;
                    // cout << latex_attr << "\t\t" ;

                    if(tagStr[0]=='<' && tagStr[1]=='a' && tagStr[2]=='>' && latex_attr_spcl[0]=='!' && latex_attr_spcl[1]=='h')
                    {
                        //operation1(str);
                        lekhalekhi3(latex_attr);
                        // cout<<latex_attr<<"wow";
                        string ass=latex_attr.erase();
                        //cout<<ass<<"delete";

                        lekhalekhi8(ass);

                    }
                    else if(tagStr[0]=='<' && tagStr[1]=='a' && tagStr[2]=='>' && latex_attr_spcl[0]=='~')
                    {
                        //operation1(str);
                        //   cout<<"Here it is";
                        lekhalekhi6(latex_attr_spcl);
                    }
                    else if(tagStr[0]=='<' && tagStr[1]=='i' && tagStr[2]=='m')
                    {
                        lekhalekhi4(latex_attr);
                    }
                    else if(tagStr[0]=='<' && tagStr[1]=='h')
                    {
                        lekhalekhi7(latex_attr);
                    }
                    else if(tagStr[0]=='<' && tagStr[1]=='p' && tagStr[2]=='>' && latex_attr_spcl[0]=='~' && latex_attr_spcl[1]=='&')
                    {
                        //operation1(str);
                        lekhalekhi8(latex_attr);
                    }

                    else if(tagStr[0]=='<' && tagStr[1]=='p' && tagStr[2]=='>' && latex_attr_spcl[0]=='!' && latex_attr_spcl[1]=='s' && latex_attr_spcl[2]=='t')
                    {
                        //operation1(str);
                        lekhalekhi8(latex_attr);
                    }
                    else if(tagStr[0]=='<' && tagStr[1]=='a' && tagStr[2]=='>' && latex_attr_spcl[0]=='~' && latex_attr_spcl[1]=='&')
                    {
                        //operation1(str);
                        lekhalekhi8(latex_attr);
                    }

                    else if(tagStr[0]=='<' && tagStr[1]=='a' && tagStr[2]=='>' && latex_attr_spcl[0]=='!' && latex_attr_spcl[1]=='c')
                    {
                        //operation1(str);
                        lekhalekhi8(latex_attr);
                    }
                    else if(tagStr[0]=='<' && tagStr[1]=='a' && tagStr[2]=='>' && latex_attr_spcl[0]=='!' && latex_attr_spcl[1]=='m')
                    {
                        //operation1(str);
                        lekhalekhi8(latex_attr);
                    }
                    else if(tagStr[0]=='<' && tagStr[1]=='a' && tagStr[2]=='>' && latex_attr_spcl[0]=='!' && latex_attr_spcl[1]=='i' && latex_attr_spcl[2]=='d')
                    {
                        //operation1(str);
                        lekhalekhi8(latex_attr);
                    }
                    else if(tagStr[0]=='<' && tagStr[1]=='a' && tagStr[2]=='>' && latex_attr_spcl[0]=='!' && latex_attr_spcl[1]=='t')
                    {
                        //operation1(str);
                        lekhalekhi8(latex_attr);
                    }


                    else if(tagStr[0]=='<' && tagStr[1]=='s' && tagStr[2]=='c')
                    {
                        lekhalekhi8(latex_attr);
                    }
                    else if(tagStr[0]=='<' && tagStr[1]=='d' && tagStr[2]=='i')
                    {
                        lekhalekhi8(latex_attr);
                    }


                    else if(tagStr[0]=='<' && tagStr[1]=='s' && tagStr[2]=='t')
                    {
                        lekhalekhi8(latex_attr);
                    }
                    else if(tagStr[0]=='<' && tagStr[1]=='t' && tagStr[2]=='d')
                    {
                        lekhalekhi5(latex_attr);
                    }

                    /*  else if(tagStr[0]=='<' && tagStr[1]=='p' && tagStr[2]=='>')
                      {
                            lekhalekhi(latex_attr);
                      }*/
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

    for(int i=0 ; i<40 ; i++)
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



//To count tag numbers
void operation(string str)
{




    if(str[0]=='<' && str[1]=='h' && str[2]=='t' )
    {

        /* newfile.open("latex.txt",std::fstream::in | std::fstream::out | std::fstream::app);
         newfile<<"\\documentclass{article}"<<endl;
         newfile<<"\\usepackage{hyperref}"<<endl;
         newfile<<"\\usepackage{graphicx}"<<endl;
         newfile<<"\\usepackage{tabularx}"<<endl;
         newfile<<"\\begin{document}"<<endl;*/
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
    if(flagForEmptyTag == 1 &&  str[0] == '<')
    {

        flagForEmptyTag = 0 ;
        if(current->parent!=NULL)
            current = current->parent ;
    }

    Node *newNode = createNode(str) ;
    insertNode(newNode,flag) ;
}
void cssOperation(char *str,int cssFlagForSelectParent)
{
    //printf("String:%s\n",str) ;
    //printf("Pre Current3:\t\t%s\n" ,current->tag);
    int flag ;
    if(cssFlagForSelectParent==1)
    {
        flag = 1 ;
        struct Node *newNode = createNode(str) ;
        insertNode(newNode,flag) ;
    }

    else if(cssFlagForSelectParent==2)
    {
        flag = 1 ;
        struct Node *newNode = createNode(str) ;
        insertNode(newNode,flag) ;
    }

    else if(cssFlagForSelectParent==3)
    {
        flag = 0 ;
        struct Node *newNode = createNode(str) ;
        insertNode(newNode,flag) ;
        current = current->parent   ;
    }

    else if(cssFlagForSelectParent==4)
    {
        flag = 0 ;
        struct Node *newNode = createNode(str) ;
        insertNode(newNode,flag) ;
        current = current->parent   ;
        current = current->parent   ;
    }
    //printf("Post Current4:\t\t%s\n" ,current->tag);

    return  ;
}
//To create tree of a HTML file
void createTreeControl(void)
{

    ifstream iFile ;
    iFile.open("b.html") ;

    string str = "" ;
    char ch,flag='0' ;

    if(iFile.is_open())
    {


        iFile >> ch ;

        while(ch!='>') //read tag from a html page
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
                getline(iFile,str,'>') ; //read a full tag
                str = ch + str + ">" ;

                flag = '0' ;
            }

            else
            {
                getline(iFile,str,'<') ; // read a full string element
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

//to get a tag's parent,children and siblings
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
            for(int i=0 ; i<40 && current->children[i]!=NULL ; i++)
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

            for(int i=0 ; i<40 && current->parent->children[i]!=NULL ; i++)
            {
                string str = current->parent->children[i]->tag ;
                if(str[0]!='~' && str[0]!='!')
                {
                    cout << str << '\t' ;
                }
            }
        }
    }

    for(int i=0 ; i<40 ; i++)
    {

        if((current->children[i])!=NULL)
        {
            getTagParentsChildrensSiblings(current->children[i],tagStr, flag) ;
        }
    }

}

//Menu
void menu()
{
    cout<<"total tag count "<<count1<<endl;
    //cout<<"total button "<<buttoncount<<endl;
    // cout<<"total column "<<colcount<<endl;
    cout<<"total link "<<linkcount<<endl;
    while(true)
    {
        int choice ;



        cout << "\n1.tag's parent\n2.tag's children\n3. tag's sibilings \n6.Convert into LaTeX \n" ;
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

        if(choice==4)
        {
            //getTagAttributeOrString(root,tagStr,'!');
        }
        if(choice==5)
        {


            //operation1(tagStr);



        }


    }

}
void outputTreePreOrder(Node *parent,string &fileprint)
{

    cout << parent->tag << endl ;


    string tag=parent->tag;


    /*if(tag=="<a>")
    {
        // operation1(tag);
        getTagAttributeOrString(root,tag,'!');
        getTagAttributeOrString(root,tag,'~');
    }
    else if(tag=="<script>")
    {
        getTagAttributeOrString(root,tag,'~');
    }
    else if(tag=="<style>")
    {
        getTagAttributeOrString(root,tag,'~');
    }
    /*  else if(tag=="<img>")
    {
        getTagAttributeOrString(root,tag,'!');
    }
    else if(tag=="<div>")
    {
        getTagAttributeOrString(root,tag,'~');
    }*/

    //cout<<tag<<endl;
//cout<<tag.substr(0,3)<<"F";
    if(tag=="<p>")
    {
        fileprint+="\\\\" ;
    }
    else if(tag[0]=='<' && tag[1]=='t' && tag[2]=='i')
    {
        tag.erase();
        //fileprint+="\\\\" ;
    }
    else if(tag=="<head>")
    {
        tag.erase() ;
    }
    else if(tag=="<body>")
    {
        tag.erase() ;
    }
    else if(tag=="<a>")
    {
        tag.erase() ;
    }
    else if(tag=="<link>")
    {
        tag.erase() ;
    }
    else if(tag=="<script>")
    {
        return;
    }
    else if(tag=="<style>")
    {
        return;
    }
     else if(tag=="<samp>")
    {
        return;
    }
    else if(tag=="<img>")
    {
        return;
    }
    else if(tag=="<meta>")
    {

        return;
    }

    else if(tag[0]=='<' && tag[1]=='!' && (tag[2]=='d' || tag[2]=='D') && (tag[3]=='o' || tag[3]=='O') )
    {
        tag.erase();
        fileprint+="\\documentclass{article}";
        fileprint+="\\usepackage{hyperref}";
        fileprint+="\\usepackage{graphicx}";
        fileprint+="\\usepackage{tabularx}";
        fileprint+="\\begin{document}";
        fileprint+="\n";


    }
//convert bold tag
    else if(tag=="<b>")
    {
        fileprint+="\\textbf" ;
    }

    else if(tag=="<strong>")
    {
        fileprint+="\\textbf" ;
    }
//convert header1 tag

    else if(tag=="<h1>")
    {


        fileprint+="\\section*";

    }
//convert header2 tag
    else if(tag=="<h2>")
    {


        fileprint+="\\subsection*";

    }
//convert header3 tag
    else if(tag=="<h3>")
    {


        fileprint+="\\subsubsection*";
    }
//convert header4 tag
    else if(tag=="<h4>")
    {


        fileprint+="\\paragraph";
    }
//convert header5 tag
    else if(tag=="<h5>")
    {


        fileprint+="\\subparagraph";
    }
//convert header6 tag
    else if(tag=="<h6>")
    {


        fileprint+="\\subsection*";
    }
//convert italic tag
    else if(tag=="<i>")
    {


        fileprint+="\\itshape";
    }
//convert emphasis tag
    else if(tag=="<em>")
    {


        fileprint+="\\emph";
    }
//convert unlisted tag
    else if(tag=="<ul>")
    {
        tag.erase();
        fileprint+="\\begin{itemize}";
    }

       else if(tag=="<ol>")
    {
        tag.erase();
        fileprint+="\\begin{enumerate}";
    }
//convert list item tag
    else if(tag=="<li>")
    {
        tag.erase();
        fileprint+="\\item";
    }
//convert underline tag
    else if(tag=="<u>")
    {
        fileprint+="\\underline";


    }
//convert subscript tag
    else if(tag=="<sub>")
    {

        fileprint+="\\textsubscript";

    }

//convert superscript tag
    else if(tag=="<sup>")
    {

        fileprint+="\\textsuperscript";

    }
    else if(tag.substr(1,3)=="rel")
    {
        int axx1;
        for(int i=0; i<5; i++)
        {
            tag.replace(0,1,"");
        }
        tag.replace(0,1,"{");
        axx1=tag.size();
        tag.replace(axx1-2,1,"}");
        string s4=tag;
        fileprint+=s4;
    }

//convert division tag
    else if(tag=="<div>")
    {

        fileprint+="\\\\";

    }
    //convert hyperlink tag
    else
    {
        if(tag.substr(1,4)=="href")
        {

            int axx,axx1;
            axx1=tag.size();

            //cout<<axx;
            // fstream fork2("latex.txt",std::fstream::app);
            fileprint+="\\";
            //cout<<tag;
             tag=insert_slash(tag);
            tag.replace(0,1,"");
            tag.replace(4,1,"{");
            tag.replace(5,1,"");
            //tag.replace(4,1,"");
            axx=tag.size();
            tag.replace(axx-1,1,"}");
            // s1.replace(s1.end()-2,1,"");
            string  s3=tag;//"{This is a link}";
            fileprint+=s3;
            // fileprint+=s2;

        }


        else if(mp[(tag.substr(0,3))]!=0)
        {

            tag.erase();
        }



        else
        {
            tag.replace(0,1,"");
            fileprint+="{";
            fileprint+=tag;
            fileprint+="}";
        }
    }



    // getTagAttributeOrString(root,parent->tag,'~');

    for(int i=0 ; i<40 ; i++)
    {

        if((parent->children[i])!=NULL)
        {
            outputTreePreOrder(parent->children[i],fileprint) ;
        }
    }


}

void  parser()
{
    mp.insert({"!cl",1});
    mp.insert({"!ta",2});
    mp.insert({"!id",3});
    mp.insert({"!sc",4});
    mp.insert({"!st",5});
    mp.insert({"~&#",1});
    mp.insert({"<no",1});
    //mp.insert({"~Go",1});
//mp.insert({"<di",1});
    mp.insert({"!bg",1});
    mp.insert({"!it",1});
    mp.insert({"!la",1});
    mp.insert({"!wi",1});
    mp.insert({"<sp",1});
    mp.insert({"<ce",1});
    mp.insert({"<br",1});
    mp.insert({"!cl",1});
    mp.insert({"<im",1});
    mp.insert({"<fo",1});
    mp.insert({"!ac",1});
    mp.insert({"!na",1});
    mp.insert({"<ta",1});
    mp.insert({"!ce",1});
    mp.insert({"<tr",1});
    mp.insert({"<td",1});
    mp.insert({"!va",1});
    mp.insert({"~&n",1});
    mp.insert({"!al",1});
    mp.insert({"!no",1});
    mp.insert({"<in",1});
    mp.insert({"!ty",1});
    mp.insert({"!ti",1});
    mp.insert({"!8p",1});
    mp.insert({"!0\"",1});
    mp.insert({"!6p",1});
    mp.insert({"!au",1});
    mp.insert({"!ma",1});
    mp.insert({"!si",1});
    mp.insert({"!&#",1});
    mp.insert({"!sb",1});
    mp.insert({"~&c",1});
    mp.insert({"~lv",1});
    mp.insert({"<lv",1});
    mp.insert({"!lv",1});
    mp.insert({"~#3",1});
    mp.insert({"!#3",1});
    /*mp.insert({"<b>",6});
    mp.insert({"<h1>",7});
    mp.insert({"<h2>",1});
    mp.insert({"<h3>",1});
    mp.insert({"<h4>",1});
    mp.insert({"<h5>",1});
    mp.insert({"<h6>",1});
    mp.insert({"<u>",1});
    mp.insert({"<emph>",1});
    mp.insert({"<sup>",1});
    mp.insert({"<sub>",1});
    mp.insert({"<!doctypehtml>",1});
    mp.insert({"<!Doctypehtml>",1});*/
    createLinkList() ;
    createTreeControl() ;
    string s;
    outputTreePreOrder(root,s) ;
    fstream fork("latex.tex",std::fstream::app);
    fork<<s;
    fork<<endl;
    fork<<endl;
    fork<<"\\end{itemize}";
    fork<<"\\end{enumerate}";
    fork<<"\\end{document}";



    menu() ;
//    return root;
}
