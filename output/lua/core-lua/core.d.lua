

--/// Generated Lua API ///--
---@class Core
local core = {}

--// Functions //--


--// Classes //--

---@class Action
local Action = {}
core.Action = Action



---@class Component
local Component = {}
core.Component = Component



---@class CustomData
local CustomData = {}
core.CustomData = CustomData


---@return CustomData
function core.CustomData.create() end


---@param list List1
---@param value boolean
---@return nil
function core.CustomData.listAddBool(list, value) end


---@param list List1
---@param value CustomData
---@return nil
function core.CustomData.listAddCustomData(list, value) end


---@param list List1
---@param value List1
---@return nil
function core.CustomData.listAddCustomDataList(list, value) end


---@param list List1
---@param value number
---@return nil
function core.CustomData.listAddFloat(list, value) end


---@param list List1
---@param value number
---@return nil
function core.CustomData.listAddInt(list, value) end


---@param list List1
---@param value string
---@return nil
function core.CustomData.listAddString(list, value) end


---@param custom_data CustomData
---@param key string
---@param value boolean
---@return nil
function core.CustomData.setBool(custom_data, key, value) end


---@param custom_data CustomData
---@param key string
---@param value CustomData
---@return nil
function core.CustomData.setCustomData(custom_data, key, value) end


---@param custom_data CustomData
---@param key string
---@param value List1
---@return nil
function core.CustomData.setCustomDataList(custom_data, key, value) end


---@param custom_data CustomData
---@param key string
---@param value number
---@return nil
function core.CustomData.setFloat(custom_data, key, value) end


---@param custom_data CustomData
---@param key string
---@param value number
---@return nil
function core.CustomData.setInt(custom_data, key, value) end


---@param custom_data CustomData
---@param key string
---@param value string
---@return nil
function core.CustomData.setString(custom_data, key, value) end



---@class GameObject
local GameObject = {}
core.GameObject = GameObject



---@class GcHelper
local GcHelper = {}
core.GcHelper = GcHelper


---@return GcHelper
function core.GcHelper.create() end



---@param self table
---@return nil
function core.GcHelper.dispose(self) end


---@param self table
---@return nil
function core.GcHelper.invalidateAllHandles(self) end


---@param self table
---@return nil
function core.GcHelper.wasmGarbageCollect(self) end


---@class IEnumerator
local IEnumerator = {}
core.IEnumerator = IEnumerator



---@class List1
local List1 = {}
core.List1 = List1



---@class Log
local Log = {}
core.Log = Log


---@param msg string
---@return nil
function core.Log.critical(msg) end


---@param msg string
---@return nil
function core.Log.debug(msg) end


---@param msg string
---@return nil
function core.Log.info(msg) end


---@param msg string
---@return nil
function core.Log.warn(msg) end



---@class NoteManager
local NoteManager = {}
core.NoteManager = NoteManager


---@param beat number
---@param line number
---@param layer number
---@param custom_data CustomData
---@return nil
function core.NoteManager.addBombNote(beat, line, layer, custom_data) end


---@param beat number
---@param line number
---@param layer number
---@param color number
---@param cut_direction number
---@param custom_data CustomData
---@return nil
function core.NoteManager.addColorNote(beat, line, layer, color, cut_direction, custom_data) end


---@param beat number
---@param duration number
---@param line number
---@param layer number
---@param width number
---@param height number
---@param custom_data CustomData
---@return nil
function core.NoteManager.addObstacle(beat, duration, line, layer, width, height, custom_data) end


---@param time number
---@return number
function core.NoteManager.timeToBeat(time) end



---@class Object
local Object = {}
core.Object = Object



---@class TaskScheduler
local TaskScheduler = {}
core.TaskScheduler = TaskScheduler


---@param task Action
---@return nil
function core.TaskScheduler.schedule(task) end



---@param self table
---@return nil
function core.TaskScheduler.dispose(self) end


---@class Transform
local Transform = {}
core.Transform = Transform



---@class TuringScriptManager
local TuringScriptManager = {}
core.TuringScriptManager = TuringScriptManager



---@class TuringerGameObject
local TuringerGameObject = {}
core.TuringerGameObject = TuringerGameObject



---@param self table
---@return boolean
function core.TuringerGameObject.activeGet(self) end


---@param self table
---@return boolean
function core.TuringerGameObject.activeInHierarchyGet(self) end


---@param self table
---@return boolean
function core.TuringerGameObject.activeSelfGet(self) end


---@param self table
---@param value boolean
---@return nil
function core.TuringerGameObject.activeSet(self, value) end


