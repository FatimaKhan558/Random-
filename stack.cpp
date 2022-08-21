#include <iostream>
using namespace std;
class Node
{
	    private:
	    int data;
	    Node* Next;
	    public:
	    Node(int data, Node* Next=NULL)
	    {
	        this-> data = data;
	        Next = NULL;
	    }
	    void SetData (int data)
	    {
	        this -> data = data;
	    }
	    void SetNext (Node* Next)
	    {
	        this-> Next = Next;
	    }
	    int GetData()
	    {
	        return this-> data;
	    }
	    Node* GetNext()
	    {
	        return this->Next;
	    }
	    
	
	};
class LinkedList {
	private:
		Node* head;
		public:
			LinkedList()
			{
				head=NULL;
			}
			bool isEmpty()
			{
				if (head!=NULL)
				{
					return false;
				}
				else
				 return true;
			}
			
			
			void insertAtbeginning(int data)
			{
			if (head==NULL)
			head=new Node (2);
			}
			
			 void insertAtLast(int val)
		{
			Node *temp=new Node(val);
			if(isEmpty())
			{
				head=temp;
			}
			else
			{
				Node *temp=head;
				while(temp->GetNext()!=NULL)
				{
					temp=temp->GetNext();
				}
				temp->SetNext(temp);
			}
		}

	
		void RemoveFromBegin()
		{
			if(!isEmpty())
			{
				Node *temp=head->GetNext();
				delete head;
				head=temp;
			}
		}
		void RemoveFromEnd()
		{
			Node *t1=head;
			Node *t2=t1->GetNext();
			while(t2->GetNext()!=NULL)
			{
				t1=t1->GetNext();
				t2=t2->GetNext();
			}
			delete t2;
			t1->SetNext(NULL);
		}
		int getLength()
		{
			int count=1;
			Node *temp=head;
			while(temp!=NULL)
			{
				temp=temp->GetNext();
				count++;
			}
			return count;
		}
	Node* getFirstElement()
		{
			if(!isEmpty())
			{
				return head;
			}
		}
		
		Node* getLastElement()
		{
			Node *t1=head;
			Node *t2=t1->GetNext();
			while(t2->GetNext()!=NULL)
			{
				t1=t1->GetNext();
				t2=t2->GetNext();
			}
			return t2;
		}
		
};
class Stack
{
	private:
		LinkedList l1;
		int size;
	public:
		void setSize(int size)
	{
		this->size = size;
	}
	int getSize()
	{
		return size;
	}
	Stack(int size)
	{
		setSize(size);
	}
	bool push(int val)
	{
		if (!(isFull()))
		{
			l1.insertAtbeginning(val);
			return true;
		}
		else
		{
			cout << "Stack is Full"<< endl;
			return false;
		}
	}
	Node* pop()
	{
		if (!(isEmpty()))
		{
			Node* data = l1.getFirstElement();
			l1.RemoveFromBegin();
			return data;
		}
		else
		{
			cout << "Stack is Empty."<<endl;
		}
	}
	bool isEmpty()
	{
		return (l1.isEmpty()) ? true : false;
	}
	bool isFull()
	{
		int length = l1.getLength();
		return (length == size) ? true : false;
	}
	Node* getTop()
	{
		if (!(l1.isEmpty()))
		{
			return l1.getFirstElement();
		}
		else
		{
			cout << "Stack is Empty."<<endl;
		}
}
	};
int main()
{
	Stack s1(10);
	s1.push(5);
	s1.setSize(10);
	s1.getSize();
	s1.getTop();
	s1.isEmpty();
	s1.isFull();
	s1.pop();
	return 0;
	}
	
