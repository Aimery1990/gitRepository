

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

