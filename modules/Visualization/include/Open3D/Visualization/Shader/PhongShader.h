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
#include <Eigen/Core>
#include <Open3D/Visualization/Shader/ShaderWrapper.h>

namespace open3d {

namespace glsl {

class PhongShader : public ShaderWrapper
{
public:
    ~PhongShader() override { Release(); }

protected:
    PhongShader(const std::string &name) : ShaderWrapper(name) { Compile(); }

protected:
    bool Compile() final;
    void Release() final;
    bool BindGeometry(const Geometry &geometry, const RenderOption &option,
            const ViewControl &view) final;
    bool RenderGeometry(const Geometry &geometry, const RenderOption &option,
            const ViewControl &view) final;
    void UnbindGeometry() final;

protected:
    virtual bool PrepareRendering(const Geometry &geometry,
            const RenderOption &option, const ViewControl &view) = 0;
    virtual bool PrepareBinding(const Geometry &geometry,
            const RenderOption &option, const ViewControl &view,
            std::vector<Eigen::Vector3f> &points,
            std::vector<Eigen::Vector3f> &normals,
            std::vector<Eigen::Vector3f> &colors) = 0;

protected:
    void SetLighting(const ViewControl &view, const RenderOption &option);

protected:
    GLuint vertex_position_;
    GLuint vertex_position_buffer_;
    GLuint vertex_color_;
    GLuint vertex_color_buffer_;
    GLuint vertex_normal_;
    GLuint vertex_normal_buffer_;
    GLuint MVP_;
    GLuint V_;
    GLuint M_;
    GLuint light_position_world_;
    GLuint light_color_;
    GLuint light_diffuse_power_;
    GLuint light_specular_power_;
    GLuint light_specular_shininess_;
    GLuint light_ambient_;

    // At most support 4 lights
    GLHelper::GLMatrix4f light_position_world_data_;
    GLHelper::GLMatrix4f light_color_data_;
    GLHelper::GLVector4f light_diffuse_power_data_;
    GLHelper::GLVector4f light_specular_power_data_;
    GLHelper::GLVector4f light_specular_shininess_data_;
    GLHelper::GLVector4f light_ambient_data_;
};

class PhongShaderForPointCloud : public PhongShader
{
public:
    PhongShaderForPointCloud() : PhongShader("PhongShaderForPointCloud") {}

protected:
    bool PrepareRendering(const Geometry &geometry,
            const RenderOption &option, const ViewControl &view) final;
    bool PrepareBinding(const Geometry &geometry,
            const RenderOption &option, const ViewControl &view,
            std::vector<Eigen::Vector3f> &points,
            std::vector<Eigen::Vector3f> &normals,
            std::vector<Eigen::Vector3f> &colors) final;
};

class PhongShaderForTriangleMesh : public PhongShader
{
public:
    PhongShaderForTriangleMesh() : PhongShader("PhongShaderForTriangleMesh") {}

protected:
    bool PrepareRendering(const Geometry &geometry,
            const RenderOption &option, const ViewControl &view) final;
    bool PrepareBinding(const Geometry &geometry,
            const RenderOption &option, const ViewControl &view,
            std::vector<Eigen::Vector3f> &points,
            std::vector<Eigen::Vector3f> &normals,
            std::vector<Eigen::Vector3f> &colors) final;
};

}   // namespace open3d::glsl

}   // namespace open3d
