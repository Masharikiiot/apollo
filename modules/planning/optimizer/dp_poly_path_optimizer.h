/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file dp_poly_path_optimizer.h
 **/

#ifndef MODULES_PLANNING_OPTIMIZER_DP_POLY_PATH_OPTIMIZER_H_
#define MODULES_PLANNING_OPTIMIZER_DP_POLY_PATH_OPTIMIZER_H_

#include "modules/planning/optimizer/path_optimizer.h"
#include "modules/planning/proto/dp_poly_path_config.pb.h"

namespace apollo {
namespace planning {

class DpPolyPathOptimizer : public PathOptimizer {
 public:
  explicit DpPolyPathOptimizer(const std::string &name);
  bool SetConfig(const std::string &config_file) override;
  virtual ::apollo::common::ErrorCode optimize(
      const SpeedData &speed_data, const ReferenceLine &reference_line,
      const ::apollo::planning::TrajectoryPoint &init_point,
      DecisionData *const decision_data,
      PathData *const path_data) const override;

 private:
  DpPolyPathConfig config_;
};

}  // namespace planning
}  // namespace apollo

#endif  // MODULES_PLANNING_OPTIMIZER_DP_POLY_PATH_OPTIMIZER_H_
