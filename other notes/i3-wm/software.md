# software 

## 1. shadowsocks 
* how to install shadowsocks
> sudo pacman -Syu shadowsocks-libev
>
* how to use ss-local?
> sudo sslocal -s server -p server-port -l localport -m method -k passward
>

## 2. chromium
 * set global proxy
> chromium --proxy-server="socks5://127.0.0.1:1080"