---@param self table
---@param component_type Type
---@return Component
function core.TuringerGameObject.addComponent(self, component_type) end


---@param self table
---@param method_name string
---@param options number
---@return nil
function core.TuringerGameObject.broadcastMessage(self, method_name, options) end


---@param self table
---@param tag string
---@return boolean
function core.TuringerGameObject.compareTag(self, tag) end


---@param self table
---@return GameObject
function core.TuringerGameObject.gameObjectGet(self) end


---@param self table
---@param index number
---@return Component
function core.TuringerGameObject.getComponentAtIndex(self, index) end


---@param self table
---@param cs_type string
---@return Component
function core.TuringerGameObject.getComponentByName(self, cs_type) end


---@param self table
---@param cs_type Type
---@return Component
function core.TuringerGameObject.getComponentByType(self, cs_type) end


---@param self table
---@return number
function core.TuringerGameObject.getComponentCount(self) end


---@param self table
---@param cs_type Type
---@param include_inactive boolean
---@return Component
function core.TuringerGameObject.getComponentInChildrenByType(self, cs_type, include_inactive) end


---@param self table
---@param cs_type Type
---@param include_inactive boolean
---@return Component
function core.TuringerGameObject.getComponentInParentByType(self, cs_type, include_inactive) end


---@param self table
---@param component Component
---@return number
function core.TuringerGameObject.getComponentIndex(self, component) end


---@param self table
---@return number
function core.TuringerGameObject.getInstanceId(self) end


---@param self table
---@return number
function core.TuringerGameObject.hideFlagsGet(self) end


---@param self table
---@param value number
---@return nil
function core.TuringerGameObject.hideFlagsSet(self, value) end


---@param self table
---@return boolean
function core.TuringerGameObject.isStaticGet(self) end


---@param self table
---@param value boolean
---@return nil
function core.TuringerGameObject.isStaticSet(self, value) end


---@param self table
---@return number
function core.TuringerGameObject.layerGet(self) end


---@param self table
---@param value number
---@return nil
function core.TuringerGameObject.layerSet(self, value) end


---@param self table
---@return string
function core.TuringerGameObject.nameGet(self) end


---@param self table
---@param value string
---@return nil
function core.TuringerGameObject.nameSet(self, value) end


---@param self table
---@return number
function core.TuringerGameObject.sceneCullingMaskGet(self) end


---@param self table
---@param method_name string
---@param options number
---@return nil
function core.TuringerGameObject.sendMessage(self, method_name, options) end


---@param self table
---@param method_name string
---@param options number
---@return nil
function core.TuringerGameObject.sendMessageUpwards(self, method_name, options) end


---@param self table
---@param value boolean
---@return nil
function core.TuringerGameObject.setActive(self, value) end


---@param self table
---@param state boolean
---@return nil
function core.TuringerGameObject.setActiveRecursively(self, state) end


---@param self table
---@return string
function core.TuringerGameObject.tagGet(self) end


---@param self table
---@param value string
---@return nil
function core.TuringerGameObject.tagSet(self, value) end


---@param self table
---@return TuringerTransform
function core.TuringerGameObject.transformGet(self) end


---@class TuringerGameObjectManager
local TuringerGameObjectManager = {}
core.TuringerGameObjectManager = TuringerGameObjectManager


---@param name string
---@return TuringerGameObject
function core.TuringerGameObjectManager.createObject(name) end


---@param listener TuringerGameObject
---@return nil
function core.TuringerGameObjectManager.destroyObject(listener) end


---@param name string
---@return TuringerGameObject
function core.TuringerGameObjectManager.find(name) end



---@param self table
---@return TuringerGameObjectManager
function core.TuringerGameObjectManager.instanceGet(self) end


---@class TuringerTransform
local TuringerTransform = {}
core.TuringerTransform = TuringerTransform



---@param self table
---@param method_name string
---@param parameter Object
---@param options number
---@return nil
function core.TuringerTransform.broadcastMessage(self, method_name, parameter, options) end


---@param self table
---@return number
function core.TuringerTransform.childCountGet(self) end


---@param self table
---@param tag string
---@return boolean
function core.TuringerTransform.compareTag(self, tag) end


---@param self table
---@return nil
function core.TuringerTransform.detachChildren(self) end


---@param self table
---@return table
function core.TuringerTransform.eulerAnglesGet(self) end


---@param self table
---@param value table
---@return nil
function core.TuringerTransform.eulerAnglesSet(self, value) end


