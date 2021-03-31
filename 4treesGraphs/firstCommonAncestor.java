//O(N) runtime
import CtCILibrary.TreeNode;

public class firstCommonAncestor {
	
	public static boolean covers(TreeNode root, TreeNode p){
		if(root==null) return false;
		if(root==p) return true;
		return covers(root.left, p) || covers(root.right, p);
	}

	public static TreeNode commonAncestor(TreeNode root, TreeNode p, TreeNode q){
		if (! covers(root,p) || !covers(root,q)){
			return null;
		}
		return ancestorHelper(root,p,q);
	}

	public static TreeNode ancestorHelper(TreeNode root, TreeNode p, TreeNode q){
		if (root == null || root == p || root == q){
			return root;
		}
		boolean pleft = covers(root.left, p);
		boolean qleft = covers(root.left, q);
		if( pleft != qleft){
			return root;
		}
		TreeNode childSide = pleft ? root.left : root.right;
		return ancestorHelper(childSide, p, q);
	}

	///////////////////////////////////////////////////////Solution 2///////////////////////////////////////////////////////
	public static class Result{
		public TreeNode node;
		public boolean isAncestor;
		public Result(TreeNode n, boolean isAnc){
			node = n;
			isAncestor = isAnc;
		}
	}

	public static TreeNode commonAncestor2(TreeNode root, TreeNode p, TreeNode q){
		Result r = commonAncestorHelper(root,p,q);
		if(r.isAncestor) return r.node;
		return null;
	}

	public static Result commonAncestorHelper(TreeNode root, TreeNode p, TreeNode q){
		if(root == null) return new Result(null, false);
		if(root == p && root == q) return new Result(root, true);

		Result rx = commonAncestorHelper(root.left,p,q);
		if(rx.isAncestor) return rx;

		Result ry = commonAncestorHelper(root.right,p,q);
		if(ry.isAncestor) return ry;

		if(rx.node != null && ry.node != null) return new Result(root,true);
		else if(root==p || root==q){
			boolean isAncestor = rx.node != null || ry.node != null;
			return new Result(root, isAncestor);
		} else {
			return new Result(rx.node!=null ? rx.node : ry.node, false);
		}
	}

	
	public static void main(String[] args) {
		int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		TreeNode root = TreeNode.createMinimalBST(array);
		TreeNode n3 = root.find(1);
		TreeNode n7 = root.find(7);
		TreeNode ancestor = commonAncestor2(root, n3, n7);
		System.out.println(ancestor.data);
	}

}
