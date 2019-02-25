
import enum


class Weekdays(enum.Enum):
    MON = 1
    TUE = 2
    WED = 3
    THR = 4
    FRI = 5
    SAT = 6
    SUN = 0
    END = "DONE"


day = Weekdays.FRI
print(day)
print(day.value)
print(day.name)

if day == Weekdays.FRI:
    print("F")


@enum.unique    # make sure enumerate value is unique
class Weekdays2(enum.IntEnum):  # only for int value enumerate value
    MON = 1
    TUE = 2
    WED = 3
    THR = 4
    FRI = 5
    SAT = 6
    SUN = 0
    # END = 0 # error


day = Weekdays.FRI
print(day)
print(day.value)
print(day.name)

if day == Weekdays.FRI:
    print("F")
