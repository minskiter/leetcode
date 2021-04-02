class Solution:
    def decodeString(self, s: str) -> str:
        times = 0
        buffer = []
        index = 0
        while index < len(s):
            ch = s[index]
            if str.isdigit(ch):
                times = times*10+ord(ch)-ord('0')
            elif str.isalpha(ch):
                if times == 0:
                    times = 1
                buffer.append(ch*times)
                times = 0
            elif ch == '[':
                if times == 0:
                    times = 1
                left = 0
                for i in range(index+1, len(s)):
                    if s[i] == '[':
                        left += 1
                    elif s[i] == ']':
                        left -= 1
                        if left < 0:
                            buffer.append(self.decodeString(
                                s[index+1:i])*times)
                            index = i
                            break
                times = 0
            index += 1
        return "".join(buffer)


if __name__ == "__main__":
    print(Solution().decodeString("3[a2[c]]"))
