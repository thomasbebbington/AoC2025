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
        if(len(num) % 2 == 0):
            if(num[0:len(num)//2] == num[len(num)//2:len(num)]):
                counter += x

print(counter)




