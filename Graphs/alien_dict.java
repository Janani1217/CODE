class Solution {
    public String alienOrder(String[] words) {
        // using bfs + Topo sorting
        int n = words.length;

        Map<Character , List<Character>> adjlist = new HashMap<>();
        Map<Character, Integer> counts = new HashMap<>();
        
        // creating adj list and init count of incoming to 0 for each char in the dict
        for(String s : words){
            for(Character ch : s.toCharArray()) {
                counts.put(ch, 0);
                adjlist.put(ch, new ArrayList<>());
            }
        }

        // prepare the adj list by comparing:
        for(int i=0; i<n-1; i++) {
            String w1 = words[i];
            String w2 = words[i+1];

            // check if w2 is prefix of w1 :
            if(w1.length() > w2.length() && w1.startsWith(w2))
                return ""; // since its not a valid ordering : w2 should come before

            // traverse both w and check chars if not matching : process it
            int minlen = Math.min(w1.length() , w2.length());

            for(int j=0; j<minlen; j++) {
                if(w1.charAt(j) != w2.charAt(j)) {
                    // put in adj list
                    adjlist.get(w1.charAt(j)).add(w2.charAt(j));
                    // incr the count / incoming edge for secon char
                    counts.put(w2.charAt(j), counts.get(w2.charAt(j))+1);
                    break; // since u found the non-match char
                }
            }
        }

        // run bfs over the adjlist formed:
        Queue<Character> q = new LinkedList<>();
        StringBuilder sb = new StringBuilder();

        // insert indegree of 0 into the queue first
        for(Character ch : counts.keySet()) {
            if(counts.get(ch).equals(0)) {
                q.add(ch);
            }
        }

        // run over queue:
        while(!q.isEmpty()) {
            Character ch = q.poll();
            sb.append(ch);

            for(Character neigh : adjlist.get(ch)) {
                // decr the indegree
                counts.put(neigh, counts.get(neigh)-1);
                // check if indegree is 0:
                if(counts.get(neigh).equals(0))
                    q.add(neigh);
            }
        }

        // check if any char is left unvisited:
        if(counts.size() != sb.length())
            return "";
        return sb.toString();
    }
}
