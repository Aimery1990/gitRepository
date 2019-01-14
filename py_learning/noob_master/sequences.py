

a = "hello"
print(a[0])
print(a[4])

print(a[-5])
print(a[-1])

a = "01234567"
print(a[:])
print(a[0:5:2])
print(a[1:-1])
print(a[-1:0]) # none output
print(a[::-1]) # 76543210


# TUPLE
a = ()
print(type(a))
a = 2,
print(type(a))

a = ("wefawe", "awefawef", 2, 3, 4)
print(a[1])

print(a[:-1])
print(a[2:8]) # by slicing, no error, even 8 beyonds the scope

a1, a2, a3, a4, a5 = a
print(a1)
print(a2)
print(a3)
print(a4)
print(a5)

*strings, x, y = a  # *strings is a list
print(strings, type(strings))
str1, str2, *n = a  # *n is a list
print(n, type(n))

# use _ to ignore some objects in a tuple while unpacking
_, *strings = a
print(strings)
_, stringx, _, *n = a
print(stringx, n)


for idx, item in enumerate(a):
    print(idx, item)

for (idx, item) in enumerate(a):
    print(idx, item)


# LIST
print("This is list................")
l0 = list((23, 24, 45),)  # [23, 24, 45]
print(l0)
l1 = list([(23, 24, 45), ])  # [(23, 24, 45)]
print(l1)
l2 = list([(2,), 34, "hh"])
print(l2)
l3 = list(range(10))
print(l3)

stu_list = ["aaa", "bbb", "ccc"]
stu_list.append("ddd")
print(stu_list)

stu_list += ["eee", "fff"]
print(stu_list)
stu_list.extend(["ggg", "hhh"])
print(stu_list)

stu_list.insert(3, "insert0")
print(stu_list)
stu_list[3] = "i0"
print(stu_list)

stu_list.remove("i0")
print(stu_list)

string1 = stu_list.pop()
print(stu_list)
print(string1)

string1 = stu_list.pop(1)
print(stu_list)
print(string1)

# string1 = stu_list.pop(10)  # IndexError: pop index out of range

stu_list_r = stu_list.reverse()
print(stu_list_r)   # None
print(stu_list)

stu_list_t = stu_list.copy()
print(id(stu_list), " ", id(stu_list_t))
stu_list.insert(3, "i0")
print(stu_list_t)
print(stu_list)

stu_list_t.clear()
print(stu_list_t)

print(stu_list)
print(stu_list.index("eee"))
print(stu_list.index("ccc", 2, -1))

print(stu_list.count("i0"))

stu_list_n = [x*2 for x in stu_list if stu_list.index(x) % 2 == 0]
print(stu_list_n)

stu_list_a = [x*2 for x in stu_list if stu_list.index(x) % 2 != 0 and stu_list.index(x) < 4]
print(stu_list_a)

stu_list_b = [x*2 for x in stu_list if stu_list.index(x) % 2 == 0 if stu_list.index(x) < 4]
print(stu_list_b)

