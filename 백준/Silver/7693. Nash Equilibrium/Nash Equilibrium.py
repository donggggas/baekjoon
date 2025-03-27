def find_nash_equilibria(PA, PB):
    m = len(PA)
    n = len(PB[0])
    equilibria = []

    for i in range(m):
        for j in range(n):
            # Check if (ai, bj) is a best response for A
            best_response_A = True
            for i_prime in range(m):
                if PA[i_prime][j] > PA[i][j]:
                    best_response_A = False
                    break

            # Check if (ai, bj) is a best response for B
            best_response_B = True
            for j_prime in range(n):
                if PB[i][j_prime] > PB[i][j]:
                    best_response_B = False
                    break

            if best_response_A and best_response_B:
                equilibria.append((i + 1, j + 1))  # Store as 1-indexed

    return equilibria


def main():
    import sys
    input = sys.stdin.read
    data = input().strip().splitlines()

    index = 0
    results = []
    
    while index < len(data):
        # Read m and n
        m, n = map(int, data[index].split())
        if m == 0 and n == 0:
            break
        index += 1
        
        # Read PA matrix
        PA = []
        for _ in range(m):
            row = list(map(int, data[index].split()))
            PA.append(row)
            index += 1
            
        # Read PB matrix
        PB = []
        for _ in range(m):
            row = list(map(int, data[index].split()))
            PB.append(row)
            index += 1
            
        # Find Nash equilibria
        equilibria = find_nash_equilibria(PA, PB)
        results.append(f"{len(equilibria)}")
        for eq in equilibria:
            results.append(f"{eq[0]} {eq[1]}")

    # Print all results
    print("\n".join(results))


if __name__ == "__main__":
    main()
