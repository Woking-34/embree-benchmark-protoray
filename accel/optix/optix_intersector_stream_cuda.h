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

#include <optix_prime/optix_primepp.h>
#include "sys/props.h"
#include "geometry/triangle_mesh_cuda.h"
#include "core/intersector_stream_cuda.h"

namespace prt {

class OptixIntersectorStreamCuda : public IntersectorStreamCuda
{
private:
    optix::prime::Context context;
    optix::prime::Model model;
    optix::prime::Query closestQuery;
    optix::prime::Query anyQuery;

public:
    OptixIntersectorStreamCuda(const TriangleMeshCuda& mesh, const Props& props, Props& stats);

    void intersect(RayCuda* rays, HitCuda* hits, int count);
    void occluded(RayCuda* rays, AnyHitCuda* hits, int count);
};

} // namespace prt
