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

    parked = {}   # car_id -> spot_number
    queue = []    # Liste als Warteschlange
    head = 0

    revenue = 0

    for x in seq:
        if x > 0:
            # Ankunft
            if free_spots:
                spot = heapq.heappop(free_spots)
                parked[x] = spot
            else:
                queue.append(x)
        else:
            # Abfahrt
            car = -x
            if car in parked:
                spot = parked.pop(car)
                # Berechne Anzahl 100kg-Einheiten (aufgerundet)
                w = weights[car - 1]
                units = (w + 99) // 100
                revenue += prices[spot - 1] * units
                # Parkplatz wieder frei machen
                heapq.heappush(free_spots, spot)
                # Wenn Warteschlange vorhanden: erstes Auto parkt sofort
                if head < len(queue):
                    next_car = queue[head]
                    head += 1
                    assign_spot = heapq.heappop(free_spots)
                    parked[next_car] = assign_spot
            else:
                # Inkonsistentes Ereignis (soll laut Aufgabenstellung nicht vorkommen) -> ignorieren
                pass

        # gelegentlich Speicher säubern (head kann wachsen)
        if head > 1000:
            queue = queue[head:]
            head = 0

    return str(revenue) + "\n"


def main():
    with open("level4/input.3", "r", encoding="UTF-8") as input_file:
        string_input = input_file.read().strip()

    output = solve(string_input)

    print(output)

    with open("output.txt", "w", encoding="UTF-8") as output_file:
        output_file.write(output)


if __name__ == '__main__':
    main()
