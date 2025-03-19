numbers = []

for i in range(4):
    n = int(input("Give a number: "))
    numbers.append(n)

print(f"Max numbers in the array: {max(numbers)}")
print(f"Min numbers in the array: {min(numbers)}")