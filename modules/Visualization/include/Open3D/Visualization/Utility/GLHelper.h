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

#include <string>

#include <Eigen/Core>
#include <GLFW/glfw3.h>

namespace open3d {

namespace GLHelper {

typedef Eigen::Matrix<GLfloat, 3, 1, Eigen::ColMajor> GLVector3f;
typedef Eigen::Matrix<GLfloat, 4, 1, Eigen::ColMajor> GLVector4f;
typedef Eigen::Matrix<GLfloat, 4, 4, Eigen::ColMajor> GLMatrix4f;

GLMatrix4f LookAt(const Eigen::Vector3d &eye, const Eigen::Vector3d &lookat,
        const Eigen::Vector3d &up);

GLMatrix4f Perspective(double field_of_view_, double aspect, double z_near,
        double z_far);

GLMatrix4f Ortho(double left, double right, double bottom, double top,
        double z_near, double z_far);

Eigen::Vector3d Project(const Eigen::Vector3d &point,
        const GLMatrix4f &mvp_matrix, const int width, const int height);

Eigen::Vector3d Unproject(const Eigen::Vector3d &screen_point,
        const GLMatrix4f &mvp_matrix, const int width, const int height);

int ColorCodeToPickIndex(const Eigen::Vector4i &color);

}   // namespace GLHelper

}   // namespace open3d
