def palindromePermutation(a):
    hashSet = {}
    odd     = 0

    for i in a:
        if i in hashSet:
            hashSet[i] += 1
        else:
            hashSet[i] = 1

    for i in hashSet:
        if hashSet[i] % 2 == 1:
            odd += 1

    if len(a) % 2 == 0:
        if odd % 2 == 0:
            return True
    else:
        if odd == 1:
            return True
    return False

print(palindromePermutation("navannavan"))
print(palindromePermutation("navan"))
#   Permutation of navan and navannavan
print(palindromePermutation("vaann"))
print(palindromePermutation("nnnnaaaavv"))

