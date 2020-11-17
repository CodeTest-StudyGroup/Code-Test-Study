d, k = map(int, input().split())
A = [0 for _ in range(d)]
B = [0 for _ in range(d)]
A[0] = B[1] = 1
for i in range(2, d):
    A[i] = A[i-2] + A[i-1]
    B[i] = B[i-2] + B[i-1]
a, b = 0, 0
for a in range(1, k // A[d-1]):
    if (k - a * A[d-1]) % B[d-1] == 0:
        b = (k - a * A[d-1]) // B[d-1]
        break
print(a, b, sep='\n')
