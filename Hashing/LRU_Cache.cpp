#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    list<int> dq;                               // actual cache
    unordered_map<int, list<int>::iterator> ma; // store page no -> list of nodes
    int csize;                                  // max size of cache

public
    LRUCache(int);
    void refer(int);
    void display();
};

// declare the size
LRUCache ::LRUCache(int n)
{
    csize = n;
}

// refer : key x

void LRUCache ::refer(int pg_no)
{

    // if the pg no. is not present in cache itself
    if (ma.find(pg_no) == ma.end())
    {

        // check whether cache is full or not
        // to make room for the new node which came

        if (dq.size() == csize)
        {
            // cache is full : evict the last node
            int last = dq.back();
            dq.pop_back();
            // remove from hash table also
            ma.erase(last);
        }
    }
    else
    {

        // node is present in cache : cache hit case
        // remove from the end of the list to bring it front
        dq.erase(ma[pg_no]);
    }

    // update the cache and the hashtable with new node
    dq.push_front(pg_no);
    ma[pg_no] = dq.begin(); /* storing the addr of that particular int no. present in the list */
}

void LRUCache ::display()
{
    for (auto itr = dq.begin(); itr != dq.end(); itr++)
    {
        cout << (*itr) << " ";
    }
    cout << endl;
}

int main()
{
    LRUCache lru(4);

    lr.refer(1);
    lr.refer(2);
    lr.refer(3);
    lr.refer(1);
    lr.refer(4);
    lr.refer(5);
    lr.display();
    return 0;
}

// TC : O(1)
// SC : O(n)