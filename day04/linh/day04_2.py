def mas(s: str) -> bool:
    if s == 'MAS' or s == 'SAM':
        return True
    return False


def xshape(x: list) -> bool:
    diag_x = [x[0][0], x[1][1], x[2][2]]
    diag_y = [x[0][2], x[1][1], x[2][0]]
    if mas("".join(diag_y)) and mas("".join(diag_x)):
        return True
    return False


if __name__ == "__main__":
    table = []
    with open("../input", "r") as f:
        for row in f:
            table.append(row.strip())

    i, j, n, result = 0, 0, len(table), 0
    while i < n - 2:
        j = 0
        while j < n - 2:
            shape = [table[i][j:j+3], table[i+1][j:j+3], table[i+2][j:j+3]]
            if xshape(shape):
                result += 1
            j += 1
        i += 1
    print(result)
