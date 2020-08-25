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

//CircularDoublyLinkedList Class
class CircularDLL
{
    public:
    Node *head,*tail,*temp,*ptr;

    CircularDLL() //Constructor for intial head and tail
    {
        tail=NULL;
    }
    //Destructor to free memory 
    ~CircularDLL()
	{
		cout << "\nDeallocating memory...\n";
		ptr = tail->next;
		tail->next = NULL;
		while (ptr != NULL)
		{
			temp = ptr->next;
			delete ptr;
			ptr = temp;
		}
	}

    //create function for create a node
    bool is_Empty()
    {
        if (tail == NULL)
		return true;
	else
		return false;

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
void CircularDLL ::insert_at_begin()
{
    temp = new Node;
	cout << "Enter the node data : ";
	cin >> temp->data;
	if (is_Empty())
	{
		tail = temp;
		tail->prev = tail;
		tail->next = tail;
	}
	else
	{
		temp->next = tail->next;
		temp->prev = tail;
		tail->next->prev = temp;
		tail->next = temp;
	}
	cout << "Node Inserted" << endl;
  
}

//Insert Node at end
void CircularDLL ::insert_at_end()
{
    temp = new Node;
	cout << "Enter the node data : ";
	cin >> temp->data;
	if (is_Empty())
	{
		tail = temp;
		tail->prev = tail;
		tail->next = tail;
	}
	else
	{
		temp->next = tail->next;
		temp->prev = tail;
		tail->next->prev = temp;
		tail->next = temp;
		tail = temp;
	}
	cout << "Node Inserted" << endl;

}

//Insert Node at any Location
void CircularDLL ::insert_at_loc()
{
    
	if (!is_Empty())
	{
		temp = new Node;
		int loc;
		cout << "Enter the location for new node : ";
		cin >> loc;
		if (loc > (count() + 1) || loc < 1)
			cout << "Invalid Location\n";
		else if (loc == 1)
			insert_at_begin();
		else
		{
			ptr = tail->next;
			for (int i = 1; i < loc - 1; i++)
			{
				ptr = ptr->next;
			}
			if (ptr == tail)
				insert_at_end();
			else
			{
				cout << "Enter the node data : ";
				cin >> temp->data;
				temp->next = ptr->next;
				temp->prev = ptr;
				ptr->next->prev = temp;
				ptr->next = temp;
				cout << "Node Inserted" << endl;
			}
		}
	}

}

//Delete Node at begin
void CircularDLL::delete_at_begin()
{
    if (!is_Empty())
	{
		temp = tail->next;
		if (tail->next == tail)
		{
			delete temp;
			tail = NULL;
		}
		else
		{
			temp->next->prev = tail;
			tail->next = temp->next;
			delete temp;
		}
		cout << "Deleted one node from beginning" << endl;
	}
  
}

//Delete Node at enD
void CircularDLL ::delete_at_end()
{
    
	if (!is_Empty())
	{
		temp = tail->prev;
		if (temp == tail)
		{
			delete tail;
			tail=NULL;
		}
		else
		{
			temp->next = tail->next;
			tail->next->prev = temp;
			delete tail;
			tail = temp;
		}
		cout << "Deleted one node from end" << endl;
	}

}

//Delete Node at any Location
void CircularDLL ::delete_at_loc()
{
    if (!is_Empty())
	{
		int loc;
		cout << "Enter the location of node to delete : ";
		cin >> loc;
		if (loc > count() || loc < 1)
			cout << "Invalid location\n";
		else if (loc == 1)
			delete_at_begin();
		else
		{
			ptr = tail->next;
			for (int i = 1; i < loc - 1; i++)
			{
				ptr = ptr->next;
			}
			temp = ptr->next;
			if (temp == tail)
				delete_at_end();
			else
			{
				ptr->next = temp->next;
				temp->next->prev = ptr;
				delete temp;
				cout << "Deleted from location : " << loc << endl;
			}
		}
	}

}

//Display The list
void CircularDLL ::display()
{
    cout << "\n\t";
	if (is_Empty())
		cout << "Linked List is empty.";
	else
	{
		ptr = tail;
		do
		{
			ptr = ptr->next;
			cout << " <--> " << ptr->data;
		} while (ptr != tail);
		cout << " <--> ";
	}
	cout << endl;

}

//Count function
int CircularDLL ::count()
{
    int count = 0;
	ptr = tail;
	do
	{
		ptr = ptr->next;
		++count;
	} while (ptr != tail);
	return count;

}

//Search Function
void CircularDLL ::search()
{
    if (!is_Empty())
	{
		int data;
		int loc = 0;
		bool contains = false;
		cout << "Enter the node data to be searched : ";
		cin >> data;
		ptr = tail;
		do
		{
			ptr = ptr->next;
			++loc;
			if (ptr->data == data)
			{
				contains = true;
				break;
			}
		} while (ptr != tail);
		if (contains)
			cout << "Data found at location " << loc << " in the list.\n";
		else
			cout << "Data not found in the list.";
	}

}

//reverse the list
void CircularDLL :: reverse()
{
   if (!is_Empty() && (tail->next != tail))
	{
		Node *temp1 = new Node;
		temp1 = tail->next;
		ptr = temp1->next;
		tail->next = NULL;
		tail = temp1;
		while (ptr != NULL)
		{
			temp = ptr;
			ptr = ptr->next;
			temp->prev = temp1;
			temp->next = temp1;
			temp1->prev = temp;
			temp1 = temp;
		}
		tail->next = temp1;
	}
	cout << "Reversed List\n";
} 
int main(void)
{
    CircularDLL s;
    int option;
    char ch;

    do
    {
        //Menu 
        cout <<"Choose the option what to do.\n0 for exit.\n";
        cout <<"1.Insert Node at Begining\n";
        cout <<"2.Insert Node at End\n";
        cout <<"3.Insert Node at any Location \n";
        cout <<"4.Delete a Node from Begin\n";
        cout <<"5.Delete a Node from End\n";
        cout <<"6.Delete a Node from any Location\n";
        cout <<"7.No of element in the List\n";
        cout <<"8.Search any Element\n";
        cout <<"9.Reverse the List\n";
        cout <<"10.Display the list\n";

        cout<<"Enter option:";//take option
        cin>>option;
        //switch case for options
        switch (option)
        {
            case 1:
            s.insert_at_begin();//insert the node at begin
            break;
            case 2:
            s.insert_at_end();//insert the node at end
            break;
            case 3:
            s.insert_at_loc();//insert the node at any loc
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
            cout<<"No of Node is : "<<s.count()<<"\n";//count no of node in the list
            break;
            case 8:
            s.search();//search any node 
            break;
            case 9:
            s.reverse();//reverse the list
            case 10:
            s.display();//display the list
            break;
        }
        cout<<"Do you choose more option?(y/n)";
        cin>>ch;

    } while (ch == 'y');//do while for selecting again option
    return 0;
}