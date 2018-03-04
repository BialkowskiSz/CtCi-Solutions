rows    = int(raw_input("M: "))
columns = int(raw_input("N: "))
array = [ [ 1 for _ in range(columns) ] for _ in range(rows) ]

#   Random 0 locations
array[3][2] = 0
array[0][0] = 0

def zeroMatrix(array):
    global rows
    global columns

    zeroLocations = []

    for i in range(rows):
        for j in range(columns):
            if array[i][j] == 0:
                zeroLocations.append((i, j))



    for zeroPair in zeroLocations:
        for i in range(columns):
            array[zeroPair[0]][i] = 0

        for i in range(rows):
            array[i][zeroPair[1]] = 0


    for i in array:
        print(i)


zeroMatrix(array)
