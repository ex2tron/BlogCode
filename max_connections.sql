
--查看MySQL响应的最大连接数：
mysql> show global status like 'max_used_connections';

--查看MySQL的最大连接数：
mysql> show variables like 'max_connections';

--最优设置：
max_used_connections / max connections * 100% ≈ 85%

--设置MySQL最大连接数:
mysql> set global max_connections = 400;

--重启mysql服务：
C:\Windows\system32>net stop mysql
C:\Windows\system32>net start mysql