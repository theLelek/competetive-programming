def solve(input: str):
    data = list(map(int, input.split()))
    if not data:
        return ""
    N, M = data[0], data[1]
    prices = data[2:2 + N]
    weights = data[2 + N: 2 + N + M]
    seq = data[2 + N + M: 2 + N + M + 2 * M]  # genau 2*M Ereignisse

    import heapq

    # Min-Heap der freien Parkplätze (1-basierte Nummerierung)
    free_spots = list(range(1, N + 1))
    heapq.heapify(free_spots)

    parked = {}     # car_id -> spot_number
    queue = []      # Liste als Warteschlange (append-only)
    head = 0        # Index des ersten noch nicht verarbeiteten Elements in queue
    in_queue = [False] * (M + 1)  # in_queue[i] == True, wenn Auto i aktuell in der Warteschlange ist

    revenue = 0

    for x in seq:
        if x > 0:
            # Ankunft
            car = x
            if free_spots:
                spot = heapq.heappop(free_spots)
                parked[car] = spot
            else:
                queue.append(car)
                in_queue[car] = True
        else:
            # Abfahrt
            car = -x
            if car in parked:
                # Auto verlässt geparkten Zustand -> berechnen und Parkplatz freigeben
                spot = parked.pop(car)
                units = (weights[car - 1] + 99) // 100
                revenue += prices[spot - 1] * units
                heapq.heappush(free_spots, spot)

                # Ein wartendes Auto (falls vorhanden) nimmt nun den kleinsten freien Platz
                # Vorher ungültige (bereits entfernte) Einträge überspringen
                while head < len(queue) and not in_queue[queue[head]]:
                    head += 1
                if head < len(queue):
                    next_car = queue[head]
                    head += 1
                    in_queue[next_car] = False
                    assign_spot = heapq.heappop(free_spots)
                    parked[next_car] = assign_spot
            elif 1 <= car <= M and in_queue[car]:
                # Auto verlässt die Warteschlange bevor es geparkt wurde -> zahlt nichts
                in_queue[car] = False
            else:
                # Inkonsistentes/irrelevantes Ereignis (z.B. doppelte Abfahrt) -> ignorieren
                pass

        # gelegentlich Speicher säubern (head kann wachsen)
        if head > 1000:
            queue = queue[head:]
            head = 0

    return str(revenue) + "\n"


def main():
    with open("level5/input.5", "r", encoding="UTF-8") as input_file:
        string_input = input_file.read().strip()

    output = solve(string_input)

    print(output)
    with open("output.txt", "w", encoding="UTF-8") as output_file:
        output_file.write(output)


if __name__ == '__main__':
    main()
