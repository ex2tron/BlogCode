# ex2tron's blog:
# http://ex2tron.wang
# 2019年5月1日

import string

# 定义64字符
base_charset = string.ascii_uppercase+string.ascii_lowercase+string.digits+"+/"


def my_b64_encode(ori_bytes):
    ret, ori_len = "", len(ori_bytes)

    for i in range(0, ori_len, 3):
        # 第一组
        first = (ori_bytes[i] & 0xFC) >> 2
        ret += base_charset[first]

        # 第二组
        if i+1 >= ori_len:
            second = (ori_bytes[i] & 0x03)*16
            ret += base_charset[second] + "=="
            break

        second = (ori_bytes[i] & 0x03)*16 + ((ori_bytes[i+1] & 0xF0) >> 4)
        ret += base_charset[second]

        # 第三组
        if i+2 >= ori_len:
            third = (ori_bytes[i+1] & 0x0F)*4
            ret += base_charset[third] + "="
            break

        third = (ori_bytes[i+1] & 0x0F)*4 + ((ori_bytes[i+2] & 0xC0) >> 6)
        ret += base_charset[third]

        # 第四组
        fourth = ori_bytes[i+2] & 0x3F
        ret += base_charset[fourth]

    return ret


print(my_b64_encode(b'ManM'))  # TWFuTQ==

# 下面的代码可对比两者的效率
import base64
import time

start = time.clock()
with open('lena.jpg', 'rb') as pic:
    data = my_b64_encode(pic.read())
end = time.clock()

print(end-start)
# print(data)
