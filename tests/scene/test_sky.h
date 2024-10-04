/**************************************************************************/
/*  test_sky.h                                                            */
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

#ifndef TEST_SKY_H
#define TEST_SKY_H

#include "scene/resources/sky.h"
#include "tests/test_macros.h"

namespace SkyTests {

TEST_CASE("[Sky][SceneTree] Constructor Test") {
    Sky *sky_instance = memnew(Sky);

    CHECK(sky_instance->get_process_mode() == Sky::PROCESS_MODE_AUTOMATIC);
    CHECK(sky_instance->get_radiance_size() == Sky::RADIANCE_SIZE_256);
    CHECK(sky_instance->get_material().is_null());

    memdelete(sky_instance);
}

TEST_CASE("[Sky][SceneTree] Radiance Size Getter/Setter") {
    Sky *sky_instance = memnew(Sky);

    // Verify default radiance size.
    CHECK(sky_instance->get_radiance_size() == Sky::RADIANCE_SIZE_256);

    sky_instance->set_radiance_size(Sky::RADIANCE_SIZE_1024);
    CHECK(sky_instance->get_radiance_size() == Sky::RADIANCE_SIZE_1024);

    ERR_PRINT_OFF;
    // Test setting an invalid radiance size.
    sky_instance->set_radiance_size(Sky::RADIANCE_SIZE_MAX);
    ERR_PRINT_ON;

    CHECK(sky_instance->get_radiance_size() == Sky::RADIANCE_SIZE_1024);

    memdelete(sky_instance);
}

TEST_CASE("[Sky][SceneTree] Process Mode Getter/Setter") {
    Sky *sky_instance = memnew(Sky);

    // Validate default process mode.
    CHECK(sky_instance->get_process_mode() == Sky::PROCESS_MODE_AUTOMATIC);

    sky_instance->set_process_mode(Sky::PROCESS_MODE_INCREMENTAL);
    CHECK(sky_instance->get_process_mode() == Sky::PROCESS_MODE_INCREMENTAL);

    memdelete(sky_instance);
}

} // namespace SkyTests

#endif // TEST_SKY_H
