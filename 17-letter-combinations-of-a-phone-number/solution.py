class Solution:
    def __init__(self):
        self.digitLetterDict = {
            "2" : "abc",
            "3" : "def",
            "4" : "ghi",
            "5" : "jkl",
            "6" : "mno",
            "7" : "pqrs",
            "8" : "tuv",
            "9" : "wxyz"
        }
    
    def letterCombinations(self, digits: str) -> List[str]:
        """
        Each number maps to 3 different possible letters
        Want to enumerate all possible letter combinations.
        
        Observation: length of each combination == length of digit string
        Each combination needs to consider all digits.
        
        Hmm. Is there perhaps a way to do this recursively?
        
        End condition: after handling the last letter of the first digit
        
        Assume: For a given letter corresponding to the first digit, we can enumerate all combinations. Then, it's just a matter of looping through all the letters in the first digit.
        
        
        """
        
        combinations = []
        
        if not digits:
            return combinations
        
        firstDigitLetters = self.digitLetterDict[digits[0]]
        
        for letter in firstDigitLetters:
            subCombinations = self.letterCombinations(digits[1:])
            if not subCombinations:
                subCombinations = [letter]
            else:
                subCombinations = list(map(lambda comb: letter + comb, subCombinations))
            combinations.extend(subCombinations)    
            
        return combinations
    