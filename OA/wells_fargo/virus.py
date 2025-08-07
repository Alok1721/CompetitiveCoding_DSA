#  A company system is attacked by a virus. The system has N running applications, each having a unique ID 0 to N-1. John has made an antivirus to detect the virus application in the system. John's antivirus works on an algorithm. The algorithm finds the group value of the applications by dividing the sum of the IDs of all the applications by two. The ID of the application which is nearest to the group value is then marked as scanned and is removed from the list. The process then continues with the remaining applications until only one application is left. That remaining application is detected as a virus. The antivirus will then remove the file with a virus.Write an algorithm for John to find the ID of the file with a virus in the system.
#  Example
# Input:  
# 4
#  1 3 5 7
# Output: 5
# Input:  
# 4
# 1 2 3 4
#Output: 5


def findVirus(n,arr):
    while len(arr)!=1:
        sum=0
        for i in range(len(arr)):
            sum+=arr[i]
        groupValue=sum//2
        nearestIndex=0
        for i in range(len(arr)):
            if abs(arr[i]-groupValue)-abs(arr[nearestIndex]-groupValue)<0:
                nearestIndex=i
        arr.pop(nearestIndex)
    return arr[0]

n=int(input())
arr=list(map(int,input().split()))
print(findVirus(n,arr))
