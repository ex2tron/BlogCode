import cv2
import matplotlib.pyplot as plt

# 显示灰度图
img = cv2.imread('lena.jpg', 0)
plt.imshow(img, cmap='gray')
plt.show()

# 显示彩色图
img = cv2.imread('lena.jpg')
# 或使用img2 = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
img2 = img[:, :, ::-1]

# 不正确的显示
plt.subplot(121), plt.imshow(img)

# 正确的显示
plt.subplot(122)
plt.xticks([]), plt.yticks([])  # 隐藏x和y轴
plt.imshow(img2)

plt.show()
