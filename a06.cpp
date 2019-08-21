#include <iostream>
using namespace std;

class List {
    struct node {
        int val;
        node *next;
    };

    node *head, *last;

    void delete_after_node(node *current);

    int do_sum(node *current);

    public:
    List();
    void push(int val);
    int pop();
    void print_list();

    int sum_list();
};

int List::sum_list() {
  return do_sum(head);
}

int List::do_sum(node *current) {
  int result = 0;
  if (current != NULL ) {
    result = current->val + do_sum(current->next);
    return result;
  } else {
    return 0;
  }
}

List::List() {
    last = head = NULL;
}

void List::push(int val) {
    node *temp = new node;
    temp->val = val;
    temp->next = NULL;

    if (last == NULL) {         // need this when list is empty
        head = temp;
        last = temp;
    } else {                    // for all other cases
        last->next = temp;
        last = last->next;
    }
}

void List::print_list() {
    node *current = head;
    cout << "[ " ;
    while (current != NULL) {
        cout << current->val << " ";

        current = current->next;
    }
    cout << "]" << endl;
}


int main() {
    List l;

    l.push(5);
    l.push(15);
    l.push(30);
    l.push(32);
    l.push(3);
    l.push(29);
    l.print_list();

    cout << "Sum = " << l.sum_list() << endl;

    return 0;
}
