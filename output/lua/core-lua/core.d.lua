

--/// Generated Lua API ///--
---@class Core
local core = {}

--// Functions //--


--// Classes //--

---@class Action
local Action = {}
core.Action = Action



---@class Action1
local Action1 = {}
core.Action1 = Action1



---@class BeatmapDataItem
local BeatmapDataItem = {}
core.BeatmapDataItem = BeatmapDataItem



---@class Component
local Component = {}
core.Component = Component



---@class CustomData
local CustomData = {}
core.CustomData = CustomData


---@return CustomData
function core.CustomData.create() end


---@param json string
---@return CustomData
function core.CustomData.fromJson(json) end


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


---@param custom_data CustomData
---@param pretty boolean
---@return string
function core.CustomData.toJson(custom_data, pretty) end



---@class CustomEventData
local CustomEventData = {}
core.CustomEventData = CustomEventData



---@param self table
---@return CustomData
function core.CustomEventData.customDataGet(self) end


---@param self table
---@return string
function core.CustomEventData.eventTypeGet(self) end


---@param self table
---@return BeatmapDataItem
function core.CustomEventData.getCopy(self) end


---@param self table
---@return Version
function core.CustomEventData.versionGet(self) end


---@class CustomNoteData
local CustomNoteData = {}
core.CustomNoteData = CustomNoteData


---@param time number
---@param beat number
---@param rotation number
---@param line_index number
---@return CustomNoteData
function core.CustomNoteData.createCustomBasicNoteData(time, beat, rotation, line_index) end


---@param time number
---@param beat number
---@param rotation number
---@param line_index number
---@return CustomNoteData
function core.CustomNoteData.createCustomBombNoteData(time, beat, rotation, line_index) end


---@param time number
---@param beat number
---@param rotation number
---@param line_index number
---@return CustomNoteData
function core.CustomNoteData.createCustomBurstSliderNoteData(time, beat, rotation, line_index) end



---@param self table
---@return CustomData
function core.CustomNoteData.customDataGet(self) end


---@param self table
---@return BeatmapDataItem
function core.CustomNoteData.getCopy(self) end


---@param self table
---@return Version
function core.CustomNoteData.versionGet(self) end


---@class CustomObstacleData
local CustomObstacleData = {}
core.CustomObstacleData = CustomObstacleData



---@param self table
---@return CustomData
function core.CustomObstacleData.customDataGet(self) end


---@param self table
---@return BeatmapDataItem
function core.CustomObstacleData.getCopy(self) end


---@param self table
---@return Version
function core.CustomObstacleData.versionGet(self) end


---@class GcHelper
local GcHelper = {}
core.GcHelper = GcHelper



---@class GameObject
local GameObject = {}
core.GameObject = GameObject



---@class GcHelper
local GcHelper = {}
core.GcHelper = GcHelper


---@return GCHelper
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


---@class IAudioTimeSource
local IAudioTimeSource = {}
core.IAudioTimeSource = IAudioTimeSource



---@class IEnumerator
local IEnumerator = {}
core.IEnumerator = IEnumerator



---@class IVariableMovementDataProvider
local IVariableMovementDataProvider = {}
core.IVariableMovementDataProvider = IVariableMovementDataProvider



---@class Int32
local Int32 = {}
core.Int32 = Int32



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



---@class Mesh
local Mesh = {}
core.Mesh = Mesh



---@class NoteControllerBase
local NoteControllerBase = {}
core.NoteControllerBase = NoteControllerBase



---@class NoteFloorMovement
local NoteFloorMovement = {}
core.NoteFloorMovement = NoteFloorMovement



---@param self table
---@return IAudioTimeSource
function core.NoteFloorMovement.AudioTimeSyncControllerGet(self) end


---@param self table
---@return number
function core.NoteFloorMovement.BeatTimeGet(self) end


---@param self table
---@param value number
---@return nil
function core.NoteFloorMovement.BeatTimeSet(self, value) end


---@param self table
---@return table
function core.NoteFloorMovement.InverseWorldRotationGet(self) end


