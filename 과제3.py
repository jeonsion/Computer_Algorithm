N = 8

cols = [0 for i in range(N+1)]

def promissing(h):
    for i in range(1, h):
        if(cols[i] == cols[h]):
            return 0
        elif( h-i == abs(cols[h]-cols[i])):
            return 0
    return 1    
        
        
def queens(h):
    if(not promissing):
        return 0
    if(h==N):
        for i in range(1, N+1):
            print("({}, {})".format(i, cols[i]))
        return 1
    for i in range(1, N+1):
        cols[h+1] = i
        if(queens(h+1)):
            return 1
    return 0

if(queens(0)==1):
    print("Success\n")
        
print(cols)