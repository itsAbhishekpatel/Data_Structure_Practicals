#include <iostream>

using namespace std;

//create node data type.
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int d, Node *ptr = 0)
    {
        data = d;
        next = ptr;
    }
};

//SingleLinkedList class
class SinglyLinkedList
{
public:
    Node *head, *tail, *temp, *ptr;

    SinglyLinkedList() //Constructor
    {
        head = tail = 0;
    }
    ~SinglyLinkedList() //Destructor to free memory
    {
        cout << "Deallocalised Memory\n";
        ptr = head;
        while (ptr != NULL)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
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
    void reverse();
};

// Append Node(insert node at end)
void SinglyLinkedList::insert_at_end()
{
    temp = new Node();
    cout << "Enter the data to store :";
    cin >> temp->data;
    if (head == NULL)
    {
        temp->next = head;
        head = temp;
        cout << "Node Inserted" << endl;
    }
    else
    {
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
        cout << "Node Inserted" << endl;
    }
}

//prepend Node(insert node at begin)
void SinglyLinkedList ::insert_at_begin()
{
    temp = new Node();
    cout << "Enter the data to store:";
    cin >> temp->data;
    temp->next = head;
    head = temp;
    cout << "Node Inserted" << endl;
}

//insert_at_any location in node
void SinglyLinkedList ::insert_at_loc()
{
    int n;
    temp = new Node();
    cout << "Enter the location to insert node:";
    cin >> n;
    cout << "Enter the data:";
    cin >> temp->data;
    ptr = head;
    for (int i = i; i < (n - 1); i++)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    cout << "Node Inserted" << endl;
}
//Delete a Node at_begin in list
void SinglyLinkedList ::delete_at_begin()
{
    if (head == NULL)
    {
        cout << "Node is Empty.\n";
    }
    else
    {
        temp = head;
        head = head->next;
        delete temp;
        cout << "Node Deleted.\n";
    }
}
//Delete a Node at_end in list
void SinglyLinkedList ::delete_at_end()
{
    if (head == NULL)
    {
        cout << "Node is Empty.\n";
    }
    else
    {
        ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        delete ptr->next;
        ptr->next = NULL;
        tail = ptr;
        cout << "Node Delete\n";
    }
}
//Delete Node of any location.
void SinglyLinkedList ::delete_at_loc()
{
    int n;
    cout << "Enter the Location:";
    cin >> n;
    ptr = head;
    for (int i = 1; n < n - 1; n++)
    {
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = ptr->next->next;
    delete temp;
    cout << "Deleted from location : " << n << "!" << endl;
}
//Display Function
void SinglyLinkedList ::display()
{
    if (head == NULL)
    {
        cout << "SSL is Empty.\n";
    }
    ptr = head;
    while (ptr != NULL)
    {
        cout << "-->" << ptr->data;
        ptr = ptr->next;
    }
    cout << "\n";
}

//Count function
void SinglyLinkedList::count()
{
    int count = 0;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        ++count;
    }
    cout << "No of Nodes is :" << count << endl;
}

//function for search the Node in list
void SinglyLinkedList ::search()
{
    int n, count = 0, flag = 0;
    cout << "Enter the node to search:";
    cin >> n;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        if (ptr->data == n)
        {
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (flag == 1)
    {
        cout << n << " is found at location " << count << endl;
    }
    else
    {
        cout << "Data is not found!\n";
    }
}

//Reverse the list
void SinglyLinkedList ::reverse()
{
    ptr = head->next;
    head->next = NULL;
    tail = head;
    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        temp->next = head;
        head = temp;
    }
    cout << "\nReversed!" << endl;
    display();
}

//Main Function...
int main(void)
{
    SinglyLinkedList s;
    int option;
    char ch;

    do
    {
        //Menu
        cout << "Choose the option what to do.\n0 for exit.\n";
        cout << "1.Appened a node\n";
        cout << "2.Prepend a Node\n";
        cout << "3.Insert Node at any location\n";
        cout << "4.Delete a Node from begin\n";
        cout << "5.Delete a Node from end\n";
        cout << "6.Delete a Node from any location\n";
        cout << "7.No of element in the List\n";
        cout << "8.Search any Element\n";
        cout << "9.Reverse the List\n";

        cout << "10.Display the list\n";

        cout << "Enter option:"; //take option
        cin >> option;
        //switch case for options
        switch (option)
        {
        case 1:
            s.insert_at_end(); //append
            break;
        case 2:
            s.insert_at_begin(); //prepend
            break;
        case 3:
            s.insert_at_loc(); //insert at any loc
            break;
        case 4:
            s.delete_at_end(); //delete at end
            break;
        case 5:
            s.delete_at_begin(); //delete at begin
            break;
        case 6:
            s.delete_at_loc(); //delete at any loc
            break;
        case 7:
            s.count(); //count no of node in the list
            break;
        case 8:
            s.search(); //search any node
            break;
        case 9:
            s.reverse(); //reverse the list
            break;
        case 10:
            s.display(); //display the list
            break;
        }
        cout << "Do you choose more option?(y/n)";
        cin >> ch;

    } while (ch == 'y'); //do while for selecting again option

    return 0;
}
//By Abhishek Patel
// 19/78106
