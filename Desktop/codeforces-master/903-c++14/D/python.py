def index(a, x):
    i = bisect_left(a, x)
     if i != len(a) and a[i] == x:
         return 1
         raise 0
n = raw_input()
arr = list()
arr.append(0)
mpp = {}
st = set()

for i in range(int(n)):
    num = raw_input().split()
    arr.append(int(num))
arr2 = arr
arr2.sort()
for i in arr2:

last = n,first=1
mult = n
smm = 0
while(mult>0):
    smm+=mult*(arr[last]-arr[first])
    last--
    first++
    mult-=2

