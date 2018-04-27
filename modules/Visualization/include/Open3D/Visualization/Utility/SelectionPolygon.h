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

#pragma once

#include <vector>
#include <memory>
#include <Eigen/Core>
#include <Open3D/Core/Geometry/Geometry2D.h>
#include <Open3D/Core/Geometry/Image.h>

namespace open3d {

class PointCloud;
class ViewControl;
class SelectionPolygonVolume;

/// A 2D polygon used for selection on screen
/// It is a utility class for Visualization
/// The coordinates in SelectionPolygon are lower-left corner based (the OpenGL
/// convention).
class SelectionPolygon : public Geometry2D
{
public:
    enum class SectionPolygonType {
        Unfilled = 0,
        Rectangle = 1,
        Polygon = 2,
    };

public:
    SelectionPolygon() : Geometry2D(Geometry::GeometryType::Unspecified) {}
    ~SelectionPolygon() override {}

public:
    void Clear() override;
    bool IsEmpty() const override;
    Eigen::Vector2d GetMinBound() const final;
    Eigen::Vector2d GetMaxBound() const final;
    void FillPolygon(int32_t width, int32_t height);
    std::shared_ptr<PointCloud> CropPointCloud(
            const PointCloud &input, const ViewControl &view);
    std::shared_ptr<SelectionPolygonVolume> CreateSelectionPolygonVolume(
            const ViewControl &view);

private:
    std::shared_ptr<PointCloud> CropPointCloudInRectangle(
            const PointCloud &input, const ViewControl &view);
    std::shared_ptr<PointCloud> CropPointCloudInPolygon(
            const PointCloud &input, const ViewControl &view);
    std::vector<uint32_t> CropInRectangle(
            const std::vector<Eigen::Vector3d> &input, const ViewControl &view);
    std::vector<uint32_t> CropInPolygon(
            const std::vector<Eigen::Vector3d> &input, const ViewControl &view);

public:
    std::vector<Eigen::Vector2d> polygon_;
    bool is_closed_ = false;
    Image polygon_interior_mask_;
    SectionPolygonType polygon_type_ = SectionPolygonType::Unfilled;
};

}   // namespace open3d
