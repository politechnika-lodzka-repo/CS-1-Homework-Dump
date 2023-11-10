import random

a = random.randint(1, 50)
while 1:
    s = input("Guess a number: ")
    if not(s.isdigit()):
        continue
    n = int(s)
    if n == a:
        print("got it")
        break
    if n > a:
        print("too big")
    else:
        print("too small")
