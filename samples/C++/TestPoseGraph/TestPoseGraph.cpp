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

#include <cstdio>

#include <Open3D/Core/Core.h>
#include <Open3D/IO/IO.h>
#include <Open3D/Core/Registration/PoseGraph.h>
#include <Open3D/Core/Registration/GlobalOptimization.h>

using namespace open3d;

int main(int argc, char **argv)
{
    SetVerbosityLevel(VerbosityLevel::VerboseAlways);

    if (argc != 2) {
        PrintInfo("Usage:\n");
        PrintInfo("    > TestPoseGraph [posegraph_for_optimization].json\n");
        PrintInfo("    The program will :\n");
        PrintInfo("    1) Generate random PoseGraph\n");
        PrintInfo("    2) Save random PoseGraph as test_pose_graph.json\n");
        PrintInfo("    3) Reads PoseGraph from test_pose_graph.json\n");
        PrintInfo("    4) Save loaded PoseGraph as test_pose_graph_copy.json\n");
        PrintInfo("    5) Load PoseGraph from [posegraph_for_optimization].json\n");
        PrintInfo("    6) Optimize PoseGraph\n");
        PrintInfo("    7) Save PoseGraph to pose_graph_optimized.json\n");
        return 0;
    }

    // test posegraph read and write
    PoseGraph pose_graph_test;
    pose_graph_test.nodes_.push_back(PoseGraphNode(Eigen::Matrix4d::Random()));
    pose_graph_test.nodes_.push_back(PoseGraphNode(Eigen::Matrix4d::Random()));
    pose_graph_test.edges_.push_back(PoseGraphEdge(0, 1,
            Eigen::Matrix4d::Random(), Eigen::Matrix6d::Random(), false, 1.0));
    pose_graph_test.edges_.push_back(PoseGraphEdge(0, 2,
            Eigen::Matrix4d::Random(), Eigen::Matrix6d::Random(), true, 0.2));
    WritePoseGraph("test_pose_graph.json", pose_graph_test);
    PoseGraph pose_graph;
    ReadPoseGraph("test_pose_graph.json", pose_graph);
    WritePoseGraph("test_pose_graph_copy.json", pose_graph);

    // testing posegraph optimization
    auto pose_graph_input = CreatePoseGraphFromFile(argv[1]);
    GlobalOptimizationConvergenceCriteria criteria;
    GlobalOptimizationOption option;
    GlobalOptimizationLevenbergMarquardt optimization_method;
    GlobalOptimization(*pose_graph_input, optimization_method,
            criteria, option);
    auto pose_graph_input_prunned = CreatePoseGraphWithoutInvalidEdges(
            *pose_graph_input, option);
    WritePoseGraph("pose_graph_optimized.json", *pose_graph_input_prunned);

    return 0;
}
