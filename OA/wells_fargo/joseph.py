def findLastPerson(n,k):
    arr=list()
    for i in range(n):
        arr.append(i)
    index=0
    # arr.pop(index)
    while len(arr)!=1:
        index=(index+k-1)%len(arr)
        arr.pop(index)
    return arr[0]
n=int(input())
k=int(input())
print(findLastPerson(n,k))