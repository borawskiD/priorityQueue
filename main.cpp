#include <iostream>
#include <cstdlib>

using namespace std;

struct element{
    int data;
    int prior;
    struct element *nextElement;
};
void pushFront(element **head, int number, int prior){
    element *currentElement = (element *)malloc(sizeof(element));
    currentElement->data = number;
    currentElement->prior = prior;
    currentElement->nextElement = (*head);
    *head = currentElement;
}

void showList(element *head){
    cout << endl;
    if(head == NULL) cout << "Empty\n";
    else{
        element *currentElement = head;

        do{
            cout << currentElement->data<< ":" <<currentElement -> prior << " ";
            currentElement = currentElement->nextElement;
        } while (currentElement != NULL);
        cout<<"\n---";
        cout << endl;
    }
}

int listSize(element *head){

    int counter = 0;
    if (head == NULL) return 0;
    else{
        element *currentElement = head;
        do{
            counter ++;
            currentElement = currentElement->nextElement;
        } while(currentElement != NULL);
    }

    return counter;
}

void popFront(element **head){
    element *tmp = NULL;
    if (*head != NULL){
        tmp = (*head)->nextElement;

        delete *head;
        *head = tmp;
    }
}

void popBack(element **head){
    std::cout<<"Usuwam ostatni element" << std::endl;
    if(*head != NULL){
        if((*head)->nextElement == NULL)
            *head = NULL;

        else{
            element *currentElement = *head;
            while(currentElement->nextElement->nextElement != NULL){
                currentElement = currentElement->nextElement;
            }

            delete currentElement->nextElement;

            currentElement->nextElement = NULL;
        }
    }
}

void pushByPrior(element **head, int number, int prior){
    std::cout<<"Dodaje element o wartosci: " <<number << " i priorytecie: "<<prior<<std::endl;
    if(listSize(*head) == 0) {
        pushFront(head,number, prior);
    }
    else{
            element *currentElement = *head;
            element *tmp;
            int i = 0;
            while(currentElement->nextElement != NULL && (currentElement -> prior <= prior && currentElement -> nextElement -> prior <= prior)){
                currentElement = currentElement->nextElement;
                i++;
            }
            //zabezpieczenie do sytuacji, w ktorej juz pierwszy element bylby z mniejszym priorytetem
            if (i == 0){
                pushFront(head,number, prior);
            }else{
                tmp = currentElement->nextElement;
                currentElement->nextElement = (element *)malloc(sizeof(element));
                currentElement->nextElement->data = number;
                currentElement->nextElement->prior = prior;
                currentElement->nextElement->nextElement = tmp;
            }



    }
}

void popByIndex(element **head, int index){
    std::cout<<"Usuwam element o indeksie: " <<index <<std::endl;
    if(index == 0) popFront(head);
    else{
        element *currentElement = *head;
        element *tmp;

        int i=0;
        while(currentElement->nextElement != NULL && i < index-1){
            currentElement = currentElement->nextElement;
            i++;
        }
        tmp = currentElement->nextElement;
        currentElement->nextElement = tmp->nextElement;
        delete tmp;
    }
}
int main()
{
    element *head = NULL;
    showList(head);
    pushByPrior(&head, 102, 2);
    showList(head);
    pushByPrior(&head, 101, 1);
    showList(head);
    popFront(&head);
    showList(head);
    pushByPrior(&head, 103, 3);
    showList(head);
    pushByPrior(&head, 105, 5);
    showList(head);
    pushByPrior(&head, 12, 12);
    showList(head);
    pushByPrior(&head, 11, 1);
    showList(head);
    popBack(&head);
    showList(head);
    popByIndex(&head,1);
    showList(head);
    pushByPrior(&head, 14, 4);
    showList(head);
    pushByPrior(&head, 3, 3);
    showList(head);
    pushByPrior(&head, 16, 6);
    showList(head);
    pushByPrior(&head, 11, 1);
    showList(head);
    popFront(&head);
    showList(head);
    pushByPrior(&head, 17, 7);
    showList(head);
    std::cout<<"Ostateczny ksztalt:\n";
    showList(head);


    return 0;
}

/* Dominik Borawski
 * A1 215IC
 * Kolejka priorytetowa
 */

/*
Empty
Dodaje element o wartosci: 102 i priorytecie: 2

102:2
---
Dodaje element o wartosci: 101 i priorytecie: 1

101:1 102:2
---

102:2
---
Dodaje element o wartosci: 103 i priorytecie: 3

103:3 102:2
---
Dodaje element o wartosci: 105 i priorytecie: 5

103:3 102:2 105:5
---
Dodaje element o wartosci: 12 i priorytecie: 12

103:3 102:2 105:5 12:12
---
Dodaje element o wartosci: 11 i priorytecie: 1

11:1 103:3 102:2 105:5 12:12
---
Usuwam ostatni element

11:1 103:3 102:2 105:5
---
Usuwam element o indeksie: 1

11:1 102:2 105:5
---
Dodaje element o wartosci: 14 i priorytecie: 4

11:1 102:2 14:4 105:5
---
Dodaje element o wartosci: 3 i priorytecie: 3

11:1 102:2 3:3 14:4 105:5
---
Dodaje element o wartosci: 16 i priorytecie: 6

11:1 102:2 3:3 14:4 105:5 16:6
---
Dodaje element o wartosci: 11 i priorytecie: 1

11:1 11:1 102:2 3:3 14:4 105:5 16:6
---

11:1 102:2 3:3 14:4 105:5 16:6
---
Dodaje element o wartosci: 17 i priorytecie: 7

11:1 102:2 3:3 14:4 105:5 16:6 17:7
---
Ostateczny ksztalt:

11:1 102:2 3:3 14:4 105:5 16:6 17:7
---


 */