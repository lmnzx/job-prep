with open("../inputs/day2.txt") as f:
    inputs = f.read().splitlines()


def part1(inputs):
    score = 0
    for input in inputs:
        if (
            (input[0] == "A" and input[1] == "X")
            or (input[0] == "B" and input[1] == "Y")
            or (input[0] == "C" and input[1] == "Z")
        ):
            match input[1]:
                case "X":
                    score += 1 + 3
                    continue
                case "Y":
                    score += 2 + 3
                    continue
                case "Z":
                    score += 3 + 3
                    continue
        if input[0] == "A" and input[1] == "Y":
            score += 6 + 2
            continue
        if input[0] == "B" and input[1] == "Z":
            score += 6 + 3
            continue
        if input[0] == "C" and input[1] == "X":
            score += 6 + 1
            continue

        match input[1]:
            case "X":
                score += 1
            case "Y":
                score += 2
            case "Z":
                score += 3

    return score

def part2(inputs):
    scores = 0
    for input in inputs:
        if input[1] == 'X':
            match input[0]:
                case 'A':
                    scores += 3
                case 'B':
                    scores += 1
                case 'C':
                    scores += 2 
        if input[1] == 'Y':
            match input[0]:
                case 'A':
                    scores += 1 + 3
                case 'B':
                    scores += 2 + 3
                case 'C':
                    scores += 3 + 3 
        if input[1] == 'Z':
            match input[0]:
                case 'A':
                    scores += 2 + 6
                case 'B':
                    scores += 3 + 6
                case 'C':
                    scores += 1 + 6 

    return scores

inputs = [i.split(" ") for i in inputs]
print(part1(inputs))
print(part2(inputs))
