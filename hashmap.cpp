#include <iostream>
#include <list>
#include <cstring>
using namespace std;

//hashtable to implement 905, jimmy 

class HashTable{
    private:
    static const int hashGroups = 10;
    list<pair<int, std::string > > table[hashGroups];

    public: 

        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
    };


    bool HashTable::isEmpty() const{
        int sum{};
        for(int i{}; i<hashGroups; i++){
            sum += table[i].size();
        }
        if(!sum){
            return true;
        }
        return false;
    };


    int HashTable::hashFunction(int key){
        return key% hashGroups; //key : 905, in return, this functio nwill sp[lit out 5]
    }

    void HashTable::insertItem(int key, string value){
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];
        auto bItr = begin(cell);
        bool keyExists=false;
        for(; bItr !=end(cell); bItr++){
            if (bItr->first==key){
                keyExists=true;
                bItr->second=value;
                cout<<"[WARNING] key exit; value replaced."<<endl; 
                break;
            }
        }

        if(!keyExists){
            cell.emplace_back(key,value);
        }
            return;
    }


    void HashTable::removeItem(int key){
        int hashValue= hashFunction(key);
        auto&cell = table[hashValue];
        atuo bItr =begin(cell);
        

    }