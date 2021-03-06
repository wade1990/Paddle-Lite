// Copyright (c) 2019 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include <string>
#include "lite/model_parser/desc_apis.h"

namespace paddle {
namespace lite {
namespace cpp {

/*
 * The cpp::VarDesc is the internal representation for Op. All the internal
 * imprementation should use it, not the pb::VarDesc.
 */
class VarDesc : public VarDescAPI {
 public:
  VarDesc() = default;

  explicit VarDesc(std::string name) : name_(name) {}

  std::string Name() const override { return name_; }

  void SetName(std::string name) override { name_ = name; }

  Type GetType() const override { return type_; }

  void SetType(Type type) override { type_ = type; }

  bool Persistable() const override { return persistable_; }

  void SetPersistable(bool persistable) override { persistable_ = persistable; }

 private:
  std::string name_;
  Type type_;
  bool persistable_;
};

}  // namespace cpp
}  // namespace lite
}  // namespace paddle
