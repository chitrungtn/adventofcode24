import re

if __name__ == "__main__":
    with open("../input", "r") as f:
        txt = f.read()
        x = re.findall(r"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))", txt)
        mul = []
        enable = True
        for p in x:
            if p[0] == "don't()":
                enable = False
            elif p[0] == "do()":
                enable = True
            else:
                if enable:
                    mul.append(p)
        result = 0
        for m in mul:
            _, a, b = m
            result += int(a) * int(b)
        print(result)
