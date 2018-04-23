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
#include <memory>
#include <vector>
#include <map>
#include <functional>
#include <Open3D/Core/Geometry/Geometry.h>

namespace open3d {

class Visualizer;

/// The convenient function of drawing something
/// This function is a wrapper that calls the core functions of Visualizer.
/// This function MUST be called from the main thread. It blocks the main thread
/// until the window is closed.

bool DrawGeometries(
        const std::vector<std::shared_ptr<const Geometry>> &geometry_ptrs,
        const std::string &window_name = "Open3D",
        int width = 640, int height = 480, int left = 50, int top = 50);

bool DrawGeometriesWithCustomAnimation(
        const std::vector<std::shared_ptr<const Geometry>> &geometry_ptrs,
        const std::string &window_name = "Open3D",
        int width = 640, int height = 480, int left = 50, int top = 50,
        const std::string &json_filename = "");

bool DrawGeometriesWithAnimationCallback(
        const std::vector<std::shared_ptr<const Geometry>> &geometry_ptrs,
        std::function<bool(Visualizer *)> callback_func,
        const std::string &window_name = "Open3D",
        int width = 640, int height = 480, int left = 50, int top = 50);

bool DrawGeometriesWithKeyCallbacks(
        const std::vector<std::shared_ptr<const Geometry>> &geometry_ptrs,
        const std::map<int, std::function<bool(Visualizer *)>> &key_to_callback,
        const std::string &window_name = "Open3D",
        int width = 640, int height = 480, int left = 50, int top = 50);

bool DrawGeometriesWithEditing(
        const std::vector<std::shared_ptr<const Geometry>> &geometry_ptrs,
        const std::string &window_name = "Open3D",
        int width = 640, int height = 480, int left = 50, int top = 50);

}   // namespace open3d
