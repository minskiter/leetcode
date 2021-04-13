from header import TreeNode, ListNode
from typing import List, Set, Tuple
from collections import OrderedDict, Counter
from queue import Queue, LifoQueue
from bisect import bisect_left
import heapq


def inside(pos: Tuple[int, int], leftTop: Tuple[int, int], rightBottom: Tuple[int, int]):
    if pos[0] < leftTop[0] or pos[0] >= rightBottom[0] or pos[1] < leftTop[1] or pos[1] >= rightBottom[1]:
        return False
    return True


def add_tuple(x: Tuple[int, int], y: Tuple[int, int]):
    return (x[0]+y[0], x[1]+y[1])


class Solution:
    def strongPasswordChecker(self, password: str) -> int:
        # 计算需要插入的数目
        inserted_cnt = 0
        judge = 0
        for ch in password:
            if str.isdigit(ch):
                judge |= 1
            elif str.islower(ch):
                judge |= 2
            elif str.isupper(ch):
                judge |= 4
        if judge != 7:
            while judge > 0:
                inserted_cnt += 1
                judge -= judge & (-judge)
            inserted_cnt = 3 - inserted_cnt
        if len(password) < 6:
            return max(inserted_cnt, 6-len(password))
        elif len(password) <= 20:
            cnt = 0
            pre = ' '
            replace_cnt = 0
            for ch in password:
                if ch != pre:
                    if cnt >= 3:
                        replace_cnt += cnt//3
                    cnt = 1
                    pre = ch
                else:
                    cnt += 1
            if cnt>=3:
                replace_cnt +=cnt//3
            return max(replace_cnt, inserted_cnt)
        else:
            deleted_cnt = len(password)-20
            box = []
            cnt = 0
            pre = ' '
            for ch in password:
                if ch != pre:
                    if cnt >= 3:
                        box.append(cnt)
                    cnt = 1
                    pre = ch
                else:
                    cnt += 1
            if cnt>=3:
                box.append(cnt)
            ans = deleted_cnt
            while deleted_cnt > 0 and len(box) > 0:
                for index,b in enumerate(box):
                    if deleted_cnt < 1:
                        break
                    if b % 3 == 0 and deleted_cnt>=1:
                        box[index] -= 1
                        deleted_cnt -= 1
                for index,b in enumerate(box):
                    if deleted_cnt < 2:
                        break
                    if b > 3:
                        if b % 3 == 1:
                            box[index] -= 2
                            deleted_cnt -= 2
                for index,b in enumerate(box):
                    if deleted_cnt < 3:
                        break
                    if b > 3 :
                        if b % 3 == 2:
                            box[index] -= 3
                            deleted_cnt -= 3
                new_box = []
                for b in box:
                    if b >= 3:
                        new_box.append(b)
                box = new_box
            replace_cnt = 0
            for b in box:
                replace_cnt += b//3
            return max(ans+replace_cnt, ans+inserted_cnt)


if __name__ == '__main__':
    pass
