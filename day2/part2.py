def isvalid(x):
    for i in range(2, len(x)+1): #loop through divisors
        if (len(x) % i == 0):
            v = False
            partlength = len(x)//i
            first = x[0:partlength]
            for j in range(1, i): #loop through parts
                part = x[j*partlength:(j+1)*partlength]
                if part != first:
                    v = True

            if v == False:
                return False
    return True

inputfile = open("input.txt")

ranges = inputfile.read()
inputfile.close()

splitted = ranges.split(',')
counter = 0

for e in splitted:
    therange = e.split('-')
    first = int(therange[0])
    last = int(therange[1])
    for x in range(first, last + 1):
        num = str(x)
        if(not isvalid(num)):
            counter += x

print(counter)




