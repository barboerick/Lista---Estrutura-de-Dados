import time
import random
import bisect
import math

def binary_search(arr, x):
    l, r = 0, len(arr) - 1
    while l <= r:
        mid = l + (r - l) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            l = mid + 1
        else:
            r = mid - 1
    return -1

def interpolation_search(arr, x):
    low, high = 0, len(arr) - 1
    while low <= high and x >= arr[low] and x <= arr[high]:
        if low == high:
            if arr[low] == x:
                return low
            return -1
        pos = low + int(((float(high - low) / (arr[high] - arr[low])) * (x - arr[low])))
        if arr[pos] == x:
            return pos
        if arr[pos] < x:
            low = pos + 1
        else:
            high = pos - 1
    return -1

def jump_search(arr, x):
    n = len(arr)
    step = int(math.sqrt(n))
    prev = 0
    while arr[min(step, n) - 1] < x:
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1
    while arr[prev] < x:
        prev += 1
        if prev == min(step, n):
            return -1
    if arr[prev] == x:
        return prev
    return -1

def exponential_search(arr, x):
    if arr[0] == x:
        return 0
    i = 1
    while i < len(arr) and arr[i] <= x:
        i = i * 2
    return binary_search(arr[:min(i, len(arr))], x)

def measure_time(search_func, arr, x):
    start_time = time.time()
    search_func(arr, x)
    end_time = time.time()
    return end_time - start_time

list_sizes = [100, 1000, 10000, 100000, 1000000]
search_algorithms = {
    "Binary Search": binary_search,
    "Interpolation Search": interpolation_search,
    "Jump Search": jump_search,
    "Exponential Search": exponential_search
}

results = []

for size in list_sizes:
    arr = sorted(random.sample(range(size * 2), size))
    x = random.choice(arr)
    for name, func in search_algorithms.items():
        exec_time = measure_time(func, arr, x)
        results.append((size, name, exec_time))

print(f"{'List Size':<10} {'Algorithm':<20} {'Execution Time (s)':<20}")
print("="*50)
for size, name, exec_time in results:
    print(f"{size:<10} {name:<20} {exec_time:<20}")
}


