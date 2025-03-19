def IsInMultiplicationTable(n):
    if n < 10:
        return 1
    for i in range(2, 10):
        if n % i == 0 and n // i <= 9:
            return 1
    return 0
    
n = int(input())
print(IsInMultiplicationTable(n))