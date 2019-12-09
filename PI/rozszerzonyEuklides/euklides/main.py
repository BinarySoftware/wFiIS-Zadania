import math


def rozNWD(j, k):
    if j < 0 or j > k:
        return None
    if j == 0:
        return (k, 1, 0)
    r = k % j
    (d, xp, yp) = rozNWD(r, j)
    x = yp - math.floor(k / j) * xp
    y = xp
    return (d, x, y)


def main():
    a = rozNWD(5,7)
    print(a)


if __name__ == "__main__":
    main()
