def merge_sort(enum):
    if len(enum) <= 1:
        return enum

    mid = len(enum) // 2
    left = merge_sort(enum[:mid])
    right = merge_sort(enum[mid:])

    merged = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i][1] <= right[j][1]:
            merged.append(left[i])
            i += 1
        else:
            count[left[i][0]] += len(right) - j
            merged.append(left[i])
            i += 1

    merged.extend(left[i:])
    merged.extend(right[j:])
    return sorted(merged, key=lambda x: x[1])

n = int(input())
arr = list(map(int, input().split()))

count = [0] * n
enum = list(enumerate(arr))

merge_sort(enum)

print(*count)