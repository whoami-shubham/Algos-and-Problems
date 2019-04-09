n = int(input())
sum_ = 0
for i in range(n):
    num = int(input())
    sum_ = sum_ + num
sum_ = str(sum_)
print(sum_[:10])