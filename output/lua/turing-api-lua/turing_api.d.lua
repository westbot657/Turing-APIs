
--/// Generated Lua Api ///--
---@class TuringApi
local turing_api = {}

--// Functions //--

--// Classes //--

---@class GameObject
local GameObject = {}
turing_api.GameObject = GameObject



---@class Transform
local Transform = {}
turing_api.Transform = Transform



---@class TuringScriptManager
local TuringScriptManager = {}
turing_api.TuringScriptManager = TuringScriptManager



---@class Object
local Object = {}
turing_api.Object = Object



---@class List1
local List1 = {}
turing_api.List1 = List1



---@class List
local List = {}
turing_api.List = List



---@class Component
local Component = {}
turing_api.Component = Component



---@class Type
local Type = {}
turing_api.Type = Type



---@class IEnumerator
local IEnumerator = {}
turing_api.IEnumerator = IEnumerator



---@class Log
local Log = {}
turing_api.Log = Log


---@param msg string
---@return nil
function turing_api.Log.warn(msg) end


---@param msg string
---@return nil
function turing_api.Log.info(msg) end


---@param msg string
---@return nil
function turing_api.Log.debug(msg) end


---@param msg string
---@return nil
function turing_api.Log.critical(msg) end



---@class TuringerGameObject
local TuringerGameObject = {}
turing_api.TuringerGameObject = TuringerGameObject



---@param self table
---@param csType Type
---@param includeInactive boolean
---@return Component
function turing_api.TuringerGameObject.getComponentsInParentByType(self, cs_type, include_inactive) end


---@param self table
---@param methodName string
---@param options number
---@return nil
function turing_api.TuringerGameObject.sendMessage(self, method_name, options) end


---@param self table
---@param csType Type
---@param includeInactive boolean
---@return Component
function turing_api.TuringerGameObject.getComponentInParentByType(self, cs_type, include_inactive) end


---@param self table
---@return boolean
function turing_api.TuringerGameObject.isStaticGet(self) end


---@param self table
---@return TuringerTransform
function turing_api.TuringerGameObject.transformGet(self) end


---@param self table
---@param csType Type
---@param includeInactive boolean
---@return Component
function turing_api.TuringerGameObject.getComponentInChildrenByType(self, cs_type, include_inactive) end


---@param self table
---@param csType Type
---@return Component
function turing_api.TuringerGameObject.getComponentsByType(self, cs_type) end


---@param self table
---@param value boolean
---@return nil
function turing_api.TuringerGameObject.activeSet(self, value) end


---@param self table
---@param methodName string
---@param options number
---@return nil
function turing_api.TuringerGameObject.broadcastMessage(self, method_name, options) end


---@param self table
---@return GameObject
function turing_api.TuringerGameObject.gameObjectGet(self) end


---@param self table
---@param value boolean
---@return nil
function turing_api.TuringerGameObject.isStaticSet(self, value) end


---@param self table
---@param componentType Type
---@return Component
function turing_api.TuringerGameObject.addComponent(self, component_type) end


---@param self table
---@param value number
---@return nil
function turing_api.TuringerGameObject.hideFlagsSet(self, value) end


---@param self table
---@param methodName string
---@param options number
---@return nil
function turing_api.TuringerGameObject.sendMessageUpwards(self, method_name, options) end


---@param self table
---@param tag string
---@return boolean
function turing_api.TuringerGameObject.compareTag(self, tag) end


---@param self table
---@return number
function turing_api.TuringerGameObject.hideFlagsGet(self) end


---@param self table
---@param value string
---@return nil
function turing_api.TuringerGameObject.tagSet(self, value) end


---@param self table
---@return number
function turing_api.TuringerGameObject.getInstanceId(self) end


---@param self table
---@return number
function turing_api.TuringerGameObject.layerGet(self) end


---@param self table
---@param csType Type
---@param includeInactive boolean
---@return Component
function turing_api.TuringerGameObject.getComponentsInChildrenByType(self, cs_type, include_inactive) end


---@param self table
---@param value number
---@return nil
function turing_api.TuringerGameObject.layerSet(self, value) end


