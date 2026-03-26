from pydoc import describe


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

def main(input: str):
    splitted = input.split("\n")
    n = int(splitted[0].split(" ")[0]) # number of tournaments
    m = int(splitted[0].split(" ")[1]) # number of fighters
    out = ""

    for line in splitted[1:]:
        out += get_winners_of_tournament(line, 2) + "\n"


    return out

if __name__ == '__main__':
    with open("level2(4)/level2_example.in") as f:
        input = f.read().strip()

    output = main(input)
    print(output)
    with open("output.txt", "w") as f:
        f.write(output)
