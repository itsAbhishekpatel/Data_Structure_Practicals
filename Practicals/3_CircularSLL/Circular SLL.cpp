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
class CircularSLL
{
    public:
    Node *head,*tail,*temp,*ptr;

    CircularSLL() //Constructor for intial head and tail
    {
        head = tail = 0;
    }
    //Destructor to free memory 
    ~CircularSLL()
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

    //check node is empty or not
    bool is_Empty()
    {
        if(tail == NULL)
        {
            return true;
        }
        else
        {
            return false;
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
void CircularSLL :: insert_at_begin()
{
    temp = new Node;
	cout << "Enter the node data : ";
	cin >> temp->data;
	if (is_Empty())
	{
		tail = temp;
		tail->next = tail;
	}
	else
	{
		temp->next = tail->next;
		tail->next = temp;
	}
	cout << "Node Inserted\n";
  
}

//Insert Node at end
void CircularSLL ::insert_at_end()
{
    temp = new Node;
	cout << "Enter the node data : ";
	cin >> temp->data;
	if (is_Empty())
	{
		tail = temp;
		tail->next = tail;
	}
	else
	{
		temp->next = tail->next;
		tail->next = temp;
		tail = temp;
	}
	cout <<"Node Inserted\n";
}

//Insert Node at any Location
void CircularSLL ::insert_at_loc()
{
    if (!is_Empty())
	{
		temp = new Node;
		int loc;
		cout << "\nEnter the location for new node : ";
		cin >> loc;
		if (loc > (count() + 1) || loc < 1)
			cout << "Invalid Location!\n";
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
				ptr->next = temp;
				cout << "Inserted!" << endl;
			}
		}
	}

}

//Delete Node at begin
void CircularSLL::delete_at_begin()
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
			tail->next = temp->next;
			delete temp;
		}
		cout << "Node Deleted" << endl;
	}
  
}

//Delete Node at end
void CircularSLL ::delete_at_end()
{
    if (!is_Empty())
	{
		if (tail->next == tail)
		{
			delete tail;
			tail=NULL;
		}
		else
		{
			ptr = tail;
			do
			{
				ptr = ptr->next;
			} while (ptr->next != tail);
			ptr->next = tail->next;
			delete tail;
			tail = ptr;
		}
		cout << "Node Deleted" << endl;
	}

}

//Delete Node at any Location
void CircularSLL ::delete_at_loc()
{
    if (!is_Empty())
	{
		int loc;
		cout << "\nEnter the location of node to delete : ";
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
			if (ptr->next == tail)
				delete_at_end();
			else
			{
				temp = ptr->next;
				ptr->next = temp->next;
				delete temp;
				cout << "Deleted from location : " << loc <<"\n";
			}
		}
	}

}

//Display The list
void CircularSLL ::display()
{
    if(is_Empty())
    {
        cout<<"List is Empty\n";
    }
    else
    {
        ptr = tail;
        do
        {
            ptr = ptr->next;
            cout<<"-->"<<ptr->data;
        } while (ptr != tail);
        
    }
    cout<<"\n";

}

//Count function
int CircularSLL ::count()
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
void CircularSLL ::search()
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
			cout << "Data found at location " << loc << " in the list." << endl;
		else
			cout << "Data not found in the list.";
	}

}

//reverse the list
void CircularSLL :: reverse()
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
			temp->next = temp1;
			temp1 = temp;
		}
		tail->next = temp1;
	}
	cout << "\nReversed!" << endl;

} 
int main(void)
{
    CircularSLL s;
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
            cout<<"No of Nodes is: "<<s.count()<<endl;// No of node in the list
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