package test_gao;

import java.util.LinkedList;
import java.util.Queue;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}
class Example101 {

	public static void main(String[] args) {
		TreeNode e1 = new TreeNode(1);
		TreeNode e2 = new TreeNode(2);
		TreeNode e3 = new TreeNode(3);
		TreeNode e4 = new TreeNode(4);
		TreeNode e5 = new TreeNode(5);
		
		e1.left = e2;
		e2.right = e3;
		e3.left = e4;
		e4.right = e5;
		
		
		TreeNode root =e1;
		
		Example101 testExample = new Example101();
		testExample.isSymmetric(root);
	}
	
	
	// 得到树的层数
	public int getHeight(TreeNode root) {
		int height = 0;
		TreeNode current = root;
		while(current!=null) {
			return Math.max(getHeight(current.left), getHeight(current.right))+1;
		}
		return height;	
	}
	
	//以2为底求解对数
	static public double log(double value, double base) {
		return Math.log(value) / Math.log(base);
	}
	
	//得到树每层的结点数
	public int[] getNumPerLayer(TreeNode root) {
		int[] numPerLayer = new int[getHeight(root)];
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		queue.offer(root);
		int layer_num = queue.size();
		int num=0;
		int i=0;
		while(queue.size()>0) {
			TreeNode temp = queue.poll();
			num+=1;
				
			if(num==layer_num) {
				numPerLayer[i] = num;
				i+=1;
				num=0;
				if(temp.left!=null) {
					queue.offer(temp.left);
				}
				if(temp.right!=null) {
					queue.offer(temp.right);
				}
				layer_num = queue.size();
			}else {
				if(temp.left!=null) {
					queue.offer(temp.left);
				}
				if(temp.right!=null) {
					queue.offer(temp.right);
				}	
			}			
		}
		
		return numPerLayer;
	}
	
	//通过得到每层数目求和得到树的所有结点数目(有些绕，但是针对解题)
	public int getTreeNodeNum(TreeNode root) {
		int[] numPerLayer = getNumPerLayer(root);
		int nodeNum = 0;

		for(int i=0;i<numPerLayer.length;i++) {
			nodeNum+=numPerLayer[i];
		}
		return nodeNum;
	}
		
	// 生成根节点到索引为i的结点的路径
	public String findNodeByIndex(int i) {
		StringBuffer s = new StringBuffer();
		while((int)(i/2)!=0) {
			if(i%2==0) {
				s.append("L");
			}else {
				s.append("R");
			}
			i = (int)i/2;
		}
		
		char[] s_array = s.toString().toCharArray();
		char[] result_array = new char[s_array.length];
		for(int j=0;j<result_array.length;j++) {
			result_array[j] = s_array[result_array.length-1-j];
		}
		String result = new String(result_array);
//		System.out.println(result);
		return result;
	}
	

	
// 判断镜像对称
	public boolean isSymmetric(TreeNode root) {
		
		int height = getHeight(root);
		for(int i=1;i<=height;i++) {
			int layerNum = (int)(Math.pow(2, i-1));
			int startIndex = (int)(Math.pow(2, i-1));
			int stopIndex = 2*(int)(Math.pow(2, i-1))-1;
			
			for(int j=0;j<(int)(layerNum/2);j++){
				char[] path1 = findNodeByIndex(startIndex+j).toCharArray();
				char[] path2 = findNodeByIndex(stopIndex-j).toCharArray();
//				System.out.println(path1+"  "+path2);
				TreeNode p1=root,p2=root;
				for(int k=0;k<path1.length;k++) {
					if(path1[k]=='L') {
						if(p1==null) {
							p1=null;
						}else {
							p1 = p1.left;
						}
						
					}
					if(path1[k]=='R') {
						if(p1==null) {
							p1=null;
						}else {
							p1 = p1.right;
						}
					}
				}
				for(int k=0;k<path2.length;k++) {
					if(path2[k]=='L') {
						if(p2==null) {
							p2=null;
						}else {
							p2 = p2.left;
						}
						
					}
					if(path2[k]=='R') {
						if(p2==null) {
							p2=null;
						}else {
							p2 = p2.right;
						}
					}
				}
				
				if((p1==null&&p2==null) || (p1!=null&&p2!=null)&&(p1.val==p2.val)) {
					continue;
				}else {
					return false;
				}

			}
		}
		return true;


	}

}
