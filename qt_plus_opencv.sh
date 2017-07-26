# Windows平台下Qt的pro文件修改
# INCLUDEPATH 头文件路径
INCLUDEPATH +=  D:\QTOpenCV\include\opencv\
                D:\QTOpenCV\include\opencv2\
                D:\QTOpenCV\include

# LIBS 库文件，-L指定库路径 -llib指定程序用到的lib库
# 使用下面方法包含所有库
# LIBS += -L D:\QTOpenCV\lib\libopencv_*.a
# 或使用下面方法只包含要使用的库
LIBS += -L D:\QTOpenCV\lib\
        -llibopencv_highgui320.dll.a\
		-llibopencv_imgproc320.dll.a
		
		
# Ubuntu系统下Qt和OpenCV环境安装
# 安装Qt5
sudo apt-get install cmake qt5-default qtcreator
# 安装opencv
sudo apt-get install libopencv-dev
sudo apt-get install libcv-dev 

INCLUDEPATH += /usr/include\
			   /usr/include/opencv\
			   /usr/include/opencv2
LIBS += -L/usr/lib\
		-llibopencv_highgui\
		-llibopencv_core\
		-llibopencv_imgproc\
		-llibopencv_calib3d