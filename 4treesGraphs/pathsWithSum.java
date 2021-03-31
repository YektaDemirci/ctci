import CtCILibrary.TreeNode;

import java.util.HashMap;
public class pathsWithSum{
    
    public static int pwSum(TreeNode root, int target){
        if (root == null) return 0;

        return pwSumRoot(root, target, 0)+pwSum(root.left, target)+pwSum(root.right, target);
    }

    public static int pwSumRoot(TreeNode root, int target, int cur){
        if(root==null) return 0;
        
        cur+=root.data;
        int totalPaths=0;
        if(cur==target) totalPaths++;
        
        totalPaths += pwSumRoot(root.left, target, cur);
        totalPaths += pwSumRoot(root.right, target,cur);
        return totalPaths;
    }

    

    ///////////////////////////////Solution 2 with Memoization/////////////////////
    public static int pwSum2(TreeNode root, int target){
        return pwSum2(root, target, 0, new HashMap<Integer,Integer>());
    }

    public static int pwSum2(TreeNode root, int target, int runningSum, HashMap<Integer,Integer> map){
        if(root==null) return 0;

        runningSum+=root.data;
        int occurance = map.getOrDefault(runningSum-target,0);

        if(runningSum==target) occurance++;

        incrementHash(map, runningSum, 1);
        occurance += pwSum2(root.right, target, runningSum, map);
        occurance += pwSum2(root.left, target, runningSum,map);
        incrementHash(map, runningSum, -1);
        return occurance;
    }
    public static void incrementHash(HashMap<Integer, Integer> map, int key, int delta){
        int occurance = map.getOrDefault(key, 0)+delta;
        if(occurance==0) map.remove(key);
        else map.put(key, occurance);
    }

    public static void main(String [] args) {
		/*
		TreeNode root = new TreeNode(5);
		root.left = new TreeNode(3);		
		root.right = new TreeNode(1);
		root.left.left = new TreeNode(-8);
		root.left.right = new TreeNode(8);
		root.right.left = new TreeNode(2);
		root.right.right = new TreeNode(6);	
		System.out.println(countPathsWithSum(root, 0));*/
		
/* 		TreeNode root = new TreeNode(-7);
		root.left = new TreeNode(-7);
		root.left.right = new TreeNode(1);
		root.left.right.left = new TreeNode(2);
		root.right = new TreeNode(7);
		root.right.left = new TreeNode(3);
		root.right.right = new TreeNode(20);
		root.right.right.left = new TreeNode(0);
		root.right.right.left.left = new TreeNode(-3);
		root.right.right.left.left.right = new TreeNode(2);
		root.right.right.left.left.right.left = new TreeNode(1);
		System.out.println(pwSum(root, -14)); */
		
		TreeNode root = new TreeNode(0);
		root.left = new TreeNode(0);
		root.right = new TreeNode(0);
		root.right.left = new TreeNode(0);
		root.right.left.right = new TreeNode(0);
		root.right.right = new TreeNode(0);
		System.out.println(pwSum2(root, 0));
		System.out.println(pwSum2(root, 4));
	}

}

/*     public static int pwSum2(TreeNode root, int target){
        return pwSum2(root, target, 0, new HashMap<Integer, Integer>());
    }

    public static int pwSum2(TreeNode root, int target, int runSum, HashMap<Integer,Integer> path){
        if (root==null) return 0;

        runSum += root.data;
        int sum = runSum - target;
        //If the value is not found, it returns the second input
        int paths = path.getOrDefault(sum,0);

        if(runSum==target) paths++;

        incrementHash(path, runSum, 1);
        paths += pwSum2(root.left, target, runSum, path);
        paths += pwSum2(root.right, target, runSum, path);
        incrementHash(path, runSum, -1);

        return paths;
    }

    public static void incrementHash(HashMap<Integer,Integer> path, int key, int delta){
        int newCount = path.getOrDefault(key, 0) + delta;
        if( newCount == 0) path.remove(key);
        else path.put(key, newCount);
    } 
*/
