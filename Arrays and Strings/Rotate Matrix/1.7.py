"""
O(n**2) Solution with O(1) space
"""

n = int(raw_input("Specify N"))
aZeroIndex = n - 1
array = [ [ j+(n*i) for j in range(1, n+1) ] for i in range(n)]

layers = int(round(n/2))

for layer in range(layers):
    for number in range(0+layer, nZeroIndex-layer):
        temp = array[number][nZeroIndex - layer]
        array[number][nZeroIndex - layer] = array[layer][number]

        array[layer][number] = array[nZeroIndex - number][layer]

        array[nZeroIndex - number][layer] = array[nZeroIndex - layer][nZeroIndex - number]

        array[nZeroIndex - layer][nZeroIndex - number] = temp

for i in array:
    print(i)
