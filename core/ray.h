// ======================================================================== //
// Copyright 2015-2018 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include "sys/common.h"
#include "math/vec2.h"
#include "math/vec3.h"
#include "math/basis3.h"

namespace prt {

struct Ray
{
    Vec3f org; // origin
    Vec3f dir; // direction
    float tfar; // hit distance

    FORCEINLINE float* getOrgX() { return &org.x; }
    FORCEINLINE float* getOrgY() { return &org.y; }
    FORCEINLINE float* getOrgZ() { return &org.z; }
    FORCEINLINE float* getDirX() { return &dir.x; }
    FORCEINLINE float* getDirY() { return &dir.y; }
    FORCEINLINE float* getDirZ() { return &dir.z; }
    FORCEINLINE float* getFar()  { return &tfar; }

    FORCEINLINE void init(const Vec3f& org, const Vec3f& dir)
    {
        this->org = org;
        this->dir = dir;
        this->tfar = posMax;
    }

    FORCEINLINE void init(const Vec3f& org, const Vec3f& dir, float tnear)
    {
        this->org = org + tnear * dir;
        this->dir = dir;
        this->tfar = posMax;
    }

    FORCEINLINE void init(const Vec3f& org, const Vec3f& dir, float tnear, float tfar)
    {
        this->org = org + tnear * dir;
        this->dir = dir;
        this->tfar = tfar - tnear;
    }

    FORCEINLINE bool isHit() const
    {
        return tfar < float(posMax);
    }

    FORCEINLINE Vec3f getHitPoint() const
    {
        return org + tfar * dir;
    }

    FORCEINLINE Vec3f getHitPoint(float& eps) const
    {
        Vec3f p = getHitPoint();
        eps = max(tfar, reduceMax(abs(p))) * 0x1.fp-18;
        return p;
    }

    FORCEINLINE bool isOccluded() const
    {
        return tfar == 0.0f;
    }

    FORCEINLINE bool isNotOccluded() const
    {
        return tfar > 0.0f;
    }
};

struct Hit
{
    int primId; // primitive ID
    float u;    // barycentric u coordinate
    float v;    // barycentric v coordinate

    FORCEINLINE int*   getPrimId() { return &primId; }
    FORCEINLINE float* getU()      { return &u; }
    FORCEINLINE float* getV()      { return &v; }
};

} // namespace prt
