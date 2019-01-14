

s0 = {"aa", "bb", "cc", "cc"}
print(s0)

s0 = {(1,1,2,2,3,3)}
print(s0)  # {(1, 1, 2, 2, 3, 3)}

# s0 = {[2,2,2,4,4,6,6,7]}  # TypeError: unhashable type: 'list'
print(s0)

s0 = set((1,1,2,2,3,3))  # {1, 2, 3}
print(s0)

s0 = set([2,2,2,4,4,6,6,7]) # {2, 4, 6, 7}
print(s0)

s0.add("aaa")
print(s0)

s0.remove("aaa")
print(s0)

s0.discard("aaa")  # None error given

s0.pop()
print(s0)

s0.pop()
print(s0)

s0.clear()
print(s0)

s1 = {"aa", "bb", "cc", "dd", "ee"}
for item in s1:
    print(item)

for i,item in enumerate(s1):
    print(i, item)   # i IS NOT INDEX, it just a sequence how to foreach the set. SET has no index


# unchangeable set
set2 = frozenset((1,1,2,2,3,3))
print(set2)
set2 = frozenset(["aaa", "bbb", "ccc", "ddd", "ddd"])
print(set2)

set2_t = {x*2 for x in set2 if x != "ccc"}
print(set2_t)  # sequences are not unique


list0 = [0,0,1,1,2,2]
set3 = { x  for x in list0}
print(set3)  # repeated values are dropped out

