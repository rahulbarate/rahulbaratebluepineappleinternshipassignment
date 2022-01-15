try:
    numstr = input("Enter Number : ")
    num = int(numstr)
    num = abs(num)
    count = 0
    if num == 0:
        print("count is ",len(numstr))
        # print("count is 1")
        exit(0)
    
    while num!=0:
        num = int(num/10)
        count += 1
    
    print("count is : ",count)
except ValueError:
    print("Please enter Integer value")

# Another Approach
# num = int(input("no : "))
# num = str(num)
# print(len(num))

