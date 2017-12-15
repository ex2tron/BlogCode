import cv2
import numpy as np

img = cv2.imread('lena.jpg')
# 均值滤波
blur = cv2.blur(img, (3, 3))

# 上面的均值滤波也可以用方框滤波实现：normalize=True
# blur = cv2.boxFilter(img, -1, (3, 3), normalize=True)

# 高斯滤波
gau_blur = cv2.GaussianBlur(img, (3, 3), 0)

# 三张图片横向叠加对比显示
res = np.hstack((img, blur, gau_blur))
cv2.imshow('res', res)
cv2.waitKey(0)


# 均值滤波vs高斯滤波
img = cv2.imread('gaussian_noise.bmp')
blur = cv2.blur(img, (5, 5))  # 均值滤波
gaussian = cv2.GaussianBlur(img, (5, 5), 1)  # 高斯滤波

res = np.hstack((img, blur, gaussian))
cv2.imshow('gaussian vs average', res)
cv2.waitKey(0)


# 均值滤波vs中值滤波
img = cv2.imread('salt_noise.bmp', 0)

blur = cv2.blur(img, (5, 5))  # 均值滤波
median = cv2.medianBlur(img, 5)  # 中值滤波

res = np.hstack((img, blur, median))
cv2.imshow('median vs average', res)
cv2.waitKey(0)


# 双边滤波vs高斯滤波
img = cv2.imread('lena.jpg', 0)
gau = cv2.GaussianBlur(img, (5, 5), 0)  # 高斯滤波
blur = cv2.bilateralFilter(img, 5, 75, 75)  # 双边滤波


res = np.hstack((img, gau, blur))
cv2.imshow('res', res)
cv2.waitKey(0)

# kernal = np.float32([[0.210724350074, 0.460264296291, 0.210724350074],
#                      [0.460264296291, 1.00530964915, 0.460264296291],
#                      [0.210724350074, 0.460264296291, 0.210724350074]])
# kernel = cv2.getGaussianKernel(6, 0)
# print(kernel)
# img = cv2.imread('6_by_6.bmp', 0)
# print(img)

# dst = cv2.filter2D(img, -1, kernal)
# print(dst)

# blur = cv2.GaussianBlur(img, (3, 3), 0)
# print(blur)
# sigma = 0.8
# center = int(3 / 2)
# for i in range(3):
#     for j in range(3):
#         print((1 / 2 * np.pi * sigma * sigma) *
#               np.exp(-(((i - center)**2 + (j - center)**2)) / (2 * sigma * sigma)))

# gaus[i][j] = (1 / (2 * PI * sigma * sigma)) * exp(-((i - center) *
#                                                     (i - center) + (j - center) * (j - center)) / (2 * sigma * sigma))
