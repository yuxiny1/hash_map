#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable
{
private:
    static const int hashGroups = 20;
    list<pair<int, std::string > > table[hashGroups];

public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();
};

bool HashTable::isEmpty() const
{
    int sum{};
    for (int i{}; i < hashGroups; i++)
    {
        sum += table[i].size();
    }
    if (!sum)
    {
        return true;
    }
    return false;
};

int HashTable::hashFunction(int key)
{
    return key % hashGroups; // key : 905, in return, this functio nwill sp[lit out 5]
}

void HashTable::insertItem(int key, string value)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING] key exit; value replaced." << endl;
            break;
        }
    }

    if (!keyExists)
    {
        cell.emplace_back(key, value);
    }
    return;
}

void HashTable::removeItem(int key)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr = cell.erase(bItr); // it will return next iterator ,no need to continue
            cout << "[INFO] key exits. value removed" << endl;
            break;
        }
    }
    if (!keyExists)
    {
        cout << "[WARNING] iterm not found " << endl;
    }
}

void HashTable::printTable()
{
    for (int i{}; i < hashGroups; ++i)
    {
        if (table[i].size() == 0)
            continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++)
        {
            cout << "[INFO] key:" << bItr->first << "value: " << bItr->second << endl;
        }
    }
    return;
}

string HashTable::searchTable(int key)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    // iterator std::list<pair<int, std::string>>::iterator
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            return bItr->second;
        }
    }
    if (!keyExists)
    {
        cout << "[WARNING] Key not found.\n";
        return {};
    }
    return {};
}

int main()
{
    
    HashTable HT;

    if (HT.isEmpty())
    {
        cout << "correct answer . good job " << endl;
    }
    else
    {
        cout << "ohoh, we need to check out code" << endl;
    };

    HT.insertItem(905, "jim");
    HT.insertItem(345, "sam");
    HT.insertItem(234, "alex");
    HT.insertItem(231, "sandy");
    HT.insertItem(123, "rob");

    HT.printTable();

    HT.removeItem(322);
    HT.removeItem(123);

    if (HT.isEmpty())
    {
        cout << "some mistakes" << endl;
    }
    else
    {
        cout << "ok no problem so far" << endl;
    };
    return 0;
};