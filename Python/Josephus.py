n, m = map(int, input().split())

lst = [x for x in range(1, n + 1)]

index = m

while len(lst) != 0:
    if index == 1:
        print(lst[0], end=" ")
        index = m
    else:
        lst.append(lst[0])
        index -= 1
    del lst[0]