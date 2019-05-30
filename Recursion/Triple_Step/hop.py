def hop(n, curr_step, d):
    if curr_step in d:
        return d[curr_step]
    if curr_step == n:
        d[curr_step] = 1
        return 1
    if curr_step > n:
        d[curr_step] = 0
        return 0

    one = hop(n, curr_step + 1, d)
    two = hop(n, curr_step + 2, d)
    three = hop(n, curr_step + 3, d)
    outcome = one + two + three
    d[curr_step] = outcome
    return outcome

print(hop(3, 0, {}))