---@param self table
---@param value table
---@return nil
function core.NoteFloorMovement.InverseWorldRotationSet(self, value) end


---@param self table
---@return table
function core.NoteFloorMovement.LocalPositionGet(self) end


---@param self table
---@param value table
---@return nil
function core.NoteFloorMovement.LocalPositionSet(self, value) end


---@param self table
---@return table
function core.NoteFloorMovement.MoveEndOffsetGet(self) end


---@param self table
---@param value table
---@return nil
function core.NoteFloorMovement.MoveEndOffsetSet(self, value) end


---@param self table
---@return table
function core.NoteFloorMovement.MoveStartOffsetGet(self) end


---@param self table
---@param value table
---@return nil
function core.NoteFloorMovement.MoveStartOffsetSet(self, value) end


---@param self table
---@return PlayerTransforms
function core.NoteFloorMovement.PlayerTransformsGet(self) end


---@param self table
---@return Transform
function core.NoteFloorMovement.RotatedObjectGet(self) end


---@param self table
---@param value Transform
---@return nil
function core.NoteFloorMovement.RotatedObjectSet(self, value) end


---@param self table
---@return IVariableMovementDataProvider
function core.NoteFloorMovement.VariableMovementDataProviderGet(self) end


---@param self table
---@return table
function core.NoteFloorMovement.WorldRotationGet(self) end


---@param self table
---@param value table
---@return nil
function core.NoteFloorMovement.WorldRotationSet(self, value) end


---@param self table
---@return number
function core.NoteFloorMovement.distanceToPlayerGet(self) end


---@param self table
---@return table
function core.NoteFloorMovement.endPosGet(self) end


---@param self table
---@param world_rotation number
---@param beat_time number
---@param move_start_offset table
---@param move_end_offset table
---@return nil
function core.NoteFloorMovement.initFloor(self, world_rotation, beat_time, move_start_offset, move_end_offset) end


---@param self table
---@return table
function core.NoteFloorMovement.inverseWorldRotationGet(self) end


---@param self table
---@return table
function core.NoteFloorMovement.localPositionGet(self) end


---@param self table
---@return table
function core.NoteFloorMovement.manualUpdate(self) end


---@param self table
---@return number
function core.NoteFloorMovement.noteTimeGet(self) end


---@param self table
---@return table
function core.NoteFloorMovement.setToStart(self) end


---@param self table
---@return boolean
function core.NoteFloorMovement.shouldMove(self) end


---@param self table
---@return table
function core.NoteFloorMovement.worldRotationGet(self) end


---@class NoteJump
local NoteJump = {}
core.NoteJump = NoteJump


---@return number
function core.NoteJump.kMissedTimeOffsetGet() end



---@param self table
---@return IAudioTimeSource
function core.NoteJump.AudioTimeSyncControllerGet(self) end


---@param self table
---@return number
function core.NoteJump.EndDistanceOffsetGet(self) end


---@param self table
---@param value number
---@return nil
function core.NoteJump.EndDistanceOffsetSet(self, value) end


---@param self table
---@return table
function core.NoteJump.EndOffsetGet(self) end


---@param self table
---@param value table
---@return nil
function core.NoteJump.EndOffsetSet(self, value) end


---@param self table
---@return table
function core.NoteJump.EndPosGet(self) end


---@param self table
---@param value table
---@return nil
function core.NoteJump.EndPosSet(self, value) end


---@param self table
---@return table
function core.NoteJump.EndRotationGet(self) end


---@param self table
---@param value table
---@return nil
function core.NoteJump.EndRotationSet(self, value) end


---@param self table
---@return number
function core.NoteJump.GravityBaseGet(self) end


---@param self table
---@param value number
---@return nil
function core.NoteJump.GravityBaseSet(self, value) end


---@param self table
---@return number
function core.NoteJump.GravityGet(self) end


---@param self table
---@param value number
---@return nil
function core.NoteJump.GravitySet(self, value) end


---@param self table
---@return number
function core.NoteJump.HalfJumpDurationGet(self) end


