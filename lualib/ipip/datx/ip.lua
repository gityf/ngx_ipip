package.cpath = '/usr/local/openresty/lualib/ipip/datx/?.so;'
local ipip = require 'libluaipip'

ipip.ipip_init('ipip.datx')

print(ipip.ipip_find('8.8.8.8'))
print(ipip.ipip_find('202.108.22.5'))
