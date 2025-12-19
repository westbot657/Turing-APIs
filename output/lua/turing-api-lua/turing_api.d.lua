
--/// Generated Lua Api ///--
---@class TuringApi
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


---@class ColorNote
local ColorNote = {}
turing_api.ColorNote = ColorNote



---@param self table
---@param x number
---@param y number
---@param z number
---@return nil
function turing_api.ColorNote.setPosition(self, x, y, z) end


---@param self table
---@param x number
---@param y number
---@param z number
---@param w number
---@return nil
function turing_api.ColorNote.setOrientation(self, x, y, z, w) end


---@param self table
---@return ColorNote
function turing_api.ColorNote.clone(self) end

--- used to log messages to the console
---@class Log
local Log = {}
turing_api.Log = Log

--- logs `msg` to the console
---@param msg string
---@return nil
function turing_api.Log.info(msg) end

--- logs `msg` to the console as a warning
---@param msg string
---@return nil
function turing_api.Log.warn(msg) end

--- logs `msg` to the console as an error
---@param msg string
---@return nil
function turing_api.Log.critical(msg) end

--- logs `msg` to the console when in debug mode
---@param msg string
---@return nil
function turing_api.Log.debug(msg) end



return turing_api