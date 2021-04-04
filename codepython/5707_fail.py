class Solution:
    def maxHappyGroups(self, batchSize: int, groups: List[int]) -> int:
        vis = set()
        ans = 0
        groups.sort()
        for i in range(len(groups)):
            groups[i] %= batchSize
            if groups[i] == 0:
                vis.add(i)
                ans += 1
        if sum(groups) % batchSize != 0:
            ans += 1
        for i in range(len(groups)):
            bags = [[] for j in range(batchSize << 1)]
            for k, val in enumerate(groups):
                if k in vis:
                    continue
                for j in range(batchSize-1, -1, -1):
                    if j == 0:
                        if len(bags[val]) == 0 or len(bags[val]) > 1:
                            bags[val] = [k]
                        elif len(bags[val]) == 1:
                            bags[val].append([k])
                    else:
                        if len(bags[j]) != 0:
                            if (len(bags[j])+1 < len(bags[j+val]) or len(bags[j+val]) == 0):
                                bags[j+val] = [[x for x in bags[j]]]
                                bags[j+val][-1].append(k)
                            elif len(bags[j])+1 == len(bags[j+val]):
                                bags[j+val].append([x for x in bags[j]])
                                bags[j+val][-1].append(k)
                for j in range(batchSize, batchSize*2, 1):
                    if len(bags[j]) > 0:
                        if (len(bags[j]) < len(bags[j-batchSize]) or len(bags[j-batchSize]) == 0):
                            bags[j-batchSize] = bags[j]
                            bags[j] = []
                        elif:
                            bags[j-batchSize].extend(bags[j])
                            bags[j] = []
            if len(bags[0]) > 0:
                # 这里判断多个bags如何获得最大
                # 问题转化：选或者不选，如何使得最后选的个数最大（即该背包被其它背包引用最少）
                # 猜想：选择出现最多的数优先匹配？
                ans += 1
                for j in bags[0]:
                    vis.add(j)
                print([groups[j] for j in bags[0]])
        for i in range(len(groups)):
            if i not in vis:
                print(groups[i])
        return ans
