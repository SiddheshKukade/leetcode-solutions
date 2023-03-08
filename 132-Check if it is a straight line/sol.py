class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        x1,y1=coordinates[0][0],coordinates[0][1]
        x2,y2=coordinates[1][0],coordinates[1][1]
        for x3,y3 in coordinates[2:]:
            if (y3-y2)*(x2-x1)!=(x3-x2)*(y2-y1):
                return False
        else:
            return True