---@param self table
---@param value number
---@return nil
function core.NoteJump.HalfJumpDurationSet(self, value) end


---@param self table
---@return boolean
function core.NoteJump.HalfJumpMarkReportedGet(self) end


---@param self table
---@param value boolean
---@return nil
function core.NoteJump.HalfJumpMarkReportedSet(self, value) end


---@param self table
---@return table
function core.NoteJump.InverseWorldRotationGet(self) end


---@param self table
---@param value table
---@return nil
function core.NoteJump.InverseWorldRotationSet(self, value) end


---@param self table
---@return number
function core.NoteJump.JumpDurationGet(self) end


---@param self table
---@param value number
---@return nil
function core.NoteJump.JumpDurationSet(self, value) end


---@param self table
---@return boolean
function core.NoteJump.JumpStartedReportedGet(self) end


---@param self table
---@param value boolean
---@return nil
function core.NoteJump.JumpStartedReportedSet(self, value) end


---@param self table
---@return table
function core.NoteJump.LocalPositionGet(self) end


---@param self table
---@param value table
---@return nil
function core.NoteJump.LocalPositionSet(self, value) end


---@param self table
---@return table
function core.NoteJump.MiddleRotationGet(self) end


---@param self table
---@param value table
---@return nil
function core.NoteJump.MiddleRotationSet(self, value) end


---@param self table
---@return boolean
function core.NoteJump.MissedMarkReportedGet(self) end


---@param self table
---@param value boolean
---@return nil
function core.NoteJump.MissedMarkReportedSet(self, value) end


---@param self table
---@return number
function core.NoteJump.MissedTimeGet(self) end


---@param self table
---@param value number
---@return nil
function core.NoteJump.MissedTimeSet(self, value) end


---@param self table
---@return number
function core.NoteJump.NoteTimeGet(self) end


---@param self table
---@param value number
---@return nil
function core.NoteJump.NoteTimeSet(self, value) end


---@param self table
---@return PlayerSpaceConvertor
function core.NoteJump.PlayerSpaceConvertorGet(self) end


---@param self table
---@return PlayerTransforms
function core.NoteJump.PlayerTransformsGet(self) end


---@param self table
---@return boolean
function core.NoteJump.RotateTowardsPlayerGet(self) end


---@param self table
---@param value boolean
---@return nil
function core.NoteJump.RotateTowardsPlayerSet(self, value) end


---@param self table
---@return Transform
function core.NoteJump.RotatedObjectGet(self) end


---@param self table
---@param value Transform
---@return nil
function core.NoteJump.RotatedObjectSet(self, value) end


---@param self table
---@return table
function core.NoteJump.StartOffsetGet(self) end


---@param self table
---@param value table
---@return nil
function core.NoteJump.StartOffsetSet(self, value) end


---@param self table
---@return table
function core.NoteJump.StartPosGet(self) end


---@param self table
---@param value table
---@return nil
function core.NoteJump.StartPosSet(self, value) end


---@param self table
---@return table
function core.NoteJump.StartRotationGet(self) end


---@param self table
---@param value table
---@return nil
function core.NoteJump.StartRotationSet(self, value) end


---@param self table
---@return boolean
function core.NoteJump.ThreeQuartersMarkReportedGet(self) end


---@param self table
---@param value boolean
---@return nil
function core.NoteJump.ThreeQuartersMarkReportedSet(self, value) end


---@param self table
---@return IVariableMovementDataProvider
function core.NoteJump.VariableMovementDataProviderGet(self) end


---@param self table
---@return table
function core.NoteJump.WorldRotationGet(self) end


---@param self table
---@param value table
---@return nil
function core.NoteJump.WorldRotationSet(self, value) end


---@param self table
---@return number
function core.NoteJump.YAvoidanceDownGet(self) end


---@param self table
---@param value number
---@return nil
function core.NoteJump.YAvoidanceDownSet(self, value) end


---@param self table
---@return number
function core.NoteJump.YAvoidanceGet(self) end


---@param self table
---@param value number
---@return nil
function core.NoteJump.YAvoidanceSet(self, value) end


