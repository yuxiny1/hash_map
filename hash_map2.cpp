#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class HashTable{
    private:
    static const int hashGroups = 20;
    vector<unordered_map<int, std::string> > table;

    public: 
        HashTable() : table(hashGroups) {}

        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
    };


    int HashTable::hashFunction(int key){
        return key % hashGroups; 
    }

    void HashTable::insertItem(int key, string value){
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];
        auto itr = cell.find(key);
        if(itr != cell.end()){
            cout<<"[WARNING] key exit; value replaced."<<endl;
            itr->second = value;
        }else{
            cell.insert({key, value});}}

    void HashTable::removeItem(int key){
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];
        auto itr = cell.find(key);
        if(itr != cell.end()){
            cout << "[INFO] key exits. value removed" << endl;
            cell.erase(itr);
        }else{
            cout << "[WARNING] item not found " << endl;}}

    string HashTable::searchTable(int key){
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];
        auto itr = cell.find(key);
        if(itr != cell.end()){
            return itr->second;
        }else{
            cout << "[WARNING] Key not found.\n";
            return {};
        }
    }

    void HashTable::printTable(){
        for(int i = 0; i < hashGroups; ++i){
            if(table[i].empty()) continue;
            for(const auto& kv : table[i]){
                cout << "[INFO] key:" << kv.first << " value: " << kv.second << endl;
            }
        }
    }

int main(){
    HashTable HT;

    HT.insertItem(905,"jim");
    HT.insertItem(345,"sam");
    HT.insertItem(234,"alex");
    HT.insertItem(231,"sandy");
    HT.insertItem(123,"rob");
    HT.printTable();
    HT.removeItem(322);
    HT.removeItem(123);

    return 0;
}