---@param self table
---@param n string
---@return TuringerTransform
function core.TuringerTransform.find(self, n) end


---@param self table
---@param n string
---@return TuringerTransform
function core.TuringerTransform.findChild(self, n) end


---@param self table
---@return table
function core.TuringerTransform.forwardGet(self) end


---@param self table
---@param value table
---@return nil
function core.TuringerTransform.forwardSet(self, value) end


---@param self table
---@return TuringerGameObject
function core.TuringerTransform.gameObjectGet(self) end


---@param self table
---@param index number
---@return TuringerTransform
function core.TuringerTransform.getChild(self, index) end


---@param self table
---@return number
function core.TuringerTransform.getChildCount(self) end


---@param self table
---@param cs_type string
---@return Component
function core.TuringerTransform.getComponentByName(self, cs_type) end


---@param self table
---@param cs_type Type
---@return Component
function core.TuringerTransform.getComponentByType(self, cs_type) end


---@param self table
---@param t Type
---@param include_inactive boolean
---@return Component
function core.TuringerTransform.getComponentInChildrenByType(self, t, include_inactive) end


---@param self table
---@param t Type
---@param include_inactive boolean
---@return Component
function core.TuringerTransform.getComponentInParentByType(self, t, include_inactive) end


---@param self table
---@return number
function core.TuringerTransform.getComponentIndex(self) end


---@param self table
---@return IEnumerator
function core.TuringerTransform.getEnumerator(self) end


---@param self table
---@return number
function core.TuringerTransform.getInstanceId(self) end


---@param self table
---@return number
function core.TuringerTransform.getSiblingIndex(self) end


---@param self table
---@return boolean
function core.TuringerTransform.hasChangedGet(self) end


---@param self table
---@param value boolean
---@return nil
function core.TuringerTransform.hasChangedSet(self, value) end


---@param self table
---@return number
function core.TuringerTransform.hideFlagsGet(self) end


---@param self table
---@param value number
---@return nil
function core.TuringerTransform.hideFlagsSet(self, value) end


---@param self table
---@return number
function core.TuringerTransform.hierarchyCapacityGet(self) end


---@param self table
---@param value number
---@return nil
function core.TuringerTransform.hierarchyCapacitySet(self, value) end


---@param self table
---@return number
function core.TuringerTransform.hierarchyCountGet(self) end


---@param self table
---@param direction table
---@return table
function core.TuringerTransform.inverseTransformDirection(self, direction) end


---@param self table
---@param position table
---@return table
function core.TuringerTransform.inverseTransformPoint(self, position) end


---@param self table
---@param vector table
---@return table
function core.TuringerTransform.inverseTransformVector(self, vector) end


---@param self table
---@param parent TuringerTransform
---@return boolean
function core.TuringerTransform.isChildOf(self, parent) end


---@param self table
---@return table
function core.TuringerTransform.localEulerAnglesGet(self) end


---@param self table
---@param value table
---@return nil
function core.TuringerTransform.localEulerAnglesSet(self, value) end


---@param self table
---@return table
function core.TuringerTransform.localPositionGet(self) end


---@param self table
---@param value table
---@return nil
function core.TuringerTransform.localPositionSet(self, value) end


---@param self table
---@return table
function core.TuringerTransform.localRotationGet(self) end


---@param self table
---@param value table
---@return nil
function core.TuringerTransform.localRotationSet(self, value) end


---@param self table
---@return table
function core.TuringerTransform.localScaleGet(self) end


---@param self table
---@param value table
---@return nil
function core.TuringerTransform.localScaleSet(self, value) end


---@param self table
---@return table
function core.TuringerTransform.localToWorldMatrixGet(self) end


---@param self table
---@param target TuringerTransform
---@param world_up table
---@return nil
function core.TuringerTransform.lookAt(self, target, world_up) end


---@param self table
---@return table
function core.TuringerTransform.lossyScaleGet(self) end


---@param self table
---@return string
function core.TuringerTransform.nameGet(self) end


---@param self table
---@param value string
---@return nil
function core.TuringerTransform.nameSet(self, value) end


---@param self table
---@return TuringerTransform
function core.TuringerTransform.parentGet(self) end


---@param self table
---@param value TuringerTransform
---@return nil
function core.TuringerTransform.parentSet(self, value) end


---@param self table
---@return table
function core.TuringerTransform.positionGet(self) end


---@param self table
---@param value table
---@return nil
function core.TuringerTransform.positionSet(self, value) end


---@param self table
---@return table
function core.TuringerTransform.rightGet(self) end


