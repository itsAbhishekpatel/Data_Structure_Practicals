// stack implementation using array 

#include<iostream>
using namespace std;

class stack
{
    private:
    int top;
    int arr[10];

    public:
    stack()
    {
        top = -1;
        for (int i = 0; i < 10; i++)
        {
            arr[i]=0;
        }
    }
    
    // isEmpty function //
    bool isEmpty()
    {
            if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // isFull function //
    bool isFull()
    {
            if (top == 9)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // push function //
    void push(int value)
    {
        if(isFull)
        {
            cout<<"Stack overflow.\n";

        }
        else
        {
            top++;
            arr[top]=value;
        }
           
    }

    // pop function //
    int pop()
    {
        if (isEmpty)
        {
            cout<<"Stack underflow.\n";
        }
        else
        {
            int pvalue = arr[top];
            arr[top] = 0;
            top--;
            return pvalue;
        }
        
    }

    //count function
    int count()
    {
        return( top+1);
    }

    //peek function
    int peek(int pos)
    {
        if (isEmpty)
        {
            cout<<"Stack underflow.\n";
        }
        else
        {
            return arr[pos];
        }
        
    }

    //change function
    void change(int pos, int value)
    {
        arr[pos] = value;
        cout<<"change at position "<<pos<<endl;
    }

    //display function
    void display()
    {
        cout<<"Values of Stack are\n";
        for( int i=9; i>=0; i++)
        {
            cout<<arr[i]<<endl;
        }
    }

    //clear the stack
	void clear()
	{
		cout << "\nClearing the stack...";
		while(!isEmpty())
		{
            pop();
		    cout << " Done" <<endl;
        }
	}

};
int main(void)
{

    return 0;
}