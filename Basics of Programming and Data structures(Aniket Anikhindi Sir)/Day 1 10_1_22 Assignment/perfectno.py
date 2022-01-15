list1 = list()
def isPerfect(no):
    sum = 0
    end = int(no/2)
    for i in range(1,end+1):
        if no%i==0:
            sum +=i

    if sum==no:
        list1.append(no)
try:
    num = int(input("Enter value of n : "))
    if num <= 0:
        print("Please Enter value greater than zero")
        exit(0)
    if num<6:
        print("No perfect numbers found")
        exit(0)
    
    for i in range(1,num+1):
        isPerfect(i)
    
    print("List of perfect numbers : ")
    print(list1)

except ValueError:
    print("Please enter Integer value")