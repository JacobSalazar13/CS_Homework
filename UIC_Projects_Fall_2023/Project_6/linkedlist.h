#define linkedlist_H
using namespace std;

//create a node class for our linkedlist class
class node {                    
   public:
        //public variables in the node class
        int value;
        node* next;
        //constructor when passed an argument
        node(int index){
            this->value = index;
            this->next = nullptr;
        }
};

//create a linkedlist class for tracking moves within the game
class linkedlist{
    public:
        //create head pointer
        node* head;
        //constructor setting head to nullptr
        linkedlist() {
            head = nullptr;
        }
        //function to append nodes to the end of a linkedlist
        void append_to_list(int index){
            //instantiate a new node with value of the index of a successful move
            node* newnode = new node(index);
            //if the linkedlist is empty
            if (head == nullptr){
                //then the head point to the node
                head = newnode;
            }
            else{
                //if linkedlist is not empty
                node* test = head;
                //iterate through the linkedlist
                while(test->next != nullptr){
                    test = test->next;                
                }
                //set the next node at the end of the list to the new node with the index
                test->next = newnode;
            }
        }

        //function that deletes the last node in the list
        void delete_last_from_list(){
            //if linkedlist is empty then don't do anything
            if (head == nullptr){
                return;
            }
            //if there is only one node the delete the head and set head equal to nullptr
            else if (head -> next == nullptr){
                delete head;
                head = nullptr;
                return;
            }
            //if the linkedlist is longer than 1 node then continue to the 2nd node after the initial
            else{
                node* current = head; 
                while(current -> next -> next != nullptr){
                    current = current -> next;
                }
                //delete the last node
                delete current -> next;
                //set new last node to nullptr
                current -> next = nullptr;
            }
        }

        //function to get the last index from the linkedlist
        int get_index(){
            //if list is empty then return 100
            if (head == nullptr){
                return 100;
            }
            //if list is not empty then iterate through and return the value of last node
            node* current = head;
            while (current->next != nullptr){
                current = current->next;
            }
            return current->value;
            
        }
        //function to get the first index from the linkedlist
        int get_first_index(){
            //if list is empty then return -1
            if (head == nullptr){
                return -1;
            }
            //else return the value of head the first node
            return head->value;
            }

        //function that deletes the first node in the list
        void delete_first_index(){
            //if list is empty then dont do anything
            if (head == nullptr){
                return;
            }
            //else delete the first node
            node* current = head;
            head = head->next;
            delete current;
            }
};
