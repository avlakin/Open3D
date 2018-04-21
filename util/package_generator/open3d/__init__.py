# Copyright (c) 2018 Hamdi Sahloul <hamdisahloul@hotmail.com>
# Redistribution and use is allowed according to the terms of the MIT license.

import importlib
from .open3d import *

globals().update(importlib.import_module('open3d.open3d').__dict__)
