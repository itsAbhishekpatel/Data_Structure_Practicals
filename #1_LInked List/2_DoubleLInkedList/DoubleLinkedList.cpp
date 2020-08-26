//By Abhishek Patel ...
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
    //count function for 
    int count();
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

    //reverse the list
    void reverse();
};

//Insert Node at begin
void DoublyLinkedList::insert_at_begin()
{
    temp = new Node();
    cout<<"Enter the node data:";
    cin>>temp->data;
    if(head==NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        head=temp;
        tail=head;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head=temp;
    }
    cout<<"Node Inserted\n";
    
}


//Insert Node at end
void DoublyLinkedList ::insert_at_end()
{
    temp =new Node();
    cout<<"Enter the Node data:";
    cin>>temp->data;
    temp->next=NULL;

    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
        tail = head;
    }
    else
    {
        temp->prev = tail;
        tail->next = temp;
        tail=temp;      
    }
    cout<<"Node Inserted\n";

}

//Insert Node at any Location
void DoublyLinkedList ::insert_at_loc()
{
    if (head != NULL)
	{
		temp = new Node;
		int loc;
		cout << "\nEnter the location for new node : ";
		cin >> loc;
		if (loc > (count() + 1) || loc < 1)
			{
                cout << "Invalid Location\n";
            }
		else if (loc == 1)
			{
                insert_at_begin();
            }
		else
		{
			ptr = head;
			for (int i = 1; i < loc - 1; i++)
			{
				ptr = ptr->next;
			}
			if (ptr == tail)
				{
                    insert_at_end();
                }
			else
			{
				cout << "Enter the node data : ";
				cin >> temp->data;
				temp->next = ptr->next;
				temp->prev = ptr;
				ptr->next->prev = temp;
				ptr->next = temp;
				cout << "Inserted" << endl;
			}
		}
	}
	else
		insert_at_end();

}

//Delete Node at begin
void DoublyLinkedList::delete_at_begin()
{
    if (head!=NULL)
	{
		if (head == tail)
		{
			delete tail;
			head = NULL;
		}
		else
		{
			temp = head;
			head = head->next;
			head->prev = NULL;
			delete temp;
		}
		cout << "Node Deleted" << endl;
	}
  
}

//Delete Node at end
void DoublyLinkedList ::delete_at_end()
{
    if (head != NULL)
	{
		if (head == tail)
		{
			delete tail;
			head = NULL;
		}
		else
		{
			temp = tail->prev;
			delete temp->next;
			temp->next = NULL;
			tail = temp;
		}
		cout << "Node Deleted" << endl;
	}

}

//Delete Node at any Location
void DoublyLinkedList ::delete_at_loc()
{
    if(head!=NULL)
    {
        int loc;
        temp = new Node();
        cout<<"Enter the location of node to be deleted:";
        cin>>loc;
        if (loc > count() || loc < 1)
			{
                cout << "Invalid location\n";
            }
		else if (loc == 1)
			{
                delete_at_begin();
            }
        else
		{
			ptr = head;
			for (int i = 1; i < loc - 1; i++)
			{
				ptr = ptr->next;
			}
			if (ptr == tail)
				delete_at_end();
			else
			{
				temp = ptr->next;
				ptr->next = temp->next;
				temp->next->prev = ptr;
				delete temp;
				cout << "Deleted from location : " << loc << endl;
			}
        }   
    }
    
}

//Display The list
void DoublyLinkedList ::display()
{
    if(head==NULL)
    {
        cout<<"List is Empty/n";
        
    }
    ptr=head;
    while(ptr != NULL)
    {
        if(ptr==head)
        {
            cout<<ptr->data;
        }
        else
        {
            cout<<"<-->"<<ptr->data;
        }
        ptr=ptr->next;
       
    }
    cout<<"\n"; 

}

//Count function
int DoublyLinkedList ::count()
{
    int count=0;
    ptr=head;
    while(ptr != NULL)
    {
        ptr=ptr->next;
        count++;
    }
    return count;

}

//Search Function
void DoublyLinkedList ::search()
{
    if (head!=NULL)
	{
		int data;
		int loc = 0;
		bool contains = false;
		cout << "\nEnter the node data to be searched : ";
		cin >> data;
		ptr = head;
		while (ptr != NULL)
		{
			++loc;
			if (ptr->data == data)
			{
				contains = true;
				break;
			}
			ptr = ptr->next;
		}
		if (contains == 1)
			cout << "Data found at location " << loc << " in the list." << endl;
		else
			cout << "Data not found in the list.";
	}

}

//reverse the list
void DoublyLinkedList :: reverse()
{
    
	if (head!=NULL)
	{
		ptr = head->next;	
		head->next = NULL;	
		tail = head;	
		while (ptr != NULL)	
		{	
			temp = ptr;	
			ptr = ptr->next;	
			temp->prev = NULL;	
			temp->next = head;	
			head->prev = temp;	
			head = temp;	
		}	
		cout << "\nReversed!" << endl;
        display();
        cout<<"\n";
	}

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
        cout <<"1.Appened a node\n";
        cout <<"2.Prepend a Node\n";
        cout <<"3.Insert Node at any location\n";
        cout <<"4.Delete a Node from begin\n";
        cout <<"5.Delete a Node from end\n";
        cout <<"6.Delete a Node from any location\n";
        cout <<"7.No of element in the List\n";
        cout <<"8.Search any Element\n";
        cout <<"9.Reverse the list\n";
        cout <<"10.Display the list\n";

        cout<<"Enter option:";//take option
        cin>>option;
        //switch case for options
        switch (option)
        {
            case 1:
            s.insert_at_end();//append
            break;
            case 2:
            s.insert_at_begin();//prepend
            break;
            case 3:
            s.insert_at_loc();//insert at any loc
            break;
            case 4:
            s.delete_at_begin();//delete at end
            break;
            case 5:
            s.delete_at_end();//delete at begin
            break;
            case 6:
            s.delete_at_loc();//delete at any loc
            break;
            case 7:
            cout<<"No of Nodes is : "<<s.count();//count no of node in the list
            break;
            case 8:
            s.search();//search any node 
            break;
            case 9:
            s.reverse();//reverse the list
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