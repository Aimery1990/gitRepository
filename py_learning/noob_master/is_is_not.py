

class Person:
    def __init__(self, name, age):
        print("this Person class")
        self.name = name
        self.age = age

    def __eq__(self, other):
        if self.name == other.name and self.age == other.age:
            return True
        else:
            return False


"if __eq__ is not defined p1!=p2 always"

p1 = Person("tom", 30)
p2 = Person("tom", 30)

print(p1 == p2)
print(id(p1))
print(id(p2))
print(p1 is p2)  # False for p1 and p2 have different address in memory

p1 = p2
print(id(p1))
print(id(p2))
print(p1 is p2)


