def findDuplicate(self, nums):
    nums.sort()
    for i in range(1, len(nums)):
        if nums[i] == nums[i-1]:
            return nums[i]
t=int(input())
while t>0:
    n=int(input())
    l=[]
    while(n>0):
        i=int(input())
        l.append(i)
        n=n-1
    print(findDuplicate(l))    
    t=t-1