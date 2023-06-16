/*
 * Hashing : data = (key, value) pairs
 * 
 * .............................................................................
 * 
 * *usecase = it simplifies search capabilities
 * *linear search will take O(nl) , n = no. of ele and l = length of each
 * element
 * *hashing will give search results in O(1)
 * *Hahsing Improves on lookups
 * 
 * .............................................................................
 * 
 * Inspiration of hash came from an array.
 * arr[10] = allocate 10 mem locations
 * search an ele in array , we will go with respect to index and find the ele.
 * 
 * arr[5] -> means the base addr + (5 * size of each ele)
 * 
 * But if we store the index and the ele in a hashmap and search the
 * ele based on the index then we can do in O(n)
 * 
 * .............................................................................
 * 
 * 
 * How can we visualize the memory usage in hashmap ?
 * 
 * HashFunction (value) : it will take the value , perform some
 * mathematical operation and results out in a hash code.
 * 
 * This hashcode will act as the memory location/ mem addr in the hashmap
 * for that particular value
 * 
 * so using the hash function , for all the values in the arr , we calculate
 * the index and store in hashmap.
 * 
 * and now when we search(value) -> hahsfunction(value) = index ->? find in
 * the hashmap.
 * 
 * .............................................................................
 * 
 * Problematic situation :
 * 
 * arr [7 71 78 85 99]
 * hashfunction = val % 64
 * 
 * hashmap :
 * 
 * key = 7
 * value = {7, 74, 78, 85, 99}
 * 
 * So now if we want to search for some ele , it will look into this list
 * similarly for other ele , we need top lookup to this whole list formed
 * 
 * Such situations a problematic , when we use hashmap.
 * When the list is sorted , then binary search is the best way to search.
 * 
 * Also we can use a binary search tree = put smaller num
 * on the left and larget number on the right.
 * 
 * We can also use balanced binary search tree , where the search will take
 * O(log n). So we can look for any number in a balanced bst.
 * 
 * .............................................................................
 * 
 * Now how is it useful in hashmap ?
 * 
 * In hashmap , <key , val> , every val = balanced bst.
 * 
 * So finding a number in a balanced bst = O(log n)
 * {n = no. of ele in that list}
 * 
 * Suppose a balanced bst has about n = 1 million = 10^6
 * log(10^6) = 6 log10 = 6 * 3.32 = 24 steps/computations !
 * 
 * so in 24 steps we will be able to find the le in a 1 million
 * elements , So the TC = O(1).
 * 
 * 
 * .............................................................................
 * 
 * So however be the list generated in a hashmap for an ele , the time
 * to find an ele in it will be O(1) only = constant time
 * 
 * 
 * .............................................................................
 * 
 * BUCKETING :
 * 
 * In a hashmap , every entry is called a bucket
 * So every bucket will have a key and value pair , where the value will be
 * in a form of BBST.
 * 
 * But there can be situation where the bucket can go FULL !
 * 
 * .............................................................................
 * 
 * How can it happen (bucket is full) ??
 * 
 * 1. situation can be hashmap keys are fulled and for every key the
 * values are also fulled.
 * 
 * 2. so when we try to insert a new pair in the hashmap , how do we deal ?
 * 
 * 3. this is handled internally , by using a function = RE-HASHING
 * 
 * .............................................................................
 * 
 * RE - HASHING :
 * 
 * 1. it simply doubles the size of existing hashmap
 * 2. for inital haahsmap we had a mapping for every key.
 * 3. now to make use of the extra space , we need to change the hash function.
 * 4. so compute the hashcode for all the data available
 * 5. we wont loose any data
 * 6. TC for this computation will take O(n) time
 * 
 * 7. so when we store ele in a bst ,
 * 
 * 
 * .............................................................................
 * 
 * Alarm based situation :
 * 
 * 1. supppose there are 5 levels in the bst.
 * 2. in the 4th level there will be 8 nodes intree ans it got filled.
 * 3. the last level will have 16 nodes.
 * 4. so if in the 4th level itselwhen n/2 data is already filled,
 * the system will be alarmed that half of the data is filled and
 * if more nodes arrives then re-hashing is needed.
 * 
 * So internal architecture it never goes out of the space or completly filled.
 * 
 * .............................................................................
 * 
 * Load Factor :
 * 
 * 1. its the height that it has set to grow
 * 
 * 2. = 0.7 * total no.of nodes
 * 
 * 3. so if the value of load factor croses, it means 70% of the nodes are
 * filled and for the next 30 percent of the node , be prepared in
 * advance.
 * 
 * 4. so for the next 30 perent , in the background automatically the
 * rehashing method starts and hash function is recomputed and new hash
 * keys are generated for the data.
 * 
 * 5. this goes in parallel programming to incoming data. And 2x size hash
 * map is created and all the data is pulled there.
 * 
 */