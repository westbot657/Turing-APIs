
--/// Generated Lua Api ///--
---@class TuringAPI
local turing_api = {}

--// Functions //--


---@param name string
---@return nil
function turing_api.testGlobal(name) end

---@return number
function turing_api.global2Test() end

---@param a number
---@param b number
---@return string
function turing_api.myTest(a, b) end
--// Classes //--

---@class MyClass
local MyClass = {}
turing_api.MyClass = MyClass



---@param self table
---@param a number
---@return nil
function turing_api.MyClass.objectFunc(self, a) end

---@class Log
local Log = {}
turing_api.Log = Log


---@param msg string
---@return nil
function turing_api.Log.info(msg) end

---@param msg string
---@return nil
function turing_api.Log.warn(msg) end

---@param msg string
---@return nil
function turing_api.Log.critical(msg) end

---@param msg string
---@return nil
function turing_api.Log.debug(msg) end


return turing_api