---@param self table
---@param state boolean
---@return nil
function turing_api.TuringerGameObject.setActiveRecursively(self, state) end


---@param self table
---@param component Component
---@return number
function turing_api.TuringerGameObject.getComponentIndex(self, component) end


---@param self table
---@return number
function turing_api.TuringerGameObject.getComponentCount(self) end


---@param self table
---@param index number
---@return Component
function turing_api.TuringerGameObject.getComponentAtIndex(self, index) end


---@param self table
---@return string
function turing_api.TuringerGameObject.tagGet(self) end


---@param self table
---@return boolean
function turing_api.TuringerGameObject.activeSelfGet(self) end


---@param self table
---@return string
function turing_api.TuringerGameObject.nameGet(self) end


---@param self table
---@param csType Type
---@return Component
function turing_api.TuringerGameObject.getComponentByType(self, cs_type) end


---@param self table
---@return boolean
function turing_api.TuringerGameObject.activeInHierarchyGet(self) end


---@param self table
---@param value boolean
---@return nil
function turing_api.TuringerGameObject.setActive(self, value) end


---@param self table
---@return boolean
function turing_api.TuringerGameObject.activeGet(self) end


---@param self table
---@param csType string
---@return Component
function turing_api.TuringerGameObject.getComponentByName(self, cs_type) end


---@param self table
---@param value string
---@return nil
function turing_api.TuringerGameObject.nameSet(self, value) end


---@param self table
---@return number
function turing_api.TuringerGameObject.sceneCullingMaskGet(self) end


---@class TuringerGameObjectManager
local TuringerGameObjectManager = {}
turing_api.TuringerGameObjectManager = TuringerGameObjectManager


---@param name string
---@return TuringerGameObject
function turing_api.TuringerGameObjectManager.createObject(name) end


---@param name string
---@return TuringerGameObject
function turing_api.TuringerGameObjectManager.find(name) end


---@param listener TuringerGameObject
---@return nil
function turing_api.TuringerGameObjectManager.destroyObject(listener) end



---@param self table
---@return TuringerGameObjectManager
function turing_api.TuringerGameObjectManager.instanceGet(self) end


---@class CustomData
local CustomData = {}
turing_api.CustomData = CustomData


---@return CustomData
function turing_api.CustomData.create() end


---@return List
function turing_api.CustomData.listCreate() end


---@param customData CustomData
---@param key string
---@param value string
---@return nil
function turing_api.CustomData.setString(custom_data, key, value) end


---@param customData CustomData
---@param key string
---@param value CustomData
---@return nil
function turing_api.CustomData.setCustomData(custom_data, key, value) end


---@param list List1
---@param value string
---@return nil
function turing_api.CustomData.listAddString(list, value) end


---@param customData CustomData
---@param key string
---@param value List1
---@return nil
function turing_api.CustomData.setCustomDataList(custom_data, key, value) end


---@param customData CustomData
---@param key string
---@param value number
---@return nil
function turing_api.CustomData.setFloat(custom_data, key, value) end


---@param list List1
---@param value number
---@return nil
function turing_api.CustomData.listAddInt(list, value) end


---@param list List1
---@param value boolean
---@return nil
function turing_api.CustomData.listAddBool(list, value) end


---@param customData CustomData
---@param key string
---@param value number
---@return nil
function turing_api.CustomData.setInt(custom_data, key, value) end


---@param customData CustomData
---@param key string
---@param value boolean
---@return nil
function turing_api.CustomData.setBool(custom_data, key, value) end


---@param list List1
---@param value List1
---@return nil
function turing_api.CustomData.listAddCustomDataList(list, value) end


---@param list List1
---@param value number
---@return nil
function turing_api.CustomData.listAddFloat(list, value) end


---@param list List1
---@param value CustomData
---@return nil
function turing_api.CustomData.listAddCustomData(list, value) end



---@class GcHelper
local GcHelper = {}
turing_api.GcHelper = GcHelper


---@return GcHelper
function turing_api.GcHelper.create() end



