#include<iostream>
#include<string.h>
using namespace std;

template <typename V>
class MapNode
{
  public:
    string key;
    V value;
    MapNode<V>* next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourMap
{
    MapNode<V>** buckets;
    int count;
    int numBuckets;

  public:
    ourMap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];

        for(int i=0;i<numBuckets;i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourMap()
    {
        for(int i=0;i<numBuckets;i++)
        {
            delete buckets[i];
        }

        delete [] buckets;
    }

    V getValue(string key)
    {

    }
  
  private:
    getBucketIndex(string key)
    {
        int length = key.length();
        int p = 1;

        int hashCode = 0;

        for(int i=length-1;i>=0;i--)
        {
            bucketIndex += key[i]*p;
            p *= 31;
        }

        int bucketIndex = hashCode%numBuckets;

        return bucketIndex;
    }

  public:
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        bucketIndex[bucketIndex]->next = new MapNode<V>(value);
    }

    V remove(string key)
    {

    }
};