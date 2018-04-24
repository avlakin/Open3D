# Open3D: www.open-3d.org
# The MIT License (MIT)
# See license file or visit www.open-3d.org for details

from open3d import *
from global_registration import *
import numpy as np
import copy

import time

def execute_fast_global_registration(source_down, target_down,
        source_fpfh, target_fpfh, voxel_size):
    distance_threshold = voxel_size * 0.5
    print(":: Apply fast global registration with distance threshold %.3f" \
            % distance_threshold)
    result = registration_fast_based_on_feature_matching(
            source_down, target_down, source_fpfh, target_fpfh,
            FastGlobalRegistrationOption(
            maximum_correspondence_distance = distance_threshold))
    return result

if __name__ == "__main__":

    voxel_size = 0.05 # means 5cm for the dataset
    source, target, source_down, target_down, source_fpfh, target_fpfh = \
            prepare_dataset(voxel_size)
    draw_registration_result(source, target, np.identity(4))

    start = time.time()
    result_fast = execute_fast_global_registration(source_down, target_down,
            source_fpfh, target_fpfh, voxel_size)
    print(result_fast)
    print("Fast global registration took %.3f sec.\n" % (time.time() - start))
    draw_registration_result(source, target,
            result_fast.transformation)
