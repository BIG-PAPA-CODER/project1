#include <cstdlib>
#include <iostream>             //********do zalatwenia: elem ktory najdluzej czeka, 
#include <string>               //********funkcja dodawania raz w jakis czas, funkcja ile elem na liscie,
#include <windows.h>            //********GUI, testy automatyczne, testy wydajnosciowe. Value of whole struct in bytes.
#include <time.h>

using namespace std;
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
    header = header->next;
    remove(header->prev);
    
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
    int key;

    cout << endl;
    cout << "*********************** PROGRAM STARTED ***********************" << endl;
    
    while(key != 0){
        
        cout << "Choose a key:" << endl;
        cout << endl;
        cout << "'1' - adding elements with delays." << endl;
        cout << "'2' - adding elements without delays." << endl;
        cout << "'0' - EXIT." << endl;
        cin >> key;

        int size;
        int num_op;
        int number;
        char key1;
        srand(time(0));

        switch(key){
            case 1:

                    cout << "Enter size of queue: " << endl;
                    cin >> size;

                    cout << "Enter number of operations: " << endl;
                    cin >> num_op;
                
                if(size < 1 || num_op < 0){
                    cout << "ERROR: Querry cant have size of 0 or have negative number of operations." << endl;
                }
                
                else{   

                    for (int i = 0; i < size; i++){
                        int TIME = rand() % 2000 + 500;
                        number = rand() % 100000 + 0;
                        DLL.addBack(number);
                        Sleep(TIME);
                        DLL.printDLL();
                    };


                    for (int i = 0; i < num_op; i++){

                        int TIME = rand() % 2000 + 500;
                        number = rand() % 100000 + 0;
                        DLL.addBack(number);
                        Sleep(TIME);
                        DLL.removeFront();
                        DLL.printDLL();
                    };

                    cout << endl;
                    cout << "Size of queue: " << DLL.sizeofDLL() << " bytes" << endl; 
                    cout << "Do you want to clean queue? (y/n)" << endl;
                    
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
                };
            break;

            case 2:

                    cout << "Enter size of queue: " << endl;
                    cin >> size;

                    cout << "Enter number of operations: " << endl;
                    cin >> num_op;
                
                if(size < 1 || num_op < 0){
                    cout << "ERROR: Querry cant have size of 0 or have negative number of operations." << endl;
                }

                else{

                    for (int i = 0; i < size; i++){
                        number = rand() % 100000 + 0;
                        DLL.addBack(number);
                        DLL.printDLL();
                    };


                    for (int j = 0; j < num_op; j++){
                        number = rand() % 100000 + 0;
                        DLL.addBack(number);
                        DLL.removeFront();
                        DLL.printDLL();
                    };

                    cout << endl;
                    cout << "Size of queue: " << DLL.sizeofDLL() << " bytes" << endl; 
                    cout << "Do you want to clean queue? (y/n)" << endl;
                    
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
                };
            break;

            case 0:
                DLL.~DLinkedList();
                cout << endl;
            break;

            default:
                cout << "ERROR: NO SUCH OPTION, TRY AGAIN" << endl;
                cout << endl;
            break;
        };
    };

    cout << "*********************** PROGRAM STOPPED ***********************" << endl;
    //DLL.~DLinkedList();
    return 0;
};