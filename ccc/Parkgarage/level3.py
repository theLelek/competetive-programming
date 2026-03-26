def solve(input: str):
    data = list(map(int, input.split()))
    if not data:
        return ""
    N, M = data[0], data[1]
    prices = data[2:2 + N]
    seq = data[2 + N: 2 + N + 2 * M]  # genau 2*M Ereignisse

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
                # Auto zahlt beim Verlassen den Preis dieses Parkplatzes
                revenue += prices[spot - 1]
                # Parkplatz wieder frei machen
                heapq.heappush(free_spots, spot)
                # Wenn Warteschlange vorhanden: erstes Auto parkt sofort
                if head < len(queue):
                    next_car = queue[head]
                    head += 1
                    # Der wartende nimmt nun den aktuell niedrigsten freien Platz
                    assign_spot = heapq.heappop(free_spots)
                    parked[next_car] = assign_spot
            else:
                # Sollte nach Aufgabenbeschreibung nicht vorkommen;
                # falls doch, ignorieren wir das inkonsistente Ereignis.
                pass

        # gelegentlich Speicher säubern (head kann wachsen)
        if head > 1000:
            queue = queue[head:]
            head = 0

    return str(revenue) + "\n"


def main():
    with open("level3/input.4", "r", encoding="UTF-8") as input_file:
        string_input = input_file.read().strip()

    output = solve(string_input)

    with open("output.txt", "w", encoding="UTF-8") as output_file:
        output_file.write(output)


if __name__ == '__main__':
    main()
