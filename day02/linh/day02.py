def delta_calc(r: list) -> list:
    dd = []
    for i in range(len(r)-1):
        dd.append(r[i+1] - r[i])
    return dd


def safer_part1(r: list) -> (bool, int):
    if len(r) <= 2:
        return True, -1

    deltas = delta_calc(r)
    if deltas[0] == 0 or abs(deltas[0]) > 3 or deltas[0] * deltas[1] < 0:
        return False, 0

    for i in range(1, len(deltas)):
        if abs(deltas[i]) > 3 or abs(deltas[i-1]) > 3 or deltas[i-1] * deltas[i] <= 0:
            return False, i

    return True, -1


def safer_part2(r: list) -> bool:
    is_safe, pos = safer_part1(r)

    if is_safe:
        return True

    r1 = r[:pos] + r[pos+1:]
    r2 = r[:pos+1] + r[pos+2:]
    return safer_part1(r1)[0] or safer_part1(r2)[0]


if __name__ == "__main__":
    j = 0
    with open("../input", "r") as f:
        for row in f:
            report = [int(level) for level in row.split()]
            if safer_part2(report):
                j += 1
    print(j)
