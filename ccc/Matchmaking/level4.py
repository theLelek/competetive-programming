from operator import attrgetter
import math
from dataclasses import dataclass


class player:

    def __init__(self, id: int, rating: int = 1000):
        self.id = id
        self.rating = rating

def solve(input: str) -> str:
    input = input.strip()
    lines = input.split('\n')

    players = [None] * int(lines[0].split(" ")[1])
    for game in lines[1:]:
        game_split = game.split(" ")
        player_1 = player(int(game_split[0]))
        player_1_score = int(game_split[1])
        player_2 = player(int(game_split[2]))
        player_2_score = int(game_split[3])

        if players[player_1.id] is None:
            players[player_1.id] = player_1
        if players[player_2.id] is None:
            players[player_2.id] = player_2


        K = 32

        # compute expectation
        player1_chance_of_winning = 1 / (1 + 10 ** ((players[player_2.id].rating - players[player_1.id].rating) / 400))
        player2_chance_of_winning = 1 / (1 + 10 ** ((players[player_1.id].rating - players[player_2.id].rating) / 400))

        # determine S values (1 win, 0 loss, 0.5 draw)
        if player_1_score > player_2_score:
            s1, s2 = 1.0, 0.0
        elif player_1_score < player_2_score:
            s1, s2 = 0.0, 1.0
        else:
            s1 = s2 = 0.5

        # compute new ratings and FLOOR the result
        players[player_1.id].rating = math.floor(players[player_1.id].rating + K * (s1 - player1_chance_of_winning))
        players[player_2.id].rating = math.floor(players[player_2.id].rating + K * (s2 - player2_chance_of_winning))
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
    with open("level4(1)/level4_5.in") as f:
        input = f.read()

        players = solve(input)
        output = ""
        for player in players:
            output += str(player.id) + " " + str(player.rating) + "\n"


    with open("output.txt", "w") as f:
        f.write(output.strip())

if __name__ == '__main__':
    main()