---@param self table
---@return number
function core.NoteJump.YAvoidanceUpGet(self) end


---@param self table
---@param value number
---@return nil
function core.NoteJump.YAvoidanceUpSet(self, value) end


---@param self table
---@param value Action
---@return nil
function core.NoteJump.addNoteJumpDidFinishEvent(self, value) end


---@param self table
---@param value Action
---@return nil
function core.NoteJump.addNoteJumpDidPassHalfEvent(self, value) end


---@param self table
---@param value Action
---@return nil
function core.NoteJump.addNoteJumpDidPassMissedMarkerEvent(self, value) end


---@param self table
---@param value Action1
---@return nil
function core.NoteJump.addNoteJumpDidPassThreeQuartersEvent(self, value) end


---@param self table
---@param value Action
---@return nil
function core.NoteJump.addNoteJumpDidStartEvent(self, value) end


---@param self table
---@param value Action1
---@return nil
function core.NoteJump.addNoteJumpDidUpdateProgressEvent(self, value) end


---@param self table
---@return table
function core.NoteJump.beatPosGet(self) end


---@param self table
---@return number
function core.NoteJump.distanceToPlayerGet(self) end


---@param self table
---@param note_time number
---@param world_rotation number
---@param move_end_offset table
---@param jump_end_offset table
---@param gravity_base number
---@param flip_y_side number
---@param end_rotation number
---@param rotate_towards_player boolean
---@param use_random_rotation boolean
---@return nil
function core.NoteJump.initNote(self, note_time, world_rotation, move_end_offset, jump_end_offset, gravity_base, flip_y_side, end_rotation, rotate_towards_player, use_random_rotation) end


---@param self table
---@return table
function core.NoteJump.localPositionGet(self) end


---@param self table
---@return table
function core.NoteJump.manualUpdate(self) end


---@param self table
---@return table
function core.NoteJump.moveVecGet(self) end


---@param self table
---@return number
function core.NoteJump.noteTimeGet(self) end


---@param self table
---@param value Action
---@return nil
function core.NoteJump.removeNoteJumpDidFinishEvent(self, value) end


---@param self table
---@param value Action
---@return nil
function core.NoteJump.removeNoteJumpDidPassHalfEvent(self, value) end


---@param self table
---@param value Action
---@return nil
function core.NoteJump.removeNoteJumpDidPassMissedMarkerEvent(self, value) end


---@param self table
---@param value Action1
---@return nil
function core.NoteJump.removeNoteJumpDidPassThreeQuartersEvent(self, value) end


---@param self table
---@param value Action
---@return nil
function core.NoteJump.removeNoteJumpDidStartEvent(self, value) end


---@param self table
---@param value Action1
---@return nil
function core.NoteJump.removeNoteJumpDidUpdateProgressEvent(self, value) end


---@class NoteManager
local NoteManager = {}
core.NoteManager = NoteManager


---@param beat number
---@param line number
---@param layer number
---@param custom_data CustomData
---@return CustomNoteData
function core.NoteManager.addBombNote(beat, line, layer, custom_data) end


---@param beat number
---@param line number
---@param layer number
---@param color number
---@param cut_direction number
---@param custom_data CustomData
---@return CustomNoteData
function core.NoteManager.addColorNote(beat, line, layer, color, cut_direction, custom_data) end


---@param beat number
---@param duration number
---@param line number
---@param layer number
---@param width number
---@param height number
---@param custom_data CustomData
---@return CustomObstacleData
function core.NoteManager.addObstacle(beat, duration, line, layer, width, height, custom_data) end


---@param n number
---@return NoteControllerBase
function core.NoteManager.getNoteController(n) end


---@param n CustomNoteData
---@return NoteControllerBase
function core.NoteManager.getNoteControllerFromCustom(n) end


---@param id number
---@return CustomEventData
function core.NoteManager.getNthEvent(id) end


---@param id number
---@return CustomNoteData
function core.NoteManager.getNthNote(id) end


---@param id number
---@return BeatmapDataItem
function core.NoteManager.getNthObject(id) end


