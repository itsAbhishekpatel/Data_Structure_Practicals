#include<iostream>

using namespace std;

//create node data type.
class Node
{
public:
    int data;
    Node *next;
    Node *prev;  

    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    
};

//DoubleLinkedList Class
class DoublyLinkedList
{
    public:
    Node *head,*tail,*temp,*ptr;

    DoublyLinkedList() //Constructor for intial head and tail
    {
        head = tail = 0;
    }
    //Destructor to free memory
    ~DoublyLinkedList()
	{
		cout << "\nDeallocating memory...\n";
		ptr = head;
		while (ptr != NULL)
		{
			temp = ptr->next;
			delete ptr;
			ptr = temp;
		}
	}

    //create function for create a node
    void create();
    //count function for 
    void count();
    //function for searching
    void search();

    // Functions declared for inserting a node.
    void insert_at_begin();
    void insert_at_loc();
    void insert_at_end();

    //Functions declared for deleting a node.
    void delete_at_begin();
    void delete_at_loc();
    void delete_at_end();

    // Display function for ssl
    void display();
    //function for reverse the list


};

//create funtion
void DoublyLinkedList::create()
{
    int n;
    char ch = 'y';

    do
    {
        temp = new Node();
        temp->next = NULL;
        cout << "Enter the node data:";
        cin >> n;
        if (head == NULL)
        {
            head = temp;
            head->data = n;
            head->next = NULL;
            head->prev=NULL;
            tail = head;
        }

        else
        {
            temp->data = n;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        cout << "Want to enter more nodes ? (y/n) : ";
        cin >> ch;
    } while (ch == 'y');
}

//Insert Node at begin
void DoublyLinkedList::insert_at_begin()
{
    
  
}

//Insert Node at end
void DoublyLinkedList ::insert_at_end()
{

}

//Insert Node at any Location
void DoublyLinkedList ::insert_at_loc()
{

}

//Delete Node at begin
void DoublyLinkedList::delete_at_begin()
{
    
  
}

//Delete Node at end
void DoublyLinkedList ::delete_at_end()
{

}

//Delete Node at any Location
void DoublyLinkedList ::delete_at_loc()
{

}

//Display The list
void DoublyLinkedList ::display()
{

}

//Count function
void DoublyLinkedList ::count()
{

}

//Search Function
void DoublyLinkedList ::search()
{

}
int main(void)
{
    DoublyLinkedList s;
    int option;
    char ch;

    do
    {
        //Menu 
        cout <<"Choose the option what to do.\n0 for exit.\n";
        cout <<"1.Create a Node\n";
        cout <<"2.Appened a node\n";
        cout <<"3.Prepend a Node\n";
        cout <<"4.Insert Node at any location\n";
        cout <<"5.Delete a Node from begin\n";
        cout <<"6.Delete a Node from end\n";
        cout <<"7.Delete a Node from any location\n";
        cout <<"8.No of element in the List\n";
        cout <<"9.Search any Element\n";

        cout <<"10.Display the list\n";

        cout<<"Enter option:";//take option
        cin>>option;
        //switch case for options
        switch (option)
        {
            case 1:
            s.create();//create function
            break;
            case 2:
            s.insert_at_end();//append
            break;
            case 3:
            s.insert_at_begin();//prepend
            break;
            case 4:
            s.insert_at_loc();//insert at any loc
            break;
            case5:
            s.delete_at_end();//delete at end
            break;
            case 6:
            s.delete_at_begin();//delete at begin
            break;
            case 7:
            s.delete_at_loc();//delete at any loc
            break;
            case 8:
            s.count();//count no of node in the list
            break;
            case 9:
            s.search();//search any node 
            break;
            case 10:
            s.display();//display the list
            break;
        }
        cout<<"Do you choose more option?(y/n)";
        cin>>ch;

    } while (ch == 'y');//do while for selecting again option



    return 0;
}