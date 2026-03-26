from operator import attrgetter


class player:

    def __init__(self, id: int, wins: int = 0):
        self.id = id
        self.wins = wins



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

        if player_1_score > player_2_score:
            players[player_1.id].wins += 1
        else:
            players[player_2.id].wins += 1


    players.sort(key=attrgetter("wins"), reverse=True)

    return players



def main():
    with open("level2(2)/level2_5.in") as f:
        input = f.read()

        players = solve(input)
        output = ""
        for player in players:
            output += str(player.id) + " " + str(player.wins) + "\n"


    with open("output.txt", "w") as f:
        f.write(output.strip())

if __name__ == '__main__':
    main()
