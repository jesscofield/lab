#include <iostream>

using namespace std;

struct Node{
	
    int data, priority;
    Node* next;
};

class PriorityQueue{
	
public:
    Node* head;
    
    PriorityQueue(){
        this->head = NULL;
    }

    int top(){
        
        return head->data;
    }

    void pop(){
        
        Node* temp = this->head;
        this->head = this->head->next;
        
        delete temp;
    }

    void push(int value, int priority){
    	
        if(this->head == NULL){
        	
           this->head = newNode(value, priority);
           return;
        }
        
        Node* begin = this->head;
        Node* temp = newNode(value, priority);

        if(this->head->priority < priority){
            
           temp->next = this->head;
           this->head = temp;
        }
        
        else{
            
            while(begin->next != NULL && begin->next->priority > priority){
            	
                  begin = begin->next;
            }
            
            temp->next = begin->next;
            begin->next = temp;
        }
    }

    bool isEmpty(){
    	
        return this->head == NULL;
    }
    
private:
    
    Node* newNode(int value, int priority){
        
        Node* temp = new Node();
        temp->data = value;
        temp->priority = priority;
        temp->next = NULL;
        
        return temp;
    }
};

int main(){
    
    PriorityQueue queue = PriorityQueue();
    
    cout << queue.head << endl;
    cout << queue.isEmpty() << endl;
    
    queue.push(3, 1);
    queue.push(6, 2);
    
    cout << queue.isEmpty() << endl;
    cout << queue.top() << endl;
    
    queue.pop();
    queue.pop();
    
    cout << queue.isEmpty() << endl;
    
    queue.push(2, 0);
    queue.push(7, 3);

    while(!queue.isEmpty()){

          cout << queue.top() << endl;
          queue.pop();
    } 

    return 0;
}
