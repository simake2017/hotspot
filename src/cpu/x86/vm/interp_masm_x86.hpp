/*
 * Copyright (c) 2013, 2016, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef CPU_X86_VM_INTERP_MASM_X86_HPP
#define CPU_X86_VM_INTERP_MASM_X86_HPP

#include "assembler_x86.inline.hpp"
#include "interpreter/invocationCounter.hpp"

// This file specializes the assember with interpreter-specific macros

/*
 * 该文件代表了 特定的 汇编指令集 针对 不同的 架构
 *
 */

class InterpreterMacroAssembler: public MacroAssembler {

#ifdef TARGET_ARCH_MODEL_x86_32
# include "interp_masm_x86_32.hpp"
#endif
#ifdef TARGET_ARCH_MODEL_x86_64
# include "interp_masm_x86_64.hpp"
#endif

 public:
  // narrow int return value
  void narrow(Register result);

};

#endif // CPU_X86_VM_INTERP_MASM_X86_HPP
