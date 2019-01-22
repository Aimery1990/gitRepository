

def print_area(width, height):
    area = width * height
    print(area)


print_area(33.0, 46)
print_area(width=33.5, height=77)
print_area(height=55.6, width= 5)
print_area(23.0, height=54)
# print_area(23.0, width=44.6)    # TypeError: print_area() got multiple values for argument 'width'
# print_area(width=55, 22.6)        # SyntaxError: positional argument follows keyword argument


def sum(*numbers, multiple=1):  # * represent tuple
    total = 0
    for num in numbers:
        total += num
    print("multiple is {0}".format(multiple))
    return total * multiple

print(sum(2,44,5.5,7))
print(sum(2,44,5,5,7, multiple=2))

sum_tuple = (2,44,5.5,7)
# print(sum(sum_tuple)) # TypeError: unsupported operand type(s) for +=: 'int' and 'tuple'
print(sum(33, 4.6, *sum_tuple)) # unpack is must

# changeable variable must be after regulatory variable!!!
def show_info(sep=":", **info):  # ** represents dict
    for key, value in info.items():
        print("{0} {2} {1}".format(key, value, sep))

show_info("->", name="tony", age=18, gender="male")
show_info("==>", name="tony", age=18, gender="male")

dict_t = {"name": "tony", "age": 18, "gender": "male"}
show_info(**dict_t, sep="++>")  # UNPACK IS MUST

dict_t = {"name": "tony", "age": 18,}
show_info(gender="male", **dict_t, sep = "-->") # UNPACK IS MUST


# based on __next__() of iterator
def square(num):
    for i in range(1, num + 1):
        yield i * i     # generator


for i in square(5):
    print(i, end=" ")
print("")


def calculate(n1, n2, opr):
    multiple = 2

    def add(a, b):
        return ( a+b ) * multiple

    def sub(a, b):
        return (a - b) * multiple

    if opr == "+":
        return add(n1, n2)
    else:
        return sub(n1, n2)

print(calculate(1,1, "+"))
print(calculate(1,1, "-"))


def calculate_fun(opr):
    multiple = 2

    def add(a, b):
        return (a + b) * multiple

    def sub(a, b):
        return (a - b) * multiple

    if opr == "+":
        return add
    else:
        return sub

print(calculate_fun("+")(1, 2))
print(calculate_fun("-")(1, 2))


def calculate_lambda(opr):
    multiple = 2

    if opr == "+":
        return lambda a, b: (a + b) * multiple
    else:
        return lambda a, b: (a - b) * multiple

print(calculate_lambda("+")(1, 2))
print(calculate_lambda("-")(1, 2))


users = ["Tony", "Tom", "Ben", "Alex"]
users_filter = filter(lambda u: u.startswith("T"), users)
print(list(users_filter))

number_list = range(1, 11)
number_filter = filter(lambda it: it % 2, number_list)
print(list(number_filter))


users_map = map(lambda it: it.lower(), users)
print(list(users_map))

print(users)
users_map = map(lambda u: u.lower(), filter(lambda  it: it.startswith("T"), users))  # works
print(users_map)
print(list(users_map))
users_map = map(lambda u: u.lower(), list(filter(lambda  it: it.startswith("T"), users))) # works also
print(list(users_map))

from functools import reduce

a = (1, 2, 3, 4)
a_reduce = reduce(lambda acc, i: acc + i, a)
print(a_reduce)
a_reduce = reduce(lambda acc, i: acc + i, a, 3)     # 3 is initial value or base value for adding
print(a_reduce)

a_reduce = reduce(lambda acc, i: acc * i, a, 3)     # 3 is initial value or base value for multiplying
print(a_reduce)


