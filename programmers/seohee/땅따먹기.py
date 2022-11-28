def solution(land):
    dp = [[0]*4 for _ in range(len(land))] # len(land)는 행의 길이
    print(dp)
    for i in range(4):
        dp[0][i] = land[0][i]
    print(dp)
    print()
    for i in range(1,len(land)): #1~2행
        for j in range(4): # 0~3열
            print(dp[i-1][:j]+dp[i-1][j+1:], land[i][j])
            dp[i][j] = max(dp[i-1][:j]+dp[i-1][j+1:])+land[i][j]
            print(dp)
        print()
        
    return max(dp[len(land)-1])