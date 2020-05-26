#include "linked-list.cpp"


int main() {
    List<int> list(5);
    list.push(6);
    list.push(7);

    Node<int> *root = list.get_root();

    while (root->next) {
        std::cout << root->valued << std::endl;
        root = root->next;
    }

}
