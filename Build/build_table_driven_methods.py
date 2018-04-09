# 构建：表驱动法
# ex2tron 2018年04月08日
# http://ex2tron.wang

# 笨的方法：使用if-else或switch-case
month = int(input())
if (month == 1):
    day = 31
elif (month == 2):
    day = 28
elif(month == 3):
    day = 31
elif (month == 4):
    day = 30
elif (month == 5):
    day = 31
elif (month == 6):
    day = 30
elif (month == 7):
    day = 31
elif (month == 8):
    day = 31
elif (month == 9):
    day = 30
elif(month == 10):
    day = 31
elif (month == 11):
    day = 30
elif (month == 12):
    day = 31
print(day)

# 简洁且优雅的方法：直接查表
month = int(input())
dayOfMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
day = dayOfMonth[month - 1]

# 1. 重复键值
distanceOfSpeed = [a, a, ……a, n31, n32, ……, n99, b, b, ……, b]
# 2. 转换键值
newKey = max(min(100, speed), 30)
distanceOfSpeed = [a, n31, n32, ……, n99, b]
result = distanceOfSpeed[max(min(100, speed), 30) - 30]

# 阶梯查表法：取区间的上限值
scoreLimit = [60.0, 70.0, 90.0, 100.0]
grade = ["不及格", "及格", "良", "优"]

score, index, result = 45, 0, '优'
while (result == '优' and index < len(grade) - 1):
    if (score < scoreLimit[index]):
        result = grade[index]
    index += 1

print(result)
