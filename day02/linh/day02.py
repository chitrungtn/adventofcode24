def delta_calc(r: list) -> dict:
    m = {"pos": 0, "neg": 0, "zer": 0, "gt3": 0}
    for i in range(1, len(r)):
        d = r[i] - r[i - 1]
        if 0 < d <= 3:
            m["pos"] += 1
        elif -3 <= d < 0:
            m["neg"] += 1
        elif d == 0:
            m["zer"] += 1
        else:
            m["gt3"] += 1
    return m


def safer_part1(deltas: dict) -> bool:
    if deltas["zer"] + deltas["gt3"] > 0 or deltas["neg"] * deltas["pos"] != 0:
        return False
    return True


if __name__ == "__main__":
    safe_counter = 0

    with open("../input_sample.txt", "r") as f:
        for row in f:
            report = [int(level) for level in row.split()]
            delta = delta_calc(report)
            print(report)
            if safer_part1(delta):
                safe_counter += 1
                print("---> True")
            else:
                print("---> False")

    print(safe_counter)
