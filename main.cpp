#include <iostream>
#include <stdlib.h>

void menu();
void enqueue(int newData);
void dequeue();
void displayFront();
void isEmpty();
void isFull();
void displayQueue();
void clean();

using namespace std;

struct node {
    int data;
    struct node *link;
};

struct node* front = NULL;
struct node* rear = NULL;
#define maximum 10
int queueSize = 1;

int main()
{
    system("color 0A");
    int choice, insertData;

    menu:
    menu();
    cout << ">> Enter your choice: ";
    cin >> choice;
    cout << endl;

    switch(choice){
        case 1:
            cout << ">> " << queueSize << ") Enter data to insert: ";
            cin >> insertData;
            enqueue(insertData);
            clean();
            goto menu;
            break;

        case 2:
            dequeue();
            clean();
            goto menu;
            break;

        case 3:
            displayFront();
            clean();
            goto menu;
            break;

        case 4:
            isEmpty();
            clean();
            goto menu;
            break;

        case 5:
            isFull();
            clean();
            goto menu;
            break;

        case 6:
            displayQueue();
            clean();
            goto menu;
            break;

        case 0:
            return 0;

        default:
            cout << "Invalid Input\n\n\n";
            clean();
            goto menu;
    }
}

void menu(){
    cout << "Q U E U E  O P E R A T I O N S\n\n";
    cout << "[1] - E N Q U E U E\n";
    cout << "[2] - D E Q U E U E\n";
    cout << "[3] - F R O N T\n";
    cout << "[4] - I S  E M P T Y\n";
    cout << "[5] - I S  F U L L\n";
    cout << "[6] - D I S P L A Y  Q U E U E\n";
    cout << "[0] - E X I T\n\n";
}

void enqueue(int newData){
    if(queueSize > maximum){
        cout << "Overflow\n\n\n";
    }
    else{
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode -> data = newData;
        newNode -> link = NULL;

        if(front == NULL){
            front = newNode;
            rear = newNode;
            cout << "Data has been added\n\n\n";
        }
        else{
            rear -> link = newNode;
            rear = newNode;
            cout << "Data has been added\n\n\n";
        }

        queueSize++;
    }
}

void dequeue(){
    if(front == NULL && rear == NULL){
        cout << "No data to be deleted\n\n\n";
    }
    else if(front == rear){
        queueSize--;
        free(front);
        front = rear = NULL;
        cout << "Data has been deleted\n\n\n";
    }
    else{
        queueSize--;
        struct node *ptr;
        ptr = front;
        front = front -> link;
        free(ptr);
        cout << "Data has been deleted\n\n\n";
    }
}

void displayFront(){
    if(front == NULL){
        cout << "Queue is empty\n\n\n";
    }
    else{
        cout << "Front Data: " << front -> data << "\n\n\n";
    }
}

void isEmpty(){
    if(front == NULL && rear == NULL){
        cout << "Queue is empty: TRUE\n\n\n";
    }
    else{
        cout << "Queue is empty: FALSE\n\n\n";
    }
}

void isFull(){
    if(queueSize - 1 == maximum){
        cout << "Queue is full: TRUE\n\n\n";
    }
    else{
        cout << "Queue is full: FALSE\n\n\n";
    }
}

void displayQueue(){
    struct node *ptr;
    ptr = front;

    if(front == NULL && rear == NULL){
        cout << "Queue has no data to display\n\n\n";
    }
    else{
        cout << "Queue Data: ";
        while(ptr != NULL){
            cout << ptr -> data << " ";
            ptr = ptr -> link;
        }

        cout << "\n\n\n";
    }
}

void clean(){
    system("PAUSE");
    system("CLS");
}
