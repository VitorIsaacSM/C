//vitor isaac sitton maia
#include"Deque.h"

Deque::Deque(int t){
	
	vet = (int *) malloc(sizeof(int)*t);
	size = t;
	front = -1;
	rear = 0;

}

Deque::~Deque(){
	
	free(vet);
	
}

bool Deque::is_empty(){
	
	if(front == -1)
		return true
	
	
}

bool Deque::is_full(){
	
	if((front == 0 && rear == size-1)|| front == rear+1)
		return true;
	
}

void Deque::insert_back(int x)
{
    if (is_full())
    {
        cout << " Overflow\n " << endl;
        return;
    }
 
    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
 
    // rear is at last position of queue
    else if (rear == size-1)
        rear = 0;
 
    // increment rear end by '1'
    else
        rear = rear+1;
 
    // insert current element into Deque
    vet[rear] = x ;
}

void Deque::insert_front(int x)
{
    // check whether Deque if  full or not
    if (is_full())
    {
        cout << "Overflow\n" << endl;
        return;
    }
 
    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
 
    // front is at first position of queue
    else if (front == 0)
        front = size - 1 ;
 
    else // decrement front end by '1'
        front = front-1;
 
    // insert current element into Deque
    vet[front] = x ;
}

// Deletes element at front end of Deque
void Deque::delete_front()
{
    // check whether Deque is empty or not
    if (is_empty())
    {
        cout << "Queue Underflow\n" << endl;
        return ;
    }
 
    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        // back to initial position
        if (front == size -1)
            front = 0;
 
        else // increment front by '1' to remove current
            // front value from Deque
            front = front+1;
}
 
// Delete element at rear end of Deque
void Deque::delete_back()
{
    if (is_empty())
    {
        cout << " Underflow\n" << endl ;
        return ;
    }
 
    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size-1;
    else
        rear = rear-1;
}

void Deque::print(){
	
	for(int i=front; i!= rear+1; i++){
		
			if(i == size){
				i = 0;
			}
			
			
			cout << vet[i] << endl;
		
	}
	
}
 

