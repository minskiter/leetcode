from typing import List


class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        area = 0
        left, bottom, right, top = min(x[0] for x in rectangles), min(
            x[1] for x in rectangles), max(x[2] for x in rectangles), max(x[2] for x in rectangles)
        points = set([(left, bottom), (left, top),
                      (right, bottom), (right, top)])
        except_area = (right-left)*(top-bottom)
        points_arr = [[0, 1], [0, 3], [2, 1], [2, 3]]
        for rectangle in rectangles:
            for point_a in points_arr:
                point = (rectangle[point_a[0]], rectangle[point_a[1]])
                if point in points:
                    points.remove(point)
                else:
                    points.add(point)
            area += (rectangle[3]-rectangle[1])*(rectangle[2]-rectangle[1])
        return len(points) == 0


if __name__ == "__main__":
    print(Solution().isRectangleCover([[0, 0, 4, 1], [0, 0, 4, 1]]))
