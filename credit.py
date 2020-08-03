from cs50 import get_int

def main():
    digitSum = 0
    leftovers = 0
    product = [] # Will store the needed products
    number = get_int("Number: ") # Prompts user for number
    digits = numberOfDigits(number) # Calculates number of digits
    print(f"Number of digits: {digits}") # Make sure it adds digits correctly
    tempNumber = number # Have to convert to string to get the ith element
    for i in range(digits): # Create list with the digits of the number in it
        product.append(tempNumber % 10)
        tempNumber //= 10
    for j in range(1, digits, 2): # Multiply ever other digit and add them together
        if product[j] * 2 > 9:
            product1 = product[j] * 2 % 10  
            product2 = product[j] *2 // 10
            digitSum += product1 + product2
        else:
            digitSum += product[j] * 2
    for k in range(0, digits, 2): # Add up leftover digits
        leftovers += product[k]
    sumOfAll = digitSum + leftovers
    if sumOfAll % 10 == 0:
        findCard(product[digits - 1], product[digits - 2 ], digits) # Find card company and print
    else:
        print("INVALID")


def findCard(x, y, digits):
    if x == 5 and (y >= 1 and y<= 5) and digits == 16:
        print("MASTERCARD")
    elif x == 3 and (y == 4 or y == 7) and digits ==15:
        print("AMEX")
    elif x == 4 and (digits == 13 or digits == 16):
        print("VISA")
    else:
        print("INVALID")


def numberOfDigits(number):
    tempDigits = 0
    while number != 0: # Count all the digits
        tempDigits += 1 # Add one to the number of digits
        number //= 10 # Take one digit off
    return tempDigits # Return the number of digits

main()
