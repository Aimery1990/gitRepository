

class Person:

    def __init__(self, name, age):
        self.name = name
        self.age = age

    # def info(self):
    #     template = 'Person [name={0}, age = {1}]'
    #     s = template.format(self.name, self.age)
    #     return s

    def __str__(self):
        template = 'Person [name={0}, age = {1}]'
        s = template.format(self.name, self.age)
        return s

    def __eq__(self, ano):
        if self.age == ano.age and self.name == ano.name:
            return True
        else:
            return False


p1 = Person("Aim", 18)
p2 = Person("Aimery", 18)
p3 = p2

print(Person("Aim", 18))

print(Person("Aimery", 19) == Person("Aim", 18))

# is is checking whether 2 objects are share common memory
print(p1 is p2)
print(p2 is p3)

