// Copyright 2021 The Khronos Group
// SPDX-License-Identifier: Apache-2.0

// This file was generated by generate_device_frontend.py
// Don't make changes to this directly

#include "TreeDevice.h"
#include "TreeObjects.h"
namespace anari_sdk{
namespace tree{
static int obj_hash(const char *str) {
   static const uint32_t table[] = {0x7a6f0012u,0x6a65002bu,0x0u,0x0u,0x0u,0x65640040u,0x6e6d0044u,0x0u,0x0u,0x0u,0x62610051u,0x0u,0x736d0056u,0x73650075u,0x76750099u,0x6a69009du,0x756300a1u,0x737200d6u,0x6f6e001du,0x0u,0x0u,0x0u,0x0u,0x0u,0x73720020u,0x0u,0x0u,0x0u,0x6d6c0024u,0x6665001eu,0x100001fu,0x80000000u,0x77760021u,0x66650022u,0x1000023u,0x80000001u,0x6a690025u,0x6f6e0026u,0x65640027u,0x66650028u,0x73720029u,0x100002au,0x80000002u,0x67660030u,0x0u,0x0u,0x0u,0x73720036u,0x62610031u,0x76750032u,0x6d6c0033u,0x75740034u,0x1000035u,0x80000003u,0x66650037u,0x64630038u,0x75740039u,0x6a69003au,0x706f003bu,0x6f6e003cu,0x6261003du,0x6d6c003eu,0x100003fu,0x80000004u,0x73720041u,0x6a690042u,0x1000043u,0x80000005u,0x62610045u,0x68670046u,0x66650047u,0x34310048u,0x4544004bu,0x4544004du,0x4544004fu,0x100004cu,0x80000006u,0x100004eu,0x80000007u,0x1000050u,0x80000008u,0x75740052u,0x75740053u,0x66650054u,0x1000055u,0x80000009u,0x6f6e005cu,0x0u,0x0u,0x0u,0x0u,0x7574006au,0x6a69005du,0x6564005eu,0x6a69005fu,0x73720060u,0x66650061u,0x64630062u,0x75740063u,0x6a690064u,0x706f0065u,0x6f6e0066u,0x62610067u,0x6d6c0068u,0x1000069u,0x8000000au,0x6968006bu,0x706f006cu,0x6867006du,0x7372006eu,0x6261006fu,0x71700070u,0x69680071u,0x6a690072u,0x64630073u,0x1000074u,0x8000000bu,0x73720083u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x6a69008du,0x0u,0x0u,0x6a690091u,0x74730084u,0x71700085u,0x66650086u,0x64630087u,0x75740088u,0x6a690089u,0x7776008au,0x6665008bu,0x100008cu,0x8000000cu,0x6f6e008eu,0x7574008fu,0x1000090u,0x8000000du,0x6e6d0092u,0x6a690093u,0x75740094u,0x6a690095u,0x77760096u,0x66650097u,0x1000098u,0x8000000eu,0x6261009au,0x6564009bu,0x100009cu,0x8000000fu,0x6f6e009eu,0x6867009fu,0x10000a0u,0x80000010u,0x6a6900b3u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x706800b8u,0x0u,0x0u,0x0u,0x737200c6u,0x777600b4u,0x6a6900b5u,0x747300b6u,0x10000b7u,0x80000011u,0x666500c0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x757400c4u,0x737200c1u,0x666500c2u,0x10000c3u,0x80000012u,0x10000c5u,0x80000013u,0x767500c7u,0x646300c8u,0x757400c9u,0x767500cau,0x737200cbu,0x666500ccu,0x656400cdu,0x535200ceu,0x666500cfu,0x686700d0u,0x767500d1u,0x6d6c00d2u,0x626100d3u,0x737200d4u,0x10000d5u,0x80000014u,0x6a6100d7u,0x6f6e00e0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x626100fcu,0x747300e1u,0x716600e2u,0x706f00edu,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x0u,0x626100f1u,0x737200eeu,0x6e6d00efu,0x10000f0u,0x80000015u,0x737200f2u,0x666500f3u,0x6f6e00f4u,0x757400f5u,0x4e4d00f6u,0x626100f7u,0x757400f8u,0x757400f9u,0x666500fau,0x10000fbu,0x80000016u,0x6f6e00fdu,0x686700feu,0x6d6c00ffu,0x66650100u,0x1000101u,0x80000017u};
   uint32_t cur = 0x75630000u;
   for(int i = 0;cur!=0;++i) {
      uint32_t idx = cur&0xFFFFu;
      uint32_t low = (cur>>16u)&0xFFu;
      uint32_t high = (cur>>24u)&0xFFu;
      uint32_t c = (uint32_t)str[i];
      if(c>=low && c<high) {
         cur = table[idx+c-low];
      } else {
         break;
      }
      if(cur&0x80000000u) {
         return cur&0xFFFFu;
      }
      if(str[i]==0) {
         break;
      }
   }
   return -1;
}
ANARIArray1D TreeDevice::newArray1D(void* appMemory, ANARIMemoryDeleter deleter, void* userdata, ANARIDataType type, uint64_t numItems1, uint64_t byteStride1) {
   return allocate<ANARIArray1D, Array1D>(appMemory, deleter, userdata, type, numItems1, byteStride1);
}
ANARIArray2D TreeDevice::newArray2D(void* appMemory, ANARIMemoryDeleter deleter, void* userdata, ANARIDataType type, uint64_t numItems1, uint64_t numItems2, uint64_t byteStride1, uint64_t byteStride2) {
   return allocate<ANARIArray2D, Array2D>(appMemory, deleter, userdata, type, numItems1, numItems2, byteStride1, byteStride2);
}
ANARIArray3D TreeDevice::newArray3D(void* appMemory, ANARIMemoryDeleter deleter, void* userdata, ANARIDataType type, uint64_t numItems1, uint64_t numItems2, uint64_t numItems3, uint64_t byteStride1, uint64_t byteStride2, uint64_t byteStride3) {
   return allocate<ANARIArray3D, Array3D>(appMemory, deleter, userdata, type, numItems1, numItems2, numItems3, byteStride1, byteStride2, byteStride3);
}
ANARIFrame TreeDevice::newFrame() {
   return allocate<ANARIFrame, Frame>();
}
ANARIGroup TreeDevice::newGroup() {
   return allocate<ANARIGroup, Group>();
}
ANARIInstance TreeDevice::newInstance() {
   return allocate<ANARIInstance, Instance>();
}
ANARIWorld TreeDevice::newWorld() {
   return allocate<ANARIWorld, World>();
}
ANARIRenderer TreeDevice::newRenderer(const char *type) {
   int idx = obj_hash(type);
   switch(idx) {
      case 3: //default
         return allocate<ANARIRenderer, RendererDefault>();
      default: // unknown object
         return 0;
   }
   return 0;
}
ANARISurface TreeDevice::newSurface() {
   return allocate<ANARISurface, Surface>();
}
ANARICamera TreeDevice::newCamera(const char *type) {
   int idx = obj_hash(type);
   switch(idx) {
      case 10: //omnidirectional
         return allocate<ANARICamera, CameraOmnidirectional>();
      case 11: //orthographic
         return allocate<ANARICamera, CameraOrthographic>();
      case 12: //perspective
         return allocate<ANARICamera, CameraPerspective>();
      default: // unknown object
         return 0;
   }
   return 0;
}
ANARIGeometry TreeDevice::newGeometry(const char *type) {
   int idx = obj_hash(type);
   switch(idx) {
      case 0: //cone
         return allocate<ANARIGeometry, GeometryCone>();
      case 1: //curve
         return allocate<ANARIGeometry, GeometryCurve>();
      case 2: //cylinder
         return allocate<ANARIGeometry, GeometryCylinder>();
      case 15: //quad
         return allocate<ANARIGeometry, GeometryQuad>();
      case 18: //sphere
         return allocate<ANARIGeometry, GeometrySphere>();
      case 23: //triangle
         return allocate<ANARIGeometry, GeometryTriangle>();
      default: // unknown object
         return 0;
   }
   return 0;
}
ANARILight TreeDevice::newLight(const char *type) {
   int idx = obj_hash(type);
   switch(idx) {
      case 4: //directional
         return allocate<ANARILight, LightDirectional>();
      case 13: //point
         return allocate<ANARILight, LightPoint>();
      case 19: //spot
         return allocate<ANARILight, LightSpot>();
      case 16: //ring
         return allocate<ANARILight, LightRing>();
      case 15: //quad
         return allocate<ANARILight, LightQuad>();
      case 5: //hdri
         return allocate<ANARILight, LightHdri>();
      default: // unknown object
         return 0;
   }
   return 0;
}
ANARIMaterial TreeDevice::newMaterial(const char *type) {
   int idx = obj_hash(type);
   switch(idx) {
      case 9: //matte
         return allocate<ANARIMaterial, MaterialMatte>();
      case 22: //transparentMatte
         return allocate<ANARIMaterial, MaterialTransparentMatte>();
      default: // unknown object
         return 0;
   }
   return 0;
}
ANARISampler TreeDevice::newSampler(const char *type) {
   int idx = obj_hash(type);
   switch(idx) {
      case 6: //image1D
         return allocate<ANARISampler, SamplerImage1D>();
      case 7: //image2D
         return allocate<ANARISampler, SamplerImage2D>();
      case 8: //image3D
         return allocate<ANARISampler, SamplerImage3D>();
      case 14: //primitive
         return allocate<ANARISampler, SamplerPrimitive>();
      case 21: //transform
         return allocate<ANARISampler, SamplerTransform>();
      default: // unknown object
         return 0;
   }
   return 0;
}
ANARISpatialField TreeDevice::newSpatialField(const char *type) {
   int idx = obj_hash(type);
   switch(idx) {
      case 20: //structuredRegular
         return allocate<ANARISpatialField, Spatial_FieldStructuredRegular>();
      default: // unknown object
         return 0;
   }
   return 0;
}
ANARIVolume TreeDevice::newVolume(const char *type) {
   int idx = obj_hash(type);
   switch(idx) {
      case 17: //scivis
         return allocate<ANARIVolume, VolumeScivis>();
      default: // unknown object
         return 0;
   }
   return 0;
}
} //namespace anari_sdk
} //namespace tree
