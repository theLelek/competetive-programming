class player:

    def __init__(self, id: int, score: int):
        self.id = id
        self.score = score


def solve(input: str) -> str:
    input = input.strip()
    lines = input.split('\n')
    best_player = player(-1, -1)
    for game in lines[1:]:
        game_split = game.split(" ")
        player1 = player(int(game_split[0]), int(game_split[1]))
        player2 = player(int(game_split[2]), int(game_split[3]))

        if best_player.score < player1.score:
            best_player = player1
        if best_player.score < player2.score:
            best_player = player2

        if best_player.score == player1.score and player1.id < best_player.id:
            best_player = player1
        if best_player.score == player2.score and player2.id < best_player.id:
            best_player = player2
    return best_player

def main():
    with open("level1(2)/level1_5.in") as f:
        input = f.read()

    best_player = solve(input)
    output = str(best_player.id) + " " + str(best_player.score)


    with open("output.txt", "w") as f:
        f.write(output)

if __name__ == '__main__':
    main()
