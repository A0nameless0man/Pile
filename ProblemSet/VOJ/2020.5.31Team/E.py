from pprint import pprint


def from_list(l):
    return {"a_ty": "list", "data": l}


def concat(lhs, rhs):
    # pprint(lhs)
    # pprint(rhs)

    if isinstance(lhs, list):
        lhs = from_list(lhs)
    if isinstance(rhs, list):
        rhs = from_list(rhs)
    return {"a_ty": "concat", "children": [lhs, rhs]}


def sorted(l):
    # pprint(l)
    if isinstance(l, list):
        l = from_list(l)
    return {"a_ty": "sorted", "children": l}


def shuffle(l):
    # pprint(l)

    if isinstance(l, list):
        l = from_list(l)
    return {"a_ty": "shuffle", "children": l}


src1 = input()
tree1 = eval(src1)
if isinstance(tree1, list):
    tree1 = from_list(tree1)
# pprint(tree1)
# pprint(type(tree1))

src2 = input()
tree2 = eval(src2)
if isinstance(tree2, list):
    tree2 = from_list(tree2)

# pprint(tree2)


def eval_tree(t):
    # pprint(type(t))
    # pprint(t)
    ty = t["a_ty"]

    if ty == "list":
        return [[x] for x in t["data"]]
    elif ty == "sorted":
        # print("in sorted")
        ans = []
        ch_ans = eval_tree(t["children"])
        for l in ch_ans:
            ans.extend(l)
        ans.sort()
        return [[x] for x in ans]
    elif ty == "concat":
        # print("in concat")
        ans = []
        for ch in t["children"]:
            ans.extend(eval_tree(ch))
        return ans
    elif ty == "shuffle":
        # print("in shuffle")
        ans = []
        ch_ans = eval_tree(t["children"])
        for l in ch_ans:
            ans.extend(l)
        ans.sort()
        if len(ans) > 0 and ans[0] == ans[len(ans)-1]:
            return [[x] for x in ans]

        return [ans]
    else:
        raise "unreachable"

# print()


ans1 = eval_tree(tree1)
pprint(ans1)

ans2 = eval_tree(tree2)
pprint(ans2)


def is_equal(lhs, rhs):
    if len(lhs) != len(rhs):
        return False

    l = len(lhs)
    for i in range(l):
        if lhs[i] != rhs[i]:
            return False

    return True

# print()
# print(is_equal(ans1,ans2))


if is_equal(ans1, ans2):
    print("equal")
else:
    print("not equal")