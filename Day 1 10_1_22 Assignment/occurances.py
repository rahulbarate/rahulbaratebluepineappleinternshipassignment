occurances = [0]*10
def countOccurances(num):
    while num!=0:
        rem = int(num%10)
        num = int(num/10)
        occurances[rem] +=1
try:
    numstr = input("Enter Number : ")
    num = int(numstr)
    num = abs(num)
    if num == 0:
        print("Occurances of 0 : ",len(numstr))
        exit(0)

    countOccurances(num)
    
    for i in range(0,10):
        print("Occurance of {} : {}".format(i,occurances[i]))

except ValueError:
    print("Please enter Integer value")