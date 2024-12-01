from collections import defaultdict

first, second = [], defaultdict(int)
with open("day01/input.txt", "r") as f:
    for line in f:
        [a, b] = line.split()
        first.append(int(a))
        second[b] += 1

result = 0
for i in range(len(first)):
    result += abs(first[i] * second[str(first[i])])
print(result)
