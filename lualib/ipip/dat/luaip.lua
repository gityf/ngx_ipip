local ipip = require 'libluaipip'

_M = {}

function _M.find()
	ipip.ipip_init('/usr/local/openresty/lualib/ipip/dat/17monipdb.dat')
        local args = ngx.req.get_uri_args()
	return ipip.ipip_find(args.ip)
end

return _M
