# ex2tron's blog:
# http://ex2tron.wang
# 2019年5月1日

import base64

print(base64.b64encode(b'Man'))  # 'TWFu'
# print(base64.b64encode(b'\x4D\x61\x6E'))
print(base64.b64decode('TWFu'))  # 'man'

# 不是3的倍数
print(base64.b64encode(b'M'))  # 'TQ=='

# URL中特殊字符处理
print(base64.b64encode(b'\xFB\xfe'))  # '+/4='
print(base64.urlsafe_b64encode(b'\xFB\xfe'))  # '-_4='

# 图片转Base64
with open('lena.jpg', 'rb') as pic:
    pic_str_data = base64.b64encode(pic.read())
print(pic_str_data)


# 中文
ch_bytes = '中'.encode('utf-8') # b'\xe4\xb8\xad'
# encode()默认是utf-8，可省略
print(ch_bytes.decode()) # '中'
print(base64.b64encode(ch_bytes))