---@param self table
---@return nil
function turing_api.GcHelper.wasmGarbageCollect(self) end


---@param self table
---@return nil
function turing_api.GcHelper.dispose(self) end


---@param self table
---@return nil
function turing_api.GcHelper.invalidateAllHandles(self) end


---@class NoteManager
local NoteManager = {}
turing_api.NoteManager = NoteManager


---@param beat number
---@param duration number
---@param line number
---@param layer number
---@param width number
---@param height number
---@param customData CustomData
---@return nil
function turing_api.NoteManager.addObstacle(beat, duration, line, layer, width, height, custom_data) end


---@param beat number
---@param line number
---@param layer number
---@param color number
---@param cutDirection number
---@param customData CustomData
---@return nil
function turing_api.NoteManager.addColorNote(beat, line, layer, color, cut_direction, custom_data) end


---@param time number
---@return number
function turing_api.NoteManager.timeToBeat(time) end


---@param beat number
---@param line number
---@param layer number
---@param customData CustomData
---@return nil
function turing_api.NoteManager.addBombNote(beat, line, layer, custom_data) end



---@class Xr
local Xr = {}
turing_api.Xr = Xr


---@param nodeInt number
---@return number
function turing_api.Xr.getDeviceTrackingState(node_int) end


---@param nodeInt number
---@return string
function turing_api.Xr.getDeviceName(node_int) end


---@param nodeInt number
---@return boolean
function turing_api.Xr.getDeviceSecondaryButtonState(node_int) end


---@param nodeInt number
---@return boolean
function turing_api.Xr.getDevicePrimaryButtonState(node_int) end


---@param nodeInt number
---@param amplitude number
---@param duration number
---@return nil
function turing_api.Xr.sendHapticImpulse(node_int, amplitude, duration) end


---@param nodeInt number
---@return boolean
function turing_api.Xr.isDeviceValid(node_int) end


---@param nodeInt number
---@return number
function turing_api.Xr.getDeviceBatteryLevel(node_int) end


---@param nodeInt number
---@return table
function turing_api.Xr.getDeviceTouchpad(node_int) end


---@param nodeInt number
---@return number
function turing_api.Xr.getDeviceGripValue(node_int) end


---@param nodeInt number
---@return number
function turing_api.Xr.getDeviceTriggerValue(node_int) end


---@param nodeInt number
---@return nil
function turing_api.Xr.stopHaptics(node_int) end


---@param nodeInt number
---@return table
function turing_api.Xr.getDeviceThumbstick(node_int) end



---@param self table
---@return TuringScriptManager
function turing_api.Xr.ManagerGet(self) end


---@class TuringerTransform
local TuringerTransform = {}
turing_api.TuringerTransform = TuringerTransform



---@param self table
---@param csType Type
---@return Component
function turing_api.TuringerTransform.getComponentByType(self, cs_type) end


---@param self table
---@param target TuringerTransform
---@param worldUp table
---@return nil
function turing_api.TuringerTransform.lookAt(self, target, world_up) end


---@param self table
---@return number
function turing_api.TuringerTransform.getInstanceId(self) end


---@param self table
---@return string
function turing_api.TuringerTransform.tagGet(self) end


---@param self table
---@return table
function turing_api.TuringerTransform.localEulerAnglesGet(self) end


---@param self table
---@return table
function turing_api.TuringerTransform.rotationGet(self) end


---@param self table
---@return table
function turing_api.TuringerTransform.worldToLocalMatrixGet(self) end


---@param self table
---@return number
function turing_api.TuringerTransform.hierarchyCountGet(self) end


---@param self table
---@param t Type
---@param includeInactive boolean
---@return Component
function turing_api.TuringerTransform.getComponentsInChildrenByType(self, t, include_inactive) end


---@param self table
---@param value string
---@return nil
function turing_api.TuringerTransform.nameSet(self, value) end


---@param self table
---@return table
function turing_api.TuringerTransform.localRotationGet(self) end


---@param self table
---@return nil
function turing_api.TuringerTransform.detachChildren(self) end


