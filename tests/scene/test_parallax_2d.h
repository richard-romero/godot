/**************************************************************************/
/*  test_parallax_2d.h                                                    */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef TEST_PARALLAX_2D_H
#define TEST_PARALLAX_2D_H

#include "scene/2d/parallax_2d.h"
#include "tests/test_macros.h"

namespace Parallax2DTests {

// Test various getter and setter methods for Parallax2D.

TEST_CASE("[Parallax2D][SceneTree] Scroll Offset") {
    // Validate setting and retrieving the scroll offset.
    Parallax2D *parallax_instance = memnew(Parallax2D);
    Point2 scroll_offset(10, 10);
    parallax_instance->set_scroll_offset(scroll_offset);
    CHECK(parallax_instance->get_scroll_offset() == scroll_offset);
    memdelete(parallax_instance);
}

TEST_CASE("[Parallax2D][SceneTree] Follow Viewport") {
    // Validate setting and retrieving the follow viewport property.
    Parallax2D *parallax_instance = memnew(Parallax2D);
    parallax_instance->set_follow_viewport(false);
    CHECK_FALSE(parallax_instance->get_follow_viewport());
    memdelete(parallax_instance);
}

TEST_CASE("[Parallax2D][SceneTree] Limit Begin") {
    // Validate setting and retrieving the limit begin coordinates.
    Parallax2D *parallax_instance = memnew(Parallax2D);
    Point2 limit_start(-100, -100);
    parallax_instance->set_limit_begin(limit_start);
    CHECK(parallax_instance->get_limit_begin() == limit_start);
    memdelete(parallax_instance);
}

} // namespace Parallax2DTests

#endif // TEST_PARALLAX_2D_H
