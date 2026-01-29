

///// Generated C++ API Header /////
#ifndef TURING_API_HPP
#define TURING_API_HPP
#include <stdint.h>
#include <string>
// skip ffi imports as they're included from wasm.h
#define TURING_API_CPP_SEMVER "0.1.0"

namespace turing_api_cpp {

uint64_t _turing_api_semver();

//// Functions ////

//// Classes ////

class GameObject {
private:
    uint64_t opaqu;

public:
    GameObject(uint64_t ptr);



};

class Transform {
private:
    uint64_t opaqu;

public:
    Transform(uint64_t ptr);



};

class TuringScriptManager {
private:
    uint64_t opaqu;

public:
    TuringScriptManager(uint64_t ptr);



};

class Object {
private:
    uint64_t opaqu;

public:
    Object(uint64_t ptr);



};

class List1 {
private:
    uint64_t opaqu;

public:
    List1(uint64_t ptr);



};

class List {
private:
    uint64_t opaqu;

public:
    List(uint64_t ptr);



};

class Component {
private:
    uint64_t opaqu;

public:
    Component(uint64_t ptr);



};

class Type {
private:
    uint64_t opaqu;

public:
    Type(uint64_t ptr);



};

class IEnumerator {
private:
    uint64_t opaqu;

public:
    IEnumerator(uint64_t ptr);



};

class Log {
public:

    
    void warn(std::string& msg);
    
    void info(std::string& msg);
    
    void debug(std::string& msg);
    
    void critical(std::string& msg);

};

class NoteManager {
public:

    
    void addObstacle(float beat, float duration, int32_t line, int32_t layer, int32_t width, int32_t height, CustomData custom_data);
    
    void addColorNote(float beat, int32_t line, int32_t layer, int32_t color, int32_t cut_direction, CustomData custom_data);
    
    float timeToBeat(float time);
    
    void addBombNote(float beat, int32_t line, int32_t layer, CustomData custom_data);

};

class TuringerGameObjectManager {
private:
    uint64_t opaqu;

public:
    TuringerGameObjectManager(uint64_t ptr);


    
    TuringerGameObject createObject(std::string& name);
    
    TuringerGameObject find(std::string& name);
    
    void destroyObject(TuringerGameObject listener);

    
    TuringerGameObjectManager instanceGet();
};

class TuringerGameObject {
private:
    uint64_t opaqu;

public:
    TuringerGameObject(uint64_t ptr);



    
    Component getComponentsInParentByType(Type cs_type, bool include_inactive);
    
    void sendMessage(std::string& method_name);
    
    Component getComponentInParentByType(Type cs_type);
    
    bool isStaticGet();
    
    TuringerTransform transformGet();
    
    Component getComponentInChildrenByType(Type cs_type);
    
    void getComponentsByType(Type cs_type, List1 results);
    
    void activeSet(bool value);
    
    void broadcastMessage(std::string& method_name);
    
    GameObject gameObjectGet();
    
    void isStaticSet(bool value);
    
    Component addComponent(Type component_type);
    
    void hideFlagsSet(int32_t value);
    
    void sendMessageUpwards(std::string& method_name);
    
    bool compareTag(std::string& tag);
    
    int32_t hideFlagsGet();
    
    void tagSet(std::string& value);
    
    int32_t getInstanceId();
    
    int32_t layerGet();
    
    Component getComponentsInChildrenByType(Type cs_type, bool include_inactive);
    
    void layerSet(int32_t value);
    
    void setActiveRecursively(bool state);
    
    int32_t getComponentIndex(Component component);
    
    int32_t getComponentCount();
    
    Component getComponentAtIndex(int32_t index);
    
    std::string tagGet();
    
    bool activeSelfGet();
    
    std::string nameGet();
    
    Component getComponentByType(Type cs_type);
    
    bool activeInHierarchyGet();
    
    void setActive(bool value);
    
    bool activeGet();
    
    Component getComponentByName(std::string& cs_type);
    
    void nameSet(std::string& value);
    
    uint64_t sceneCullingMaskGet();
};

class TuringerTransform {
private:
    uint64_t opaqu;

public:
    TuringerTransform(uint64_t ptr);



    
    Component getComponentByType(Type cs_type);
    
    void lookAt(glm::vec3 world_position);
    
    int32_t getInstanceId();
    
    std::string tagGet();
    
    glm::vec3 localEulerAnglesGet();
    
    glm::quat rotationGet();
    
    glm::mat4 worldToLocalMatrixGet();
    
    int32_t hierarchyCountGet();
    
    Component getComponentsInChildrenByType(Type t, bool include_inactive);
    
    void nameSet(std::string& value);
    
    glm::quat localRotationGet();
    
    void detachChildren();
    
    glm::vec3 inverseTransformPoint(float x, float y, float z);
    
    Component getComponentInChildrenByType(Type t, bool include_inactive);
    
    Transform transformGet();
    
    glm::vec3 lossyScaleGet();
    
    TuringerTransform rootGet();
    
    void getComponentsByType(Type cs_type, List1 results);
    
    IEnumerator getEnumerator();
    
    void localScaleSet(glm::vec3 value);
    
    int32_t childCountGet();
    
    void parentSet(TuringerTransform value);
    
    TuringerTransform getChild(int32_t index);
    
