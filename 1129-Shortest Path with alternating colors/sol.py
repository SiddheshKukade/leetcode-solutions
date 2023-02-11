class Solution(object):
    def shortestAlternatingPaths(self, n, redEdges, blueEdges):
        """
        :type n: int
        :type redEdges: List[List[int]]
        :type blueEdges: List[List[int]]
        :rtype: List[int]
        """
        # TC O  of n 
        red = collections.defaultdict(list)
        blue =  collections.defaultdict(list)


        for src , dst in redEdges:
            red[src].append(dst)

        for src , dst in blueEdges:
            blue[src].append(dst)

        answer = [-1 for i  in range(n)]
        # answer[0] = 0
        q =   deque()
        q.append([0,0,None]) # [node, length, prev_edge_color]
        visit = set()
        visit.add((0,None))
        while q:
            node, length,edgeColor = q.popleft()
            if answer[node] == -1:
                answer[node]= length

            if edgeColor != "RED":
                #iteraate throught blue neighbours
                for nei in red[node]:
                    if (nei, "RED") not in visit:
                        visit.add((nei,"RED"))
                        q.append([nei,length+1, "RED"])

            if edgeColor != "BLUE":
                #iteraate throught blue neighbours
                for nei in blue[node]:
                    if (nei, "BLUE") not in visit:
                        visit.add((nei,"BLUE"))
                        q.append([nei,length+1, "BLUE"])

        return answer

