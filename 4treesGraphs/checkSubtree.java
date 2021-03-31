import CtCILibrary.TreeNode;
import CtCILibrary.AssortedMethods;

public class checkSubtree{

    /////////////////1st Solution I implemented myself//////////////// O(A+B), insufficient solution because root of T2 may appear more than once in T1

    public static boolean checker(TreeNode root1, TreeNode root2){
        if(root1==null && root2==null)
            return true;
        if(root1.data == root2.data){
            return (checker(root1.right, root2.right) && checker(root1.left, root2.left) );
        }
        else return false;
    }

    public static TreeNode findRoot(TreeNode T1, TreeNode T2){
        if( T1 == null) return null;
        
        else if (T1.data == T2.data) return T1;

        else{ 
            TreeNode left = findRoot(T1.left, T2);
            if(left!=null) return left;
            TreeNode right = findRoot(T1.right, T2);
            if(right!=null) return right;
            return null;
        }
    }

    public static boolean checkSubtree(TreeNode T1, TreeNode T2){
        TreeNode root = findRoot(T1,T2);
        return checker(root, T2);
    }

    ////////////////////A better solution///////////////

    public static boolean containsTree(TreeNode T1, TreeNode T2){
        if(T2 == null) return true;
        return subTree(T1, T2);
    }

    public static boolean subTree(TreeNode T1, TreeNode T2){
        if(T1 == null){
            return false;
        }
        else if (T1.data == T2.data && matchTree(T1,T2)){
            return true;
        }
        return subTree(T1.left, T2) || subTree(T1.right, T2);
    }

    public static boolean matchTree(TreeNode r1, TreeNode r2){
        if(r1 == null && r2 == null) return true;
        else if (r1 == null || r2 == null) return false;
        else if (r1.data != r2.data) return false;
        else return matchTree(r1.left,r2.left) && matchTree(r1.right, r2.right);
    }

    public static void main(String[] args) {
		// t2 is a subtree of t1
		int[] array1 = {1, 2, 1, 3, 1, 1, 5};
		int[] array2 = {2, 3, 1};
		
		TreeNode t1 = AssortedMethods.createTreeFromArray(array1);
		TreeNode t2 = AssortedMethods.createTreeFromArray(array2);

		if (containsTree(t1, t2)) {
			System.out.println("t2 is a subtree of t1");
		} else {
			System.out.println("t2 is not a subtree of t1");
		}

        int[] array3 = {1, 2, 3};
		TreeNode t3 = AssortedMethods.createTreeFromArray(array1);
		TreeNode t4 = AssortedMethods.createTreeFromArray(array3);

		if (containsTree(t3, t4)) {
			System.out.println("t4 is a subtree of t3");
		} else {
			System.out.println("t4 is not a subtree of t3");
		}
    }
}