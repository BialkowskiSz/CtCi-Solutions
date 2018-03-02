#   Insert or delete = One Away = 1 Characters different
#   Replace          = Two Away = 2 Characters different


def oneAway(first, second):
    if first == second:
        return True

    if not first:
        if abs(len(first) - len(second)) == 1:
            return True

    dictionary  = {}
    count       = 0

    for i in first:
        if i in dictionary:
            dictionary[i] += 1
        else:
            dictionary[i] = 1

    for i in second:
        if i in dictionary:
            dictionary[i] -= 1
        else:
            count += 1
            if count > 1:
                return False

    #   If more than 2 characters difference can't replace
    for i in dictionary:
        if dictionary[i] > 0:
            count += dictionary[i]
            if count > 2:
                return False

    return True


print(oneAway("pale", "ple"))
print(oneAway("pales", "pale"))
print(oneAway("pale", "bale"))
print(oneAway("pale", "bake"))
print(oneAway(" ", ""))
print(oneAway("", " "))
print(oneAway(" ", " "))
