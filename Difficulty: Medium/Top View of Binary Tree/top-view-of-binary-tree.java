/*
class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}
*/

    class Pair {
    public Integer key;
    public Integer value;

    public Pair(Integer key, Integer value) {
        this.key = key;
        this.value = value;
    }

    public Integer getKey() { return key; }
    public Integer getValue() { return value; }
}
class Solution {
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.


    static void helper(Node root,int hd,int level, Map<Integer,Pair> topNodes)
    {
        if(root == null) return ;
        if(!topNodes.containsKey(hd) || topNodes.get(hd).getValue() > level){
            topNodes.put(hd, new Pair(root.data,level));
        }
        helper(root.left,hd-1,level+1,topNodes);
        helper(root.right,hd+1,level+1,topNodes);
        return ;
    }
    static ArrayList<Integer> topView(Node root) {
        // code here
        ArrayList<Integer> ans = new ArrayList<>();
        if(root == null) return ans;
        Map<Integer,Pair> topNodes = new TreeMap<>();
        helper(root,0,0,topNodes);
        for(Pair p : topNodes.values()){
            ans.add(p.getKey());
        }
        return ans;
    }
}