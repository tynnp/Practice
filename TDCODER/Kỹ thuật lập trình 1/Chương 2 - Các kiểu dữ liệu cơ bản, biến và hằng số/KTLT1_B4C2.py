def swap(a, b):
    return b, a
    
a = int(input())
b = int(input())

a, b = swap(a, b)
print(a, b, sep='\n')