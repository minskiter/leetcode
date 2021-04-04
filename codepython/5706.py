class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        if len(sentence1)<len(sentence2):
            sentence1,sentence2 = sentence2,sentence1
        sentence1 = sentence1.split(' ')
        sentence2 = sentence2.split(' ')
        l = 0
        r = 0
        while l<len(sentence1) and l<len(sentence2):
            if sentence1[l]==sentence2[l]:
                l+=1
            else:
                break
        while len(sentence1)-r>0 and len(sentence2)-r>0:
            if sentence1[len(sentence1)-r-1]==sentence2[len(sentence2)-r-1]:
                r+=1
            else:
                break
        return l+r>=len(sentence2)