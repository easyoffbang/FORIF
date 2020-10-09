def solution(citations):
    k = len(citations)
    citations.sort()
    while True:
        for i, value in enumerate(citations):
            if value >= k and len(citations[i:]) >= k:
                return k
        else:
            k -= 1
            continue

        break
