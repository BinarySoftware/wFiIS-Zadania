

# Rekurencyjne przeszukiwanie binarne.
# Uwaga: może dojść do przekroczenia maksymalnej głębokości
# rekurencyjnej w przypadku zbyt dużej tablicy wejściowej
# gdyż python nie został zoptymalizowany pod kątem rekurencji
# Uwaga: Tablica musi być posortowana od najmniejszego do
# największego elementu
def binarySearchRec(A, x):
    mid = int(abs(len(A) / 2))
    if A[mid] == x:
        return mid
    elif A[mid] < x:
        return mid + binarySearchRec(A[mid:len(A)], x)
    elif A[mid] > x:
        return binarySearchRec(A[0:mid], x)


# Przeszukiwanie binarne z pętlą while
def binarySearchWhile(A, x):
    l = 0
    r = len(A) - 1
    while l <= r:
        mid = int(l + (r - l) / 2)
        if A[mid] == x:
            return mid
        elif A[mid] < x:
            l = mid + 1
        else:
            r = mid - 1
    return -1


# Przeszukiwanie liniowe - najwolniejsze, najprostsze
def linearSearch(A, x):
    for i in range(len(A)):
        if A[i] == x:
            return i
    return -1


def main():
    list = [0,4,6,8,12,29,45,376,876,972,1080,2070,4060,435345]

    print(binarySearchRec(list, 376))
    print(binarySearchWhile(list, 376))
    print(linearSearch(list, 376))

if __name__ == "__main__":
    main()