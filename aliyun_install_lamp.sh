# 博客：【云端漫步】一起上“阿里云”（3）、LAMP环境搭建
# ex2tron 2017年6月3日
# http://ex2tron.lofter.com 

# 查看Linux系统版本
lsb_release -a

# 查看Linux内核版本
uname -a

# 一键安装lamp(ubuntu)
sudo tasksel install lamp-server

# ubuntu分别安装（按照以下步骤）
apt-get update
apt-get install mysql-server
apt-get install apache2
apt-get install libapache2-mod-php7.0（或：apt-get install libapache2-mod-php）
apt-get install phpmyadmin
# phpmyadmin文件链接到apache目录下
sudo ln -s /usr/share/phpmyadmin/ /var/www/html/phpmyadmin

# centos分别安装（按照以下步骤）
yum install mysql-server
yum install httpd
yum install php
yum install phpmyadmin

# 查看版本
php -v
apache2 -v

# phpInfo
<?php
	phpinfo()
?>