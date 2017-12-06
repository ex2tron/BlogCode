import cv2

# 灰度图加载一张彩色图
img = cv2.imread('lena.jpg', 0)

# 显示图片
cv2.imshow('lena', img)
cv2.waitKey(0)

# 保存图片
cv2.imwrite('lena_gray.jpg', img)
