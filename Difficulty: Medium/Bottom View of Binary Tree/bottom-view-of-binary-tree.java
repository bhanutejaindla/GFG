
class Pair{
    public Integer key;
    public Integer value;
    Pair(Integer k,Integer v)
    {
        this.key=k;
        this.value=v;
    }
    public Integer getkey()
    {
        return key;
    }
    public Integer getValue()
    {
        return value;
    }
}
class Solution {
    // Function to return a list containing the bottom view of the given tree.
    static void helper(Node root,ArrayList<Integer>ans,Map<Integer,Pair>mp,int hd,int level)
    {
          if(root==null) return ;
          
          if(!mp.containsKey(hd) || mp.get(hd).getValue()<=level)
          {
              mp.put(hd,new Pair(root.data,level));
          }
          helper(root.left,ans,mp,hd-1,level+1);
          helper(root.right,ans,mp,hd+1,level+1);
          return ;
    }
    public ArrayList<Integer> bottomView(Node root) {
        // Code here
       
        ArrayList<Integer>ans=new ArrayList<>();
         if(root==null) return ans;
        Map<Integer,Pair>mp= new TreeMap<>();
        helper(root,ans,mp,0,0);
        for(Pair p :mp.values())
        {
            ans.add(p.getkey());
        }
        return ans;
        
    }
}