import heapq


def solution(scoville, K):
    heapq.heapify(scoville)
    answer = 0
    while K > scoville[0]:
        if len(scoville) < 2:
            return -1
        new_num = heapq.heappop(scoville) + (heapq.heappop(scoville) * 2)
        heapq.heappush(scoville, new_num)
        answer += 1

    return answer