import sys


def solve(root, start, end):
    for i in range(start, end):
        if inorder[i] == preorder[root]:
            solve(root + 1, start, i)  # left subtree
            solve(root + i + 1 - start, i + 1, end)  # right subtree
            print(preorder[root], end=" ")


if __name__ == "__main__":
    t = int(sys.stdin.readline())
    for _ in range(t):
        n = int(sys.stdin.readline())
        preorder = list(map(int, sys.stdin.readline().split()))
        inorder = list(map(int, sys.stdin.readline().split()))
        solve(0, 0, n)
        print("")