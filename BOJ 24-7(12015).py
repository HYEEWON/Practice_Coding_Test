n = int(input()) # 수열 A의 크기
A = list(map(int, input().split()))

# 찾으려는 수와 같거나, 수가 없으면 큰 수 중 가장 작은 수 반환
def lower_bound(arr, start, end, n):
    while end > start:
        mid = (start+end)//2
        if n > arr[mid]:
            start = mid+1
        else:
            end = mid
    return end
    
ans = []
for a in A:
    if len(ans) == 0:
        ans.append(a)
    if ans[-1] < a:
        ans.append(a)
    else:
        idx = lower_bound(ans, 0, len(ans)-1, a)
        ans[idx] = a

print(len(ans))
    
    
