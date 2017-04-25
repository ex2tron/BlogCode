import struct

# 把整数100存成二进制数据
num = 100
bytes = struct.pack('i', num)
print(bytes)
# 解析二进制数据
num2 = struct.unpack('i', bytes)
print(num2)


# 多个不同数据类型存成二进制数据
num1, num2 = 100, 3.14
str1 = 'ex2tron'
bytes2 = struct.pack('if7s', num1, num2, str.encode(str1))
print(bytes2)

# 得到二进制数据中的真实数据
result = struct.unpack('if7s', bytes2)
print(result)
# 分开得到二进制数据中的真实数据
n1, n2, s1 = struct.unpack('if7s', bytes2)
print(n1, n2, s1, sep=',')


# 解析message.dat文件
file = open(R"D:\ex2tron\Desktop\message.dat", 'rb')
src = file.read()
dataLength = len(src) / 2
data = struct.unpack('h' * int(dataLength), src)
print(data)