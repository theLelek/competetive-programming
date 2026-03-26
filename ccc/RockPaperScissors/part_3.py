def does_a_win(a, b):
    # a wins
    if a == "S" and (b == "S" or b == "P"):
        return True
    elif a == "P" and (b == "P" or b == "R"):
        return True
    elif a == "R" and (b == "R" or b == "S"):
        return True

    elif a == "S" and b == "R":
        return False
    elif a == "R" and b == "P":
        return False
    elif a == "P" and b == "S":
        return False
    else:
        print("function does_a_win")
        return True

def get_winners_of_tournament(fighting_styles: str, number_of_rounds):
    players = list(range(len(fighting_styles)))
    current_players = players.copy()
    for i in range(number_of_rounds):
        for i in range(0, len(current_players), 2):
            b = does_a_win(fighting_styles[current_players[i]], fighting_styles[current_players[i + 1]])
            if b:
                players[current_players[i + 1]] = None
            else:
                players[current_players[i]] = None
        current_players = [x for x in players if x is not None]

    out = ""
    for player in current_players:
        out += fighting_styles[player]
    return out

def get_fighting_styles(line: str):
    splitted = line.split(" ")
    r_amount = int(splitted[0][:-1])
    p_amount = int(splitted[1][:-1])
    s_amount = int(splitted[2][:-1])
    p_left = p_amount

    fighting_styles = ["R"] * r_amount
    current_index = 0
    while p_left > 0:
        fighting_styles.insert(current_index, "P")
        current_index += 5
        p_left -= 1
    fighting_styles.extend(["S"] * s_amount)
    return fighting_styles


def main(input: str):
    splitted = input.split("\n")
    n = int(splitted[0].split(" ")[0]) # number of tournaments
    m = int(splitted[0].split(" ")[1]) # number of fighters
    out = ""

    for line in splitted[1:]:
        current = get_fighting_styles(line)
        s_current = "".join(current)
        winners = get_winners_of_tournament(s_current, 2)
        if "R" in winners or "S" not in winners:
            print("oh no-------------------")
            print(line)

        out += s_current + "\n"
    return out

if __name__ == '__main__':
    with open("level3(7)/level3_1.in") as f:
        input = f.read().strip()

    output = main(input)
    print(output)
    with open("output.txt", "w") as f:
        f.write(output)


# after 2 round:
#   0 rock
#   min 1 scissor

# you need 1/4 Paper of Rocks
