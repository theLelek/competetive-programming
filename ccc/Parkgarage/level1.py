def solve(input: str):
    data = list(map(int, input.split()))
    if not data:
        return ""
    # erste beiden Zahlen: N, M
    N, M = data[0], data[1]
    seq = data[2:]
    # Falls mehr/weniger gelesen wurde, stellen wir sicher, dass wir nur 2*M Werte nutzen
    seq = seq[:2 * M]

    present = set()
    max_present = 0

    for x in seq:
        if x > 0:
            present.add(x)
            if len(present) > max_present:
                max_present = len(present)
        else:
            # Abfahrt: entferne das Ticket (Vorbedingung: Ankunft war vorher)
            ticket = -x
            if ticket in present:
                present.remove(ticket)
            # else: aus Aufgabenbeschreibung sollte das nicht vorkommen

    return str(max_present) + "\n"


def main():
    with open("level1/input.3", "r", encoding="UTF-8") as input_file:
        string_input = input_file.read().strip()

    output = solve(string_input)

    with open("output.txt", "w", encoding="UTF-8") as output_file:
        output_file.write(output)


if __name__ == '__main__':
    main()
