/*
 * Copyright (c) 2022 Trail of Bits, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

template <typename D>
DEF_SEM(GET_PC, D dst) {
  addr_t pc = Read(REG_PC);
  Write(dst, Read(ReadPtr<D>(pc)));
  return memory;
}

DEF_ISEL(GET_PC_16) = GET_PC<M16W>;
DEF_ISEL(GET_PC_32) = GET_PC<M32W>;
DEF_ISEL(GET_PC_64) = GET_PC<M64W>;