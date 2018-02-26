def URLLify(a):
    for i in range(len(a)):
        if a[i] == ' ':
            a = a[:i:] + '%20' + a[i+1::]
    return a

print(URLLify("Mr John Smith"))
