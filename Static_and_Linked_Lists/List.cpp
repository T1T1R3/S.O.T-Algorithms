#include <iostream>
#include <cstdlib> 
#define MAX_VAL 1000

using namespace std;

//Static List declaration and functions

class StaticList{
public: 

    int listSize;
    int data[MAX_VAL];

    StaticList(){
        listSize = 0;
    }

    void insertListStatic(int);
    void insertSpecificStatic(int, int);
    void switchPositionStatic(int, int);
    int searchValueStatic(int);
    int lowerValueStatic();
    void printListStatic();
    void printInverseStatic();
    
    

};

void StaticList::insertListStatic(int value){
    if(listSize == 0){
        data[listSize] = value;
        listSize += 1;
        return;
    }

    data[listSize] = value;
    listSize += 1;

    return;
}

void StaticList::insertSpecificStatic(int pos, int value){
    for(int i = listSize; i > pos; i--)
        data[i] = data[i - 1];

    data[pos] = value;
    listSize += 1;
} 

void StaticList::switchPositionStatic(int pos1, int pos2){
    int aux = data[pos1];
    data[pos1] = data[pos2];

    data[pos2] = aux;

    return;
}

int StaticList::searchValueStatic(int value){
    for(int pos = 0; pos < listSize; pos++){
        if(data[pos] == value)
            return data[pos];
        if(data[pos] != value && pos == listSize - 1)
            return -1;
    }
    return -1;
}

int StaticList::lowerValueStatic(){
    int lower = data[0];

    for(int i = 0; i < listSize; i++){
        if(data[i] < lower){
            lower = data[i];

            return lower;
        }
    }

    return -1;
}

void StaticList::printListStatic(){
    if(listSize == 0)
        return;

    for(int i = 0; i < listSize; i++)
        cout << "Pos[" << i << "]: " << data[i] << endl;

    return;
}

void StaticList::printInverseStatic(){
    for(int i = listSize - 1; i >= 0; i--)
        cout << "Pos[" << i << "]: " << data[i] << endl;
    
    return;
}


//Node declaration;

class Node{
public:
    int data;
    Node* next;

    Node(){
        data = 0;
        next = NULL;
    }

    Node(int value){
        data = value;
        next = NULL;
    }
};

class DoublyNode{
public:
    int data;
    DoublyNode* next;
    DoublyNode* prev;

    DoublyNode(){
        data = 0;
        next = NULL;
        prev = NULL;
    }

    DoublyNode(int value){
        data = value;
        next = NULL;
        prev = NULL;
    }
};

//Linked Lists declaration and functions;

class LinkedList{

public:

    Node* head;
    int listSize;
    LinkedList(){
        head = NULL;
        listSize = 0;
    }

    void insertNodeSingly(int);
    void insertSpecificSingly(int, int);
    void switchPositionSingly(int, int);
    int searchValueSingly(int);
    int lowerValueSingly();
    void printListSingly();
    void printListInverseSingly();

};

void LinkedList::insertNodeSingly(int value){
    Node* newNode = new Node(value);

    if (!head){
        head = newNode;
        listSize += 1;
        return;
    }

    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }

    temp->next = newNode;
    listSize += 1;

    return;
}

void LinkedList::insertSpecificSingly(int pos, int value){
    Node* newNode = new Node(value);

    if(!head){
        head = newNode;
        listSize += 1;
        return;
    }

    if(pos == 0){
        Node* aux = head;
        newNode->next = aux;
        head = newNode;
        listSize += 1;
        return;
    }

    Node* temp = head;

    for(int i = 0; i < listSize; i++){
        if(i + 1 == pos){
            Node* aux = temp->next;
            temp->next = newNode;
            newNode->next = aux;

            temp = newNode;

            listSize += 1;
            return;
        }
        temp = temp->next;
    }

    return;
}

void LinkedList::switchPositionSingly(int pos1, int pos2){
    if(!head)
        return;

    Node* aux1 = head;
    Node* aux2 = head;

    for(int i = 0; i != pos1; i++)
        aux1 = aux1->next;

    for(int i = 0; i != pos2; i++)
        aux2 = aux2->next;

    int aux3 = aux1->data;

    aux1->data = aux2->data;
    aux2->data = aux3;
    return;
}

int LinkedList::searchValueSingly(int value){
    if(!head)
        return -1;

    Node* aux = head;

    while(aux && aux->data != value)
        aux = aux->next;

    if(!aux)
        return -1;

    if(aux->data == value)
        return aux->data;

    return -1;
}

int LinkedList::lowerValueSingly(){
    if(!head)
        return -1;

    Node* lower = head;
    Node* temp = head;
    temp = temp->next;
    for(int i = 0; i < listSize - 1; i++){
        if(temp->data < lower->data)
            lower = temp;
        temp = temp->next;
    }



    return lower->data;
}

