#include <string>
#include "../linkedlist/linked-list.cpp"

class HashMap {
    List<std::string>* arr[1000];
    int size = 1000;

    int hash(std::string key) {
        return static_cast<int>(key[0]);
    }
public:

    HashMap() {
        for (int i = 0; i < size; i++)
            arr[i] = nullptr;
    }

    ~HashMap() {
        std::cout << "I want to know when in the lifecycle of the program this runs..." << std::endl;
        for(List<std::string> *l : arr) {
            if (l) {
                std::cout << l << std::endl;
                delete l;
            }
        }
    }

    void insert(std::string key, std::string value) {
        // Implemented with chaining
        int index = hash(key);
        if (arr[index]) {
            List<std::string> *ptr = arr[index];
            ptr->push(value);
            return;
        }
        List<std::string> *list = new List<std::string>(value);
        arr[index] = list;
    }

    int search(std::string key, std::string value) {
        int index = hash(key);
        if (!arr[index]) {
            std::cout << "No key found with that indicator." << std::endl;
            return -1;
        }

        List<std::string> *p = arr[index];
        int return_index = p->search_list(value);
        std::cout << index << ", " << return_index << std::endl;
        return return_index;
    }

    void remove(std::string key, std::string value) {
        int index = hash(key);
        if (!arr[index]) {
            std::cout << "Key not found" << "\n";
            return;
        }

        List<std::string> *p = arr[index];
        p->remove(value);
    }
};

int main() {
    HashMap hash;
    std::string key = "key";
    std::string value = "value";
    hash.insert(key, value);
    hash.search(key, value);
    hash.insert(key, "newvalue");
    hash.search(key, "newvalue");

    hash.search("newkey", "newval");
}
