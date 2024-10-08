#include <iostream>
#include <climits>
using namespace std;

struct node{
    string val;
    node * prev;
    node * next;
    node(string val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
struct dll{
    public:
        dll(){
            head = NULL;
            tail = NULL;
        }
        int size(){
            node *node = head;
            int iter=0;
            while(node != NULL ){
                node = node->next;
                iter++;
        }
        return iter;
        }
        void pop_back(){
                if(tail != NULL){
                    if (tail == head) {
                        delete tail;
                        tail = NULL;
                        head = NULL;
                    } else {
                        tail = tail->prev;
                        tail->next = NULL;
                    }
                }
            }

        void pop_front(){
            if(head != NULL){
                if (head == tail) {
                    delete head;
                    head = NULL;
                    tail = NULL;
                } else {
                    head = head->next;
                    head->prev = NULL;
                }
            }
        }
        void push_front(string x){
            node * temp = new node(x);
             if(head == NULL){
                head = temp;
                tail = temp;
            }else{
                head->prev = temp;
                temp->next = head;
                head = temp;
            }
        }

        // void nearest(int a){
        // int min = INT_MAX;
        // int index = 0;
        // int i=0;
        // node * temp = head;
        // while(temp != NULL){
        //     if(abs((temp->val)-a)<min){
        //     min = abs((temp->val)-a);
        //     index = i;
        //     }
        //     ++i;
        //     temp = temp->next;
            
        // }
        // cout<<index;
        
        // }   

        void push_back(string x){
            node * temp = new node(x);
            if(head == NULL){
                head = temp;
                tail = temp;
            }else{
                tail->next = temp;  
                temp->prev = tail;
                tail = temp;  
            }
        }
        void print(){
            print(head);
        }
        void r_print(){
            r_print(tail);
        }
        void print_every_first_element(){
            node * temp = head;
            int i = 0;
            while(temp != NULL){
                if(i % 2 == 0){
                cout << temp->val << " ";
                }
                temp = temp->next;
                ++i;
            }
        } 
        void print_delay(int delay){
            if (head == NULL) {
            return; 
            }
            node * temp = head;
            for(int j = 0; j < delay;j++){
                temp = temp->next;
            }
            for(int k = 0; k < size();k++){
                if(temp != NULL){
                cout << temp->val << " ";
                temp = temp->next;
                }
                else if(temp == NULL){
                    temp = head;
                    cout << temp->val << " ";
                    temp = temp->next;
                }
            }
        }
        node* cyclicShift(int k) {
            node* cur = head; 
            while(cur->next != NULL) {
                cur = cur->next;
            }
            for(int i = 0; i < k; i++) {
                cur->next = head;
                head = head->next;
                cur = cur->next;
                cur->next = NULL;
            }
            return head;
        }
    private:
        node * head;
        node * tail;
        void print(node * cur){
            if(cur!=NULL){
                cout << cur->val << " ";
                print(cur->next);
            }
        }
        void r_print(node * cur){
            if(cur != NULL){
                cout << cur->val << " ";
                r_print(cur->prev);
            }
        }
}
;

int main(){

    dll dl;
    int n;
    int x;
    cin >> n;
    cin >> x;
    for(int j=0;j<n;j++){
        string b;
        cin>>b;
        dl.push_back(b);
    }
    dl.cyclicShift(x);
    dl.print();
    cout << endl;
   return 0;
}