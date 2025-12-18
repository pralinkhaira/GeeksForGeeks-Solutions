class Solution:
    def sortIt(self, arr):
        odd=sorted([num for num in arr if num%2!=0],reverse=True)
        even=sorted([num for num in arr if num %2==0])
        arr[:]=odd+even