---@param self table
---@param position table
---@return table
function turing_api.TuringerTransform.inverseTransformPoint(self, position) end


---@param self table
---@param t Type
---@param includeInactive boolean
---@return Component
function turing_api.TuringerTransform.getComponentInChildrenByType(self, t, include_inactive) end


---@param self table
---@return Transform
function turing_api.TuringerTransform.transformGet(self) end


---@param self table
---@return table
function turing_api.TuringerTransform.lossyScaleGet(self) end


---@param self table
---@return TuringerTransform
function turing_api.TuringerTransform.rootGet(self) end


---@param self table
---@param csType Type
---@return Component
function turing_api.TuringerTransform.getComponentsByType(self, cs_type) end


---@param self table
---@return IEnumerator
function turing_api.TuringerTransform.getEnumerator(self) end


---@param self table
---@param value table
---@return nil
function turing_api.TuringerTransform.localScaleSet(self, value) end


---@param self table
---@return number
function turing_api.TuringerTransform.childCountGet(self) end


---@param self table
---@param value TuringerTransform
---@return nil
function turing_api.TuringerTransform.parentSet(self, value) end


---@param self table
---@param index number
---@return TuringerTransform
function turing_api.TuringerTransform.getChild(self, index) end


---@param self table
---@param direction table
---@return table
function turing_api.TuringerTransform.transformDirection(self, direction) end


---@param self table
---@param value boolean
---@return nil
function turing_api.TuringerTransform.hasChangedSet(self, value) end


---@param self table
---@param methodName string
---@param value Object
---@param options number
---@return nil
function turing_api.TuringerTransform.sendMessageUpwards(self, method_name, value, options) end


---@param self table
---@param n string
---@return TuringerTransform
function turing_api.TuringerTransform.findChild(self, n) end


---@param self table
---@param t Type
---@param includeInactive boolean
---@return Component
function turing_api.TuringerTransform.getComponentsInParentByType(self, t, include_inactive) end


---@param self table
---@param eulers table
---@return nil
function turing_api.TuringerTransform.rotate(self, eulers) end


---@param self table
---@return boolean
function turing_api.TuringerTransform.hasChangedGet(self) end


---@param self table
---@return table
function turing_api.TuringerTransform.localPositionGet(self) end


---@param self table
---@param translation table
---@param relativeTo TuringerTransform
---@return nil
function turing_api.TuringerTransform.translateRelative(self, translation, relative_to) end


---@param self table
---@param value table
---@return nil
function turing_api.TuringerTransform.localEulerAnglesSet(self, value) end


---@param self table
---@param localPosition table
---@param localRotation table
---@return nil
function turing_api.TuringerTransform.setLocalPositionAndRotation(self, local_position, local_rotation) end


---@param self table
---@return table
function turing_api.TuringerTransform.forwardGet(self) end


---@param self table
---@return number
function turing_api.TuringerTransform.getSiblingIndex(self) end


---@param self table
---@param t Type
---@param includeInactive boolean
---@return Component
function turing_api.TuringerTransform.getComponentInParentByType(self, t, include_inactive) end


---@param self table
---@return table
function turing_api.TuringerTransform.upGet(self) end


---@param self table
---@return number
function turing_api.TuringerTransform.getComponentIndex(self) end


---@param self table
---@param axis table
---@param angle number
---@return nil
function turing_api.TuringerTransform.rotateAroundLocal(self, axis, angle) end


---@param self table
---@param translation table
---@param relativeTo number
---@return nil
function turing_api.TuringerTransform.translate(self, translation, relative_to) end


---@param self table
---@param methodName string
---@param parameter Object
---@param options number
---@return nil
function turing_api.TuringerTransform.broadcastMessage(self, method_name, parameter, options) end


---@param self table
---@param value table
---@return nil
function turing_api.TuringerTransform.eulerAnglesSet(self, value) end


---@param self table
---@param methodName string
---@param value Object
---@param options number
---@return nil
function turing_api.TuringerTransform.sendMessage(self, method_name, value, options) end


---@param self table
---@return TuringerTransform
function turing_api.TuringerTransform.parentGet(self) end


