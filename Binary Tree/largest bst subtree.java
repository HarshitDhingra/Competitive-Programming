import java.io.*;
import java.util.*;

public class Main {
  public static class Node {
    int data;
    Node left;
    Node right;

    Node(int data, Node left, Node right) {
      this.data = data;
      this.left = left;
      this.right = right;
    }
  }

  public static class Pair {
    Node node;
    int state;

    Pair(Node node, int state) {
      this.node = node;
      this.state = state;
    }
  }

  public static Node construct(Integer[] arr) {
    Node root = new Node(arr[0], null, null);
    Pair rtp = new Pair(root, 1);

    Stack<Pair> st = new Stack<>();
    st.push(rtp);

    int idx = 0;
    while (st.size() > 0) {
      Pair top = st.peek();
      if (top.state == 1) {
        idx++;
        if (arr[idx] != null) {
          top.node.left = new Node(arr[idx], null, null);
          Pair lp = new Pair(top.node.left, 1);
          st.push(lp);
        } else {
          top.node.left = null;
        }

        top.state++;
      } else if (top.state == 2) {
        idx++;
        if (arr[idx] != null) {
          top.node.right = new Node(arr[idx], null, null);
          Pair rp = new Pair(top.node.right, 1);
          st.push(rp);
        } else {
          top.node.right = null;
        }

        top.state++;
      } else {
        st.pop();
      }
    }

    return root;
  }

  public static void display(Node node) {
    if (node == null) {
      return;
    }

    String str = "";
    str += node.left == null ? "." : node.left.data + "";
    str += " <- " + node.data + " -> ";
    str += node.right == null ? "." : node.right.data + "";
    System.out.println(str);

    display(node.left);
    display(node.right);
  }

  public static class bstpair {
    int size;
    boolean isbst;
    int min;
    int max;
    Node lbst;
  }

  public static bstpair lbst(Node node) {
    if (node == null) {
      bstpair b = new bstpair();
      b.size = 0;
      b.isbst = true;
      b.lbst = null;
      b.min = Integer.MAX_VALUE;
      b.max = Integer.MIN_VALUE;
      return b;
    }
    bstpair left = lbst(node.left);
    bstpair right = lbst(node.right);

    bstpair ans = new bstpair();
    ans.isbst = left.isbst && right.isbst && (node.data >= left.max && node.data <= right.min);
    ans.min = Math.min(node.data, Math.min(left.min, right.min));
    ans.max = Math.max(node.data, Math.max(left.max, right.max));

    if (ans.isbst) {
      ans.lbst = node;
      ans.size = left.size + right.size + 1;
    } else if (left.size > right.size) {
      ans.lbst = left.lbst;
      ans.size = left.size;
    } else {
      ans.lbst = right.lbst;
      ans.size = left.size;
    }

    return ans;
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    Integer[] arr = new Integer[n];
    String[] values = br.readLine().split(" ");
    for (int i = 0; i < n; i++) {
      if (values[i].equals("n") == false) {
        arr[i] = Integer.parseInt(values[i]);
      } else {
        arr[i] = null;
      }
    }

    Node root = construct(arr);
    bstpair ans = lbst(root);
    System.out.println(ans.lbst.data + "@" + ans.size);
  }

}