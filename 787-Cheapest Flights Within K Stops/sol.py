class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        # //TC O(no of edges* k times)
        prices = [float("inf")] * n # n size of array containing infinities
        prices[src] =0 # src node has price as 0

        for i in range(k+1):
            tempPrices= prices.copy()
        # Bellman Ford Algorithm
            for source, destination, price in flights:
                if prices[source] == float("inf"):
                    continue # skip if it's infinity
                if prices[source] + price < tempPrices[destination]:
                    tempPrices[destination] = prices[source] + price
            prices= tempPrices

        return -1 if prices[dst]  == float("inf") else prices[dst]
