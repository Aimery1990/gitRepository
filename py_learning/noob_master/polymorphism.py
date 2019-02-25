

class Figure:

    def draw(self):
        print("Draw a shape")


class Eclipse(Figure):

    def draw(self):
        print("Draw an eclipse")


class Triangle(Figure):

    def draw(self):
        print("Draw a triangle")


ply_list = [Figure(), Eclipse(), Triangle()]

print(isinstance(ply_list[0], Figure))
print(isinstance(ply_list[1], Eclipse))
print(isinstance(ply_list[2], Triangle))

print(isinstance(ply_list[1], Figure))  # True
print(isinstance(ply_list[2], Figure))  # True

# father is a special son

for sp in ply_list:

    if isinstance(sp, Figure):
        print("This Figure")  # print 3 times here!!!!

    if isinstance(sp, Eclipse):
        sp.draw()


