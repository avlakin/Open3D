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

#include <Open3D/IO/ClassIO/ImageIO.h>

#include <unordered_map>
#include <Open3D/Core/Utility/Console.h>
#include <Open3D/Core/Utility/FileSystem.h>

namespace open3d {

namespace {

static const std::unordered_map<std::string,
        std::function<bool(const std::string &, Image &)>>
        file_extension_to_image_read_function
        {{"png", ReadImageFromPNG},
        {"jpg", ReadImageFromJPG},
        {"jpeg", ReadImageFromJPG},
        };

static const std::unordered_map<std::string,
        std::function<bool(const std::string &, const Image &, int32_t)>>
        file_extension_to_image_write_function
        {{"png", WriteImageToPNG},
        {"jpg", WriteImageToJPG},
        {"jpeg", WriteImageToJPG},
        };

}   // unnamed namespace

std::shared_ptr<Image> CreateImageFromFile(const std::string &filename)
{
    auto image = std::make_shared<Image>();
    ReadImage(filename, *image);
    return image;
}

bool ReadImage(const std::string &filename, Image &image)
{
    std::string filename_ext =
            filesystem::GetFileExtensionInLowerCase(filename);
    if (filename_ext.empty()) {
        PrintWarning("Read Image failed: unknown file extension.\n");
        return false;
    }
    auto map_itr = file_extension_to_image_read_function.find(filename_ext);
    if (map_itr == file_extension_to_image_read_function.end()) {
        PrintWarning("Read Image failed: unknown file extension.\n");
        return false;
    }
    return map_itr->second(filename, image);
}

bool WriteImage(const std::string &filename, const Image &image,
        int32_t quality/* = 90*/)
{
    std::string filename_ext =
            filesystem::GetFileExtensionInLowerCase(filename);
    if (filename_ext.empty()) {
        PrintWarning("Write Image failed: unknown file extension.\n");
        return false;
    }
    auto map_itr = file_extension_to_image_write_function.find(filename_ext);
    if (map_itr == file_extension_to_image_write_function.end()) {
        PrintWarning("Write Image failed: unknown file extension.\n");
        return false;
    }
    return map_itr->second(filename, image, quality);
}

}   // namespace open3d
