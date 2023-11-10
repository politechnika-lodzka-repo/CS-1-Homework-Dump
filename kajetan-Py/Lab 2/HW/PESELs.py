PESEL_LENGTH = 11
PESEL_WEIGHT = (1, 3, 7, 9, 1, 3, 7, 9, 1, 3)


def numbers_only(pes):
    return pes.isdigit()


def correct_date(pes):
    year = int(pes[0:2])
    month = int(pes[2:4])
    day = int(pes[4:6])

    if month > 80:
        year += 1800
        month -= 80
    elif month > 60:
        year += 2200
        month -= 60
    elif month > 40:
        year += 2100
        month -= 40
    elif month > 20:
        year += 2000
        month -= 20
    else:
        year += 1900

    if(month > 12):
        return 0

    if month < 1 or day < 1:
        return 0

    isLeap = 0
    if year % 4 == 0:
        isLeap = 1
    if year % 100 == 0:
        isLeap = 0
    if year % 400 == 0:
        isLeap = 1

    if day > 31:
        return 0
    if (month in [4, 6, 9, 11]) and day > 30:
        return 0
    if month == 2:
        if day > 29 or (isLeap == 0 and day == 29):
            return 0

    return 1


def cchecksum(pes):

    checksum = 0

    for i in range(PESEL_LENGTH - 1):
        checksum += PESEL_WEIGHT[i] * int(pes[i])

    checksum = (10 - (checksum % 10)) % 10

    if checksum != int(pes[10]):
        return 0

    return 1


# counters
total = correct = male = female = 0
invalid_length = invalid_digit = invalid_date = invalid_checksum = 0

file = open("1e6.dat", 'r')

# main processing loop
for pesel in file:
    pesel = pesel.strip()
    total += 1

    if len(pesel) != PESEL_LENGTH:
        invalid_length += 1
        continue
    if not numbers_only(pesel):
        invalid_digit += 1
        continue
    if not correct_date(pesel):
        invalid_date += 1
        continue
    if not cchecksum(pesel):
        invalid_checksum += 1
        continue

    correct += 1

    if int(pesel[9]) % 2 == 0:
        female += 1
    else:
        male += 1


file.close()

# show results
print(total, correct, female, male)
print(invalid_length, invalid_digit, invalid_date, invalid_checksum)
