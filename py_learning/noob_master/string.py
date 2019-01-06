
str1 = r"hello \t world"    # raw string
print(str1)

str2 = '''
        hi
        nice 
        to 
        see 
        you
        '''
print(str2)

name = 'mary'
age = 18
money = 30.66

print("{0}'s age is {1:d}, and she has {2:f} dollars.".format(name, age, money))
print("{0:s}'s age is {1:5d}, and she has {2:.4f} dollars.".format(name, age, money))

print(int('AB', 16))
print(str([]), str(True))


