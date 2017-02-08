// ======================================================================== //
// Copyright 2015-2017 Intel Corporation                                    //
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

#include "integrator.h"

namespace prt {

// Primary occlusion
template <class Sampler>
class PoIntegratorSingle : public IntegratorBase
{
public:
    PoIntegratorSingle(const Props& props) {}

    int getSampleSize() const
    {
        return sampleDimBaseSize;
    }

    Vec3f getColor(Ray& ray, IntersectorSingle* intersector, const Scene* scene, Sampler& sampler, IntegratorState<Sampler>& state)
    {
        intersector->occluded(ray, state.rayStats);
        return ray.isHit() ? Vec3f(1.0f, 0.5f, 0.0f) : 0.05f;
    }
};

} // namespace prt