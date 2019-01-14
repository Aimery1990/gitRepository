
key = 5
dict1 = { key: "value_5"}
print(type(dict1))
print(dict1)


tp1 = ((100, "aaa"),(101, "bbb"),(102, "ccc"))
dict1 = dict(tp1)
print(dict1)

lst1 = [(100, "aaa"),(101, "bbb"),(102, "ccc")]
dict1 = dict(lst1)
print(dict1)

dict2 = dict(x100="aa", x101="bb")  # {'x100': 'aa', 'x101': 'bb'}
print(dict2)

key_str1 = "100"
key_str2 = "101"
dict2 = dict(key_str1="aa", key_str2="bb") #  {'key_str1': 'aa', 'key_str2': 'bb'}
print(dict2)

dict2["key_str1"] = "aaa"
print(dict2)
dict2[key_str1] = "cc"
print(dict2)

del dict2['key_str2']
print(dict2)

dict2.pop("key_str1")
print(dict2)

# dict2.pop(key_str2)  # error
dict2.pop(key_str2, 'cc')  # no error prompt but "cc" is still in dict2
print(dict2)


tp1 = ((100, "aaa"),(101, "bbb"),(102, "ccc"))
dict3 = dict(tp1)
print(dict3)

print(dict3.get(100))
print(dict3.get(100, "a")) # still prints aaa, even though "a" is not existed
print(dict3.get(1000))  # None

its = dict3.items()
print(its, type(its))

for i in its:
    print(i, type(i))

keys = dict3.keys()
print(keys,  type(keys))

keys_list = list(keys)
print(keys_list)

values = dict3.values()
print(values, type(values))

values_list = list(values)
print(values_list)

for key in dict3.keys():
    print(key)

for val in dict3.values():
    print(val)

for key, val in dict3.items():
    print(key, val)


dict4 = {key:val for key, val in dict3.items() if key % 2 == 0}
print(dict4)

set4 = {key  for key, val in dict3.items()}
print(set4)

list4 = [key for key, _ in dict3.items()]
print(list4)
