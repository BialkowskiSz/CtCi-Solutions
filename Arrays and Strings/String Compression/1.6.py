def stringCompression(a):
    count = 0
    compressed = []
    last = a[0]
    for i in a:
        if i == last:
            count += 1
        else:
            compressed.append("{}{}".format(last, count))
            count = 1
            last = i
    compressed.append("{}{}".format(last, count))

    compressed = ''.join(compressed)
    if len(compressed) >= len(a):
        return a
    return compressed


print(stringCompression("aabcccccaaa"))
print(stringCompression("python"))
print(stringCompression("abbcccddddeeeeeffffff"))

