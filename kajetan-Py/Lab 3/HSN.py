def next_hsn(c):
    if c % 2 == 0:
        return c//2
    else:
        return 3*c+1


def hsn(c):
    sequence = [c]
    while c > 1:
        c = next_hsn(c)
        sequence.append(c)
    return sequence


sequence_lenghts = []
highiest_values = []
for i in range(1000):
    a = hsn(i)
    sequence_lenghts.append(len(a))
    highiest_values.append(max(a))

longest_sequence_index = sequence_lenghts.index(max(sequence_lenghts))

print(f"Problem 1 (for range 1-1000):\n"
      f"- longest sequence contains {max(sequence_lenghts)} elements\n"
      f"- starts from seed: {longest_sequence_index})"
      )

h = max(highiest_values)
p2 = []
for i in range(1000):
    if highiest_values[i] == h:
        p2.append(i)

print("\nProblem 2 (for range 1-1000):\n"
      f"- highest element value is {h}\n"
      f"- found {len(p2)} times\n"
      f"- in sequences starting from seeds: {p2}"
      )

p3 = [0]*(max(sequence_lenghts)+1)
for i in sequence_lenghts:
    p3[i] += 1

p3_2 = []
for i in range(1000):
    if sequence_lenghts[i] == p3.index(max(p3)):
        p3_2.append(i)

mcsn = p3.index(max(p3))
print("\nProblem 3 (for range 1-1000): \n"
      f"- most common sequence length is {mcsn} \n"
      f"- found {max(p3)} times,\n"
      f"- in sequences starting from seeds: {p3_2}"
      )
