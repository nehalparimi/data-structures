#include "node.h"


template <typename T>
class List {
  Node<T> *_root = nullptr;
  Node<T> *iter = nullptr;

public:
    List() {
        Node<T> *node = new Node<T>;
        node->value = 0;
        node->next = nullptr;

        _root = node;
        iter = _root;
    }

    List(T val) {
        Node<T> *node = new Node<T>;
        node->value = val;
        node->next = nullptr;

        _root = node;
        iter = _root;

    }

    ~List() {
        if (iter != _root) {
            iter = _root;
        }
        Node<T> *tail = _root;
        while(tail) {
            iter = tail->next;
            delete tail;
            tail = iter;
        }
    }

    Node<T>* get_root() {
        return _root;
    }

    void push(T val) {
        if (iter != _root) iter = _root;
        while(iter->next) {
            iter = iter->next;
        }
        Node<T> *n = new Node<T>;
        n->value = val;
        n->next = nullptr;

        iter->next = n;
    }

    int search_list(T val){
        if (iter != _root) iter = _root;
        int index = 0;
        while (iter->next && iter->value != val) {
            iter = iter->next;
            ++index;
        }
        // Equality check
        if (iter->value == val)
            return index;
        else
            return -1;
    }

    void remove(T val) {
        if (iter != _root) iter = _root;
        while (iter->next && iter->next->value != val) {
            iter = iter->next;
        }

        if (iter->next->value == val) {
            if (!iter->next->next) {
                iter->next = nullptr;
                return;
            }
            iter->next = iter->next->next;
        }
        else {
            std::cout << "Value not found" << "\n";
            return;
        }
    }

    // friend std::ostream& operator << (std::ostream &out, const List &l) {
    //     // Have to call functions on the instance
    //     // this friend function / operator overload doesn't know what iter is
    //     // it works with either static variables or some value returned by List l -- which it knows
    //     Node<T> *iter = l.get_iter();
    //     while (iter->next) {
    //         out << iter->value << " ";
    //     }
    //     return out;
    // }
};
