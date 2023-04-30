class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:

        # THE ALGORITHM UNION FIND
        # Firstly all of the parent values are the nodes themselves i.e. [1,2,3,4,5,6,7,...]
        # assuming that they're not connected with each other and we have to form a tree from them.
        # 
        #  Input ranks [[1,2],[1,3],[2,3]]
        #  Then we iterate over each rank vector

        # so starting with [1,2]
        # here we firstly check the current ranks of these two nodes if one of them is higher than
        # other the it then it becomes the parent
         
        # 1->2
        # updating ones rank as 2 and 2s parent as 1


        # now for [1,3]
        # 1 already has a rank 2 means 1 child present 
        # so update the rank of 1 with sum of rank of 3 and also update the parent of 3 as one


        # this keep on continuing.....


        # the BASE CASE:
        #       for [2,3]

        # here we check if the parent of the curr nodes are same or not
        # if same
        #     RETURN FALSE
        # if not
        #     CONTINUE FURTHER.   
        # then



        par = [i for i in range(len(edges)+1)] # 0 to edges len +1  ex. parents=[1,2,3,4...]
        rank = [1]*(len(edges)+1)  # all 1s [1,1,1,1,1,1,...]
        # rank basically means the no of child with starting value 1 
        # Ex. rank for 1 child will be 2 

        def find(n):
            p = par[n]
            while p != par[p]: # IF P DOESN'T HAVE A PARENT
                par[p]= par[par[p]] # updating parent with grandparent
                p = par[p] # updating p with parent
            return p

        def union(n1,n2):
            p1,p2 = find(n1) , find(n2)

            if p1 == p2: # if they have same parent means a conn 
            # already exists there so return false
                return False
            # NOT SAME PARENT THEN UNION  THEM BY RANK

            if rank[p1] > rank[p2]: # P1 is parent of p2
                par[p2] = p1 # updating the parent
                rank[p1] += rank[p2] # unioning the ranks
            else: # p2 is parent of p1
                par[p1] = p2 # updating the parent
                rank[p2] = rank[p1] # unioing the ranks
            return True # if all good return True

        for n1, n2 in edges:
            if not union(n1,n2): #RETURN THE EDGE THAT IS RETURNING FALSE FOR THE UNION FUNCTION DEFINED ABOVE
                return [n1,n2]
