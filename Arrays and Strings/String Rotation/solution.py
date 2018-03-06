#   Iterate through first string until meeting element
#   Iterate until end of first string if characters match
#   Re iterate through start

def stringRotation(first, second):
    firstLength     = len(first)
    secondLength    = len(second)

    if firstLength != secondLength:
        return False

    for i, value in enumerate(first):
        if value == second[0]:
            temp = 0
            for j in range( i+1, firstLength ):
                temp += 1
                if first[j] != second[temp]:
                    return False
            for j in range( 0, i ):
                temp += 1
                if first[j] != second[temp]:
                    return False
            return True
    return False

first   = raw_input("First string: ")
second  = raw_input("Second string: ")
print(stringRotation(first, second))
