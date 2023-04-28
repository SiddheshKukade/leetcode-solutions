class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        N = len(strs)

        def calculateDelta(x,y):
            d=0
            for a,b in zip(x,y):
                if a!=b:
                    d +=1
            return d # returning the count of not same chars
        
        adj_list = collections.defaultdict(list) # created array of arrays
        for i in range(N):
            for j in range(i+1, N): #checking chars after current
                if calculateDelta(strs[i], strs[j]) <=2:
                    adj_list[i].append(j)
                    adj_list[j].append(i) #saving the pairs

        visited = [False] * N # creating a all FALSE visited matrix to keep track of visited nodes
        count =0

        def visit(x):
            for v in adj_list[x]:
                if not visited[v]:
                    visited[v] = True
                    visit(v)# visiting all the adjacent nodes further
            
        for i in range(N):
            if not visited[i]:
                count += 1 # if not visited means not matching so coutt++
                visited[i]= True
                visit(i)

        return count
        
