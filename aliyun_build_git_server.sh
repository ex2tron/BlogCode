# 博客：【云端漫步】一起上“阿里云”（4）、搭建Git服务器
# ex2tron 2017年6月4日
# http://ex2tron.lofter.com 

# 安装git、ssh
sudo apt-get install git
sudo apt-get install ssh
# 创建新用户
sudo adduser git
# 创建.ssh文件夹
mkdir /home/git/.ssh
# 创建authorized_keys文件
touch /home/git/.ssh/authorized_keys
# 把id_rsa.pub的公钥导入到authorized_keys中
echo "ssh-rsa pubkey" >> /home/git/.ssh/authorized_keys
# 切换到当前用户（git）目录
cd /home/git/
# 新建一个仓库
git init --bare sample.git
# 更改文件所属用户及组
chown -R git:git sample.git


# 克隆远程仓库
$ git clone git@139.224.xxx.xxx:/home/git/sample.git


# 推送到远程仓库
$ git add .
$ git commit -m 'the first version'
# 首次推送需要加-u
$ git push -u origin master


# 生成公钥
$ ssh-keygen -t rsa
