def calc_fibonacci(n):
    call_cnt0 = [1, 0]
    call_cnt1 = [0, 1]
    for i in range(2, n + 1):
        call_cnt0.append(call_cnt0[i-2]+call_cnt0[i-1])
        call_cnt1.append(call_cnt1[i-2]+call_cnt1[i-1])
    return (call_cnt0, call_cnt1)
    
(call_cnt0, call_cnt1) = calc_fibonacci(40)

T = int(input())

for _ in range(T):
    N = int(input())
    print(call_cnt0[N], call_cnt1[N])