---@param self table
---@return table
function turing_api.TuringerTransform.localToWorldMatrixGet(self) end


---@param self table
---@param csType string
---@return Component
function turing_api.TuringerTransform.getComponentByName(self, cs_type) end


---@param self table
---@param parent TuringerTransform
---@param worldPositionStays boolean
---@return nil
function turing_api.TuringerTransform.setParent(self, parent, world_position_stays) end


---@param self table
---@param point table
---@param axis table
---@param angle number
---@return nil
function turing_api.TuringerTransform.rotateAround(self, point, axis, angle) end


---@param self table
---@param value number
---@return nil
function turing_api.TuringerTransform.hierarchyCapacitySet(self, value) end


---@param self table
---@param value table
---@return nil
function turing_api.TuringerTransform.upSet(self, value) end


---@param self table
---@param direction table
---@return table
function turing_api.TuringerTransform.inverseTransformDirection(self, direction) end


---@param self table
---@return table
function turing_api.TuringerTransform.localScaleGet(self) end


---@param self table
---@param vector table
---@return table
function turing_api.TuringerTransform.transformVector(self, vector) end


---@param self table
---@param position table
---@return table
function turing_api.TuringerTransform.transformPoint(self, position) end


---@param self table
---@return table
function turing_api.TuringerTransform.eulerAnglesGet(self) end


---@param self table
---@param parent TuringerTransform
---@return boolean
function turing_api.TuringerTransform.isChildOf(self, parent) end


---@param self table
---@param value table
---@return nil
function turing_api.TuringerTransform.rightSet(self, value) end


---@param self table
---@return number
function turing_api.TuringerTransform.getChildCount(self) end


---@param self table
---@return number
function turing_api.TuringerTransform.hideFlagsGet(self) end


---@param self table
---@param eulers table
---@param relativeTo number
---@return nil
function turing_api.TuringerTransform.rotateRelative(self, eulers, relative_to) end


---@param self table
---@param value table
---@return nil
function turing_api.TuringerTransform.rotationSet(self, value) end


---@param self table
---@return TuringerGameObject
function turing_api.TuringerTransform.gameObjectGet(self) end


---@param self table
---@return number
function turing_api.TuringerTransform.hierarchyCapacityGet(self) end


---@param self table
---@return nil
function turing_api.TuringerTransform.setAsFirstSibling(self) end


---@param self table
---@return table
function turing_api.TuringerTransform.rightGet(self) end


---@param self table
---@param value table
---@return nil
function turing_api.TuringerTransform.localPositionSet(self, value) end


---@param self table
---@param value table
---@return nil
function turing_api.TuringerTransform.forwardSet(self, value) end


---@param self table
---@return string
function turing_api.TuringerTransform.nameGet(self) end


---@param self table
---@param tag string
---@return boolean
function turing_api.TuringerTransform.compareTag(self, tag) end


---@param self table
---@return nil
function turing_api.TuringerTransform.setAsLastSibling(self) end


---@param self table
---@return table
function turing_api.TuringerTransform.positionGet(self) end


---@param self table
---@param index number
---@return nil
function turing_api.TuringerTransform.setSiblingIndex(self, index) end


---@param self table
---@param value table
---@return nil
function turing_api.TuringerTransform.positionSet(self, value) end


---@param self table
---@param value number
---@return nil
function turing_api.TuringerTransform.hideFlagsSet(self, value) end


---@param self table
---@param position table
---@param rotation table
---@return nil
function turing_api.TuringerTransform.setPositionAndRotation(self, position, rotation) end


---@param self table
---@param n string
---@return TuringerTransform
function turing_api.TuringerTransform.find(self, n) end


---@param self table
---@param value string
---@return nil
function turing_api.TuringerTransform.tagSet(self, value) end


---@param self table
---@param value table
---@return nil
function turing_api.TuringerTransform.localRotationSet(self, value) end


---@param self table
---@param vector table
---@return table
function turing_api.TuringerTransform.inverseTransformVector(self, vector) end


return turing_api