import java.util.LinkedList;

/*
 *  Design a HashMap without using any built-in hash table libraries.
 *  
 *  Implement the MyHashMap class:

    MyHashMap() initializes the object with an empty map.

    void put(int key, int value) inserts a (key, value) pair into the HashMap. 
    If the key already exists in the map, update the corresponding value.

    int get(int key) returns the value to which the specified key is mapped, 
    or -1 if this map contains no mapping for the key.

    void remove(key) removes the key and its corresponding value if the map 
    contains the mapping for the key.
 * 
 * .............................................................................
 * 
 *  Examples of hash functions :
 * 
 * 1.   for large keys : h(key) = key%m;
 * 
 * 2.   for string keys : weighted sum 
 *      "cat" = s[0]*x^0 + s[1]*x^1 + s[2]*x^2 
 *      here x : any random prime number.
 *      this is done to avoid collisions (not to give same output for 2 diff keys).
 *  
 * 
 *      h(key_string) = (s[0]*x^0 + s[1]*x^1 + s[2]*x^2 ) % m ;   
 * 
 * 3.   for objects (non-pr imitive) : weighted sum of elements 
 *      
 *.............................................................................
 *  PUT (K , V) :
 * 
 *  Hashtable looks like a linkedlist format :
 *  Node[] hashtable = new Node[7];
 * 
 *  Node {
 *      K key;
 *      V value;
 *      int hash;
 *      Node next;
 *  } 
 * 
 *  size of hash table = n = 7;
 *  hash function -> h(key) = key % 7
 * 
 * https://www.youtube.com/watch?v=wZLn2BN1TvY
 * 
 *  Now for every ele , pick the key.
 * 
 *  Calc the hash value from the hash function = %7.
 * 
 *  that will act as a index of the hashtable.
 * 
 *  if collision happens , then next pointer is used and 
 *  insert the new node there.
 * 
 * .............................................................................
 * 
 *  GET (K) :
 *  
 *  1.  get the key.
 *  2.  use the hashfunc = key%7 = x;
 *  3.  in hahstable index = x = get the value and retrun
 *  4.  if there is a collision , we traverse the chain linkelist.
 *  5.  else return -1;
 * 
 *  TC : O(1 + len(chain))
 * 
 *  ****
 * 
 *  So sometimes , it might happen that the len of the chain is very large.
 *  This will make the TC worsen.
 * 
 *  So in java 8 , updated that , there is a threshhold for the len of the
 *  chain. So if that threshold is crossed , then remove the linkedlist and
 *  convert that into a self balancing binary search tree.
 * 
 *  Lookup time reduces by this.
 * 
 *  ****
 * 
 * ............................................................................
 * 
 *  IMPLEMENTATION HAHSMAP : 
 * 
 * https://www.youtube.com/watch?v=KDZ_IXvpMG4&t=31s
 * 
 *  O(1) : 
 *  
 *  put 
 *  get
 *  containsKey
 *  remove
 *  size
 *  keySet 
 * 
 *  ****
 *  
 *  1. in java we impl using an array of linkelist.
 *  2. at every index there will be a linkedlist stored.
 *  3. index = this we can calc using hash function.
 *  4. handle collision by linkedlist.
 * 
 *  Every index is called BUCKET.
 *  Size of hashmap = no. of buckets
 *  nodes = no. of elements has to be inserted into the hahsmap
 *  
 * 
 * ...........................................................................
 * 
 *  1.  hashing = data form is changed
 *  2.  there are famous alogo's = SHA1 , SHA256
 *  3.  majorly used in password security.
 * 
 * ...........................................................................
 * 
 * 
 * 
 * 
 */

public class design_hashtable {
   private class Node {
      int key;
      int value;

      Node(int key, int value) {
         this.key = key;
         this.value = value;
      }
   }

   private int n; // total no. of ele to be inserted
   private int N; // total no.of buckets created
   private LinkedList<Node> buckets[]; // array of ll

   private design_hashtable() {
      this.N = 4;
      this.buckets = new LinkedList[N];

      for (int i = 0; i < N; i++) {
         this.buckets[i] = new LinkedList<>();
      }
   }

   private int hashFunc(int key) {
      int hc = key.hashCode();
      return Math.abs(hc) % key;
   }

   private int searchInLL(int key, int bi) {
      LinkedList<Node> ll = buckets[bi];
      int di = 0;

      for (int i = 0; i < ll.size(); i++) {
         Node node = ll.get(i);
         if (node.key == key)
            return di;
         di++;
      }
      return -1;
   }

   private void rehash() {
      LinkedList<Node> oldList[] = buckets[];
      N = N * 2;
      buckets = new LinkedList[N * 2];

      for(int i=0; i<buckets.length; i++) {
         buckets[i] = new LinkedList<>();
      }

      for(int i=0; i<oldList.size(); i++) {
         LinkedList<Node> ll = oldList[i];
         for(int j=0; j<ll.size(); j++) {
            Node node = ll.get(j);
            put(node.key, node.value);
         }
      }
   }

   public void put(int key, int value) {
      int bi = hashFunc(key);
      int di = searchInLL(key, bi);

      if (di != -1) {
         // key is already present : replace the old val with curr val
         Node node = buckets[bi].get(di);
         node.value = value;
      } else {
         // new bucket has to be created
         buckets[bi].add(new Node(key, value));
         n++;
      }

      // check the thresh hold value
      double lambda = (double) n / N;
      if (lambda > 2.0) // half of the arr are already filled
         rehash();
   }

   public int get(int key) {
      int bi = hashFunc(key);
      int di = searchInLL(key, bi);

      if (di != -1) {
         // key is found
         Node node = buckets[bi].get(di);
         return node.value;
      }
      return -1;
   }

   public void remove(int key) {
      int bi = hashFunc(key);
      int di = searchInLL(key, bi);

      if (di != -1) {
         Node node = bucket[bi].remove(di);
         n--;
         return;
      }
   }

}
