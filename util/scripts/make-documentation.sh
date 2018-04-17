#!/bin/sh

# open-3d.org/docs
pip install sphinx sphinx-autobuild sphinx-rtd-theme
cd docs && make html && cd ..

# open-3d.org/cppapi
sudo apt-get -y install doxygen
doxygen Doxyfile
