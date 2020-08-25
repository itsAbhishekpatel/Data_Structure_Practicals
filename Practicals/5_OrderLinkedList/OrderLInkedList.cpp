#include<iostream>
using namespace std;

//Node Class
class Node
{
    public:
    int data;
    Node *next;

    //constructor
    Node()
    {
        next=NULL;
    }

};

// Order Linked List Class 
class OLL
{
    public:
    Node *head, *tail, *temp, *ptr;

    //Constructor
    OLL()
    {
        head = NULL;
    }

    //Destructor
    ~OLL()
    {
        ptr = head;
        while (ptr!=NULL)
        {
            temp=ptr->next;
            delete ptr;
            ptr=temp;
        }

    }

};

// Main Function 
int main(void)
{

    return 0;
}