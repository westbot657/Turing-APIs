-- NOTE: lua does not need any compiler or any extra setup, just include the plain lua file in-place of the wasm file in your map
-- you do NOT need to include the api file with the script when putting the script in the map.
local script = {}
---@type TuringApi
local api = require("turing_api")

function script.on_load()
    api.Log.info("Running lua in turing!")
end

function script.on_update()

end

function script.on_exit()

end



function script._turing_api_semver()
    -- this function is used by turing to make sure your script can be run without issues.
    -- feel free to update the numbers manually or copy-paste from the template
    -- whenever you update to a new version of the API
    return (1 << 32) -- (major << 32)
    | (0 << 16) -- (minor << 16)
    | 0 -- patch
end
return script