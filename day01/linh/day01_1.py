import heapq

first, second = [], []
with open("day01/input.txt", "r") as f:
    for line in f:
        [a, b] = line.split()
        first.append(int(a))
        second.append(int(b))

heapq.heapify(first)
heapq.heapify(second)
result = 0
while len(first) > 0:
    a, b = heapq.heappop(first), heapq.heappop(second)
    result += abs(a - b)
print(result)
