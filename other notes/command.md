# commands rarely used but necessary in ubuntu 

1. remove some useless software

```shell
sudo apt-get purge gnome-shell-extension-ubuntu-dock
sudo apt-get purge gnome-shell-extension-appindicator
```

2. some common file positions

```shell
/etc/fstab				//挂载分区文件
/usr/share/themes		//gnome主题解压之后的位置
/usr/share/icons		//gnome-icons positon
						//fonts install position
						
```

3. install fonts in ubuntu 

```shell
/usr/share/fonts/truetype/msttcorefonts
```

4. usually used gnome-extensions

> 1. dash to dock                       
> 2. hide activities button     
> 3. hide top bar
> 4. netspeed
> 5. user themes   

5. icons & themes used in ubuntu 

> 1. macterial theme 
> 2. papirus icons

6. repair the gnome-shell fonts in top-bar 
7. commands about ssh-connection

```shell
ssh-keygen -t rsa -C "youremail@example.com"
```

6. git configurations 

```shell
git config --global user.name "yourname"
git config --global user.email youremail@example.com
git config --list
ssh-keygen -t rsa -C "youremail@example.com"
cd ~/.ssh
```

6. shadowsocks
   1. shadowsocks configurations

```json
{
    "server":"45.77.177.47",
    "server_port":8080,
    "local_address":"127.0.0.1",
    "local_port":1080,
    "password":"Pangxiangru0604",
    "timeout":300,
    "method":"aes-256-gcm",
    "fast_open":true
}
shackdowsocks1.json
{
    "server":"167.179.64.231",
    "server_port":60666,
    "local_address":"127.0.0.1",
    "local_port":1080,
    "password":"freebird",
    "timeout":300,
	"protocol":"origin",
    "method":"chacha20",
    "fast_open":true
}
```

​	2. shadowsocks install &use 

```shell
sudo apt-get install python-pip
pip install shadowsocks
sudo sslocal -c ConfigurationPath -d start		//后台运行
sudo sslocal -c ConfigurationPath -d stop		//后台停止运行
sudo sslocal -c ConfigurationPath -d restart	//重启
```

 	3. switchyomega

> https://blog.huihut.com/2017/08/25/LinuxInstallConfigShadowsocksClient/

6. ln和alias的区别