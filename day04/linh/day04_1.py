def count_xmas(s: str) -> int:
    if len(s) < 4:
        return 0
    count = 0
    for i in range(len(s) - 3):
        ss = s[i:i+4]
        if ss == 'XMAS' or ss == 'SAMX':
            count += 1
            # print(s)
    return count


if __name__ == "__main__":
    table = []
    with open("../input", "r") as f:
        for row in f:
            table.append(row.strip())

    n, result = len(table), 0

    # left <-> right
    for lr in table:
        result += count_xmas(lr)
    print(result)

    # top <-> down
    j = 0
    while j < n:
        s = []
        for i in range(n):
            s.append(table[i][j])
        result += count_xmas("".join(s))
        j += 1
    print(result)

    # left-right diagonal
    i, j = n - 1, 0
    while i >= 0 and j < n:
        s = []
        x, y = i, j
        while x < n and y < n:
            s.append(table[x][y])
            x += 1
            y += 1
        result += count_xmas("".join(s))
        i -= 1
        if i == -1:
            j += 1
            i = 0
    print(result)

    # right-left diagonal
    i, j = 0, 0
    while i < n and j < n:
        s = []
        x, y = i, j
        while x < n and y >= 0:
            s.append(table[x][y])
            x += 1
            y -= 1
        result += count_xmas("".join(s))
        j += 1
        if j == n:
            i += 1
            j = n - 1
    print(result)
