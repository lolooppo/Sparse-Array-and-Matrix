#include<bits/stdc++.h>
using namespace std;

/***********************************************************/
/*                 Author : Alaa Omran                     */
/*                 Object : sparse 2-D array               */
/***********************************************************/

struct arr_node{
    int data{0} , idx{0};
    arr_node* next{nullptr} ,* prev{nullptr};
    arr_node(int data , int idx):data(data) , idx(idx){}
};

class ArrayLinkedList{
private:
    int size{0};
    arr_node* head{nullptr};

    //for destructor(free the heap)
    void clear(){
        arr_node* temp = head;

        while(temp){
            arr_node* before = temp;
            temp = temp->next;
            delete before;
        }
    }

    //return the node at the given index
    arr_node* get_idx(int idx){
        arr_node* temp{head};

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
    arr_node* insert_before(arr_node* temp,arr_node* newNode,int idx){
        arr_node* before = temp->prev;

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
    arr_node* add_to_be_valid(int idx){
        arr_node* temp{head};

        //if it will be the first node
        if(!temp){
            temp = new arr_node(0,idx);
            head = temp;
        }else{
            arr_node* newNode = new arr_node(0,idx);

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

        arr_node* temp = get_idx(idx);

        if(!temp){
            temp = add_to_be_valid(idx);
        }

        temp->data = data;
    }

    int get(int idx){
        assert(idx>-1 and idx<size);

        arr_node* temp = get_idx(idx);

        if(temp)
            return temp->data;

        return 0;
    }

    void print() const{
        int cnt{0};

        arr_node* temp{head};

        while(temp){
            while(cnt<temp->idx){
                cout<<0<<" ";
                cnt++;
            }
            cout<<temp->data<<" ";
            temp = temp->next;
            cnt++;
        }

        while(cnt<size){
            cout<<0<<" ";
            cnt++;
        }

        cout<<"\n";
    }

    void print_noneZeros() const{
        arr_node* temp{head};

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

/*****************************************************/

struct mat_node{
    ArrayLinkedList arr;
    int idx{0};
    mat_node* prev{nullptr} ,* next{nullptr};
    mat_node(int idx , int c):idx(idx) , arr(c){}
};

class MatrixLinkedList{
private:
    int rows{0} , columns{0};
    mat_node* head{nullptr};

    //for destructor(free the heap)
    void clear(){
        mat_node* temp{head};

        while(temp){
            mat_node* dummy{temp};
            temp = temp->next;
            delete dummy;
        }
    }

    //return the node at the given index
    mat_node* get_idx(int idx){
        mat_node* temp{head};

        while(temp){
            if(temp->idx == idx){
                break;
            }

            temp = temp->next;
        }

        return temp;
    }

    //add the given new node(dummy) before the given node(temp)
    mat_node* insert_before(mat_node* temp,mat_node* newNode,int idx){
        mat_node* before = temp->prev;

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
    mat_node* add_to_be_valid(int idx){
        mat_node* temp{head};

        //if it will be the first node
        if(!temp){
            temp = new mat_node(idx,columns);
            head = temp;
        }else{
            mat_node* newNode = new mat_node(idx,columns);

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
    MatrixLinkedList(int rows , int columns):rows(rows) , columns(columns){}

    void set(int data , int r , int c){
        mat_node* temp = get_idx(r);
        if(!temp){
            temp = add_to_be_valid(r);
        }
        temp->arr.set(data , c);
    }

    int get(int r , int c){
        mat_node* temp = get_idx(r);

        if(temp){
            return temp->arr.get(c);
        }

        return 0;
    }

    void print() const{
        int cnt{0};

        mat_node* temp{head};

        while(temp){

            while(cnt<temp->idx){
                for(int i = 0;i<columns;i++){
                    cout<<0<<" ";
                }
                cnt++;
                cout<<"\n";
            }

            temp->arr.print();
            temp = temp->next;
            cnt++;
        }
    }

    void print_noneZeros(){

        mat_node* temp{head};

        while(temp){
            temp->arr.print_noneZeros();
            temp = temp->next;
        }

    }

    ~MatrixLinkedList(){

    }
};