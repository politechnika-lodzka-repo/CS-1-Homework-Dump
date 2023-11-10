# import time

# start = time.time()

PESEL_LENGTH = 11
PESEL_WEIGHT = (1, 3, 7, 9, 1, 3, 7, 9, 1, 3)
CENTURY_INDICATORS = {4: 1800, 0: 1900, 1: 2000, 2: 2100, 3: 2200}


def get_day(pesel: str) -> int:
    return int(pesel[4:6])


def get_month(pesel: str) -> int:
    return int(pesel[2:4]) % 20


def get_year(pesel: str) -> int:
    last_two_digits_of_year = int(pesel[0:2])
    century = get_century(pesel)
    return century + last_two_digits_of_year


def get_century(pesel: str) -> int:
    month_digits = int(pesel[2:4])
    return CENTURY_INDICATORS[month_digits // 20]


def is_leap_year(year: int) -> bool:
    if year % 4 == 0 and not year % 100 == 0:
        return True
    else:
        if year % 100 == 0 and year % 400 == 0:
            return True
        else:
            return False


def verify_length(pesel: str) -> bool:
    return len(pesel) == PESEL_LENGTH


def verify_digit(pesel: str) -> bool:
    return pesel.isdigit()


def verify_date(pesel: str) -> bool:
    year = get_year(pesel)
    month = get_month(pesel)
    day = get_day(pesel)

    if day < 1 or day > 31:
        return False

    if month > 12 or month < 1:
        return False

    if not is_leap_year(year) and month == 2 and day > 28:
        return False
    else:
        if is_leap_year(year) and month == 2 and day > 29:
            return False

    if month in [1, 3, 5, 7, 8, 10, 12] and day > 31:
        return False

    if month in [4, 6, 9, 11] and day > 30:
        return False

    return True


def get_sex(pesel: str) -> bool:
    return int(pesel[9]) % 2 == 0


def verify_checksum(pesel: str) -> bool:
    checksum = 0

    for i in range(PESEL_LENGTH - 1):
        checksum += PESEL_WEIGHT[i] * int(pesel[i])

    checksum = (10 - (checksum % 10)) % 10

    if checksum == int(pesel[10]):
        return True
    else:
        return False


# counters
total = correct = male = female = 0
invalid_length = invalid_digit = invalid_date = invalid_checksum = 0

file = open("1e6.dat", 'r')

# main processing loop
for pesel in file:
    pesel = pesel.strip()
    total += 1

    if not verify_length(pesel):
        invalid_length += 1
        continue

    if not verify_digit(pesel):
        invalid_digit += 1
        continue

    if not verify_date(pesel):
        invalid_date += 1
        continue

    if not verify_checksum(pesel):
        invalid_checksum += 1
        continue

    correct += 1

    if get_sex(pesel):
        female += 1
    else:
        male += 1

file.close()

# show results
print(total, correct, female, male)
print(invalid_length, invalid_digit, invalid_date, invalid_checksum)

# print(f"Runtime [s]= {time.time() - start}")
