
import heapq


#[시작노드, 끝노드, 가중치]
A = [[1, 2, 4],
[1, 8, 8],
[4, 5, 9],
[4, 6, 14],
[5, 6, 10],
[2, 3, 8],
[2, 8, 11],
[3, 4, 7],
[3, 6, 4],
[3, 9, 2],
[4, 5, 9]]

heapq.heapify(A)

heap = [1,2,7,3,4]
print(heapq.heappop(heap))
print(heapq.heappop(heap))
print(heapq.heappop(heap))
print(heapq.heappop(heap))
print(heapq.heappop(heap))




