#include "LoginHash.hpp"
#include <iostream>

namespace
{
    unsigned int hashF1(const std::string& s)
    {
        unsigned int value = 0;
        for(int i=0; i<s.size(); i++)
        {
            value += int(s[i]);
        }
        return value;
    }

    unsigned int hashMod(unsigned int hash, unsigned int bucketS)
    {
        return hash%bucketS;
    }

}


LoginHash::LoginHash()
        : hashFunction{hashF1}, buckets{new Node*[INITIAL_BUCKET_COUNT]()}, keyCount{0}, bucketSize{INITIAL_BUCKET_COUNT}
{
}

LoginHash::LoginHash(HashFunction hashFunction)
        : hashFunction{hashFunction}, buckets{new Node*[INITIAL_BUCKET_COUNT]()}, keyCount{0}, bucketSize{INITIAL_BUCKET_COUNT}
{
}

LoginHash::LoginHash(const LoginHash& hm)
        : hashFunction{hm.hashFunction}, buckets{new Node*[hm.bucketSize]}, keyCount{hm.keyCount}, bucketSize{hm.bucketSize}
{
    for (int i=0; i<bucketSize; i++)
    {
        Node* current = hm.buckets[i];
        Node** bucketNode = &buckets[i];
        *bucketNode = nullptr;

        while (current != nullptr)
        {
            Node* temp = new Node;
            temp->key = current->key;
            temp->value = current->value;
            temp->next = nullptr;

            *bucketNode = temp;
            bucketNode = &temp->next;

            current = current->next;
        }
    }
}

LoginHash::~LoginHash()
{
    for(int i=0;i<bucketSize;i++)
    {
        Node* current = buckets[i];
        while(current!=nullptr)
        {
            Node* toBeDeleted = current;
            current=current->next;
            delete toBeDeleted;
        }
    }
    delete[] buckets;
}

/*HashMap& HashMap::operator=(const HashMap& hm)
{
    if(this != &hm)
    {
        bucketSize = hm.bucketSize;
        keyCount = hm.keyCount;
        hashFunction = hm.hashFunction;

        Node** tempBuckets = new Node*[bucketSize]();

        for(int i=0; i<bucketSize; i++)
        {
            Node* current = hm.buckets[i];
            while(current != nullptr)
            {
                Node* temp1 = current;
                current = current->next;

                unsigned int index = hashMod(hashFunction(temp1->key),bucketSize);
                Node*& temp2 = tempBuckets[index];
                temp1->next = temp2;
                temp2 = temp1;
            }
        }
        this->~HashMap();
        buckets = tempBuckets;
    }
    return *this;
}*/

LoginHash& LoginHash::operator=(const LoginHash& hm)
{
    if(this != &hm)
    {
        bucketSize = hm.bucketSize;
        keyCount = hm.keyCount;
        hashFunction = hm.hashFunction;

        Node** tempBuckets = new Node*[bucketSize];

        for(int i=0; i<bucketSize; i++)
        {
            Node* current = hm.buckets[i];
            Node** newB = &tempBuckets[i];
            *newB = nullptr;
            while(current != nullptr)
            {
                Node* newNode = new Node;
                newNode->key = current->key;
                newNode->value = current->value;
                newNode->next = nullptr;
                *newB = newNode;
                newB = &newNode->next;
                current=current->next;
            }
        }
        delete[] buckets;
        buckets = tempBuckets;
    }
    return *this;
}


bool LoginHash::contains(const std::string& key) const
{
    unsigned int index = hashMod(hashFunction(key),bucketSize);
    const Node* current = buckets[index];

    while (current != nullptr)
    {
        if (current->key == key)
            return true;
        current = current->next;
    }

    return false;

}

unsigned int LoginHash::size() const
{
    return keyCount;
}

unsigned int LoginHash::bucketCount() const
{
    unsigned int total = 0;
    for(int i=0; i<bucketSize;++i)
    {
        if (buckets[i]!=nullptr)
            total+=1;
    }
    return total;
}

double LoginHash::loadFactor() const
{
    return float(size())/float(bucketSize);
}

void LoginHash::add(const std::string& key, const std::string& value)
{
    if (contains(key))
        return;
    
    if (loadFactor() > 0.8)
    {
        unsigned int oldBucketSize = bucketSize;
        bucketSize = bucketSize*2+1;
        Node** tempBuckets = new Node*[bucketSize];

        for(int i=0; i<bucketSize; i++)
        {
            tempBuckets[i] = nullptr;
        }

        for(int i=0; i<oldBucketSize; i++)
        {
            Node* current = buckets[i];
            while(current != nullptr)
            {
                Node* temp1 = current;
                current=current->next;

                unsigned int index = hashMod(hashFunction(temp1->key),bucketSize);
                Node*& temp2 = tempBuckets[index];
                temp1->next = temp2;
                temp2 = temp1;
            }
        }
        delete[] buckets;
        buckets = tempBuckets;
        add(key, value);
    }
    else
    {
        keyCount+=1;
        Node* temp = new Node;
        temp->key = key;
        temp->value = value;

        unsigned int index = hashMod(hashFunction(key),bucketSize);

        if (buckets[index] == nullptr)
        {
            temp->next = nullptr;
            buckets[index] = temp;
        }
        else
        {
            temp->next = buckets[index];
            buckets[index] = temp;
        }
    }
}

bool LoginHash::remove(const std::string& key)
{
    if (contains(key))
    {
        keyCount-=1;
        unsigned int index = hashMod(hashFunction(key),bucketSize);
        const Node* current = buckets[index];
        const Node* toBeRemoved = current;

        while (current != nullptr)
        {
            if (current->key == key)
            {
                buckets[index] = current->next;
                delete toBeRemoved;
                return true;
            }
            current = current->next;
        }
    }
    return false;
}

void LoginHash::clear()
{
    keyCount = 0;
    for (unsigned int i = 0; i < bucketSize; ++i)
    {
        while (buckets[i] != nullptr)
        {
            Node* temp = buckets[i];
            buckets[i] = temp->next;
            delete temp;
        }
    }
}

std::string LoginHash::value(const std::string& key) const
{
    if (contains(key))
    {
        unsigned int index = hashMod(hashFunction(key),bucketSize);
        const Node* current = buckets[index];

        while (current != nullptr)
        {
            if (current->key == key)
                return current->value;
            current = current->next;
        }
    }
    return "";
}

unsigned int LoginHash::maxBucketSize() const
{
    unsigned int max = 0;
    for(int i=0; i< bucketSize; ++i)
    {
        unsigned int value = 0;
        const Node* current = buckets[i];
        while(current!=nullptr)
        {
            value+=1;
            current=current->next;
        }
        if (max<value)
            max = value;
    }

    return max;
}

unsigned int LoginHash::index(const std::string& key) const
{
    unsigned int index = hashMod(hashFunction(key),bucketSize);
    return index;
}

unsigned int LoginHash::getBucketSize() const
{
    return bucketSize;
}