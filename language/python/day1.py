with open("../inputs/day1.txt") as f:
    input = f.read().split("\n\n")
    input = [sum(map(int, i.splitlines())) for i in input]
    input.sort(reverse=True)
    print(input[0])
    print(input[0] + input[1] + input[2])
