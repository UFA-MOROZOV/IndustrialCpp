#include <iostream>
#include <memory>
#include <vector>

class Item {
public:
    Item(int id) : id(id) { std::cout << "Item " << id << " created" << std::endl; }
    ~Item() { std::cout << "Item " << id << " destroyed" << std::endl; }
private:
    int id;
};

int main() {
    std::vector<std::shared_ptr<Item>> items;
    for (int i = 0; i < 5; ++i) {
        items.push_back(std::make_shared<Item>(i));
    }
    std::cout << "Items are stored in the vector" << std::endl;
}
