#include <iostream>

struct Node{
    int number = 0;
    Node* next = nullptr;

    Node(int n){
        number = n;
    }
};

struct List{
    Node* head = nullptr;
    Node* last = nullptr;
    int size = 0;

    void add(int n){
        if(head == nullptr){
            head = new Node(n);
            last = head;
            last->next = head;
        }else{
            last->next = new Node(n);
            last = last->next;
            last->next = head;
        }

        size++;
    }
};

void sortList(List* arr){
   List* resultArr = new List;

   Node* ptr = arr->head;

   for(int i = 0; i < arr->size; i++){
       if(ptr->number % 2 == 1) resultArr->add(ptr->number);
       ptr = ptr->next;
   }

    for(int i = 0; i < arr->size; i++){
        if(ptr->number % 2 == 0) resultArr->add(ptr->number);
        ptr = ptr->next;
    }

    std::swap((*resultArr), (*arr));
}
