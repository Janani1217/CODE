Find the Celebrity :

Suppose you are at a party with n people labeled from 0 to n - 1 and among them, 
there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people 
know the celebrity, but the celebrity does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. 
You are only allowed to ask questions like: "Hi, A. Do you know B?" to get information about 
whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as 
few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) that tells you whether a knows b. 
Implement a function int findCelebrity(n). There will be exactly one celebrity if they are at the party.

Return the celebrity's label if there is a celebrity at the party. If there is no celebrity, return -1.




  

/* The knows API is defined in the parent class Relation.
      boolean knows(int a, int b); */

public class Solution extends Relation {
    public int findCelebrity(int n) {
        // 1 : use stack to store all ele : 
        Stack<Integer> st = new Stack<>();
        for(int i=0; i<n; i++) {
            st.push(i);
        }

        // 2. pick always 2 ele and compare : till st has only 1 ele left or none :
        while(st.size() > 1) {
            int a = st.pop();
            int b = st.pop();

            // first check if a is celeb:
            if(knows(a, b))
                st.push(b);
            else if(knows(b, a))
                st.push(a);
        }

        // 3. check the size of st first :
        if(st.isEmpty())
            return -1;

        // 4. validate if celeb found :
        int celeb = st.pop();
        
        // * celeb should not know anyone  
        // * everyone else should know celeb
        for(int i=0; i<n; i++) {
            if(i!=celeb && (knows(celeb, i) || knows(i, celeb)==false))
                return -1;
        }
        return celeb;
    }
}
