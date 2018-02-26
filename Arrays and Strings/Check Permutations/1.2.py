def checkPermutation(a, b):
    
    hashSet = {}

    if len(a) != len(b):
        return False

    for i in a:

        if i in hashSet:
            hashSet[i] += 1
        else:
            hashSet[i] = 1

    for i in b:

        if i not in hashSet:
            return False
        
        if hashSet[i] == 0:
            return False

        hashSet[i] -= 1

    return True

print(checkPermutation("1234567890", "1029384756"))
print(checkPermutation("1234567890", "1234567899"))
