// circular single link list 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node      // create only for our data type
{
    public:
    int value;
    Node *next;
     Node()
     {
        next = NULL;
        value = 0;
     }
};
class CSlist
{
    Node *head ;
    public:
        CSlist()
        {
            head = NULL;
        }
        void insert_(int n)
        {
            Node *temp = new Node();
            temp->value = n;
            if(head == NULL)
            {
                head=temp;
                temp->next=temp;
            }
            else {
                Node *last=head;
                while(last->next!=head){
                    last=last->next;
                }
                temp->next = head;
                last->next = temp;
                // head = temp;
            }
        }
        void insert_Begin(int v)
        {
            Node *temp = new Node();
            temp->value = v;
            Node *last=head;
            while(last->next!=head)
            {
                last=last->next;
            }
             temp->next = head;
             last->next = temp;
             head = temp;
        }
        void insert_Middle(int v,int n)  
     {
        Node *temp = new Node();   // create a node 
        temp->value = v;  // assign value 
        if(n==1)   //  agr use nye 1 diya hai to 
        {
            this->insert_Begin(v);
        }
        else {
            Node *s=head; 
            while(n-2) 
            {
                    n--;  
                    if(s->next!=head) 
                    {
                        s=s->next;   
                    }
                    else { 
                    cout<<"Position Not found ";  
                    return ;
                    }
              }
              temp->next=s->next; 
             s->next=temp;    
          }
       }
      

        void Delete_Begin()
        {    Node *s = head;
             Node *last=head;
                while(last->next!=head)
                {
                    last=last->next;
                }
               head=s->next; 
               last->next = s->next;
        }
         void Delete_End()
         {
            Node *temp = head;
            Node *last = head;
            while(last->next->next!=head)
            {
                last=last->next;
            }
             temp=last->next;
             last->next =head;
            
             delete temp;
         }
         void Search_(int v)
         {
            Node *temp = head;
            while(temp!=head)
            {
                if(temp->value==v)
                {
                    cout<<"Value founded \n";
                    return ;
                }
            }
            cout<<"Value not found \n";
         }
        
    void Print_()
    {
        Node *temp = head;
        do
        {
            cout<<temp->value<<" <--> ";
            temp=temp->next;
         } while(temp!=head);
       
        
    }
};
int main()
{
    CSlist c;
    while(1)
    {
        cout<<"\n....................................................................\n";
        cout<<"1 For Insert Element \n";
        cout<<"2 For Insert Element in Begin \n";
     
        cout<<"3 For Insert Element in Any Position \n";
        cout<<"4 For Delete Begin \n";
        cout<<"5 Delete End \n";
        cout<<"6 For Search Any Value \n";
        cout<<"7 For Print All Value \n";
        cout<<"8 For Exit \n";
        cout<<"\nEnter Your Choice \n";

        int choice,r,s;
        cin>>choice;
        switch(choice )
        {
            case 1: 
                 cout<<"Enter value ";
                 cin>>r;
                 c.insert_(r);
            break;
            case 2:
                 cout<<"Enter value ";
                 cin>>r;
                 c.insert_Begin(r);
            break;
            case 3: 
                 cout<<"Enter value ";
                 cin>>r;
                 cout<<"Ok then enter position ";
                 cin>>s;
                 c.insert_Middle(r,s);
            break;
            case 4:
                 
                 c.Delete_Begin();
            break;
            case 6:
                 cout<<"Enter value ";
                 cin>>r;
                 c.Search_(r);
            break;
            case 7:
                 c.Print_();
            break;
            case 8:
                 exit(0);
            break;
            default:
                 cout<<"Please Enter a Valid Choice ";
            break;
        }

    }

}