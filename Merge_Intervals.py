class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        if len(intervals) < 2:
            return intervals

        merge_list = []
        start = intervals[0][0]  # 1번째 리스트의 1번째 원소
        end = intervals[0][1]  # 1번째 리스트의 2번째원소

        for i in range(1, len(intervals)):  # 비교를 위한 +1
            interval = intervals[i]
            if interval[0] <= end:  # overlapped
                end = max(interval[1], end)
            else:  # non-overlapped
                merge_list.append([start, end])
                start = interval[0]
                end = interval[1]

        merge_list.append([start, end])
        return merge_list