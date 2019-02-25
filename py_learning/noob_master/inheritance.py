

class Person:

    def __init__(self, name, age):
        self.name = name
        self.age = age

    def info(self):
        template = 'Person [name={0}, age = {1}]'
        s = template.format(self.name, self.age)
        return s


class Student(Person):

    def __init__(self, name, age, school):
        super().__init__(name, age)
        self.school = school

    def info(self):
        template = "Person [name={0}, age = {1}, school = {2}]"
        s = template.format(self.name, self.age, self.school)
        return s


stu = Student("tony", 18, "Stanford")
print(stu.info())


class ParentClass1:
    def run(self):
        print("ParentClass1 run ...")


class ParentClass2:
    def run(self):
        print("ParentClass2 run ...")


class SubClass1(ParentClass1, ParentClass2):
    pass


class SubClass2(ParentClass2, ParentClass1):
    pass


class SubClass3(ParentClass1, ParentClass2):
    def run(self):
        print("SubClass3 run ...")


sub1 = SubClass1()
sub1.run()

sub2 = SubClass2()
sub2.run()

sub3 = SubClass3()
sub3.run()


