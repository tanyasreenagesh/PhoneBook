#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <functional>
#include <string>


class LoginHash
{
public:
    using HashFunction = std::function<unsigned int(const std::string&)>;

    static constexpr unsigned int INITIAL_BUCKET_COUNT = 10;


public:
    LoginHash();
    LoginHash(HashFunction hashFunction);


    LoginHash(const LoginHash& hm);
    ~LoginHash();
    LoginHash& operator=(const LoginHash& hm);


    void add(const std::string& key, const std::string& value);

    bool remove(const std::string& key);

    bool contains(const std::string& key) const;

    std::string value(const std::string& key) const;

    unsigned int size() const;

    unsigned int bucketCount() const;

    double loadFactor() const;

    unsigned int maxBucketSize() const;

    unsigned int index(const std::string& key) const;

    unsigned int getBucketSize() const;

    void clear();


private:

    struct Node
    {
        std::string key;
        std::string value;
        Node* next;
    };

    HashFunction hashFunction;

    Node** buckets;

    unsigned int keyCount;
    unsigned int bucketSize;

};


#endif

