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

#include <Open3D/Core/Core.h>
#include <Open3D/Core/Utility/Helper.h>

void PrintHelp()
{
    using namespace open3d;
    PrintInfo("Usage :\n");
    PrintInfo("    > TestProgramOptions [--help] [--switch] [--int32_t i] [--double d] [--string str] [--vector (x,y,z,...)]\n");
}

int32_t main(int32_t argc, char *argv[])
{
    using namespace open3d;
    if (argc == 1 || ProgramOptionExists(argc, argv, "--help")) {
        PrintHelp();
        return 0;
    }

    PrintInfo("Switch is %s.\n",
            ProgramOptionExists(argc, argv, "--switch") ? "ON" : "OFF");
    PrintInfo("Int is %d\n", GetProgramOptionAsInt(argc, argv, "--int32_t"));
    PrintInfo("Double is %.10f\n",
            GetProgramOptionAsDouble(argc, argv, "--double"));
    PrintInfo("String is %s\n",
            GetProgramOptionAsString(argc, argv, "--string").c_str());
    std::vector<std::string> strs;
    SplitString(strs, GetProgramOptionAsString(argc, argv, "--string"), ",.",
            true);
    for (auto &str : strs) {
        PrintInfo("\tSubstring : %s\n", str.c_str());
    }
    typedef Eigen::VectorXd::Index VectorXdIndexType;
    Eigen::VectorXd vec = GetProgramOptionAsEigenVectorXd(argc, argv,
            "--vector");
    PrintInfo("Vector is (");
    for (VectorXdIndexType i = 0; i < vec.size(); i++) {
        if (i == 0) {
            PrintInfo("%.2f", vec(i));
        } else {
            PrintInfo(",%.2f", vec(i));
        }
    }
    PrintInfo(")\n");
    return 0;
}