#include<iostream>
#include<string>
using namespace std;

class node
{
    public:
    int value;
    string suit;
    string colour;
    node* next;
    void display()
    {
        string val=to_string(value);
        if(value==1)
            val="A";
        else if(value==11)
            val="Jack";
        else if(value==12)
            val="Queen";
        else if(value==13)
            val="King";        



        printf("(%s,%s,%s)\n", val.c_str(),suit.c_str(),colour.c_str());

    }
    node(int val,string Suit)
    {
        value=val;
        suit=Suit;
        if(suit.compare("Clubs")==0||suit.compare("Spades")==0)
            colour="Black";
        else if(suit.compare("Hearts")==0||suit.compare("Diamonds")==0)
            colour="Red";  
        else 
        {
            colour="Please re-enter the Suit";
        } 
        next=NULL;     

    }
};    

void insertAtTail(node* &head,int val,string Suit)
{
    node* n=new node(val,Suit);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

void displaydeck(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        node n=*temp;
        n.display();
        temp=temp->next;
    }


}

void shuffle(node* &head)
{
    int x=rand()%50+1;
    node* ptr1 = head;
    for(int i=0;i<x;i++)
    {
        ptr1=ptr1->next;
    }
    node* ptr2=ptr1->next;
    ptr1->next=NULL;
    int y=rand()%x;
    node* ptr3=head;
    for(int i=0;i<y-1;i++)
    {
        ptr3=ptr3->next;
    }
    node* ptr4=ptr2;
    while(ptr4->next!=NULL)
    {
        ptr4=ptr4->next;
    }
    ptr4->next=ptr3->next;
    ptr3->next=ptr2;


}

void riffle_shuffle(node* &head)
{
    node* ptr1=head;
    node* ptr2=head;
    for(int i=0;i<26;i++)
    {
        ptr2=ptr2->next;
    }
    node* dummyNode=new node(0,"Zero");
    node* ptr3=dummyNode;
    int count=0;
    while(ptr2!=NULL)
    {
        if(count%2==0)
        {
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }   
        else
        {
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
        count++;
    }
    head=dummyNode->next;
}
int ll_length(node* head)
{
    int length=0;
    node* temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        length++;
    }
    return length;
}

node* merge_suit(node* &head1,node* &head2)
{
    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(0,"zero");
    node* p3=dummyNode;

    while(p1!=NULL&&p2!=NULL)
    {
        string p=p1->suit;
        string q=p2->suit;
        bool a=p[0]<=q[0];
        if(a)
        {
            p3->next=p1;
            p1=p1->next;
        }
        else{
             p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL)
    {
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL)
    {
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummyNode->next;
}
node* merge_value(node* &head1,node* &head2)
{
    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(0,"zero");
    node* p3=dummyNode;

    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->value<=p2->value)
        {
            p3->next=p1;
            p1=p1->next;
        }
        else{
             p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL)
    {
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL)
    {
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummyNode->next;
}

node* merge_colour(node* &head1,node* &head2)
{
    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(0,"zero");
    node* p3=dummyNode;

    while(p1!=NULL&&p2!=NULL)
    {
        bool a=p1->colour[0]<=p2->colour[0];
        if(a)
        {
            p3->next=p1;
            p1=p1->next;
        }
        else{
             p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL)
    {
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL)
    {
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummyNode->next;
}

void splitinhalf(node* head,node* &a,node* &b)
{
    int len=ll_length(head);
    node* temp=head;
    for(int i=1;i<len/2;i++)
    {
        temp=temp->next;
    }
    node* temp1=temp->next;
    temp->next=NULL;
    a=head;
    b=temp1;

}

void value_sort(node* &head)
{
    if(ll_length(head)==1||ll_length(head)==0)
    {
        return;
    }
    node* a=NULL;
    node* b=NULL;
    splitinhalf(head,a,b);
    value_sort(a);
    value_sort(b);
    head=merge_value(a,b);
}

void suit_sort(node* &head)
{
    if(ll_length(head)==1||ll_length(head)==0)
    {
        return;
    }
    node* a=NULL;
    node* b=NULL;
    splitinhalf(head,a,b);
    suit_sort(a);
    suit_sort(b);
    head=merge_suit(a,b);
}

void colour_sort(node* &head)
{
    if(ll_length(head)==1||ll_length(head)==0)
    {
        return;
    }
    node* a=NULL;
    node* b=NULL;
    splitinhalf(head,a,b);
    colour_sort(a);
    colour_sort(b);
    head=merge_colour(a,b);
}

void total_sort(node* &head)
{
    value_sort(head);
    suit_sort(head);
    colour_sort(head);
}


int main()
{
    node* head=NULL;
   
    for(int i=1;i<=13;i++)
    {
        insertAtTail(head,i,"Clubs");
    }
    for(int i=1;i<=13;i++)
    {
        insertAtTail(head,i,"Spades");
    }
    for(int i=1;i<=13;i++)
    {
        insertAtTail(head,i,"Diamonds");
    }
    for(int i=1;i<=13;i++)
    {
        insertAtTail(head,i,"Hearts");
    }
    while(true)
    {
        cout<<"Type your command. Type 'End' (without quotes) to end the program"<<endl;
        string input;
        getline(cin, input);
        if(input.find("Riffle Shuffle")!=string::npos)
        {
            string tempstring=input;
            tempstring.erase(0,15);
            if(tempstring.length()!=0)
            {
            int times=stoi(tempstring);
            for(int i=0;i<times;i++)
            {
                riffle_shuffle(head);
                
            }
            displaydeck(head);
            }
            else{
                cout<<"Please try again";
            }

        }
        else if(input.find("Shuffle")!=string::npos)
        {
            string tempstring=input;
            tempstring.erase(0,8);
            if(tempstring.length()!=0)
            {
            int times=stoi(tempstring);
            for(int i=0;i<times;i++)
            {
                shuffle(head);
                
            }
            displaydeck(head);
            }
            else{
                cout<<"Please try again";
            }
        }
        else if(input.find("Display")!=string::npos)
        {
            displaydeck(head);
        }
        else if(input.find("Value sort")!=string::npos)
        {
            value_sort(head);
            displaydeck(head);
        }
        else if(input.find("Suit sort")!=string::npos)
        {
            suit_sort(head);
            displaydeck(head);
        }
        else if(input.find("Colour sort")!=string::npos)
        {
            colour_sort(head);
            displaydeck(head);
        }
        else if(input.find("Sort")!=string::npos)
        {
            total_sort(head);
            displaydeck(head);
        }
        else if(input.find("End")!=string::npos)
        {
            break;
        }
        else{
            cout<<"Please try again"<<endl;
        }
        

    }

    return 0;
}
