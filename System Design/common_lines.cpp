/*
given two very big files , each having around 1 billion lines ,
u have to print all the lines that are common to both files .
Please suggest a good optimal approach.


When dealing with very large files, an optimal approach to find common lines in both files involves using a technique called "hashing" to reduce memory usage and improve performance. Here's a step-by-step guide on how to achieve this:

Hashing Step:

Read through the first file line by line and compute a hash for each line. You can use a hash function like SHA-256 or MD5 to create a fixed-size hash value for each line.
Store these hashes in a hash set (or a hash table) to quickly check for duplicates.
Comparison Step:

Now, read through the second file line by line.
For each line, compute the hash using the same hash function as in step 1.
Check if the computed hash exists in the hash set created in step 1. If it does, then the line is common in both files, so you can print it.

*/

#include <bits/stdc++.h>
using namespace std;

// no need to rem this fuction
string compute_hash(string &line)
{
    unsigned char digest[MD5_DIGEST_LENGTH];
    unsigned chMD5((unsigned char *)line.c_str(), line.size(), digest);

    stringstream ss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << static_cast<int>(digest[i]);
    }

    return ss.str();
}

void findCommonLines(string &file1, string &file2)
{
    unordered_set<string> common;

    // step 1 : hashing
    ifstream f1(file1);
    if (!f1)
    {
        cerr << "err opening file" << file1 << endl;
    }

    string line;
    while (getLine(f1, line))
    {
        string hash_val = compute_hash(line);
        common.insert(hash_val);
    }

    // step 2 : comparison
    ifstream f2(file2);
    if (!f2)
    {
        cerr << "err opening file 2" << file2 << endl;
    }

    while (getLine(f2, line))
    {
        string hash_val = compute_hash(line);
        if (common.find(hash_val) != comm.end())
        {
            cout << line << endl;
        }
    }
}

int main()
{
    string file1_path = "path/to/first_file.txt";
    string file2_path = "path/to/second_file.txt";
    findCommonLines(file1_path, file2_path);
}