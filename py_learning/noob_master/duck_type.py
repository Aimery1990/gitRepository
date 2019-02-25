

class Animal(object):
    def run(self):
        print("Animal runs")


class Dog(Animal):
    def run(self):
        print("Dog runs")


class Car(object):
    def run(self):
        print("Car runs")


def go(animal):
    animal.run()


go(Animal())
go(Dog())
go(Car())   # even car doesn't belong to Animal family, but it seems like an animal. That's enough to go.

