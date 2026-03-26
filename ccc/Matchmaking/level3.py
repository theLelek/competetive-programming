from operator import attrgetter
from dataclasses import dataclass


class player:

    def __init__(self, id: int, points: int = 0):
        self.id = id
        self.points = points



def solve(input: str) -> str:
    input = input.strip()
    lines = input.split('\n')
    win_increment = int(lines[0].split(" ")[0])
    loss_decrement = int(lines[0].split(" ")[1])

    players = [None] * int(lines[1].split(" ")[1])
    for game in lines[2:]:
        game_split = game.split(" ")
        player_1 = player(int(game_split[0]))
        player_1_score = int(game_split[1])
        player_2 = player(int(game_split[2]))
        player_2_score = int(game_split[3])

        if players[player_1.id] is None:
            players[player_1.id] = player_1
        if players[player_2.id] is None:
            players[player_2.id] = player_2

        if player_1_score > player_2_score:
            players[player_1.id].points += win_increment
            players[player_2.id].points -= loss_decrement
        else:
            players[player_2.id].points += win_increment
            players[player_1.id].points -= loss_decrement


    players = bubble_sort_by_points_then_id(players)
    return players

def bubble_sort_by_points_then_id(players):
    n = len(players)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            a = players[j]
            b = players[j + 1]
                # swap if a should come after b
            if (a.rating < b.rating) or (a.rating == b.rating and a.id > b.id):
                players[j], players[j + 1] = b, a
                swapped = True
        if not swapped:
            break
        # do not return (mimic list.sort())
    return players

def main():
    with open("level3(4)/level3_5.in") as f:
        input = f.read()

        players = solve(input)
        output = ""
        for player in players:
            output += str(player.id) + " " + str(player.points) + "\n"


    with open("output.txt", "w") as f:
        f.write(output.strip())

if __name__ == '__main__':
    main()
