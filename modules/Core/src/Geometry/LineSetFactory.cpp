// ----------------------------------------------------------------------------
// -                        Open3D: www.open-3d.org                            -
// ----------------------------------------------------------------------------
// Imported on Apr 11th, 2018 from the Open3D project
// Copyright (c) 2018 www.open3d.org
// released under MIT licence
//
// A fork of their project is avilable at legacy-code.open-3d.org
// Refer to http://legacy-code.open-3d.org/blob/master/LICENSE
// for their full licence
// Check http://legacy-code.open-3d.org/graphs/contributors
// to get the list of their contributors and their contributions
//
// The rights of any later updates or modifications are reserved
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2018, Hamdi Sahloul - www.open-3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#include <Open3D/Core/Geometry/LineSet.h>

#include <Eigen/Dense>
#include <Open3D/Core/Geometry/PointCloud.h>

namespace open3d {

std::shared_ptr<LineSet> CreateLineSetFromPointCloudCorrespondences(
        const PointCloud &cloud0, const PointCloud &cloud1,
        const std::vector<std::pair<int32_t, int32_t>> &correspondences)
{
    auto lineset_ptr = std::make_shared<LineSet>();
    lineset_ptr->point_set_[0] = cloud0.points_;
    lineset_ptr->point_set_[1] = cloud1.points_;
    lineset_ptr->lines_ = correspondences;
    return lineset_ptr;
}

}   // namespace open3d
