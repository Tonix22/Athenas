# Set para que la busqueda sea 0(1)
def subArraySumk(nums,k):
    subSum = []
    result = 0
    #suma parcial del array
    for x in nums:
        pos = len(subSum)
        if pos != 0:
            subSum.append(x+subSum[pos-1])
        elif pos == 0:
            subSum.append(x)
    print(subSum)
    
    for i in range(len(subSum)):
        if i == 0 :
            if subSum[i]==k:
                result += 1
        else:
            value = subSum[i]-k
            print(f"value = {value}")
            if subSum[i] == k:
                result += 1
            if value in subSum[0:i]:
                result += 1
    return result

nums = [1,-1,0] 
k = 0
print(subArraySumk(nums,k))

#[1,2,3], k = 3
#7,9,10,11,25,5 k = 30 , respuesta es 2 