void LinkedList::printListSingly(){
    Node* temp = head;
    int i = 0;

    while(temp->next){
        cout << "Pos[" << i << "]: "<< temp->data << endl;
        temp = temp->next;
        i++;
    }
    cout << "Pos[" << i << "]: " << temp->data;

    return;
}

void LinkedList::printListInverseSingly(){}


//DoublyLinkedList declaration and functions

class DoublyLinkedList{
public:

    DoublyNode* head;
    DoublyNode* last;
    int listSize;

    DoublyLinkedList(){
        head = NULL;
        last = NULL;
        listSize = 0;
    }

    void insertNodeDoubly(int);
    void insertSpecificDoubly(int, int);
    void switchPositionDoubly(int, int);
    int searchValueDoubly(int);
    int lowerValueDoubly();
    void printListDoubly();
    void printListInverseDoubly();

};

void DoublyLinkedList::insertNodeDoubly(int value){
    DoublyNode* newNode = new DoublyNode(value);

    if(!head){
        head = newNode;
        last = newNode;

        head->next = NULL;
        head->prev = NULL;

        listSize += 1;
        return;
    }

    if(!head->next){
        head->next = newNode;
        last = newNode;

        newNode->next = NULL;
        newNode->prev = head;

        listSize += 1;
        return;
    }

    DoublyNode* temp = head;

    while(temp->next)
        temp = temp->next;

    last = newNode;
    temp->next = newNode;

    newNode->next = NULL;
    newNode->prev = temp;

    listSize += 1;
    return;
}

void DoublyLinkedList::insertSpecificDoubly(int pos, int value){
    DoublyNode* newNode = new DoublyNode(value);
    if(!head){
        head = newNode;
        last = newNode;
        listSize += 1;
        return;
    }

    if(pos == 0){
        DoublyNode* aux = head;
        newNode->next = aux;
        head = newNode;
        last = newNode;

        listSize += 1;
        return;
    }

    if(pos == listSize){
        DoublyNode* aux = last;
        last->next = newNode;
        last = newNode;

        listSize += 1;
        return;
    }

    DoublyNode* temp = head;

    for(int i = 0; i < pos; i++)
        temp = temp->next;

    DoublyNode* aux1 = temp->prev;


    temp->prev = newNode;
    aux1->next = newNode;

    newNode->prev = aux1;
    newNode->next = temp;

    while(last)
        last = last->next;


}

void DoublyLinkedList::switchPositionDoubly(int pos1, int pos2){
    if(!head)
        return;

    DoublyNode* node1 = head;
    DoublyNode* node2 = head;

    for(int i = 0; i < pos1; i++)
        node1 = node1->next;
    
    for(int i = 0; i < pos2; i++)
        node2 = node2->next;

    int aux = node2->data;

    node2->data = node1->data;
    node1->data = aux;
}

int DoublyLinkedList::searchValueDoubly(int value){
    if(!head)
        return -1;

    DoublyNode* temp = head;

    for(int i = 0; i < listSize; i++){
        if(temp->data == value)
            return temp->data;
        
        temp = temp->next;
    }

    if(!temp)
        return -1;

    return -1;
}

int DoublyLinkedList::lowerValueDoubly(){
    if(!head)
        return -1;

    DoublyNode* lower = head;
    DoublyNode* temp = head;

    for(int i = 0; i < listSize; i++){
        if(temp->data < lower->data)
            lower = temp;
        temp = temp->next;
    }

    return lower->data;

}

void DoublyLinkedList::printListInverseDoubly(){
    if(!head)
        return;

    int i = listSize;
    DoublyNode* aux = last;
    while(aux != head){
        cout << "Pos[" << i << "]: "<< aux->data << endl;
        aux = aux->prev;
        i--;
    }
    cout << aux->data << endl;



}


void DoublyLinkedList::printListDoubly(){
    if(!head)
        return;
    int i = 0;
    if(!head->next){
        cout << "Pos[" << i << "]: "<< head->data << endl;
        return;
    }

    DoublyNode* temp = head;
    
    while(temp){    
        cout << "Pos[" << i << "]: "<< temp->data << endl;
        temp = temp->next;
        i++;
    }
}

//Random List Generator

StaticList randomStatic(){
    StaticList* ptr = new StaticList();
    for(int i = 0; i < 100; i++){
        ptr->insertListStatic(rand() % 1000);
    }

    return *ptr;
}

LinkedList randomLinked(){
    LinkedList* ptr = new LinkedList();
    for(int i = 0; i < 100; i++){
        ptr->insertNodeSingly(rand() % 1000);
    }

    return *ptr;
}

DoublyLinkedList randomDoubly(){
    DoublyLinkedList* ptr = new DoublyLinkedList();
    for(int i = 0; i < 100; i++){
        ptr->insertNodeDoubly(rand() % 1000);
    }

    return *ptr;
}

