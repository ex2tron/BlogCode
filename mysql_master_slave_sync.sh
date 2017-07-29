# 博客：MySQL学习小记（5）、主从服务器同步
# ex2tron 2017年7月29日
# http://ex2tron.xin

#（一）、主机配置
# 创建同步账号
> grant replication slave on *.* to 'rep_slave'@'192.168.1.%' identified by 'repslavepwd';
> flush privileges;

# 修改my.ini配置文件
[mysqld]
; 数据库唯一ID，主从机不能重复
server-id = 1
; 指定二进制日志存放路径，只有文件名的话，默认存放在mysql的data目录下
log-bin = mysql-bin
; 以下为可选配置项
; 需要同步的数据库名，如果有多个，按此格式多写几行即可，不指定的话，默认全部同步
; binlog-do-db = database
; 不需要备份的数据库名
; binlog-ignore-db = database

# 重启MySQL服务
> net stop wampmysqld64
> net start wampmysqld64

# 查看主机状态
mysql> show master status;
+------------------+----------+--------------+------------------+-------------------+
| File             | Position | Binlog_Do_DB | Binlog_Ignore_DB | Executed_Gtid_Set |
+------------------+----------+--------------+------------------+-------------------+
| mysql-bin.000002 |     3046 |              |                  |                   |
+------------------+----------+--------------+------------------+-------------------+
1 row in set (0.00 sec)

#（二）、从机配置
# 修改my.cnf配置文件
[mysqld]
# 数据库唯一ID，主从机不能重复
server-id = 2

# 重启MySQL服务
$ sudo service mysql restart

# 配置同步信息
 > stop slave;
 > change master to master_host = '192.168.1.102',
-> master_user = 'rep_slave',
-> master_password = 'repslavepwd',
-> master_log_file = 'mysql-bin.000002',
-> master_log_pos = 3046;
 > start slave;

# 显示从机状态
> show slave status\G;
 
#（三）、测试同步
# 主机上新建一个数据库
> create database testsync;

# 从机上查看数据库
> show databases; 