---@param id number
---@return CustomObstacleData
function core.NoteManager.getNthObstacle(id) end


---@param n number
---@return ObstacleControllerBase
function core.NoteManager.getObstacleController(n) end


---@param n CustomObstacleData
---@return ObstacleController
function core.NoteManager.getObstacleControllerFromCustom(n) end


---@param time number
---@return number
function core.NoteManager.timeToBeat(time) end



---@class Object
local Object = {}
core.Object = Object



---@class ObstacleController
local ObstacleController = {}
core.ObstacleController = ObstacleController



---@class ObstacleControllerBase
local ObstacleControllerBase = {}
core.ObstacleControllerBase = ObstacleControllerBase



---@class PlayerSpaceConvertor
local PlayerSpaceConvertor = {}
core.PlayerSpaceConvertor = PlayerSpaceConvertor



---@class PlayerTransforms
local PlayerTransforms = {}
core.PlayerTransforms = PlayerTransforms



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



---@class TuringMesh
local TuringMesh = {}
core.TuringMesh = TuringMesh



---@param self table
---@return Mesh
function core.TuringMesh.MeshGet(self) end


---@param self table
---@param value Mesh
---@return nil
function core.TuringMesh.MeshSet(self, value) end


---@param self table
---@return nil
function core.TuringMesh.clear(self) end


---@param self table
---@return number
function core.TuringMesh.getBoundsMaxX(self) end


---@param self table
---@return number
function core.TuringMesh.getBoundsMaxY(self) end


---@param self table
---@return number
function core.TuringMesh.getBoundsMaxZ(self) end


---@param self table
---@return number
function core.TuringMesh.getBoundsMinX(self) end


---@param self table
---@return number
function core.TuringMesh.getBoundsMinY(self) end


---@param self table
---@return number
function core.TuringMesh.getBoundsMinZ(self) end


---@param self table
---@return number
function core.TuringMesh.getInstanceId(self) end


---@param self table
---@param channel number
---@return table
function core.TuringMesh.getUVs(self, channel) end


---@param self table
---@return table
function core.TuringMesh.getVertices(self) end


---@param self table
---@return nil
function core.TuringMesh.hideFlagsGet(self) end


---@param self table
---@return nil
function core.TuringMesh.hideFlagsSet(self) end


---@param self table
---@return nil
function core.TuringMesh.markModified(self) end


---@param self table
---@return string
function core.TuringMesh.nameGet(self) end


---@param self table
---@param value string
---@return nil
function core.TuringMesh.nameSet(self, value) end


---@param self table
---@return nil
function core.TuringMesh.optimize(self) end


---@param self table
---@return nil
function core.TuringMesh.optimizeIndexBuffers(self) end


---@param self table
---@return nil
function core.TuringMesh.recalculateBounds(self) end


---@param self table
---@return nil
function core.TuringMesh.recalculateNormals(self) end


---@param self table
---@return nil
function core.TuringMesh.recalculateTangents(self) end


---@param self table
---@param min_x number
---@param min_y number
---@param min_z number
---@param max_x number
---@param max_y number
---@param max_z number
---@return nil
function core.TuringMesh.setBounds(self, min_x, min_y, min_z, max_x, max_y, max_z) end


---@param self table
---@param triangles Int32
---@param submesh number
---@param calculate_bounds boolean
---@param base_vertex number
---@return nil
function core.TuringMesh.setTriangles(self, triangles, submesh, calculate_bounds, base_vertex) end


---@param self table
---@param channel number
---@param uvs table
---@return nil
function core.TuringMesh.setUVs(self, channel, uvs) end


---@param self table
---@param in_vertices table
---@return nil
function core.TuringMesh.setVertices(self, in_vertices) end


---@param self table
---@param mark_no_longer_readable boolean
---@return nil
function core.TuringMesh.uploadMeshData(self, mark_no_longer_readable) end


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
---@return TuringMesh
function core.TuringerGameObject.addOrGetMesh(self) end


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



---@class Version
local Version = {}
core.Version = Version



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