#include<iostream>
#include<fstream>

using namespace std ;

struct Node{
    string tag ;
    Node *parent,*children[10] ;
};

Node *root , *current;
 int count=0,headcount=0,buttoncount=0;

void createLinkList(){
    root = NULL ;
    current = NULL ;
}

Node* createNode(string tag){

    Node *temp = new Node ;

    temp->tag = tag ;

    for(int i=0 ; i<10 ; i++){
        temp->children[i] = NULL ;
    }
    temp->parent = NULL ;

    return temp ;
}

void insertNode(Node *newNode , int flag){
    newNode->parent = current ;
    for(int i=0 ; i<10 ; i++){
        if(current->children[i]==NULL)
        {
            current->children[i] = newNode ;
            if(flag==1) current = newNode ;
            break ;
        }
    }
}

void operation(string str){
    //cout << current->tag << endl;
        if(str[0]=='<' && str[1]=='h' && str[2]=='e')
        {
            headcount++;
        }
        if(str[0]=='<' && str[1]=='b'  && str[2]=='u')
        {
            buttoncount++;
        }

        if(str[1]=='/'){
            if(current->parent == NULL){
                current = NULL ;
                return ;
            }
            current = current->parent ;

            return ;
        }

        int flag ;

        if(str[0]=='<') flag = 1 ;

        Node *newNode = createNode(str) ;
        insertNode(newNode,flag) ;
}

void createTreeControl(void){

    ifstream iFile ;
    iFile.open("hello.html") ;

    string str = "" ;
    char ch,flag='0' ;

    if(iFile.is_open()){


        iFile >> ch ;

        while(ch!='>'){
            str=str+ch ;
            iFile >> ch ;
        }
        str=str+ch ;

        root = createNode(str) ;
        //count++;
        current = root ;


        while(current!=NULL){
            if(flag == '0')
                iFile >> ch ;

            else ch = flag ;

            str.clear() ;
            if(ch=='<'){
                getline(iFile,str,'>') ;
                str = ch + str + ">" ;

                flag = '0' ;
            }

            else{
                getline(iFile,str,'<') ;
                char c = '~';
                str = ch + str ;
                str = c + str ;
                flag = '<' ;
            }

            string s ;
            int flagForTag = 0;
            for(int i = 0 ; i<str.size()-1 && flag=='0' ; i++ ){
                s = s + str[i] ;

                if(str[i]==' ' || str[i+1]=='>')
                {
                    if(flagForTag == 0){
                        if(s[s.size()-1]==' '){
                            s.replace(s.size()-1,1,">") ;
                        }
                        else s = s + ">" ;
                        flagForTag = 1 ;
                        count++;
                        operation(s) ;
                    }

                    else {
                            char c1 = '!';
                            s = c1 + s ;
                            operation(s) ;
                    }

                    s.clear() ;
                }
            }

            if(flag == '<') operation(str) ;
        }
    }

    else cout << "Can't open file" << endl ;

}


void getTagParentsChildrensSiblings(Node *current,string tagStr,int flag){

    if(current->tag == tagStr){
        if(flag==1){
            if(current->parent!=NULL)
                cout <<tagStr <<"'s parent is" <<current->parent->tag << endl ;
            return ;
        }

        else if(flag==2){
            for(int i=0 ; i<10 && current->children[i]!=NULL ; i++){
                string str = current->children[i]->tag ;
                if(str[0]!='~' && str[0]!='!'){
                    cout <<tagStr <<"'s children are"<< str << '\t' ;
                }
            }
        }

        else if(flag==3){

            for(int i=0 ; i<10 && current->parent->children[i]!=NULL ;i++){
                string str = current->parent->children[i]->tag ;
                if(str[0]!='~' && str[0]!='!'){
                    cout << str << '\t' ;
                }
            }
        }
    }

    for(int i=0 ; i<10 ; i++){

        if((current->children[i])!=NULL)
        {
            getTagParentsChildrensSiblings(current->children[i] ,tagStr , flag) ;
        }
    }

}


void menu(){
    while(true){
        int choice ;
        cout<<count;
        cout<<headcount;
        cout<<buttoncount;
        cout << "\n1.tag's parent\n2.tag's children\n3. exit \n " ;
        cin >> choice ;

        string tagStr ;
        cout << "Enter Tag Name : "  ;
        cin >> tagStr ;

        if(choice == 1){
            getTagParentsChildrensSiblings(root , tagStr , 1) ;
        }
        if(choice == 2){
            getTagParentsChildrensSiblings(root , tagStr , 2) ;
        }
        if(choice == 3){
            getTagParentsChildrensSiblings(root , tagStr , 3) ;
        }
        if(choice == 4) break;

    }

}

struct node *parser(){
    createLinkList() ;
    createTreeControl() ;
   // outputTreePreOrder(root) ;

    menu() ;
}
