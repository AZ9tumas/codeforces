#include <vector>

using namespace std;

class Node {
public:
    int value;
    Node* prev;
    Node* next;

    Node(int value) {
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class Node {
 public:
  int value;
  Node* prev;
  Node* next;

  Node(int value);
};


class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void setHead(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
            return;
        }
        insertBefore(head, node);
    }

    void setTail(Node* node) {
        if (tail == nullptr) {
            setHead(node);
            return;
        }
        insertAfter(tail, node);
    }

    void insertBefore(Node* node, Node* nodeToInsert) {
        if (nodeToInsert == head && nodeToInsert == tail) {
            return;
        }
        remove(nodeToInsert);
        nodeToInsert->prev = node->prev;
        nodeToInsert->next = node;
        if (node->prev == nullptr) {
            head = nodeToInsert;
        } else {
            node->prev->next = nodeToInsert;
        }
        node->prev = nodeToInsert;
    }

    void insertAfter(Node* node, Node* nodeToInsert) {
        if (nodeToInsert == head && nodeToInsert == tail) {
            return;
        }
        remove(nodeToInsert);
        nodeToInsert->prev = node;
        nodeToInsert->next = node->next;
        if (node->next == nullptr) {
            tail = nodeToInsert;
        } else {
            node->next->prev = nodeToInsert;
        }
        node->next = nodeToInsert;
    }

    void insertAtPosition(int position, Node* nodeToInsert) {
        if (position == 1) {
            setHead(nodeToInsert);
            return;
        }
        Node* current = head;
        int currentPosition = 1;
        while (current != nullptr && currentPosition++ != position) {
            current = current->next;
        }
        if (current != nullptr) {
            insertBefore(current, nodeToInsert);
        } else {
            setTail(nodeToInsert);
        }
    }

    void removeNodesWithValue(int value) {
        Node* node = head;
        while (node != nullptr) {
            Node* nodeToRemove = node;
            node = node->next;
            if (nodeToRemove->value == value) {
                remove(nodeToRemove);
            }
        }
    }

    void remove(Node* node) {
        if (node == head) {
            head = head->next;
        }
        if (node == tail) {
            tail = tail->prev;
        }
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }
        node->prev = nullptr;
        node->next = nullptr;
    }

    bool containsNodeWithValue(int value) {
        Node* node = head;
        while (node != nullptr && node->value != value) {
            node = node->next;
        }
        return node != nullptr;
    }
};