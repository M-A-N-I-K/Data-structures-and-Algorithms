#include <iostream>

using namespace std;
template <typename V>
class mapNode
{

public:
    string key;
    V value;
    mapNode *next;
    mapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~mapNode()
    {
        delete next;
    }
};

template <typename V>
class ourMap
{
    mapNode<V> **buckets;
    int count;
    int bucketSize;

public:
    ourMap()
    {
        count = 0;
        bucketSize = 5;
        buckets = new mapNode<V> *[bucketSize];

        for (int i = 0; i < bucketSize; i++)
        {
            buckets[i] = NULL;
        }
    }

    int size()
    {
        return count;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        mapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int currCoeff = 1;

        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currCoeff;
            hashCode %= bucketSize;
            currCoeff *= 37;
            currCoeff %= bucketSize;
        }

        return hashCode % bucketSize;
    }

    void reHash()
    {
        mapNode<V> **temp = buckets;
        buckets = new mapNode<V> *[2 * bucketSize];
        for (int i = 0; i < 2 * bucketSize; i++)
        {
            buckets[i] = NULL;
        }
        int oldBucketCount = bucketSize;
        bucketSize *= 2;
        count = 0;

        for (int i = 0; i < oldBucketCount; i++)
        {
            mapNode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketCount; i++)
        {
            mapNode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        mapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        mapNode<V> *newNode = new mapNode<V>(key, value);
        newNode->next = head;
        buckets[bucketIndex] = newNode;
        count++;
        double loadFactor = (1.0 * count) / bucketSize;
        if (loadFactor > 0.7)
        {
            reHash();
        }
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        mapNode<V> *head = buckets[bucketIndex];
        mapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }

    ~ourMap()
    {
        for (int i = 0; i < bucketSize; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }
};

int main()
{
    ourMap<int> map;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
    }
    cout << map.size() << endl;
}