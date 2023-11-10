"""
Functions related to Fibonacci sequence.

The module provides functions returning
numbers from Fibonacci sequence
as single values or lists.
"""


def fib(n: int) -> int:
    """
    Returns the n-th number of
    the Fibonacci series using
    iteration.

    For n<=0, function returns 0

    :param n:
    :return:
    """
    if n <= 0:
        return 0
    a, b = 0, 1
    for i in range(n - 1):
        a, b = b, a + b
    return b


def fib_r(n: int) -> int:
    """
    Returns the n-th number of
    the Fibonacci series using
    recurrence.

    For n<=0, function returns 0

    :param n:
    :return:
    """
    if n <= 0:
        return 0
    elif n in [1, 2]:
        return 1
    else:
        return fib_r(n - 1) + fib_r(n - 2)


def fib_series(n: int) -> list[int]:
    """
    Returns the list of n-numbers
    from the Fibonacci series.

    For n<=0, function returns []

    :param n:
    :return:
    """
    series: list[int] = []
    if n <= 0:
        return series
    a, b = 0, 1
    for i in range(n):
        series.append(a)
        a, b = b, a + b
    return series


def fib_upto(n: int) -> list[int]:
    """
    Returns the list of numbers of
    the Fibonacci series which are
    smaller than n

    For n<=0, function returns []
    :param n:
    :return:
    """

    series: list[int] = []
    if n <= 0:
        return series
    a, b = 0, 1
    for i in range(n):
        if a >= n:
            return series
        series.append(a)
        a, b = b, a + b
    return series


if __name__ == "__main__":
    print("Library tests:")
    print(fib(50))
    print(fib_r(35))
    print(fib_series(10))
    print(fib_upto(60))
    print("Comparison between fib() and fib_r() [n=10, 20, 40]")

    import time
    print("running the functions for n=10...")
    iterative10 = time.time()
    print("iterative n=10: ", fib(10))
    iterative10 = time.time() - iterative10
    recursive10 = time.time()
    print("recursive n=10: ", fib_r(10))
    recursive10 = time.time() - recursive10
    print("running the functions for n=20...")
    iterative20 = time.time()
    print("iterative n=20: ", fib(20))
    iterative20 = time.time() - iterative20
    recursive20 = time.time()
    print("recursive n=20: ", fib_r(20))
    recursive20 = time.time() - recursive20
    print("running the functions for n=40...")
    iterative40 = time.time()
    print("iterative n=40: ", fib(40))
    iterative40 = time.time() - iterative40
    recursive40 = time.time()
    print("recursive n=40: ", fib_r(40))
    recursive40 = time.time() - recursive40
    print("These are the results:")
    print("|\tn\t|\tfib()\t|\tfib_r()\t|")
    print(f"|\t10\t|\t{iterative10:.5f}s\t|\t{recursive10:.5f}s\t|")
    print(f"|\t20\t|\t{iterative20:.5f}s\t|\t{recursive20:.5f}s\t|")
    print(f"|\t40\t|\t{iterative40:.5f}s\t|\t{recursive40:.5f}s\t|")


