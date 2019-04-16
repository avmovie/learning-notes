# software 

## 1. shadowsocks 
* how to install shadowsocks
> ```shell
> sudo pacman -Syu shadowsocks-libev
>```
* how to use ss-local?
> ```shell
> sudo sslocal -s server -p server-port -l localport -m method -k passward
>```

## 2. chromium
 * set global proxy
> ```shell
> chromium --proxy-server="socks5://127.0.0.1:1080"
> ```
## disable touchpad
1. Install xinput
> ```shell
> sudo pacman -Syu extra/xorg-input
> ```
2. Make use of xinput 
> ```shell
> xinput --disable 14
> ``` 
