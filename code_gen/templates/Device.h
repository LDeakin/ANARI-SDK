// This file was generated by $generator from $template

#pragma once

// anari
#include "anari/backend/DeviceImpl.h"
#include "$prefixObject.h"
#include "$prefixArrayObjects.h"
#include "$prefixFrameObject.h"

#include <vector>
#include <memory>
#include <atomic>
#include <mutex>

#ifdef _WIN32
#ifdef DEVICE_STATIC_DEFINE
#define DEVICE_INTERFACE
#else
#ifdef anari_library_$libraryname_EXPORTS
#define DEVICE_INTERFACE __declspec(dllexport)
#else
#define DEVICE_INTERFACE __declspec(dllimport)
#endif
#endif
#elif defined __GNUC__
#define DEVICE_INTERFACE __attribute__((__visibility__("default")))
#else
#define DEVICE_INTERFACE
#endif

$begin_namespaces

void anariRetainInternal(ANARIDevice, ANARIObject);
void anariReleaseInternal(ANARIDevice, ANARIObject);
void anariDeleteInternal(ANARIDevice, ANARIObject);
void anariReportStatus(ANARIDevice,
      ANARIObject source,
      ANARIDataType sourceType,
      ANARIStatusSeverity severity,
      ANARIStatusCode code,
      const char *format, ...);

template<class T>
T deviceHandle(ANARIDevice d){
      anari::DeviceImpl *ad = reinterpret_cast<anari::DeviceImpl*>(d);
      return dynamic_cast<T>(ad);
}

struct DEVICE_INTERFACE $prefixDevice : public anari::DeviceImpl
{
   // Device API ///////////////////////////////////////////////////////////////

   int deviceImplements(const char *extension) override;

   // Data Arrays //////////////////////////////////////////////////////////////

   ANARIArray1D newArray1D(void *appMemory,
         ANARIMemoryDeleter deleter,
         void *userdata,
         ANARIDataType,
         uint64_t numItems1,
         uint64_t byteStride1) override;

   ANARIArray2D newArray2D(void *appMemory,
         ANARIMemoryDeleter deleter,
         void *userdata,
         ANARIDataType,
         uint64_t numItems1,
         uint64_t numItems2,
         uint64_t byteStride1,
         uint64_t byteStride2) override;

   ANARIArray3D newArray3D(void *appMemory,
         ANARIMemoryDeleter deleter,
         void *userdata,
         ANARIDataType,
         uint64_t numItems1,
         uint64_t numItems2,
         uint64_t numItems3,
         uint64_t byteStride1,
         uint64_t byteStride2,
         uint64_t byteStride3) override;

   void *mapArray(ANARIArray) override;
   void unmapArray(ANARIArray) override;

   // Renderable Objects ///////////////////////////////////////////////////////

   ANARILight newLight(const char *type) override;

   ANARICamera newCamera(const char *type) override;

   ANARIGeometry newGeometry(const char *type) override;
   ANARISpatialField newSpatialField(const char *type) override;

   ANARISurface newSurface() override;
   ANARIVolume newVolume(const char *type) override;

   // Surface Meta-Data ////////////////////////////////////////////////////////

   ANARIMaterial newMaterial(const char *material_type) override;

   ANARISampler newSampler(const char *type) override;

   // Instancing ///////////////////////////////////////////////////////////////

   ANARIGroup newGroup() override;

   ANARIInstance newInstance() override;

   // Top-level Worlds /////////////////////////////////////////////////////////

   ANARIWorld newWorld() override;

   // Object + Parameter Lifetime Management ///////////////////////////////////

   int getProperty(ANARIObject object,
         const char *name,
         ANARIDataType type,
         void *mem,
         uint64_t size,
         ANARIWaitMask mask) override;

   void setParameter(ANARIObject object,
         const char *name,
         ANARIDataType type,
         const void *mem) override;

   void unsetParameter(ANARIObject object, const char *name) override;

   void commit(ANARIObject object) override;

   void release(ANARIObject) override;
   void retain(ANARIObject) override;
   void retainInternal(ANARIObject);
   void releaseInternal(ANARIObject);

   // FrameBuffer Manipulation /////////////////////////////////////////////////

   ANARIFrame newFrame() override;

   const void *frameBufferMap(ANARIFrame fb, const char *channel) override;

   void frameBufferUnmap(ANARIFrame fb, const char *channel) override;

   // Frame Rendering //////////////////////////////////////////////////////////

   ANARIRenderer newRenderer(const char *type) override;

   void renderFrame(ANARIFrame) override;
   int frameReady(ANARIFrame, ANARIWaitMask) override;
   void discardFrame(ANARIFrame) override;

   /////////////////////////////////////////////////////////////////////////////
   // Helper/other functions and data members
   /////////////////////////////////////////////////////////////////////////////

   $prefixDevice();
   ~$prefixDevice();

   template<typename R, typename T>
   R fromHandle(T handle) {
      std::lock_guard<std::recursive_mutex> guard(mutex);
      uintptr_t id = reinterpret_cast<uintptr_t>(handle);
      if(id<objects.size()) {
            return dynamic_cast<R>(objects[id].get());
      } else {
            return nullptr;
      }
   }
private:
   // object allocation and translation

   friend void anariDeleteInternal(ANARIDevice, ANARIObject);
   friend void anariReportStatus(ANARIDevice,
      ANARIObject source,
      ANARIDataType sourceType,
      ANARIStatusSeverity severity,
      ANARIStatusCode code,
      const char *format, ...);

   template<typename R, typename T, typename... ARGS>
   R allocate(ARGS... args) {
      std::lock_guard<std::recursive_mutex> guard(mutex);
      uintptr_t id = objects.size();
      R handle = reinterpret_cast<R>(id);
      objects.emplace_back(new Object<T>(this_device(), handle, args...));
      return handle;
   }

   void deallocate(ANARIObject handle) {
      std::lock_guard<std::recursive_mutex> guard(mutex);
      uintptr_t id = reinterpret_cast<uintptr_t>(handle);
      if(id<objects.size()) {
            return objects[id].reset(nullptr);
      }
   }

   std::atomic<int64_t> refcount;
   std::recursive_mutex mutex;
   std::vector<std::unique_ptr<ObjectBase>> objects;

   ANARIStatusCallback statusCallback;
   void* statusCallbackUserData;

   $namespace::Device staging;
   $namespace::Device current;
};

$end_namespaces

