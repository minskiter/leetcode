class Solution:
    def maxHappyGroups(self, batchSize: int, groups: List[int]) -> int:
        vis = set()
        cnt = {}
        ans = 0
        for i in range(len(groups)):
            groups[i] %= batchSize
            if groups[i] == 0:
                vis.add(i)
                ans += 1
            else:
                if groups[i] not in cnt:
                    cnt[groups[i]] = 1
                else:
                    cnt[groups[i]] += 1
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
                    else:
                        if len(bags[j]) != 0:
                            if (len(bags[j])+1 < len(bags[j+val]) or len(bags[j+val]) == 0):
                                bags[j+val] = [x for x in bags[j]]
                                bags[j+val].append(k)
                            elif len(bags[j])+1 == len(bags[j+val]):
                                # 增加贪心条件，优先取剩余的数字最多的
                                tmp = [x for x in bags[j]]
                                tmp.append(k)
                                if sum([cnt[groups[x]] for x in bags[j+val]]) < sum([cnt[groups[x]] for x in tmp]):
                                    bags[j+val] = tmp
                for j in range(batchSize, batchSize*2, 1):
                    if len(bags[j]) > 0:
                        if (len(bags[j]) < len(bags[j-batchSize]) or len(bags[j-batchSize]) == 0):
                            bags[j-batchSize] = bags[j]
                            bags[j] = []
                        elif len(bags[j]) == len(bags[j-batchSize]):
                            if sum([cnt[groups[x]] for x in bags[j-batchSize]]) > sum([cnt[groups[x]] for x in bags[j]]):
                                bags[j-batchSize] = bags[j]
                                bags[j] = []
            if len(bags[0]) > 0:
                ans += 1
                for j in bags[0]:
                    vis.add(j)
                    cnt[groups[j]] -= 1
        return ans
