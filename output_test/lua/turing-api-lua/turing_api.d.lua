

--/// Generated Lua API ///--
---@class TuringApi
local turing_api = {}

--// Functions //--


---@param random Random
---@return Something
function turing_api.doThing(random) end


--// Classes //--
--- Used to log messages to the console
---@class Log
local Log = {}
turing_api.Log = Log

--- Only logs in debug mode
---@param msg string
---@return nil
function turing_api.Log.debug(msg) end

--- Highlights red
---@param msg string
---@return nil
function turing_api.Log.critical(msg) end

--- Highlights yellow
---@param msg string
---@return nil
function turing_api.Log.warn(msg) end

--- Highlights blue
---@param msg string
---@return nil
function turing_api.Log.info(msg) end


--- Vivify compatibility systems
---@class Vivify
local Vivify = {}
turing_api.Vivify = Vivify

--- Uploads a data buffer to beat saber
---@param buf table
---@return nil
function turing_api.Vivify.uploadBuffer(buf) end

--- Fetches a data buffer from beat saber
---@return table
function turing_api.Vivify.getBuffer() end



---@class Random
local Random = {}
turing_api.Random = Random



---@class Something
local Something = {}
turing_api.Something = Something



return turing_api