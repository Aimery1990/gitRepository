

i = 0

while i**2 < 100_0000:
    i += 1;

print(i)


for num in range(1, 10, 2):
    print("{0} X {0} = {1}".format(num, num**2))

numbers = [2, 3, 5, 6]

for idx, num in enumerate(numbers):
    print(idx, num)

else:
    print("FOR LOOP DONE")


i = 0

while i * i < 10:
    i += 1
    print("{0} X {0} = {1}".format(i, i**2))
    # if i >3:
    #     break

else:
    print("WHILE LOOP DONE")