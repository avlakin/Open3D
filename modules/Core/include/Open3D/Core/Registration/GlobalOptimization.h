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

#include <memory>
#include <Open3D/Core/Registration/GlobalOptimizationMethod.h>
#include <Open3D/Core/Registration/GlobalOptimizationConvergenceCriteria.h>

namespace open3d {

class PoseGraph;

/// Function to optimize a PoseGraph
/// Reference:
/// [Kümmerle et al 2011]
///    R Kümmerle, G. Grisetti, H. Strasdat, K. Konolige, W. Burgard
///    g2o: A General Framework for Graph Optimization, ICRA 2011
/// [Choi et al 2015]
///    S. Choi, Q.-Y. Zhou, V. Koltun,
///    Robust Reconstruction of Indoor Scenes, CVPR 2015
/// [M. Lourakis 2009]
///    M. Lourakis,
///    SBA: A Software Package for Generic Sparse Bundle Adjustment,
///    Transactions on Mathematical Software, 2009
void GlobalOptimization(
        PoseGraph &pose_graph,
        const GlobalOptimizationMethod &method =
        GlobalOptimizationLevenbergMarquardt(),
        const GlobalOptimizationConvergenceCriteria &criteria =
        GlobalOptimizationConvergenceCriteria(),
        const GlobalOptimizationOption &option =
        GlobalOptimizationOption());

/// Function to prune out uncertain edges having
/// confidence_ < .edge_prune_threshold_
std::shared_ptr<PoseGraph> CreatePoseGraphWithoutInvalidEdges(
        const PoseGraph &pose_graph,
        const GlobalOptimizationOption &option);

}   // namespace open3d
