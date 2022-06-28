// Copyright 2021 The Khronos Group
// SPDX-License-Identifier: Apache-2.0

// This file was generated by generate_device_frontend.py from $template

#pragma once

#include <cstring>
#include <atomic>
#include <cstdint>
#include "anari/anari.h"


namespace anari_sdk{
namespace tree{


class ParameterPack;

void anariDeleteInternal(ANARIDevice, ANARIObject);

class ObjectBase {
   std::atomic<uint64_t> refcount;
protected:
   ANARIDevice device;
   ANARIObject handle;
public:
   ObjectBase(ANARIDevice d, ANARIObject handle) : refcount(1), device(d), handle(handle) { }

   virtual void retain() { refcount += 1; }
   virtual void release() {
      uint64_t c = refcount.fetch_sub(1);
      if(c == 1) {
         anariDeleteInternal(device, handle);
      } else if((c&UINT64_C(0xFFFFFFFF)) == 1) {
         releasePublic();
      }
   }
   virtual void retainInternal(ANARIObject) {
      refcount += UINT64_C(0x100000000);
   }
   virtual void releaseInternal(ANARIObject) {
      uint64_t c = refcount.fetch_sub(UINT64_C(0x100000000));
      if(c == UINT64_C(0x100000000)) {
         anariDeleteInternal(device, handle);
      }
   }
   virtual void releasePublic() { }

   virtual bool set(const char *paramname, ANARIDataType type, const void *mem) = 0;
   virtual void unset(const char *paramname) = 0;
   virtual void commit() = 0;
   virtual int getProperty(
      const char *propname, ANARIDataType type,
      void *mem, uint64_t size, ANARIWaitMask mask) = 0;
   virtual ~ObjectBase() { }
   virtual ANARIDataType type() const = 0;
   virtual const char* subtype() const = 0;
   virtual ParameterPack& parameters() = 0;
};

class ArrayObjectBase : public ObjectBase {
public:
   ArrayObjectBase(ANARIDevice d, ANARIObject handle) : ObjectBase(d, handle) { }
   virtual void* map() { return nullptr; }
   virtual void unmap() { }
};

class FrameObjectBase : public ObjectBase {
public:
   FrameObjectBase(ANARIDevice d, ANARIObject handle) : ObjectBase(d, handle) { }
   virtual void* mapFrame(const char*) { return nullptr; }
   virtual void unmapFrame(const char*) { }
   virtual void renderFrame() { }
   virtual void discardFrame() { }
   virtual int frameReady(ANARIWaitMask) { return 1; }
};

template<class T>
class DefaultObject : public ObjectBase {
protected:
   T staging;
   T current;
public:
   DefaultObject(ANARIDevice d, ANARIObject handle) : ObjectBase(d, handle), staging(d, handle), current(d, handle) {

   }
   bool set(const char *paramname, ANARIDataType type, const void *mem) override {
      return staging.set(paramname, type, mem);
   }
   void unset(const char *paramname) override {
      staging.unset(paramname);
   }
   void commit() override {
      current = staging;
   }
   int getProperty(
      const char *propname, ANARIDataType type,
      void *mem, uint64_t size, ANARIWaitMask mask) override {
      (void)propname;
      (void)type;
      (void)mem;
      (void)size;
      (void)mask;
      return 0;
   }

   ANARIDataType type() const override { return T::type; }
   const char* subtype() const override { return T::subtype; }
   ParameterPack& parameters() override { return current; }
};

template<class T>
class Object : public DefaultObject<T> {
public:
   Object(ANARIDevice d, ANARIObject handle) : DefaultObject<T>(d, handle) {

   }
};

} //namespace anari_sdk
} //namespace tree

