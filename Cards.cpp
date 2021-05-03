#include<iostream>
#include<string>
#include<iomanip>
#include<climits>
#include<queue>
using namespace std;


class node
{
    public:
    int value;
    string Val;
    int black_value;
    string suit;
    string colour;
    node* next;
    
    node(int val,string Suit)
    {
        value=val;
        suit=Suit;
        
        if(val>=2&&val<=10)
        {
            black_value=val;
            Val=to_string(val);
        }
        else if(val==1)
        {
            black_value=1;
            Val="A";
        }
        else if(val==11)
        {
            black_value=10;
            Val="Jack";
        }
        else if(val==12)
        {
            black_value=10;
            Val="Queen";
        }
        else if(val==13)
        {
            black_value=10;
            Val="King";
        }
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
node* createdeck()
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
    return head;
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

void displayhead(node* head)
{
    cout<<"___________"<<endl;
    cout<<"|"<<setw(9)<<head->Val<<"|"<<endl;
    cout<<"|"<<setw(9)<<"of"<<"|"<<endl;
    cout<<"|"<<setw(9)<<head->suit<<"|"<<endl;
    cout<<"|         |"<<endl;
    cout<<"|_________| "<<endl;
}

void displaydeck(node* head)
{
    node* temp1=head;
    node* temp2=head;
    int len=ll_length(head);
    int x=len/13;
    int y=len%13;
    
    for(int i=0;i<x;i++)
    {
        for(int i=0;i<13;i++)
        {
            cout<<"___________ ";
        }
        cout<<endl;
        for(int i=0;i<13;i++) 
        {   
            cout<<"|"<<setw(9)<<temp1->Val<<"| ";
            temp1=temp1->next;
        }
        cout<<endl;
        for(int i=0;i<13;i++)
        {    
            cout<<"|"<<setw(9)<<"of"<<"| ";
        }
        cout<<endl;    
        for(int i=0;i<13;i++)
        {    
            cout<<"|"<<setw(9)<<temp2->suit<<"| ";
            temp2=temp2->next;
        }
        cout<<endl;    
        for(int i=0;i<13;i++)
        {    
            cout<<"|         | ";
        }
        cout<<endl;
        for(int i=0;i<13;i++)
        {    
            cout<<"|_________| ";
        }
        cout<<endl;
    }

    for(int i=0;i<y;i++)
    {
        cout<<"___________ ";
    }
    cout<<endl;
    for(int i=0;i<y;i++) 
    {   
        cout<<"|"<<setw(9)<<temp1->Val<<"| ";
        temp1=temp1->next;
    }
    cout<<endl;
    for(int i=0;i<y;i++)
    {    
        cout<<"|"<<setw(9)<<"of"<<"| ";
    }
    cout<<endl;    
    for(int i=0;i<y;i++)
    {    
        cout<<"|"<<setw(9)<<temp2->suit<<"| ";
        temp2=temp2->next;
    }
    cout<<endl;    
    for(int i=0;i<y;i++)
    {    
        cout<<"|         | ";
    }
    cout<<endl;
    for(int i=0;i<y;i++)
    {    
        cout<<"|_________| ";
    }
    cout<<endl;

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

void overhand_shuffle(node* &head)
{
   int start=rand()%51+2;
   int end=rand()%51+2;
   node* prevhead=head;
   node* temp1=head;
   if(start>end)
   {
       int temp1=start;
       start=end;
       end=temp1;
   }
   for(int i=0;i<start-2;i++)
   {
       temp1=temp1->next;

   }
   node* temp2=temp1;
   head=temp1->next;
   for(int i=start;i<=end;i++)
   {
       temp2=temp2->next;
   }
   temp1->next=temp2->next;
   temp2->next=prevhead;


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


void random_shuffle(node* &head)
{
    int x=rand()%20+20;
    int y=rand()%20+20;
    int z=rand()%20+20;
    for(int i=0;i<x;i++)
    {
        riffle_shuffle(head);
    }
    for(int j=0;j<y;j++)
    {
        shuffle(head);
    }
    for(int k=0;k<z;k++)
    {
        overhand_shuffle(head);
    }
}

void hit(node* &head,node* &OnTheTable)
{
    if(ll_length(head)==0)
    {
        head=createdeck();
        random_shuffle(head);
        
    }
    node* ans=head;
    node* temp1=head->next;
    
    if(OnTheTable==NULL)
    {
        OnTheTable=ans;
        ans->next=NULL;
        head=temp1;
        return;
    }

    node*temp=OnTheTable;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=ans;
    ans->next=NULL;
    head=temp1;
    return;
}


int sumofblackvalue_normal(node* head)
{
    node* temp=head;
    int sum=0;
    for(int i=0;i<ll_length(head);i++)
    {
        sum+=temp->black_value;
        temp=temp->next;
    }
    return sum;

}

int sumofblackvalue_soft(node* head)
{
    node* temp=head;
    int sum=0;
    int tempblack=0;
    for(int i=0;i<ll_length(head);i++)
    {
        if(temp->Val.compare("A")==0)
            tempblack=11;
        else{
            tempblack=temp->black_value;
        }    
        sum+=tempblack;
        temp=temp->next;
    }
    return sum;

}

void displayDD(node* head)
{
    node* temp1=head;
    node* temp2=head;
    
    
    for(int i=0;i<2;i++)
    {
        cout<<"___________ ";
    }
    cout<<"______________"<<endl;
    for(int i=0;i<2;i++) 
    {   
        cout<<"|"<<setw(9)<<temp1->Val<<"| ";
        temp1=temp1->next;
    }
    cout<<"|"<<setw(12)<<temp1->Val<<"|"<<endl;
    for(int i=0;i<2;i++)                                  
    {    
        cout<<"|"<<setw(9)<<"of"<<"| ";
    }
    cout<<"|"<<setw(12)<<"of"<<"|"<<endl;    
    for(int i=0;i<2;i++)
    {    
        cout<<"|"<<setw(9)<<temp2->suit<<"| ";
        temp2=temp2->next;
    }
    cout<<"|"<<setw(12)<<temp2->suit<<"|"<<endl;    
    for(int i=0;i<2;i++)
    {    
        cout<<"|         | ";
    }
    cout<<"|____________|"<<endl;
    for(int i=0;i<2;i++)
    {    
        cout<<"|_________| ";
    }
    cout<<endl;
}


void bet(node* &player,node* &dealer,node* &head,int &betamount,int &curr_bal,string split,queue<string> &result)
{
    
    if(betamount<=curr_bal&&betamount>0)
    {    
        curr_bal-=betamount;
        int play_count=0;                    
        hit(head,player);
        if(ll_length(player)==1)
            hit(head,player);
        if(split.compare("M")==0)
            hit(head,dealer);
        cout<<"Dealer's card:-"<<endl;
        displayhead(dealer);
        cout<<"Your cards:-"<<endl;
        displaydeck(player);
        if(split.compare("M")==0)
            hit(head,dealer);
        

        if((player->black_value+player->next->black_value==11)&&(player->Val.compare("A")==0||player->next->Val.compare("A")==0))
        {
            
            if((dealer->black_value+dealer->next->black_value==11)&&(dealer->Val.compare("A")==0||dealer->next->Val.compare("A")==0))
            {
                result.push("It's a push!");
                curr_bal+=betamount;
                
            }
            else{
                result.push("It's Blackjack! You win!");
                curr_bal=curr_bal+betamount*2.5;
                
            }
            
        }

        else{
            while(true)
            {
                if(sumofblackvalue_normal(player)<21)
                {
                    cout<<"Hit"<<endl;
                    cout<<"Stand"<<endl;
                    if(play_count==0)
                    {
                        cout<<"Double down N(Here N is the amount to be added to bet)"<<endl;
                        cout<<"Surrender"<<endl;
                        if(dealer->Val.compare("A")==0)
                        {
                            cout<<"Insurance N(Here N is the amount to be put in insurance)"<<endl;
                        }
                    }
                    if(player->value==player->next->value)
                    {
                        cout<<"Split"<<endl;
                    }
                    cout<<"Display"<<endl;
                    cout<<"End"<<endl;
                    cout<<"Your command:- ";
                    string play_input;
                    getline(cin,play_input); 
                    if(play_input.find("Hit")!=string::npos)
                    {
                        hit(head,player);
                        cout<<"Your cards:-"<<endl;
                        displaydeck(player);
                        play_count++;
                        
                    }
                    else if(play_input.find("Stand")!=string::npos)
                    {
                        cout<<"Your cards:-"<<endl;
                        displaydeck(player);
                        if(split.compare("M")==0)
                            while(max(sumofblackvalue_soft(dealer),sumofblackvalue_normal(dealer))<=16)
                            {
                                hit(head,dealer);
                            }
                        
                        if(sumofblackvalue_normal(dealer)>21)
                        {
                            result.push("Dealer busts. You win!");
                            curr_bal=curr_bal+betamount*2;
                        }
                        else if(sumofblackvalue_normal(player)>sumofblackvalue_soft(dealer))
                        {
                            result.push("You win!");
                            curr_bal=curr_bal+betamount*2;

                        }
                        else if(sumofblackvalue_soft(player)>sumofblackvalue_soft(dealer)&&sumofblackvalue_soft(player)<=21&&sumofblackvalue_soft(dealer)<=21)
                        {
                            result.push("You win!");
                            curr_bal=curr_bal+betamount*2;
                        }
                        else if(sumofblackvalue_soft(player)>sumofblackvalue_normal(dealer)&&sumofblackvalue_soft(player)<=21&&sumofblackvalue_soft(dealer)>21)
                        {
                            result.push("You win!");
                            curr_bal=curr_bal+betamount*2;
                        }
                        else if(sumofblackvalue_normal(player)>sumofblackvalue_normal(dealer)&&sumofblackvalue_soft(player)>1&&sumofblackvalue_soft(dealer)>21)
                        {
                            result.push("You win!");
                            curr_bal=curr_bal+betamount*2;
                        }
                        else if(sumofblackvalue_normal(player)==sumofblackvalue_soft(dealer))
                        {
                            result.push("It's a push!");
                            curr_bal+=betamount;

                        }
                        else if(sumofblackvalue_soft(player)==sumofblackvalue_soft(dealer)&&sumofblackvalue_soft(player)<=21&&sumofblackvalue_soft(dealer)<=21)
                        {
                            result.push("It's a push!");
                            curr_bal+=betamount;
                        }
                        else if(sumofblackvalue_soft(player)==sumofblackvalue_normal(dealer)&&sumofblackvalue_soft(player)<=21&&sumofblackvalue_soft(dealer)>21)
                        {
                            result.push("It's a push!");
                            curr_bal+=betamount;
                        }
                        else if(sumofblackvalue_normal(player)==sumofblackvalue_normal(dealer)&&sumofblackvalue_soft(player)>1&&sumofblackvalue_soft(dealer)>21)
                        {
                            result.push("It's a push!");
                            curr_bal+=betamount;
                        }
                        else{
                            result.push("You lose.");
                        }
                        
                        break;
                    }
                    else if(play_input.find("Double down")!=string::npos&&play_count==0)
                    {
                        string tempstring=play_input;
                        tempstring.erase(0,12);
                        if(tempstring.length()!=0)
                        {
                            int DDamount=stoi(tempstring);
                            if(DDamount<=betamount&&DDamount>0&&curr_bal>=DDamount)
                            {
                                curr_bal-=DDamount;
                                hit(head,player);
                                cout<<"Your cards:-"<<endl;
                                displayDD(player);

                                if(sumofblackvalue_normal(player)>21)
                                {
                                    
                                    result.push("You lose.");
                                    break;
                                }
                                else
                                {    
                                    if(split.compare("M")==0)
                                        while(max(sumofblackvalue_soft(dealer),sumofblackvalue_normal(dealer))<=16)
                                        {
                                            hit(head,dealer);
                                        }
                                    
                                

                                    if(sumofblackvalue_normal(dealer)>21)
                                    {
                                        result.push("Dealer busts. You win!");
                                        curr_bal=curr_bal+(DDamount+betamount)*2;
                                    }
                                    else if(sumofblackvalue_normal(player)>sumofblackvalue_soft(dealer))
                                    {
                                        result.push("You win!");
                                        curr_bal=curr_bal+(DDamount+betamount)*2;

                                    }
                                    else if(sumofblackvalue_soft(player)>sumofblackvalue_soft(dealer)&&sumofblackvalue_soft(player)<=21&&sumofblackvalue_soft(dealer)<=21)
                                    {
                                        result.push("You win!");
                                        curr_bal=curr_bal+(DDamount+betamount)*2;
                                    }
                                    else if(sumofblackvalue_soft(player)>sumofblackvalue_normal(dealer)&&sumofblackvalue_soft(player)<=21&&sumofblackvalue_soft(dealer)>21)
                                    {
                                        result.push("You win!");
                                        curr_bal=curr_bal+(DDamount+betamount)*2;
                                    }
                                    else if(sumofblackvalue_normal(player)>sumofblackvalue_normal(dealer)&&sumofblackvalue_soft(player)>1&&sumofblackvalue_soft(dealer)>21)
                                    {
                                        result.push("You win!");
                                        curr_bal=curr_bal+(DDamount+betamount)*2;
                                    }
                                    else if(sumofblackvalue_normal(player)==sumofblackvalue_soft(dealer))
                                    {
                                        result.push("It's a push!");
                                        curr_bal+=(betamount+DDamount);

                                    }
                                    else if(sumofblackvalue_soft(player)==sumofblackvalue_soft(dealer)&&sumofblackvalue_soft(player)<=21&&sumofblackvalue_soft(dealer)<=21)
                                    {
                                        result.push("It's a push!");
                                        curr_bal+=(betamount+DDamount);
                                    }
                                    else if(sumofblackvalue_soft(player)==sumofblackvalue_normal(dealer)&&sumofblackvalue_soft(player)<=21&&sumofblackvalue_soft(dealer)>21)
                                    {
                                        result.push("It's a push!");
                                        curr_bal+=(betamount+DDamount);
                                    }
                                    else if(sumofblackvalue_normal(player)==sumofblackvalue_normal(dealer)&&sumofblackvalue_soft(player)>1&&sumofblackvalue_soft(dealer)>21)
                                    {
                                        result.push("It's a push!");
                                        curr_bal+=(betamount+DDamount);
                                    }
                                    else{
                                        result.push("You lose.");
                                    }
                                
                                break;
                                }
                            }
                            else{
                                cout<<"Please try again. Note, double down amount must be less than bet amount and greater than 0."<<endl;
                            }                          
                        }
                        else{
                            cout<<"Please try again"<<endl;
                        }
                    }
                    else if(play_input.find("Surrender")!=string::npos&&play_count==0)
                    {

                        curr_bal=curr_bal+betamount/2;
                        break;
                    }
                    else if(play_input.find("Insurance")!=string::npos&&dealer->Val.compare("A")==0&&play_count==0)
                    {
                        
                        string tempstring=play_input;
                        tempstring.erase(0,10);
                        if(tempstring.length()!=0)
                        {
                            play_count++;
                            int INamount=stoi(tempstring);
                            if(INamount<=betamount/2&&INamount>0&&curr_bal>=INamount)
                            {
                                curr_bal-=INamount;
                                if((dealer->black_value+dealer->next->black_value==11)&&(dealer->Val.compare("A")==0||dealer->next->Val.compare("A")==0)&&(sumofblackvalue_normal(player)!=21||sumofblackvalue_soft(player)!=21))
                                {
                                    curr_bal=curr_bal+INamount*2;
                                }
                                
                            }
                            else
                            {
                                cout<<"Please try again.Note, insurance amount must be less than or equal to half of bet amount."<<endl;
                            }
                        }
                        else
                        {
                            cout<<"Please try again"<<endl;
                        }    
                    }
                    else if(play_input.find("Split")!=string::npos&&player->value==player->next->value&&betamount<=curr_bal)
                    {
                        int splitbet=betamount;
                        curr_bal-=splitbet;
                        node* a=NULL;
                        node* b=NULL;
                        
                        splitinhalf(player,a,b);
                        cout<<"New Hand:-"<<endl;
                        bet(a,dealer,head,splitbet,curr_bal,"M",result);
                        cout<<"New Hand:-"<<endl;
                        bet(b,dealer,head,splitbet,curr_bal,"S",result);
                        break;
                        
                        
                    }
                    else if(play_input.find("Display")!=string::npos)
                    {
                        displaydeck(head);  
                    }
                    else if(play_input.find("End")!=string::npos)
                    {
                        break;  
                    }
                    else
                    {
                        cout<<"Please try again"<<endl<<endl;
                    }

                }
                
                else
                {
                    
                    result.push("It's a bust!You lose.");
                    break;
                }

            }
                    
        }       
    }
    else
    {
        cout<<"Enter correct bet amount"<<endl;
    }
}





int main()
{
    srand(time(0));
    cout<<"Hi. Welcome to Deck of Cards!!! "<<endl;
    node* head=createdeck();
   
    
    while(true)
    {
        cout<<"Type Display to display the deck" <<endl;
        cout<<"Type Riffle Shuffle N to riffle-shuffle the deck."<<endl;
        cout<<"Type Shuffle N to shuffle the deck."<<endl;
        cout<<"Type O Shuffle N to overhand-shuffle the deck."<<endl;
        cout<<"Type Value Sort to sort the cards in the ascending order of card's value."<<endl;
        cout<<"Type Colour Sort to sort the cards in the alphabetic order of card's colour."<<endl;
        cout<<"Type Suit Sort to sort the cards in the alphabetic order of card's suit."<<endl;
        cout<<"Type Sort to sort the cards."<<endl;
        cout<<"Type Blackjack to play Blackjack."<<endl;
        cout<<"Type End to end the program."<<endl;
        cout<<"Type your command. Commands are case sensitive."<<endl;
        cout<<"Your command:- ";
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
        else if(input.find("O Shuffle")!=string::npos)
        {
            string tempstring=input;
            tempstring.erase(0,10);
            
            if(tempstring.length()!=0)
            {
            int times=stoi(tempstring);
            for(int i=0;i<times;i++)
            {
                overhand_shuffle(head);
                
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

        else if(input.find("Blackjack")!=string::npos)
        {
            cout<<endl;
            int curr_bal=0;
            node* head=createdeck();
            random_shuffle(head);
            while(true)
            {
                cout<<endl;
                
                cout<<"Blackjack pays 3 to 2"<<endl;
                cout<<"Dealer must draw to 16, and stand on all 17's"<<endl;
                cout<<"Insurance pays to 2 to 1"<<endl<<endl;
                cout<<"Your current balance is= "<<curr_bal<<". You have four choices to make:-"<<endl;
                cout<<"Type Bet N to start the game with bet amount equals to N"<<endl;
                cout<<"Type Add Bal N to add N amount to your balance"<<endl;
                cout<<"Type Display to display the deck"<<endl;
                cout<<"Type End to stop playing Blackjack"<<endl;
                cout<<"Your command:- ";
                string black_input;
                getline(cin,black_input);
                if(black_input.find("Display")!=string::npos)
                {
                    displaydeck(head);
                }
                else if(black_input.find("Add Bal")!=string::npos)
                {
                    string tempstring=black_input;
                    tempstring.erase(0,8);
                    if(tempstring.length()!=0)
                    {
                        int amount=stoi(tempstring);
                        curr_bal+=amount;
                        cout<<"Your current balance is "<<curr_bal<<endl;
                    }

                    else{
                        cout<<"Please try again"<<endl;;
                    }
                }
                else if(black_input.find("Bet")!=string::npos)
                {
                    string tempstring=black_input;
                    tempstring.erase(0,4);
                    if(tempstring.length()!=0)
                    {
                        int betamount=stoi(tempstring);
                        node* player=NULL;
                        node* dealer=NULL;
                        queue<string> result;
                        bet(player,dealer,head,betamount,curr_bal,"M",result);
                        cout<<"Dealer's cards:-"<<endl;
                        displaydeck(dealer);
                        if(result.size()==1)
                        {
                            cout<<result.front()<<endl;
                            result.pop();  
                        }
                        else{
                            for(int i=1;i<=result.size();i++)
                            {
                                cout<<"Hand "<<i<<":-"<<result.front()<<endl;
                                result.pop();
                            }
                        }
                        
                    }
                }            
                else if(black_input.find("End")!=string::npos)
                {
                    cout<<"Bye.Hope we meet again!"<<endl;
                    break;
                } 

                else{
                    cout<<"Please try again"<<endl;
                }     
                        
            }

                

        }
        else if(input.find("End")!=string::npos)
        {
            cout<<"Thank you for using my software -- Archishman Das."<<endl;
            break;
        }
        else{
            cout<<"Please try again"<<endl;
        }
        

    }

    return 0;
}
