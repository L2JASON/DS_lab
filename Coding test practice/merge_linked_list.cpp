#include <iostream>
#include <string>
using namespace std;
class node {
public:
    string name;
    int age;
    node* link;
};
class LinkedList {
private:
    node* head;
public:
    LinkedList(){head = NULL;}
    void add_to_tail(string new_name,int new_age);
    int list_size();
    void show_all();
    void setHead(node* new_head){head = new_head;}
    node* getHead(){return head;}
};
node* mergeList(LinkedList a,LinkedList b) {
    node* dummy = new node;
    node* tail = dummy;
    node* pa = a.getHead();
    node* pb = b.getHead();
    while (pa!=NULL&&pb!=NULL) {
        tail->link = (pa->age < pb->age)?pa:pb;
        (pa->age < pb->age)?pa=pa->link:pb=pb->link;
        tail = tail->link;
    }
    tail->link = (pa!=NULL)?pa:pb;
    node* result = dummy->link;
    delete dummy;
    return result;
}
int main() {
    LinkedList a,b;
    int size_a = 3; int size_b = 5;
    string input_name;
    int input_age;
    // input A
    for (int i=0;i<size_a;i++) {
        cout << "A input (name) (age):";
        cin >> input_name >> input_age;
        a.add_to_tail(input_name,input_age);
    }
    // input B
    for (int i=0;i<size_b;i++) {
        cout << "B input (name) (age):";
        cin >> input_name >> input_age;
        b.add_to_tail(input_name,input_age);
    }
    // print A,B
    cout << "A list"<<endl;
    a.show_all();
    cout << "B list"<<endl;
    b.show_all();
    //merge A+B
    LinkedList m;
    m.setHead(mergeList(a,b));
    cout << "A+B list"<<endl;
    m.show_all();
    return 0;
}
void LinkedList::add_to_tail(string new_name,int new_age) {
    node* tmp = new node;
    tmp->name = new_name;
    tmp->age = new_age;
    tmp->link = NULL;
    if (head == NULL) {
        head = tmp;
        return;
    }
    node* p = head;
    while (p->link!=NULL) p=p->link;
    p->link = tmp;
}

int LinkedList::list_size() {
    int count = 0;
    for (node* p = head;p!=NULL;p=p->link)
        count++;
    return count;
}

void LinkedList::show_all() {
    int size = list_size();
    int i = 1;
    for (node* p=head;p!=NULL;p=p->link)
        cout <<"# "<<i++<<'/'<<size<<" name: "<<p->name<<", age: "<<p->age<<endl;
}