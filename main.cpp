#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
    Node* prev;
};

// Додавання елемента на початок списку
void insertAtBeginning(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->info = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

// Додавання елемента в кінець списку
void insertAtEnd(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->info = new_data;
    new_node->next = NULL;
    if ((*head_ref) == NULL) {
        new_node->prev = NULL;
        (*head_ref) = new_node;
        return;
    }
    Node* last = (*head_ref);
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

// Додавання елемента в середину списку
void insertAfter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        cout << "Попередній елемент не може бути NULL";
        return;
    }
    Node* new_node = new Node();
    new_node->info = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}

// Видалення елемента з початку списку
void deleteAtBeginning(Node** head_ref) {
    if (*head_ref == NULL) {
        cout << "Список порожній";
        return;
    }
    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    if (*head_ref != NULL) {
        (*head_ref)->prev = NULL;
    }
    delete temp;
}

// Видалення елемента з кінця списку
void deleteAtEnd(Node** head_ref) {
    if (*head_ref == NULL) {
        cout << "Список порожній";
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    if (last->prev != NULL) {
        last->prev->next = NULL;
    }
    else {
        *head_ref = NULL;
    }
    delete last;
}

// Видалення елемента з середини списку
void deleteNode(Node** head_ref, Node* del) {
    if (*head_ref == NULL
        || del == NULL) {
        return;
    }
    if (*head_ref == del) {
        *head_ref = del->next;
    }
    if (del->next != NULL) {
        del->next->prev = del->prev;
    }
    if (del->prev != NULL) {
        del->prev->next = del->next;
    }
    delete del;
}
// Обхід списку з початку до кінця
void traverseForward(Node* node) {
    cout << "Список: ";
    while (node != NULL) {
        cout << node->info << " ";
        node = node->next;
    }
    cout << endl;
}
// Обхід списку з кінця до початку
void traverseBackward(Node* node) {
    cout << "Список у зворотному порядку: ";
    Node* last;
    while (node != NULL) {
        last = node;
        node = node->next;
    }
    while (last != NULL) {
        cout << last->info << " ";
        last = last->prev;
    }
    cout << endl;
}
int main() {
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAfter(head->next, 4);
    traverseForward(head);
    traverseBackward(head);
    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    deleteNode(&head, head->next);
    traverseForward(head);
    traverseBackward(head);
    return 0;
}