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

#include <iostream>
#include <thread>
#include <librealsense/rs.hpp>
#include <Open3D/Core/Core.h>
#include <Open3D/Visualization/Visualization.h>

using namespace open3d;

int main(int argc, char **args)
{
    rs::context ctx;
    PrintInfo("There are %d connected RealSense devices.\n",
            ctx.get_device_count());
    if(ctx.get_device_count() == 0) {
        return 0;
    }

    rs::device * dev = ctx.get_device(0);
    PrintInfo("Using device 0, an %s\n", dev->get_name());
    PrintInfo("    Serial number: %s\n", dev->get_serial());
    PrintInfo("    Firmware version: %s\n\n", dev->get_firmware_version());

    dev->set_option(rs::option::color_enable_auto_exposure, 0.0);
    dev->set_option(rs::option::color_exposure, 625);
    dev->set_option(rs::option::color_gain, 128);
    dev->set_option(rs::option::color_enable_auto_white_balance, 0.0);

    dev->enable_stream(rs::stream::depth, 640, 480, rs::format::z16, 30);
    dev->enable_stream(rs::stream::color, 1920, 1080, rs::format::rgb8, 30);
    dev->start();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    dev->set_option(rs::option::color_white_balance, 2100.0);

    auto depth_image_ptr = std::make_shared<Image>();
    depth_image_ptr->PrepareImage(640, 480, 1, 2);
    auto color_image_ptr = std::make_shared<Image>();
    color_image_ptr->PrepareImage(1920, 1080, 3, 1);
    FPSTimer timer("Realsense stream");

    rs::extrinsics extrinsics = dev->get_extrinsics(rs::stream::depth,
            rs::stream::rectified_color);
    for (int i = 0; i < 9; i++) {
        PrintInfo("%.6f ", extrinsics.rotation[i]);
    }
    PrintInfo("\n");
    for (int i = 0; i < 3; i++) {
        PrintInfo("%.6f ", extrinsics.translation[i]);
    }
    PrintInfo("\n");

    rs::intrinsics depth_intr = dev->get_stream_intrinsics(rs::stream::depth);
    PrintInfo("%d %d %.6f %.6f %.6f %.6f\n",
            depth_intr.width, depth_intr.height,
            depth_intr.fx, depth_intr.fy,
            depth_intr.ppx, depth_intr.ppy);
    for (int i = 0; i < 5; i++) {
        PrintInfo("%.6f ", depth_intr.coeffs[i]);
    }
    PrintInfo("\n\n");

    rs::intrinsics color_intr = dev->get_stream_intrinsics(rs::stream::color);
    PrintInfo("%d %d %.6f %.6f %.6f %.6f\n",
            color_intr.width, color_intr.height,
            color_intr.fx, color_intr.fy,
            color_intr.ppx, color_intr.ppy);
    for (int i = 0; i < 5; i++) {
        PrintInfo("%.6f ", color_intr.coeffs[i]);
    }
    PrintInfo("\n\n");

    rs::intrinsics rect_intr = dev->get_stream_intrinsics(
            rs::stream::rectified_color);
    PrintInfo("%d %d %.6f %.6f %.6f %.6f\n",
            rect_intr.width, rect_intr.height,
            rect_intr.fx, rect_intr.fy,
            rect_intr.ppx, rect_intr.ppy);
    for (int i = 0; i < 5; i++) {
        PrintInfo("%.6f ", rect_intr.coeffs[i]);
    }
    PrintInfo("\n\n");

    Visualizer depth_vis, color_vis;
    if (depth_vis.CreateWindow("Depth", 640, 480, 15, 50) == false ||
            depth_vis.AddGeometry(depth_image_ptr) == false ||
            color_vis.CreateWindow("Color", 1920, 1080, 675, 50) == false ||
            color_vis.AddGeometry(color_image_ptr) == false) {
        return 0;
    }

    while (depth_vis.PollEvents() && color_vis.PollEvents()) {
        timer.Signal();
        dev->wait_for_frames();
        memcpy(depth_image_ptr->data_.data(),
                dev->get_frame_data(rs::stream::depth), 640 * 480 * 2);
        memcpy(color_image_ptr->data_.data(),
                dev->get_frame_data(rs::stream::rectified_color),
                1920 * 1080 * 3);
        depth_vis.UpdateGeometry();
        color_vis.UpdateGeometry();

        PrintInfo("%.2f\n", dev->get_option(rs::option::color_white_balance));

        /*
        rs::option opts[10] = {
                rs::option::color_enable_auto_exposure,
                rs::option::color_exposure,
                rs::option::color_backlight_compensation,
                rs::option::color_brightness,
                rs::option::color_contrast,
                rs::option::color_gain,
                rs::option::color_gamma,
                rs::option::color_saturation,
                rs::option::color_sharpness,
                rs::option::color_hue
                };
        double value[10];
        dev->get_options((const rs::option *)opts, 10, (double *)value);
        PrintInfo("%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n",
                value[0], value[1], value[2], value[3], value[4],
                value[5], value[6], value[7], value[8], value[9]);
        */
    }

    //DrawGeometryWithAnimationCallback(depth_image_ptr,
    //      [&](Visualizer &vis) {
    //          timer.Signal();
    //          dev->wait_for_frames();
    //          memcpy(depth_image_ptr->data_.data(),
    //                  dev->get_frame_data(rs::stream::depth), 640 * 480 * 2);
    //          return true;
    //      }, "Depth", 640, 480);
    return 0;
}