---@param self table
---@param value table
---@return nil
function core.TuringerTransform.rightSet(self, value) end


---@param self table
---@return TuringerTransform
function core.TuringerTransform.rootGet(self) end


---@param self table
---@param eulers table
---@return nil
function core.TuringerTransform.rotate(self, eulers) end


---@param self table
---@param point table
---@param axis table
---@param angle number
---@return nil
function core.TuringerTransform.rotateAround(self, point, axis, angle) end


---@param self table
---@param axis table
---@param angle number
---@return nil
function core.TuringerTransform.rotateAroundLocal(self, axis, angle) end


---@param self table
---@param eulers table
---@param relative_to number
---@return nil
function core.TuringerTransform.rotateRelative(self, eulers, relative_to) end


---@param self table
---@return table
function core.TuringerTransform.rotationGet(self) end


---@param self table
---@param value table
---@return nil
function core.TuringerTransform.rotationSet(self, value) end


---@param self table
---@param method_name string
---@param value Object
---@param options number
---@return nil
function core.TuringerTransform.sendMessage(self, method_name, value, options) end


---@param self table
---@param method_name string
---@param value Object
---@param options number
---@return nil
function core.TuringerTransform.sendMessageUpwards(self, method_name, value, options) end


---@param self table
---@return nil
function core.TuringerTransform.setAsFirstSibling(self) end


---@param self table
---@return nil
function core.TuringerTransform.setAsLastSibling(self) end


---@param self table
---@param local_position table
---@param local_rotation table
---@return nil
function core.TuringerTransform.setLocalPositionAndRotation(self, local_position, local_rotation) end


---@param self table
---@param parent TuringerTransform
---@param world_position_stays boolean
---@return nil
function core.TuringerTransform.setParent(self, parent, world_position_stays) end


---@param self table
---@param position table
---@param rotation table
---@return nil
function core.TuringerTransform.setPositionAndRotation(self, position, rotation) end


---@param self table
---@param index number
---@return nil
function core.TuringerTransform.setSiblingIndex(self, index) end


---@param self table
---@return string
function core.TuringerTransform.tagGet(self) end


---@param self table
---@param value string
---@return nil
function core.TuringerTransform.tagSet(self, value) end


---@param self table
---@param direction table
---@return table
function core.TuringerTransform.transformDirection(self, direction) end


---@param self table
---@return Transform
function core.TuringerTransform.transformGet(self) end


---@param self table
---@param position table
---@return table
function core.TuringerTransform.transformPoint(self, position) end


---@param self table
---@param vector table
---@return table
function core.TuringerTransform.transformVector(self, vector) end


---@param self table
---@param translation table
---@param relative_to number
---@return nil
function core.TuringerTransform.translate(self, translation, relative_to) end


---@param self table
---@param translation table
---@param relative_to TuringerTransform
---@return nil
function core.TuringerTransform.translateRelative(self, translation, relative_to) end


---@param self table
---@return table
function core.TuringerTransform.upGet(self) end


---@param self table
---@param value table
---@return nil
function core.TuringerTransform.upSet(self, value) end


---@param self table
---@return table
function core.TuringerTransform.worldToLocalMatrixGet(self) end


---@class Type
local Type = {}
core.Type = Type



---@class Xr
local Xr = {}
core.Xr = Xr


---@param node_int number
---@return number
function core.Xr.getDeviceBatteryLevel(node_int) end


---@param node_int number
---@return number
function core.Xr.getDeviceGripValue(node_int) end


---@param node_int number
---@return string
function core.Xr.getDeviceName(node_int) end


---@param node_int number
---@return boolean
function core.Xr.getDevicePrimaryButtonState(node_int) end


---@param node_int number
---@return boolean
function core.Xr.getDeviceSecondaryButtonState(node_int) end


---@param node_int number
---@return table
function core.Xr.getDeviceThumbstick(node_int) end


---@param node_int number
---@return table
function core.Xr.getDeviceTouchpad(node_int) end


---@param node_int number
---@return number
function core.Xr.getDeviceTrackingState(node_int) end


---@param node_int number
---@return number
function core.Xr.getDeviceTriggerValue(node_int) end


---@param node_int number
---@return boolean
function core.Xr.isDeviceValid(node_int) end


---@param node_int number
---@param amplitude number
---@param duration number
---@return nil
function core.Xr.sendHapticImpulse(node_int, amplitude, duration) end


---@param node_int number
---@return nil
function core.Xr.stopHaptics(node_int) end



---@param self table
---@return TuringScriptManager
function core.Xr.ManagerGet(self) end


return core