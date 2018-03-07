package.cpath = '/usr/local/openresty/lualib/ipip/dat/?.so;'
local ipip = require 'libluaipip'

ipip.ipip_init('17monipdb.dat')

print(ipip.ipip_find('8.8.8.8'))
print(ipip.ipip_find('202.108.22.5'))
