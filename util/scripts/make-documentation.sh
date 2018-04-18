#!/bin/sh

# docs.open-3d.org
pip install sphinx sphinx-autobuild sphinx-rtd-theme
cd doc && make html && cd ..

# api.open-3d.org
sudo apt-get -y install doxygen
cd doc && doxygen Doxyfile && cd ..
