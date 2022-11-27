def solution(n, lost, reserve):
    lost.sort()
    reserve.sort()

    for i in lost[:]:
        if i in reserve:
            lost.pop(lost.index(i))
            reserve.pop(reserve.index(i))
    
    reserve_count = [0] * (n+2)
    
    num = n - len(lost)
    print(lost, reserve, num)
    for i in reserve:
        reserve_count[i] += 1
    
    for i in range(len(lost)):
        if reserve_count[lost[i]-1] != 0:
            num += 1
            reserve_count[lost[i]-1] = 0
        elif reserve_count[lost[i]+1] != 0:
            num += 1
            reserve_count[lost[i]+1] = 0
    return num