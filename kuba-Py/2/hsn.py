''' Experiments with Hailstone sequences '''


def next_hsn(c):
    ''' Return next hsn-number'''
    if c % 2 == 0:
        return c//2
    else:
        return 3*c+1


def hsn(c):
    ''' Return full hsn-sequence for seed c'''
    sequence = [c]
    while c > 1:
        c = next_hsn(c)
        sequence.append(c)
    return sequence


LIMIT = 1000

print(hsn(3))

print(len(hsn(3)))
