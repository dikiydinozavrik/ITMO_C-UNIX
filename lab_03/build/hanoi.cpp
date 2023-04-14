#include <iostream>
#include <list>

using namespace std;

struct MoveNode {
    int disk;              
    int from_peg, to_peg;  
    MoveNode* prev;        
    MoveNode* next;        
};

void hanoi(int n, int from, int to, int via, MoveNode** head_ptr) {
    if (n == 0) {
        return;
    }

    hanoi(n-1, from, via, to, head_ptr);

    MoveNode* new_move = new MoveNode;
    new_move->disk = n;
    new_move->from_peg = from;
    new_move->to_peg = to;
    new_move->prev = *head_ptr;
    new_move->next = nullptr;

    if (*head_ptr) {
        (*head_ptr)->next = new_move;
    }

    *head_ptr = new_move;

    hanoi(n-1, via, to, from, head_ptr);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    MoveNode* head = nullptr;

    hanoi(n, 1, 3, 2, &head);

    cout << "Moves:" << endl;
    while (head) {
        cout << "Move disk " << head->disk << " from peg " << head->from_peg << " to peg " << head->to_peg << endl;
        head = head->prev;
    }
    
   while (head) {
        MoveNode* temp = head;
        head = head->prev;
        delete temp;
    }

    return 0;
}
