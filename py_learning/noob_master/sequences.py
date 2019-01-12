

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

*strings, x, y = a
print(strings, type(strings))
str1, str2, *n = a
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