# ngx_ipip
converts ip to country and city

## Steps of installing
```
    1. download https://openresty.org/download/openresty-x.y.z.a.tar.gz .
    2. install openresty.
    3. To copy all files in lualib to directory openresty/lualib/
    4. To cpoy all conf file to directory openresty/nginx/conf/
    5. compile source in directory openresty/lualib/ipip/datx
        cd /usr/local/openresty/lualib/ipip/datx ; make; make install
    6. Start openresty nginx server.
```
## demo of lua client
```lua
package.cpath = '/usr/local/openresty/lualib/ipip/datx/?.so;'
local ipip = require 'libluaipip'

ipip.ipip_init('ipip.datx')

print(ipip.ipip_find('8.8.8.8'))
print(ipip.ipip_find('202.108.22.5'))

```
## result
```bash
[root@localhost datx]# lua ip.lua
GOOGLE.COM	GOOGLE.COM		google.com
中国	北京	北京			39.904989	116.405285	Asia/Shanghai	UTC+8	110000	86	CN	AP
```

## nginx conf
```
server {
        listen 8000;

        location = /v1/ipip {
            access_log logs/access.log main;
            add_header 'Content-Type' 'text/html';
            content_by_lua '
                local cln = require "luaip"
                ngx.say(cln.find());
            ';
        }
}
```
## Testing
    To access web url http://127.0.0.1:8000/v1/ip?ip=8.8.8.8 and get result.
```
	GOOGLE.COM	GOOGLE.COM	google.com
```

## Refer
```bash
	https://github.com/17mon/c
```
