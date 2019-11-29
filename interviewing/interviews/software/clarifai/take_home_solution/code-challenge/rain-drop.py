class RainDrop:
    def __init__(self, l):
        self.sw = [[0,0,0] for i in range(l)]
        self.max = l
        self.min = 0
        self.filled = 0

    def drop(self, f):
        floor = int(f)
        if floor > self.max or floor < self.min:
            return

        floor = min(self.max-1, floor)
        if self.sw[floor][0] != 1:
            self.sw[floor][0] = 1
            self.filled += 1
        
        if floor == self.min:
            self.fillRight(f)
        elif floor+1 >= self.max:
            self.fillLeft(f)
        else:
            self.fillLeft(f)
            self.fillRight(f)
    
    def isSideWalkWet(self):
        return self.filled == self.max

    def fillLeft(self,f):
        p = int(f)
        if self.sw[p-1][0] != 1:
            decimal = p - f + 1.0
            if (decimal >= 1.0 or self.sw[p-1][1] > 1 - decimal)\
                and self.sw[p-1][0] != 1:
                self.sw[p-1][0] = 1
                self.filled += 1
            elif self.sw[p-1][2] < decimal: 
                self.sw[p-1][2] = decimal
    
    def fillRight(self,f):
        p = int(f)
        if self.sw[p+1][0] != 1:
            decimal = f - p
            if (decimal >= 1.0 or self.sw[p+1][2] > 1 - decimal)\
                and self.sw[p+1][0] != 1:
                self.sw[p+1][0] = 1
                self.filled += 1
            elif self.sw[p+1][1] < decimal: 
                self.sw[p+1][1] = decimal

print("Create sidewalk of size 10")
rd = RainDrop(10)

print("From -1 to 11")
for i in range (-1,12):
    rd.drop(i)

print("is sidewalk wet",rd.isSideWalkWet())

rd = RainDrop(10)

print("From 1.1 to 9.1")
for i in range (1, 10):
    rd.drop(i+.1)

print("is sidewalk wet", rd.isSideWalkWet())