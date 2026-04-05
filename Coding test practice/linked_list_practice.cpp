#include <iostream>
#include <string>
#define LIST_SIZE 6
using namespace std;
class node {
public:
    string name;
    node* link;
};
class LinkedList {
private:
    node* head;
public:
    LinkedList() { head = NULL; }
    void add_to_head(string new_name);
    void add_to_tail(string new_name);
    void remove_node(string target);
    void reverse_list();
    void show_all();
    string get_middle_node();
};
int main(){
    LinkedList my_list;

    // Input -> Add tail
    string input;
    for (int i=0;i<LIST_SIZE;i++) {
        cout << "# "<<i+1<<"/"<<LIST_SIZE<<" Add tail to Linked List: ";
        cin >> input;
        my_list.add_to_tail(input);
    }

    /* Input -> Add head Example
    for (int i=0;i<LIST_SIZE;i++) {
        cout << "# "<<i+1<<"/"<<LIST_SIZE<<" Add head to Linked List: ";
        cin >> input;
        my_list.add_to_head(input);
    }
    */

    // Print All name in List after input
    cout << "Show list after input\n";
    my_list.show_all();

    /* Remove Example
    cout << "Remove color name:";
    cin >> input;
    my_list.remove_node(input);
    cout << "Show list after remove\n";
    my_list.show_all();
    */

    /* Reverse Example
    my_list.reverse_list();
    cout << "Show list after inverse\n";
    my_list.show_all();
    */

    // Print middle node
    cout << "middle node: " << my_list.get_middle_node();

    return 0;
}
void LinkedList::add_to_head(string new_name) {
    node* tmp = new node;
    tmp->name = new_name;
    tmp->link = head;
    head = tmp;
}
void LinkedList::add_to_tail(string new_name) {
    node* tmp = new node;
    tmp->name = new_name;
    tmp->link = NULL;
    if (head == NULL) {
        head = tmp;
        return;
    }
    node* p = head;
    while (p->link!=NULL) {
        p = p->link;
    }
    p->link = tmp;
}
void LinkedList::remove_node(string target_name) {
    node* current = head;
    node* prev = NULL;
    if (head == NULL) return;
    if (head->name == target_name) {
        head = head->link;
        delete current;
        return;
    }
    while (current != NULL && current->name != target_name) {
        prev = current;
        current = current->link;
    }
    if (current == NULL) return;
    prev->link = current->link;
    delete current;
}
void LinkedList::reverse_list() {
    node* current = head;
    node* prev = NULL;
    node* next_node;
    while (current!=NULL) {
        next_node = current->link;
        current->link = prev;
        prev = current;
        current = next_node;
    }
    head = prev;
}

void LinkedList::show_all() {
    for (node* p = head;p!=NULL;p=p->link) {
        cout << p->name << '\n';
    }
}

string LinkedList::get_middle_node() {
    if (head==NULL) return "Empty";
    node* fast = head;
    node* slow = head;
    while (fast!=NULL&&fast->link!=NULL) {
        fast = fast->link->link;
        slow = slow->link;
    }
    return slow->name;
}
