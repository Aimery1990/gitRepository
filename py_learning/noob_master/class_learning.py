

class Animal(object):

    def __init__(self, age, sex, weight):
        self.age = age
        self.sex = sex
        self.__weight = weight  # private

    # get must fore than set
    @property
    def weight(self):
        return self.__weight

    @weight.setter
    def weight(self, weight):
        self.__weight = weight

    def eat(self):
        self.__weight += 0.05
        self.__run()
        print("eat ...")

    def __run(self):
        self.__weight -= 0.03
        print("run ...")

    pass


anim = Animal(2, "male", 50)
print(anim)
print(anim.age)
anim.eat()
# anim.run()            # unable to reference private attribute
anim._Animal__run()     # tricky way to reference private attribute
print(anim.weight)            # unable to reference private attribute without getter/setter
print(anim._Animal__weight)     # tricky way to reference private attribute


print("\n\n")


class Account:

    interest_rate = 0.068

    def __init__(self, owner, amount):
        self.owner = owner
        self.amount = amount

    @classmethod
    def interest_by(cls, amt):
        print(type(cls))
        return cls.interest_rate * amt

    @staticmethod
    def interest_with(amt):
        # return Account.interest_rate * amt
        return Account.interest_by(amt)


account = Account("Tony", 50000)
print(account.owner, account.amount)
print(Account.interest_rate)

print(account.interest_rate)    # extremely bad!!!

account.interest_rate = 0.0555  # new member created, extremely bad!!!
print(account.__dict__)

print(Account.interest_rate)
print(account.interest_rate)

interest = Account.interest_by(12_000)
print(interest)

interest = Account.interest_with(12_000)
print(interest)
