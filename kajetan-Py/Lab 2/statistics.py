file = open("dorian.txt", "r")

locc = {}

# input data
for line in file:
    line = line.strip().lower()
    for let in line:
        if let not in locc:
            locc[let] = 1
        else:
            locc[let] += 1
file.close()

pom = locc
n = 5

print("Letters statistics:\n"
      "- 5 most common letters/chars:")

# reverse the dictionary
rlocc = {}
for let, num in locc.items():
    if num not in rlocc:
        rlocc[num] = [let]
    else:
        rlocc[num].append(let)

# least letter occurances
n = 5
for num, let in reversed(sorted(rlocc.items())):
    print(f"letter/char {str(let)[1:-1]} found {num} times,")
    n -= 1
    if n == 0:
        break


# least letter occurances
n = 5
print("-5 least common letters / chars:")
for num, let in sorted(rlocc.items()):
    print(f"letter/char {str(let)[1:-1]} found {num} times,")
    n -= 1
    if n == 0:
        break

# reading words data
file = open("dorian.txt")
wocc = {}
wlen = {}
for line in file:
    words = line.strip().lower().split()
    for wor in words:
        # wor = wor.replace('"', '')
        wor = wor.strip(".,;:-'`\?!()\"")
        if wor not in wocc:
            wocc[wor] = 1
            wlen[wor] = len(wor)
        else:
            wocc[wor] += 1
file.close()

print("\nWords statistics:\n"
      f"- number of unique words: {len(wocc.values())}\n"
      "- 5 most common words:")

# reversing the dictionaries
rwocc = {}
for wor, num in wocc.items():
    if num not in rwocc:
        rwocc[num] = [wor]
    else:
        rwocc[num].append(wor)

rwlen = {}
for wor, num in wlen.items():
    if num not in rwlen:
        rwlen[num] = [wor]
    else:
        rwlen[num].append(wor)

# printing the result
n = 5
for num, wor in reversed(sorted(rwocc.items())):
    print(f"word {str(wor)[1:-1]} found {num} times,")
    n -= 1
    if n == 0:
        break

n = 5
print("- the longest words(with 5 longest lengths) :")
for num, wor in reversed(sorted(rwlen.items())):
    print(f"words of length {num} are {str(wor)[1:-1]},")
    n -= 1
    if n == 0:
        break
