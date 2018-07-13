

# about eval using
res = eval(input("please input your expression: "))
print(res)

# swap value
x, y = 10, 20
print("x is %d y is %d" %(x, y))
x, y = y, x
print("x is %d y is %d" %(x, y))


# multi inputs
score1, score2 = eval(input("Please input 2 scores separated by a comma: "))
print(score1)
print(score2)

# error!!! eval and input are unable to parse input string into 2 strings
#str1, str2 = eval(input("Please input 2 strings separated by a comma: "))

pi = 3.1415926
print(round(pi))
print(round(pi, 2))
print(round(pi, 3))


import math

def quadratic_solution():
    print("This function is for finding the real solutions to a quadratic")

    a = float(input("Enter coefficient a: "))
    b = float(input("Enter coefficient b: "))
    c = float(input("Enter coefficient c: "))

    discRoot = math.sqrt(b * b - 4 * a * c)
    root1 = (-b + discRoot)/(2 * a)
    root2 = (-b - discRoot)/(2 * a)

    print("The solutions are: ", root1, root2)


quadratic_solution()


#compute factorial

def compute_factorial(n):
    factor = 1
    for i in range(n, 1, -1):
        factor = factor * i
    print("factorial of %d is %d" % (n, factor))


compute_factorial(6)
compute_factorial(8)
compute_factorial(10)





