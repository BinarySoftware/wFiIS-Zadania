#!/usr/bin/env python3
import copy


def main():
    """
    Program entry point.
    """
    k = [1,2.3, '4', (5,6), [7,8,9]]
    c = k
    c[1] = [4,2,0]
    print(c,k)
    print(id(c), id(k))
        
    print() 

    c = k[:]
    c[1] = [6,5,4]
    c[4][1] = 0
    print(c,k)
    print(id(c), id(k))

    print()

    cp = copy.deepcopy(k)
    c[4][1] = 2
    print("cp: " + str(cp))
    print("k: " + str(k))
    print(id(cp),id(k))

    print()
            
    l = [1, 1, 2 ,3 ,3, 4 ,4 ,4]
        
    print(l.count(4))
    print(l.count(-4))
        
    print(l.index(4))
    try:
        print(l.index(-4))
    except:
        print("does not exist")
    finally:
        print("foo")
        
    print(4 in l)
    print(4 not in l)
        
    if 4 in l:
        print(l.index(4))

    if 14 not in l:
        print("Nonexistent.")

    print()
        
    l.insert(-23, 4)
    l.insert(23, 4)
    print(l)
    l.remove(4) # pierwsze wyst.
    # l.remove(-4) #ValueError
    print(l)
    del l[4] # po indeksie
    print(l)
    print(l.pop(1))
    print(l)
    l.insert(23, 6)
    print(l)
    print(l.pop())
    print(l)
    l[0:3] = [0,0,0,0,0,0]
    print(l)
    l[0:5] = [[0,0,],]
    print(l)
    l[0:999] = [0]
    print(l)
    del l[:]
    print(l)

    print()

    a = 2
    b = 3 
    print(a, b)
    a, b = b, a
    print(a, b)

    # Lista składana
    k = [[] for i in range(10)]
    k[3].append(1)
    k[5] = [4,2]
    print(k)

    c = [8, 0 , 3, 4, 6, 7, 6,5]
    print()
    print(c)
    for i in range(len(c)):
        c[i] *= 2
    print(c)

    for i, v in enumerate(c):
        c[i] = 1 if v > 10 else 0
    print(c)

    for i in c:
        if i > 2: #jesli sie spelni to else sie nie wykona
            break
    else: 
        print("foo")

    print()

    c = [8, 0 , 3, 4, 6, 7, 6,5]
    print(c)
    np = [i for i in c if i%2]
    print(np)
    np = [i if i > 5 else -1 for i in c]
    print(np)

    k = [(c[i], c[-i-1]) for i in range(len(c)//2)]
    print(k)

    print()

    k = [(89,34), (92,31), (96,0), (48,30),(38,10)]
    c = k[:]
    print(c)
    c.sort() # c.sort(reverse=True)
    print(c)

    print()

    c = k[:]
    print(c)
    c.sort(key = lambda x: x[0] + x[1])
    print(c)
    m = sorted(c)
    print(c)
    print(m)
    c.reverse()
    print(c)

    # Zadanie 1
    print()
    k = [1,2,2,2,2,2,3,4,5,6,6,6,6,6,7]
    print(k)
    # k = [i for i in k if i!=6]
    # k[:] = (i for i in k if i != 6)
    for i in range(k.count(6)):
        k.remove(6)
    print(k)

    # Zadanie 2
    while 2 in k: k.remove(2)
    print(k)

    # Zadanie 3
    k = [1,2,2,2,2,2,3,4,5,6,6,6,6,6,7]
    print()
    for i in range(1, len(k), 2):
        print(k[i])
    print()

    # Zadanie 4
    for i, v in enumerate(k):
        if i%2:
            print(v)
    print()

    # Zadanie 5
    for i in range(len(k)-2, 0, -2):
        print(k[i])
    print()

    # Zadanie 6
    for i, v in enumerate(reversed(k)):
        if i%2:
            print(v)
    print()

    # Zadanie 7
    k = [(i, k[i]) for i in range(len(k))]
    print(k)
    print()

    # Zadanie 8
    k.sort(key = lambda x: x[1])
    print(k)
    print()

    # Zadanie 9
    k = [1,2,2,2,3,3,3,4,5,5,6,6,6,6,7]
    k = [(i, k[i]) for i in range(len(k)) if k[i]%2==0]
    print(k)
    print()

    # Zadanie 10
    k = [1,2,2,3,3,3,4,5,5,6,6,6,6,7]
    k = [(i, k[i]) if i < k[i] else (k[i], i)  for i in range(len(k))]
    print(k)
    print()


if __name__ == "__main__":
    main()