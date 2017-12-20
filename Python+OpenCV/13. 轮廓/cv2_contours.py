import cv2
import numpy as np

img = cv2.imread('handwriting.jpg')
img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
ret, thresh = cv2.threshold(
    img_gray, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)


# imgtemp = cv2.cvtColor(thresh, cv2.COLOR_GRAY2BGR)

image, contours, hierarchy = cv2.findContours(
    thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
print(len(contours))  # 结果应该为2

# cv2.drawContours(img, contours, -1, (0, 0, 255), 2)

cnt = contours[1]
cv2.drawContours(img, [cnt], 0, (0, 0, 255), 3)

cv2.imshow('fs', img)
# cv2.imshow('f', np.hstack((img, thresh, image)))
cv2.waitKey(0)
