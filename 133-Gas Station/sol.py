class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # Bruteforce on2 but our solution On
        if sum(gas) < sum(cost):
            return -1

        total =0
        start=0
        for i in range(len(gas)):
            total+= (gas[i]-cost[i]) #avialable gas after travelling current gas station

            if total<0: #out of gas
                total=0
                start = i+1 #we'll try starting for next
        return start
