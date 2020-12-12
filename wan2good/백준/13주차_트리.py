input=__import__('sys').stdin.readline
MIS=lambda:map(int,input().rstrip().split())

def print_post_order(pre_list, in_list):

    size=len(pre_list)
    if not pre_list: 
        return
    root=pre_list[0]
    root_idx=0
    for idx in range(len(in_list)):
        if root==in_list[idx]: 
            root_idx=idx;break

    print_post_order(pre_list[1:root_idx+1],in_list[0:root_idx])
    print_post_order(pre_list[root_idx+1:size],in_list[root_idx+1:size])

    print(root,end=' ')

t=int(input().rstrip())
for _ in range(t):
    n=int(input().rstrip())
    pre_list=list(MIS())
    in_list=list(MIS())

    print_post_order(pre_list,in_list)
    print()