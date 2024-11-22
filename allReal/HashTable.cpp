#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

class HashTable {
private:
    vector<list<pair<int, string>>> table;
    int size;
    int hashFunction(int key) {
        return key % size;
    }
public:
    HashTable(int size) : size(size) {
        table.resize(size);
    }
    void insert(int key, const string& value) {
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];
        for (auto& pair : cell) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        cell.emplace_back(key, value);
    }
    void remove(int key) {
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];
        cell.remove_if([key](const pair<int, string>& pair) { return pair.first == key; });
    }
    string search(int key) {
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];
        for (const auto& pair : cell) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return "Not Found";
    }
    void display() {
        for (int i = 0; i < size; ++i) {
            cout << "Bucket " << i << ": ";
            for (const auto& pair : table[i]) {
                cout << "[" << pair.first << ": " << pair.second << "] ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable(10);

    hashTable.insert(1, "Value1");
    hashTable.insert(2, "Value2");
    hashTable.insert(12, "Value12");

    hashTable.display();

    cout << "Search key 2: " << hashTable.search(2) << endl;

    hashTable.remove(2);
    hashTable.display();

    return 0;
}