#!/bin/bash

echo "脚本仅供学习交流，后续更新请关注原博客："
echo "http://ex2tron.wang/python-ubuntu-nodejs-change-sources/"


# 1.确定系统版本
uVersion=$(lsb_release -a |grep Release |awk -F : '{print $2}' |sed 's/^[ \t]*//g')

read -s -n1 -p "检测到您的Ubuntu系统版本为：$uVersion，是否继续？(Y/N) " choice

if [ $choice != "y" ] && [ $choice != 'Y' ];then
    echo
    echo 'Good Bye.'
    exit
fi

# 2.选择镜像站
sources=('tsinghua' 'aliyun' 'netease')
echo
echo "**********************************"
echo "请选择镜像源："
echo "1. 清华大学   2. 阿里巴巴   3.网易"
echo "**********************************"
read -s -n1 sourceChoice

if [ $sourceChoice -ne 1 ] && [ $sourceChoice -ne 2 ] && [ $sourceChoice -ne 3 ];then
    echo
    echo '输入有误，Good Bye.'
    exit
fi


# 3.克隆文件并更新
gitFileName="ubuntu_${sources[sourceChoice-1]}_${uVersion}_list"

echo
echo "克隆中..."
sudo git clone https://gitee.com/ex2tron/Ubuntu_Common_Domestic_Source.git
cd Ubuntu_Common_Domestic_Source

echo "备份sources.list..."
sudo cp /etc/apt/sources.list /etc/apt/sources.list.bak
echo "设置新的镜像源..."
sudo cp $gitFileName /etc/apt/sources.list
echo "更新源..."
sudo apt update

cd ..
sudo rm -rf Ubuntu_Common_Domestic_Source
echo "设置完成，Thanks."