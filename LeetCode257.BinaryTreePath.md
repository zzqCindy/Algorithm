## LeetCode 257. BinaryTreePath

Given a binary tree, return all root-to-leaf paths.

**Note:** A leaf is a node with no children.

**Example:**

```
Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
```



差不多一年没做过题了，一直习惯了用C++刷题，JAVA差不多忘光了=。=而且最近python用的多，编程不带脑子（喂）偶然发现JAVA有个坑，记下来免得以后忘了



**Solution 1**

最直接的想法，DFS，字符串构造

```
public List<String> binaryTreePaths2(TreeNode root) {
        if (root == null) {
            return resultList;
        }
        findPaths(root, root.val + "");
        return resultList;
    }

    private void findPaths(TreeNode node, String path) {
        if (node.left == null && node.right == null) {
            resultList.add(path);
        }
        if (node.left != null) {
            findPaths(node.left, path + "->" + node.left.val);
        }
        if (node.right != null) {
            findPaths(node.right, path + "->" + node.right.val);
        }
    }
```



**Solution 2**

String改为StringBuilder效率更高，不过要注意截取长度

```
public List<String> binaryTreePaths3(TreeNode root) {
        findPath(root, new StringBuilder());
        return resultList;
    }

    private void findPath(TreeNode node, StringBuilder sb) {
        if (node == null) {
            return;
        }
        int len = sb.length();
        sb.append(node.val);
        if (node.left == null && node.right == null) {
            resultList.add(sb.toString());
        } else {
            sb.append("->");
            findPath(node.left, sb);
            findPath(node.right, sb);
        }
        sb.setLength(len);// 截取 ！！！
    }
```