    glm::vec3 transformDirection(float x, float y, float z);
    
    void hasChangedSet(bool value);
    
    void sendMessageUpwards(std::string& method_name, Object value, int32_t options);
    
    TuringerTransform findChild(std::string& n);
    
    Component getComponentsInParentByType(Type t, bool include_inactive);
    
    void rotate(glm::vec3 axis, float angle);
    
    bool hasChangedGet();
    
    glm::vec3 localPositionGet();
    
    void translateRelative(glm::vec3 translation, TuringerTransform relative_to);
    
    void localEulerAnglesSet(glm::vec3 value);
    
    void setLocalPositionAndRotation(glm::vec3 local_position, glm::quat local_rotation);
    
    glm::vec3 forwardGet();
    
    int32_t getSiblingIndex();
    
    Component getComponentInParentByType(Type t, bool include_inactive);
    
    glm::vec3 upGet();
    
    int32_t getComponentIndex();
    
    void rotateAroundLocal(glm::vec3 axis, float angle);
    
    void translate(glm::vec3 translation);
    
    void broadcastMessage(std::string& method_name, Object parameter, int32_t options);
    
    void eulerAnglesSet(glm::vec3 value);
    
    void sendMessage(std::string& method_name, Object value, int32_t options);
    
    TuringerTransform parentGet();
    
    glm::mat4 localToWorldMatrixGet();
    
    Component getComponentByName(std::string& cs_type);
    
    void setParent(TuringerTransform parent, bool world_position_stays);
    
    void rotateAround(glm::vec3 axis, float angle);
    
    void hierarchyCapacitySet(int32_t value);
    
    void upSet(glm::vec3 value);
    
    glm::vec3 inverseTransformDirection(float x, float y, float z);
    
    glm::vec3 localScaleGet();
    
    glm::vec3 transformVector(float x, float y, float z);
    
    glm::vec3 transformPoint(float x, float y, float z);
    
    glm::vec3 eulerAnglesGet();
    
    bool isChildOf(TuringerTransform parent);
    
    void rightSet(glm::vec3 value);
    
    int32_t getChildCount();
    
    int32_t hideFlagsGet();
    
    void rotateRelative(glm::vec3 axis, float angle, int32_t relative_to);
    
    void rotationSet(glm::quat value);
    
    TuringerGameObject gameObjectGet();
    
    int32_t hierarchyCapacityGet();
    
    void setAsFirstSibling();
    
    glm::vec3 rightGet();
    
    void localPositionSet(glm::vec3 value);
    
    void forwardSet(glm::vec3 value);
    
    std::string nameGet();
    
    bool compareTag(std::string& tag);
    
    void setAsLastSibling();
    
    glm::vec3 positionGet();
    
    void setSiblingIndex(int32_t index);
    
    void positionSet(glm::vec3 value);
    
    void hideFlagsSet(int32_t value);
    
    void setPositionAndRotation(glm::vec3 position, glm::quat rotation);
    
    TuringerTransform find(std::string& n);
    
    void tagSet(std::string& value);
    
    void localRotationSet(glm::quat value);
    
    glm::vec3 inverseTransformVector(float x, float y, float z);
};

class GcHelper {
private:
    uint64_t opaqu;

public:
    GcHelper(uint64_t ptr);


    
    GCHelper create();

    
    void wasmGarbageCollect();
    
    void dispose();
    
    void invalidateAllHandles();
};

class Xr {
private:
    uint64_t opaqu;

public:
    Xr(uint64_t ptr);


    
    int32_t getDeviceTrackingState(int32_t node_int);
    
    std::string getDeviceName(int32_t node_int);
    
    bool getDeviceSecondaryButtonState(int32_t node_int);
    
    bool getDevicePrimaryButtonState(int32_t node_int);
    
    void sendHapticImpulse(int32_t node_int, float amplitude, float duration);
    
    bool isDeviceValid(int32_t node_int);
    
    float getDeviceBatteryLevel(int32_t node_int);
    
    glm::vec2 getDeviceTouchpad(int32_t node_int);
    
    float getDeviceGripValue(int32_t node_int);
    
    float getDeviceTriggerValue(int32_t node_int);
    
    void stopHaptics(int32_t node_int);
    
    glm::vec2 getDeviceThumbstick(int32_t node_int);

    
    TuringScriptManager ManagerGet();
};

class CustomData {
private:
    uint64_t opaqu;

public:
    CustomData(uint64_t ptr);


    
    CustomData create();
    
    List listCreate();
    
    void setString(CustomData custom_data, std::string& key, std::string& value);
    
    void setCustomData(CustomData custom_data, std::string& key, CustomData value);
    
    void listAddString(List1 list, std::string& value);
    
    void setCustomDataList(CustomData custom_data, std::string& key, List1 value);
    
    void setFloat(CustomData custom_data, std::string& key, float value);
    
    void listAddInt(List1 list, int32_t value);
    
    void listAddBool(List1 list, bool value);
    
    void setInt(CustomData custom_data, std::string& key, int32_t value);
    
    void setBool(CustomData custom_data, std::string& key, bool value);
    
    void listAddCustomDataList(List1 list, List1 value);
    
    void listAddFloat(List1 list, float value);
    
    void listAddCustomData(List1 list, CustomData value);

};

} // namespace turing_api_cpp

#endif // TURING_API_HPP