void printLists(StaticList staticListing, LinkedList linkedListing, DoublyLinkedList doublyListing){
    cout << "\n\n";
    cout << "Static List: " << endl;
    staticListing.printListStatic();

    cout << "\n\n";

    cout << "Linked Listing: " << endl;
    linkedListing.printListSingly();

    cout << "\n\n";

    cout << "Doubly Linked Listing: " << endl;
    doublyListing.printListDoubly();
}


//Main


int main(){
    int quantValues;
    int vetValues[quantValues];

    cin >> quantValues;

    StaticList* staticListing = new StaticList();
    LinkedList* linkedListing = new LinkedList();
    DoublyLinkedList* doublyListing = new DoublyLinkedList();

    for(int i = 0; i < quantValues; i++){
        int inserted;
        cin >> inserted;

        staticListing->insertListStatic(inserted);
        linkedListing->insertNodeSingly(inserted);
        doublyListing->insertNodeDoubly(inserted);
    }

    printLists(*staticListing, *linkedListing, *doublyListing);

    staticListing->insertSpecificStatic(10, 11);
    linkedListing->insertSpecificSingly(10, 11);
    doublyListing->insertSpecificDoubly(10, 11);

    staticListing->insertSpecificStatic(4, 2);
    linkedListing->insertSpecificSingly(4, 2);
    doublyListing->insertSpecificDoubly(4, 2);

    staticListing->insertSpecificStatic(0, 7);
    linkedListing->insertSpecificSingly(0, 7);
    doublyListing->insertSpecificDoubly(0, 7);

    printLists(*staticListing, *linkedListing, *doublyListing);

    cout << "\n\n";

    cout << "Static searching: " << staticListing->searchValueStatic(10) << endl;
    cout << "Linked searching: " << linkedListing->searchValueSingly(10) << endl;
    cout << "Doubly searching: " << doublyListing->searchValueDoubly(10) << endl;

    cout << "\n\n";

    cout << "Static searching: " << staticListing->searchValueStatic(8) << endl;
    cout << "Linked searching: " << linkedListing->searchValueSingly(8) << endl;
    cout << "Doubly searching: " << doublyListing->searchValueDoubly(8) << endl;

    cout << "\n\n";

    cout << "Static searching: " << staticListing->searchValueStatic(12) << endl;
    cout << "Linked searching: " << linkedListing->searchValueSingly(12) << endl;
    cout << "Doubly searching: " << doublyListing->searchValueDoubly(12) << endl;


    cout << "\n\n";

    staticListing->switchPositionStatic(3, 4);
    linkedListing->switchPositionSingly(3, 4);
    doublyListing->switchPositionDoubly(3, 4);

    staticListing->switchPositionStatic(0, 6);
    linkedListing->switchPositionSingly(0, 6);
    doublyListing->switchPositionDoubly(0, 6);

    staticListing->switchPositionStatic(6, 12);
    linkedListing->switchPositionSingly(6, 12);
    doublyListing->switchPositionDoubly(6, 12);

    printLists(*staticListing, *linkedListing, *doublyListing);

    cout << "\n\n";


    cout << "Lower value static: " << staticListing->lowerValueStatic() << endl;
    cout << "Lower value linked: " << linkedListing->lowerValueSingly() << endl;
    cout << "Lower value doubly: " << doublyListing->lowerValueDoubly() << endl;

    cout << "\n\n";

    cout << "Static List: " << endl;
    staticListing->printInverseStatic();

    //cout << "Linked List: " << endl;
    //linkedListing->printListInverseSingly();

    cout << "\n\nDoubly List: " << endl;
    doublyListing->printListInverseDoubly();

    cout << "\n\nStatic Random List: " << endl;

    StaticList RandomValues = randomStatic();
    RandomValues.printListStatic();

    cout << "\n\nLinked Random List" << endl;

    LinkedList RandomValuesLk = randomLinked();
    RandomValuesLk.printListSingly();

    cout << "\n\nDoubly Random List" << endl;

    DoublyLinkedList RandomValuesDb = randomDoubly();
    RandomValuesDb.printListDoubly();

    cout << "\n\n";

    cout << "Lower value static: " << RandomValues.lowerValueStatic() << endl;
    cout << "Lower value linked: " << RandomValuesLk.lowerValueSingly() << endl;
    cout << "Lower value doubly: " << RandomValuesDb.lowerValueDoubly() << endl;

    cout << "\n\nStatic List: " << endl;
    RandomValues.printInverseStatic();

    //cout << "Linked List: " << endl;
    //RandomValuesLk.printListInverseSingly();

    cout << "\n\nDoubly List: " << endl;
    RandomValuesDb.printListInverseDoubly();


    return 0;
}
