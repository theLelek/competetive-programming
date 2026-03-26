def solve(input: str):
    data = list(map(int, input.split()))
    if not data:
        return ""
    N, M = data[0], data[1]
    seq = data[2:2 + 2 * M]  # genau 2*M Werte

    parked = set()
    queue = []    # Liste als Warteschlange
    head = 0      # Index auf das erste Element in der Warteschlange
    max_parked = 0
    max_queue = 0

    for x in seq:
        if x > 0:
            # Ankunft
            if len(parked) < N:
                parked.add(x)
                if len(parked) > max_parked:
                    max_parked = len(parked)
            else:
                queue.append(x)
                current_queue_len = len(queue) - head
                if current_queue_len > max_queue:
                    max_queue = current_queue_len
        else:
            # Abfahrt
            ticket = -x
            if ticket in parked:
                parked.remove(ticket)
            # Wenn Warteschlange vorhanden, erstes Auto parkt sofort
            if head < len(queue):
                next_car = queue[head]
                head += 1
                parked.add(next_car)
                if len(parked) > max_parked:
                    max_parked = len(parked)
            # gelegentlich Speicher säubern, falls head groß wird
            if head > 1000:
                queue = queue[head:]
                head = 0

    return f"{max_parked} {max_queue}\n"


def main():
    with open("level2/input.5", "r", encoding="UTF-8") as input_file:
        string_input = input_file.read().strip()

    output = solve(string_input)

    with open("output.txt", "w", encoding="UTF-8") as output_file:
        output_file.write(output)


if __name__ == '__main__':
    main()
