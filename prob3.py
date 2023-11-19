
for _ in range (int(input())):
    n, m = map(int, input().split())

    starting = list(map(int, input().split()))
    ending = list(map(int, input().split()))

    ls = list(zip(starting, ending))

    mx = float("-inf")
    for s, e in ls:

        val = e - s 

        if val < 0:
            val = (m-s)+e

        mx = max(val, mx)

    print(mx)