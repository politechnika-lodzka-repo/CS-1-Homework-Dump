import random

goal = random.randint(1, 100)

while True:
    user_input = input("Guess a number ")
    if not(user_input.isdigit()):
        continue
    answer = int(user_input)
    if answer > goal:
        print("Too big")
    elif answer < goal:
        print("Too small")
    else:
        print("Got it")
        break
