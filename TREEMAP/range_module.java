A Range Module is a module that tracks ranges of numbers. Design a data structure to track the ranges represented as half-open intervals and query about them.

A half-open interval [left, right) denotes all the real numbers x where left <= x < right.

Implement the RangeModule class:

RangeModule() Initializes the object of the data structure.
void addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
boolean queryRange(int left, int right) Returns true if every real number in the interval [left, right) is currently being tracked, and false otherwise.
void removeRange(int left, int right) Stops tracking every real number currently being tracked in the half-open interval [left, right).








class RangeModule {
    private TreeMap<Integer, Integer> map = new TreeMap<>();
    
	/* Start with earliest interval available in the tree */
	/* And then gradually merge until there's no overlapping intervals in the tree */
    public void addRange(int left, int right) {
        if (right <= left) return;
        Map.Entry<Integer, Integer> e = map.floorEntry(left);
        
        if (e != null && e.getValue() >= left) {
            map.remove(e.getKey());
            left = e.getKey();
            right = Math.max(right, e.getValue());
        }
        
        while (true) {
            e = map.ceilingEntry(left);
            
            if (e == null || e.getKey() > right) {
                break;
            }
            
            map.remove(e.getKey());
            right = Math.max(right, e.getValue());
        }
        
        map.put(left, right);
    }
    
    public boolean queryRange(int left, int right) {
        Map.Entry<Integer, Integer> e = map.floorEntry(left);
        
        if (e == null) {
            return false;
        } else {
            return e.getKey() <= left && right <= e.getValue();
        }
    }
    
	/* Start with earliest interval available in the tree */
    public void removeRange(int left, int right) {
        if (right <= left) return;
        Map.Entry<Integer, Integer> e = map.floorEntry(left);
        
        if (e != null && e.getValue() >= left) {
            map.remove(e.getKey());
            map.put(e.getKey(), left);
            
            if (e.getValue() > right) {
                map.put(right, e.getValue());
            }
        }
        
        while (true) {
            e = map.ceilingEntry(left);
            
            if (e == null || e.getKey() > right) {
                break;
            }
            
            map.remove(e.getKey());
            
            if (e.getValue() > right) {
                map.put(right, e.getValue());
                break;
            }
        }
    }
}

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * boolean param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
