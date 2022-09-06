#include <iostream>

using namespace std;
class Node {
private:
    int data;
    Node * next;
public:
    Node(int data, Node * next = NULL) {
        this->data = data;
        this->next = next;
    }
    void setData(int data) {
        this->data = data;
    }
    void setNext(Node * next) {
        this->next = next;
    }
    int getData() {
        return this->data;
    }
    Node * getNext() {
        return this->next;
    }

};
class LinkedList {
private:
    Node * head;
public:
    LinkedList() {
        head = NULL;
    }
    bool isEmpty() {
        if (head != NULL) {
            return false;
        } else
            return true;
    }

    void insertAtbeginning(int data) {
        Node * temp = new Node(data,head);
        head = temp;
    }

    void insertAtLast(int val) {
        Node * temp = new Node(val);
        if (isEmpty()) {
            head = temp;
        } else {
            Node * temp2 = head;
            while (temp2->getNext() != NULL) {
                temp2 = temp2->getNext();
            }
            temp2->setNext(temp);
        }
    }

    void removeFromBegin() {
        if (!isEmpty()) {
            Node * temp = head->getNext();
            delete head;
            head = temp;
        }
    }
    void removeFromEnd() {
        Node * t1 = head;
        Node * t2 = t1 -> getNext();
        while (t2 -> getNext() != NULL) {
            t1 = t1 -> getNext();
            t2 = t2 -> getNext();
        }
        delete t2;
        t1 -> setNext(NULL);
    }
    int getLength() {
        int count = 0;
        Node * temp = head;
        while (temp != NULL) {
            temp = temp->getNext();
            count++;
        }
        return count;
    }
    Node * getFirstElement() {
        if (!isEmpty()) {
            return head;
        }
        return NULL;
    }

    Node * getLastElement() {
        Node * t1 = head;
        while (t1->getNext()  != NULL) {
            t1 = t1->getNext();
        }
        return t1;
    }

    void print(){
        for(Node * temp = head ; temp != NULL ; temp = temp->getNext()){
            cout << temp->getData() << "->";
        }
        cout << "NULL\n";
    }

};
class Stack {
private:
    LinkedList l1;
    int size;
public:
    Stack(){
        size = 100;
    }
    void setSize(int size) {
        this->size = size;
    }
    int getSize() {
        return size;
    }
    Stack(int size) {
        setSize(size);
    }
    bool push(int val) {
        if (!(isFull())) {
            l1.insertAtbeginning(val);
            return true;
        } else {
            cout << "Stack is Full" << endl;
            return false;
        }
    }
    int pop() {
        if (!(isEmpty())) {
            int data = l1.getFirstElement()->getData();
            l1.removeFromBegin();
            return data;
        } else {
            cout << "Stack is Empty." << endl;
        }
        return -9999;
    }
    bool isEmpty() {
        return (l1.isEmpty());
    }
    bool isFull() {
        int length = l1.getLength();
        return (length == size);
    }
    int top() {
        if (!(l1.isEmpty())) {
            return l1.getFirstElement()->getData();
        } else {
            cout << "Stack is Empty." << endl;
        }
        return -9999;
    }
    
    void print(){
        l1.print();
    }
};

int main() {
    Stack s1(10);
    s1.push(5);
    s1.push(10);
    s1.print();
    cout << "\nTop : " << s1.top();
    cout << "\nisEmpty : " << s1.isEmpty();
    cout << "\nisFull : " << s1.isFull();
    cout << "\nPopped : " << s1.pop();
    return 0;
}
