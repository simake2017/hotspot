/*
 * Copyright (c) 1997, 2011, Oracle and/or its affiliates. All rights reserved.
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

#ifndef SHARE_VM_OOPS_KLASSOOP_HPP
#define SHARE_VM_OOPS_KLASSOOP_HPP

#include "oops/oop.hpp"

// A klassOop is the C++ equivalent of a Java class.
// Part of a klassOopDesc is a Klass which handle the
// dispatching for the C++ method calls.

//  klassOop object layout:
//    [header     ]
//    [klass_field]
//    [KLASS      ]

/*
 * 这里要区分清楚，Klass是实际 的c++类，有继承关系，
 * 比如 Instancelass类，都是具体的c++类，他们的创建都要
 * 通过new 进行创建，返回的都是对象指针，在自由区（通常也是通过malloc分配）
 * 在堆区重新分配，所以不会在jvm的堆区上分配
 *
 * 这里要理解清楚，只需要有一个KlassOop就可以了 ，不需要像instanceOop 一样 有 instanceOopdesc
 * 下面的klass_part会指向 实际的 Klass对象
 *
 */
class klassOopDesc : public oopDesc {
 public:
  // returns the Klass part containing dispatching behavior
  /**
   * 这里在 获取 获取具体的 Klass对象 的时候 会转为 相应的 Klass 对象     
   * 
   * @return Klass* 
   */
  Klass* klass_part() const                      { return (Klass*)((address)this + sizeof(klassOopDesc)); }

  //方法 在外部 实现
  // Convenience wrapper
  inline oop java_mirror() const; //wangyang 通过 java_mirror获取相应的 镜像类 

/**
 * 下面的 方法 都是私有定义 , 具体实现 在 oopDesc里面
 * 
 */
 private:
  // These have no implementation since klassOop should never be accessed in this fashion
  oop obj_field(int offset) const;
  volatile oop obj_field_volatile(int offset) const;
  void obj_field_put(int offset, oop value);
  void obj_field_put_raw(int offset, oop value);
  void obj_field_put_volatile(int offset, oop value);

  jbyte byte_field(int offset) const;
  void byte_field_put(int offset, jbyte contents);

  jchar char_field(int offset) const;
  void char_field_put(int offset, jchar contents);

  jboolean bool_field(int offset) const;
  void bool_field_put(int offset, jboolean contents);

  jint int_field(int offset) const;
  void int_field_put(int offset, jint contents);

  jshort short_field(int offset) const;
  void short_field_put(int offset, jshort contents);

  jlong long_field(int offset) const;
  void long_field_put(int offset, jlong contents);

  jfloat float_field(int offset) const;
  void float_field_put(int offset, jfloat contents);

  jdouble double_field(int offset) const;
  void double_field_put(int offset, jdouble contents);

  address address_field(int offset) const;
  void address_field_put(int offset, address contents);

  oop obj_field_acquire(int offset) const;
  void release_obj_field_put(int offset, oop value);

  jbyte byte_field_acquire(int offset) const;
  void release_byte_field_put(int offset, jbyte contents);

  jchar char_field_acquire(int offset) const;
  void release_char_field_put(int offset, jchar contents);

  jboolean bool_field_acquire(int offset) const;
  void release_bool_field_put(int offset, jboolean contents);

  jint int_field_acquire(int offset) const;
  void release_int_field_put(int offset, jint contents);

  jshort short_field_acquire(int offset) const;
  void release_short_field_put(int offset, jshort contents);

  jlong long_field_acquire(int offset) const;
  void release_long_field_put(int offset, jlong contents);

  jfloat float_field_acquire(int offset) const;
  void release_float_field_put(int offset, jfloat contents);

  jdouble double_field_acquire(int offset) const;
  void release_double_field_put(int offset, jdouble contents);

  address address_field_acquire(int offset) const;
  void release_address_field_put(int offset, address contents);
};

#endif // SHARE_VM_OOPS_KLASSOOP_HPP
