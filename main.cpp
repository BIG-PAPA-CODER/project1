#include <cstdlib>
#include <iostream>             //********do zalatwenia: elem ktory najdluzej czeka, 
#include <string>               //********funkcja dodawania raz w jakis czas, funkcja ile elem na liscie,
using namespace std;            //********GUI, testy automatyczne, testy wydajnosciowe. Value of whole struct in bytes.
#include <windows.h>
#include <time.h>

typedef int Elem;
//template <typename Elem>               //definition of one node 
class DNode{
    private:
    Elem elem;
    DNode* prev;
    DNode* next;
    friend class DLinkedList;
};

//////////////////

class DLinkedList{  //definition of doubly linked list
    public:
        DLinkedList();  //constructor
        ~DLinkedList(); //distructor

        bool isEmpty(); //checks if list is empty
        const Elem& getFront() const; //shows next elem
        const Elem& getBack() const;  //shows prev elem
        void addFront(const Elem& e); // add to front of list
        void addBack(const Elem& e); // add to back of list
        void removeFront(); // remove from front
        void removeBack(); // remove from back
        void printDLL();
        int sizeofDLL();

    private:
        DNode* header;
        DNode* trailer;
    protected:
        void add(DNode* v, const Elem& e);
        void remove(DNode* v);
};

DLinkedList::DLinkedList(){
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
};

DLinkedList::~DLinkedList(){
    while (!isEmpty()) removeFront();
    delete header;
    delete trailer;
};

bool DLinkedList::isEmpty(){
    return header->next == trailer;
};

const Elem& DLinkedList::getFront() const{
    return header->next->elem;
};

const Elem& DLinkedList::getBack() const{
    return trailer->prev->elem;
};

void DLinkedList::add(DNode* v, const Elem& e){
    DNode* u = new DNode;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = v->prev = u;
};

void DLinkedList::remove(DNode* v){
    DNode* u = v->prev;
    DNode* w = v->next;
    u = w->prev;
    w = u->next;
    delete v; 
};

void DLinkedList::addFront(const Elem& e){
    add(header->next, e);
    //header = header->next;
};

void DLinkedList::addBack(const Elem& e){
    add(trailer, e);
};

void DLinkedList::removeFront(){
    remove(header->next);
    header = header->next;
};

void DLinkedList::removeBack(){
    remove(trailer->prev);
    //trailer = trailer->prev;
};

void DLinkedList::printDLL(){
    int res = 0;
    while(header != trailer->prev){                          
        cout << header->next->elem << " ";
        header = header->next;              //here is the problem, header is moved
        ++res;
    };
    
    int j = 0;                              //and here is the solution, returning head to its place
    while(j < res){
        header = header->prev;
        ++j;
    };

    cout << endl;
};

int DLinkedList::sizeofDLL(){

    int res = 0;
    int sizeDLL = 0;
    while(header != trailer){                          
        sizeDLL += sizeof(header);
        header = header->next;              
        ++res;
    };

    int j = 0;                              //returning head to its place
    while(j < res){
        header = header->prev;
        ++j;
    };

    return sizeDLL;
};


/*void addauto(){
    int number = 1;
        for (int i = 0; i < 10; i++){
            int TIME = rand() % 2000 + 500;
            DLL.addBack(number);
            number += 1;
            Sleep(TIME);
            DLL.printDLL();

        };   
};

void removeauto(){
    for (int j = 0; j < 5; j++){
            int TIME = rand() % 2000 + 500;
            DLL.removeFront();
            Sleep(TIME);
            DLL.printDLL();
            //Sleep(1000);
        };
};*/


int main(){
    
    DLinkedList DLL;
    
    //cout << "Size of queue: " << sizeof(DLL) << " bytes" << endl;

    int key;
    cout << "choose a key" << endl;
    cout << "1 - adding elements with delays" << endl;
    cout << "2 - adding elements without delays" << endl;
    cin >> key;

    int size;
    int num_op;
    int number;
    int random;
    srand(time(0));

    switch(key){
        case 1:

                cout << "Enter size of queue: " << endl;
                cin >> size;

                cout << "Enter number of operations: " << endl;
                cin >> num_op;
                
            for (int i = 0; i < size; i++){
                int TIME = rand() % 2000 + 500;
                number = rand() % 100000 + 0;
                DLL.addBack(number);
                Sleep(TIME);
                DLL.printDLL();
            };


            for (int j = 0; j < num_op; j++){

                int TIME = rand() % 2000 + 500;
                number = rand() % 100000 + 0;
                random = rand() % 2;

                if(random == 0){
                    DLL.addBack(number);
                };
                //DLL.addBack(number);
                Sleep(TIME);
                DLL.printDLL();
                if(!DLL.isEmpty()){
                    DLL.removeFront();
                    DLL.printDLL();
                }                
            };

            for (int j = 0; j < size; j++){
                
                DLL.removeFront();
                DLL.printDLL();
            };

            DLL.~DLinkedList();

            cout << endl;
        break;

        case 2:

                cout << "Enter size of queue: " << endl;
                cin >> size;

                cout << "Enter number of operations: " << endl;
                cin >> num_op;
                
            for (int i = 0; i < size; i++){
                number = rand() % 100000 + 0;
                DLL.addBack(number);
                DLL.printDLL();
            };


            for (int j = 0; j < num_op; j++){
                number = rand() % 100000 + 0;
                random = rand() % 1 + 0;

                if(random == 1){
                DLL.addBack(number);
                };

                //DLL.printDLL();
                DLL.removeFront();
                DLL.printDLL();
            };

            cout << endl;
            cout << "Size of queue: " << DLL.sizeofDLL() << " bytes" << endl; 
            cout << "Do you want to clean queue? (y/n)" << endl;
            
            char key1;
            cin >> key1;
            cout << endl;

                if (key1 == 'y'){
                    for (int j = 0; j < size; j++){
                        DLL.removeFront();
                        DLL.printDLL();
                    };
                    DLL.~DLinkedList(); 
                    cout << "Queue is empty." << endl;
                    cout << endl;
                }
                else{
                    cout << endl;
                    DLL.~DLinkedList();
                };
        break;

        case 000:
            DLL.printDLL();
            DLL.~DLinkedList();
        cout << endl;
        break;
    };
    
    return 0;
};
