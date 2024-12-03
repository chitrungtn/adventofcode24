import re

if __name__ == "__main__":
    with open("../input", "r") as f:
        txt = f.read()
        x = re.findall(r"mul\((\d{1,3}),(\d{1,3})\)", txt)
        result = 0
        for p in x:
            a, b = p
            result += int(a) * int(b)
        print(result)
