#include<bits/stdc++.h>
using namespace std;

/***********************************************************/
/*                 Author : Alaa Omran                     */
/*                 Object : sparse 1-D array               */
/***********************************************************/

struct node{
    int data{0} , idx{0};
    node* next{nullptr} ,* prev{nullptr};
    node(int data , int idx):data(data) , idx(idx){}
};

class ArrayLinkedList{
private:
    int size{0};
    node* head{nullptr};

    //for destructor(free the heap)
    void clear(){
        node* temp = head;

        while(temp){
            node* before = temp;
            temp = temp->next;
            delete before;
        }
    }

    //return the node at the given index
    node* get_idx(int idx){
        node* temp{head};

        while(temp){

            //iterate till we reach the index if exist
            if(temp->idx == idx){
                break;
            }

            temp = temp->next;
        }

        return temp;
    }

    //add the given new node(dummy) before the given node(temp)
    node* insert_before(node* temp,node* newNode,int idx){
        node* before = temp->prev;

        if(!before){

            //inserting before the head itself
            newNode->next = head;
            head->prev = newNode;

            //update the head
            head = newNode;
        }else{
            before->next = newNode;
            newNode->next = temp;
            newNode->prev = before;
            temp->prev = newNode;
        }

        return newNode;
    }

    //insert the given index in his right order
    node* add_to_be_valid(int idx){
        node* temp{head};

        //if it will be the first node
        if(!temp){
            temp = new node(0,idx);
            head = temp;
        }else{
            node* newNode = new node(0,idx);

            //keep iterating till the next index after the given or till the end if not found
            while(temp->next and temp->idx<idx){
                temp = temp->next;
            }

            //if there is no index greater then we have to add in the end
            if(temp->idx<idx){
                temp->next = newNode;
                newNode->prev = temp;
                temp = temp->next;
            }else{
                temp = insert_before(temp,newNode,idx);
            }
        }
        return temp;
    }
public:
    ArrayLinkedList(int size):size(size){}

    void set(int data , int idx){
        assert(idx>-1 and idx<size);

        node* temp = get_idx(idx);

        if(!temp){
            temp = add_to_be_valid(idx);
        }

        temp->data = data;
    }

    int get(int idx){
        assert(idx>-1 and idx<size);

        node* temp = get_idx(idx);

        if(temp)
            return temp->data;

        return 0;
    }

    void print() const{
        int cnt{0};

        node* temp{head};

        while(temp){
            while(cnt<temp->idx){
                cout<<0<<" ";
                cnt++;
            }
            cout<<temp->data<<" ";
            temp = temp->next;
            cnt++;
        }

        cout<<"\n";
    }

    void print_nonZeros() const{
        node* temp{head};

        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }

        cout<<"\n";
    }

    ~ArrayLinkedList(){
        clear();
    }
};