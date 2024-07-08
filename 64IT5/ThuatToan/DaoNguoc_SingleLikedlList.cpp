#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newElement(int data)  {
    Node* e = new Node;
    e->data = data;
    e->next = NULL;

    return e;
}

void initialize(Node*& n)    {
    n = NULL;
}

void print(Node* n) {
    while(n != NULL)    {
        cout << n->data << " ";
        n = n->next;
    }
}

void addFirst(Node*& n, int data)   {
    Node* e = newElement(data);
    e->next = n;
    n = e;
}

void input(Node*& n) {
    int num_of_element, d;
    cout << "Enter number of element: ";
    cin >> num_of_element;

    for(int i = 0; i < num_of_element; i++) {
        cout << "Enter value: ";
        cin >> d;
        addFirst(n, d);
    }
}

void reverseList(Node*& n)  {
    if(n == NULL)
        return;

    Node *current = NULL;
    Node *previous = NULL;

    while(n != NULL)    {
        current = n;
        n = n->next;
        current->next = previous;
        previous = current;
    }
    n = current;
}

int main()  {

    Node* list;
    initialize(list);
    input(list);
    print(list);

    cout << endl << endl;

    reverseList(list);
    print(list);
    return 0;
}
